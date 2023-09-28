// 353ece3a-cc59-416c-8933-cecc4db69553

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// looking for the lowest number (the start of where the array was)
int countRotations(vector<int> &nums, int left, int right){
    if (left >= right)
        return left;
    int mid = (left + right) / 2;
    if (nums[mid] > nums[right])
        return countRotations(nums, mid+1, right);
    else
        return countRotations(nums, left, mid);
    return 0;
}
/*
int binarySearch(vector<int> &nums, int left, int right, int target){
    int mid = (left + right) / 2;
    if (target == nums[mid])
        return mid;

    // left subarray
    if (nums[left] <= nums[mid]){
        // search right subarray conditions
        if (target > nums[mid] || target < nums[left]){
            return binarySearch(nums, mid+1, right, target);
        }
        // search left conditions
        else{
            return binarySearch(nums, left, mid-1, target);
        }
    }
    // right subarray
    else{
        // search left subarray conditions
        if (target < nums[mid] || target > nums[right]){
            return binarySearch(nums, left, mid-1, target);
        }
        // search right conditons
        else{
            return binarySearch(nums, mid+1, right, target);
        }
    }
    return -1;
}
*/

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
    cout << k << '\n' << target;

    return 0;
}