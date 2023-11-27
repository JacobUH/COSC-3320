// 9702ae94-66ef-4bad-bd1f-1407ff1638c5

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

void addRoad(vector<vector<pair<int, int>>> &adj, int startTown, int nextTown, int distance) {
    adj[startTown].push_back({nextTown, distance});
    adj[nextTown].push_back({startTown, distance});
}

vector<int> dijkstra(int src, const vector<vector<pair<int, int>>> &adj, int d) {
    int n = adj.size();
    vector<int> dist(n, INF);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        int distance = pq.top().first;
        pq.pop();

        if (distance > dist[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (distance + w <= d && distance + w < dist[v]) {
                dist[v] = distance + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int wellConnectedTowns(int n, int d, int k, const vector<int>& busStations, const vector<vector<pair<int, int>>>& adj) {
    vector<int> reachableCount(n, 0); // Initialize the count outside the loop

    for (int station : busStations) {
        vector<int> distances = dijkstra(station, adj, d);

        for (int i = 0; i < n; ++i) {
            if (distances[i] <= d) {
                reachableCount[i]++;
            }
        }
    }

    int wellConnectedCount = 0;
    for (int i = 0; i < n; i++) {
        if (reachableCount[i] >= k) {
            wellConnectedCount++;
        }
    }

    return wellConnectedCount;
}

int main() {
    int n, d, k, b, m;
    cin >> n >> d >> k >> b >> m;

    // store bus station nodes
    vector<int> busStations(b);
    for (int i = 0; i < b; i++)
        cin >> busStations[i];

    // create an adjacency list with all the nodes/distances
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++) {
        int startTown, nextTown, distance;
        cin >> startTown >> nextTown >> distance;
        addRoad(adj, startTown, nextTown, distance);
    }

    cout << wellConnectedTowns(n, d, k, busStations, adj);
    return 0;
}