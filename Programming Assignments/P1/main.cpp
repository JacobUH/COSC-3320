// 854e55d7-1725-46b1-be70-83d0b635d8aa

#include <iostream>
using namespace std;

bool isSafe(int temp[], int n, int i, int index)
{ // if "i" column contains a chess piece(#)
    for(int j = 0; j < index; j++){
        if(temp[j] == i)
            return false; 
    }
    return true;
}

int calculatePlacements(string arr[], int temp[], int n, int piecesToPlace, int index, int count){
    if(count == piecesToPlace) 
        return 1; 
    if(index == n) // If index is n, then there is no row to place pieces
        return 0;
    int totalPlacements = 0;
    for (int i = 0; i < n; i++){
        if (arr[index][i] == '#' && isSafe(temp, n, i, index)){
            temp[index] = i; 
            totalPlacements = totalPlacements + calculatePlacements(arr, temp, n, piecesToPlace, index + 1, count + 1); // Backtrack and remmove i from position[index]                     
            temp[index] = -1; 
        }
    }
    totalPlacements = totalPlacements + calculatePlacements(arr, temp, n, piecesToPlace, index + 1, count);          
    return totalPlacements; 
}

int main(){
    int n, piecesToPlace;
    cin >> n >> piecesToPlace;
    
    string arr[n]; // input board from the user as . and #         
    for(int i = 0; i < n; i++){             
        cin >> arr[i];         
    } // position[i] => location of chess piece in ith row         
    int temp[n];         
    for(int i = 0; i < n; i++)         
    {             
        temp[i] = -1;         
    }         
    int output = calculatePlacements(arr, temp, n, piecesToPlace, 0, 0);         
    cout << output << endl;    
    
    return 0;
}