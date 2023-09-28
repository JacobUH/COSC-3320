#include <iostream>
#include <vector>
using namespace std;

// backtracking
vector<int> steppingNumbers(int low, int high){
    vector <int> permutations;

    // base case
    while (low < high){
        int prev = -1;
        while (low){
            int cur = low % 10;
        }
    }
    return permutations;
}

int main(){
    int low;
    int high;
    cin >> low >> high;
    vector <int> combinations = steppingNumbers(low, high);

    for (int i: combinations)
        cout << i << " ";
    return 0;
}