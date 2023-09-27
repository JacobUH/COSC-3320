#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int countRotations(vector<int> &nums, int left, int mid){
    return 0;
}

int binarySearch(vector<int> &nums, int left, int mid, int right, int target){
    while (left <= right){
        mid = (left + right) / 2;
        if (target == nums[mid])
            return mid;

        // left subarray
        if (nums[left] <= nums[mid]){
            // search right subarray conditions
            if (target > nums[mid] || target < nums[left]){
                left = mid+1;
            }
            // search left conditions
            else{
                right = mid-1;
            }
        }
        // right subarray
        else{
            // search left subarray conditions
            if (target < nums[mid] || target > nums[right]){
                right = mid-1;
            }
            // search right conditons
            else{
                left = mid+1;
            }
        }
    }
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

    int mid = arr.size()/2;

    int k = countRotations(arr, 0, arr.size()-1);
    int target = binarySearch(arr, 0, mid, arr.size()-1, value);
    cout << k << endl << target;

    return 0;
}