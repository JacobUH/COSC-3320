// 13f26e1e-192d-473f-9283-709f7cb8711b

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int robertPoints = 0;
int rachelPoints = 0;

int calcPoints(vector <int> subArrayLeft, vector <int> subArrayRight){
  int index = 0;
  int tempScore = 0;
  int finalScore = 0;
  while (index < subArrayRight.size()){
    while ( tempScore < subArrayLeft.size() && subArrayLeft[tempScore] < subArrayRight[index]){
      tempScore++;
    }
    finalScore += tempScore;
    index++;
  }
  return finalScore;
}

void merge(vector <int> &robert, vector <int> & rachel, int left, int mid, int right){
  int leftSize = mid - left + 1;
  int rightSize = right - mid;

  vector <int> robertLeft(robert.begin() + left, robert.begin() + mid+1);
  vector <int> robertRight(robert.begin() + mid+1, robert.begin() + right+1);
  vector <int> rachelLeft(rachel.begin() + left, rachel.begin() + mid+1);
  vector <int> rachelRight(rachel.begin() + mid+1, rachel.begin() + right+1);

  /*
  // copy the subarrays over to the vectors
  for (int i = 0; i < leftSize; i++){
    robertLeft.push_back(robert[left + i]);
    rachelLeft.push_back(rachel[left + i]);
}

  for (int j = 0; j < rightSize; j++){
    robertRight.push_back(robert[mid + 1 + j]);
    rachelRight.push_back(rachel[mid + 1 + j]);
  }
  */
  
  

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

  // helper function
  robertPoints += calcPoints(rachelLeft, robertRight);
  rachelPoints += calcPoints(robertLeft, rachelRight);

  // if there are remaining elements leftover in the Left and Right subarrays for robert and rachel

  // robert left subarray
  while (robert_i < leftSize){
    robert[robert_k] = robertLeft[robert_i];
    robert_i++;
    robert_k++;
  }

  // robert right subarray
  while (robert_j < rightSize){
    robert[robert_k] = robertRight[robert_j];
    robert_j++;
    robert_k++;
  }

  // rachel left subarray
  while (rachel_i < leftSize){
    rachel[rachel_k] = rachelLeft[rachel_i];
    rachel_i++;
    rachel_k++;
  }

  // rachel right subarray
  while (rachel_j < rightSize){
    rachel[rachel_k] = rachelRight[rachel_j];
    rachel_j++;
    rachel_k++;
  }
}

void mergeSort(vector <int> &robert, vector <int> &rachel, int left, int right){
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
    stringstream iss1(in);
    while (iss1 >> num)
      robert.push_back(num);
    
    getline(cin, in);
    stringstream iss2(in);
    while (iss2 >> num)
      rachel.push_back(num);
    
    mergeSort(robert, rachel, 0, rachel.size()-1);
    cout << robertPoints << " " << rachelPoints;

    return 0;
}