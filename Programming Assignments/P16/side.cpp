#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lastRemainingNum(vector <int> &nums, vector <int>::iterator it, bool removingFromLeft){
    if (nums.size() == 1)
        return nums[0];

    if (removingFromLeft){
        it = nums.begin();
        for (auto i = it; i != nums.end(); i+2)
            nums.erase(i);
        return lastRemainingNum(nums, it, false);
    }
    else{
        it = nums.end();
        for(auto i = it; i != nums.begin(); i-2)
            nums.erase(i);
        return lastRemainingNum(nums, it, true);
    }
}

int main(){
    int num;
    vector <int> nums;
    vector <int>::iterator it;
    cin >> num;

    for (int i = 0; i < num; i++){
        nums.push_back(i);
    }
    
    cout << lastRemainingNum(nums, it, true);
}