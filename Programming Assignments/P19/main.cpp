#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int robertPoints = 0;
int rachelPoints = 0;

int calcPoints(vector <int> subArray1, vector <int> subArray2){
  int index = 0;
  int tempScore = 0;
  int finalScore = 0;
  while (index < subArray1.size()){
    while (){
      
    }

    index++;
  }
  return finalScore;
}

void merge(vector <int> &robert, vector <int> & rachel, int left, int mid, int right){
  
}

void mergeSort(vector <int> robert, vector <int> rachel, int left, int right){
  if (left >= right)
    return;

  int mid = left + (right - left) / 2;

  // lefts
  mergeSort(robert, rachel, left, mid);
  // rights
  mergeSort(robert, rachel, mid + 1, right);
  merge(robert, rachel, left, mid, right);
}

int main(){
    string in;
    vector <int> robert;
    vector <int> rachel;
    int num;

    getline(cin, in);
    istringstream iss1(in);
    while (iss1 >> num)
      robert.push_back(num);
    
    getline(cin, in);
    istringstream iss2(in);
    while (iss2 >> num)
      rachel.push_back(num);
    
    mergeSort(robert, rachel, 0, rachel.size()-1);
}
