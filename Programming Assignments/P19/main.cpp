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
  int leftSize = mid - left + 1;
  int rightSize = right - mid;

  vector <int> robertLeft;
  vector <int> robertRight;
  vector <int> rachelLeft;
  vector <int> rachelRight;

  // copy the subarrays over to the vectors
  for (int i = 0; i < leftSize; i++){
    robertLeft[i] = robert[left + i];
    rachelLeft[i] = rachel[left + i];
  }

  for (int j = 0; j < rightSize; j++){
    robertRight[j] = robert[mid + 1 + j];
    rachelRight[j] = rachel[mid + 1 + j];
  }

  // helper here
  int i = 0;
  int j = 0;
  

  // create indexes for saving the indexes of the main array and subarrays
  int robert_i = 0;
  int robert_j = 0;
  int robert_k = left;

  int rachel_i = 0;
  int rachel_j = 0;
  int rachel_k = left;

  while (robert_i < leftSize && robert_j < rightSize){
    if (robertLeft[robert_i] <= robertRight[robert_j]){
      robert[robert_k] = robertLeft[robert_i];
      robert_i++;
    }
    else{
      robert[robert_k] = robertRight[robert_j];
      robert_j++;
    }
    robert_k++;
  }

  while (rachel_i < leftSize && rachel_j < rightSize){
    if (rachelLeft[rachel_i] <= rachelRight[rachel_j]){
      rachel[rachel_k] = rachelLeft[rachel_i];
      rachel_i++;
    }
    else{
      rachel[rachel_k] = rachelRight[rachel_j];
      rachel_j++;
    }
    rachel_k++;
  }

  // if there are remaining elements leftover in the Left and Right subarrays for robert and rachel

  // robert left subarray
  while (robert_i < leftSize){
    robert[robert_k] = robertLeft[robert_i];
    robert_i++;
  }

  // robert right subarray
  while (robert_j < rightSize){
    robert[robert_k] = robertRight[robert_j];
    robert_j++;
  }

  // rachel left subarray
  while (rachel_i < leftSize){
    rachel[rachel_k] = rachelLeft[rachel_i];
    rachel_i++;
  }

  // rachel right subarray
  while (rachel_j < rightSize){
    rachel[rachel_k] = rachelRight[rachel_j];
    rachel_j++;
  }
}

void mergeSort(vector <int> robert, vector <int> rachel, int left, int right){
  if (left < right){
    int mid = left + (right - left) / 2;

    // lefts
    mergeSort(robert, rachel, left, mid);
    // rights
    mergeSort(robert, rachel, mid + 1, right);
    // merge function
    merge(robert, rachel, left, mid, right);
  } 
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
    cout << robertPoints << " " << rachelPoints;
}
