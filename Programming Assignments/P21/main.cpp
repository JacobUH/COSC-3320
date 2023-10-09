// a461b331-b478-44c9-bc4e-80a71ef76b20

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

bool isValid(const string &symbols, const unordered_map <char, char> &charToInt, const string &line1, const string &line2, const string &target) {
    int num1 = 0, num2 = 0, sum = 0;
    
    for (char c : line1) {
        num1 = num1 * 10 + (charToInt.at(c) - '0');
    }

    for (char c : line2) {
        num2 = num2 * 10 + (charToInt.at(c) - '0');
    }

    for (char c : target) {
        sum = sum * 10 + (charToInt.at(c) - '0');
    }
    return num1 + num2 == sum;
}

bool backtrack(const string &symbols, unordered_map <char, char> &charToInt, bool usedBool[], int currIndex, string line1, string line2, string sum){
    // Base case: If we have assigned every letter a digit
    if (currIndex == symbols.size()){
        if (isValid(symbols, charToInt, line1, line2, sum)){
            // if we found the output
            for (char c: symbols)
                cout << charToInt[c];
            cout << endl;
            return true;
        }
        return false;
    }
    
    // assigning each digit from 0 to 9
    for (char curDigit = '0'; curDigit <= '9'; ++curDigit){
        if (!usedBool[curDigit - '0']){
            // assign the symbol as the current number
            charToInt[symbols[currIndex]] = curDigit; // store int to current char
            usedBool[curDigit - '0'] = true; // used

            if(backtrack(symbols, charToInt, usedBool, currIndex + 1, line1, line2, sum))
                return true;

            usedBool[curDigit - '0'] = false; // unused
        }
    }
    return false;
}

int main(){
    string symbols;
    string line1;
    string line2;
    string sum;
    unordered_map <char, char> charToInt;
    bool usedBool[10] = {false};

    cin >> symbols >> line1 >> line2 >> sum;
    backtrack(symbols, charToInt, usedBool, 0, line1, line2, sum);
    return 0;
}