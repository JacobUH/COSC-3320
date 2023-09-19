// 5c9714f1-ded6-41c2-b6f4-b4dfc09699dd

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

bool finder(vector<int> &nums, int &current){
  auto element = find(nums.begin(), nums.end(), ++current);
  if (element != nums.end()){
    nums.erase(element);
    return true;
  }    
  else{
    cout << "false";
    return false;
  }
}

bool divideArr(vector<int> &nums, int k){
    // base case
    if (nums.size() == 0){
        cout << "true";
        return true;
    }
    
    int current = nums[0];
    nums.erase(nums.begin());

    for (int i = 1; i < k; i++){
        bool numFound = finder(nums, current);
        if (!numFound)
          return false;
    }
    return divideArr(nums, k);
}

int main(){
    string in;
    vector <int> nums;

    getline(cin, in);
    istringstream iss(in);
    int num;
    while (iss >> num)
      nums.push_back(num);
    
    int k;
    cin >> k;
    
    sort(nums.begin(), nums.end());
    if (nums.size() % k != 0){
      cout << "false";
      return false;
    }
        
    divideArr(nums, k);
}
