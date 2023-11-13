// 402d6caf-3750-44b9-899e-d8af8edb8caa

#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

/*
Input:
2 (width)
6 (height)
cosc 3320
Output: 1

Explanation: The text is a sequence of 2 words: cosc, 3320
c o s c - -
3 3 2 0 - -
*/

// width: 2
// height: 6

int dpSolution(const vector<int>& lengthWords, const int width, const int height, const int sizeLengthWords, const int count) {
    vector<int> dpArray(width + 1, 0);

    int index = 0;
    int spaceTaken = 0;
    int widthIndex = 0;
    int textCounter = 0;
    
    while (widthIndex < width) {
        if (height >= count){
            int linesFit = height / count;
            textCounter += linesFit;
            dpArray[widthIndex] = textCounter;
            spaceTaken = height - (height % count);
        }
        else
            spaceTaken = 0;

        while (index < sizeLengthWords && lengthWords[index] + spaceTaken + 1 <= height){
            spaceTaken += lengthWords[index] + 1; // Include word and space
            index++;

            if (index == sizeLengthWords) {
                index = 0;
                textCounter++;
                dpArray[widthIndex] = textCounter;
            }
        }

        widthIndex++;
    }

    return dpArray[width - 1];
}

int init(const int width, const int height, const string input){
    vector <int> lengthWords;
    stringstream ss(input);
    string word;
    while (ss >> word)
        lengthWords.push_back(word.size());

    int size = lengthWords.size();
    int count = input.size() + 1;

    int result = dpSolution(lengthWords, width, height, size, count);
    return result;
}

int main(){
    int width, height;
    cin >> width >> height;
    cin.ignore();

    string input;
    getline(cin, input);

    int output = init(width, height, input);
    cout << output;

    return 0;
}