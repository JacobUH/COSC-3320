// 933ec051-6e76-48ae-8c52-c9da165b3fab

#include <iostream>
#include <vector>
using namespace std;

int maxDif(vector <int> arr, int n){
    // 1 5 8 2
    int maxDiff = 0;
    int leftPointer = 0;
    int rightPointer = 0;

    while (rightPointer < n){
        if (arr[leftPointer] < arr[rightPointer])
            maxDiff = max(maxDiff, arr[rightPointer] - arr[leftPointer]);
        else
            leftPointer = rightPointer;
        rightPointer++;
    }
    return maxDiff;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; ++i) {
        int in;
        cin >> in;
        arr.push_back(in);
    }
    cout << maxDif(arr, n);
}
