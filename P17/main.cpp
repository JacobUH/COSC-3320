#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int countRotations(vector<int> &nums){

}
int binarySearch(vector<int> &nums, int target){
    return -1;
}

int main(){

    string array;
    vector <int> arr;
    int num;
    int value;
    
    getline(cin, array);
    stringstream ss(array);

    while (ss >> num)
        arr.push_back(num);
    cin >> value;

    int k = countRotations(arr);
    int target = binarySearch(arr, value);
    cout << k << endl << target;
    return 0;
}