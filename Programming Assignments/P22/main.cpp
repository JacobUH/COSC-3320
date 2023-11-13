// 67f9b823-df6f-42ba-8181-d3a775d84f46

#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

void highestNumKSwaps(string number, int k, string &max, int index){
    // base case
    if (k == 0)
        return;

    // find max number
    char maxIndex = number[index];
    for (int i = index + 1; i < number.length(); i++){
        if (number[i] > maxIndex)
            maxIndex = number[i];
    }
        
    // if MaxIndex is a new number
    if (maxIndex != number[index])
        --k;
    
    // backtrack
    for (int i = number.length() - 1; i >= index; i--){
        if (number[i] == maxIndex){
            swap(number[index], number[i]);
            if (number > max)
                max = number;
            highestNumKSwaps(number, k, max, index + 1);
            swap(number[index], number[i]);
        }
    }
}

bool compare(char a, char b) { return a > b; }

void maxNumKSwaps(string number, const string maxNumber, int &minSwaps, int swaps, int index){
    // base case
    if (number == maxNumber) {
        minSwaps = min(minSwaps, swaps);
        return;
    }

    // 
    char maxDigit = '0';
    for (int i = index; i < number.size(); i++)
        maxDigit = max(maxDigit, number[i]); 
    if (number[index] != maxDigit)
        swaps++;
    for (int i = index; i < number.size(); i++) {
        if (number[i] == maxDigit) {
            swap(number[i], number[index]);
            maxNumKSwaps(number, maxNumber, minSwaps, swaps, index + 1);
            swap(number[i], number[index]);
        }
    }
}

int main(){
    string number;
    int k;
    cin >> number >> k;

    string max = number;
    highestNumKSwaps(number, k, max, 0);

    string maxNum = number;
    int totalSwaps = INT_MAX;
    sort(maxNum.begin(), maxNum.end(), compare);
    maxNumKSwaps(number, maxNum, totalSwaps, 0, 0);

    cout << max << '\n' << totalSwaps;
    return 0;
}