// 32b9ea59-eb9d-462c-9011-d5280e3c91b8

#include <iostream>
using namespace std;

int staircaseTraversal(int height, int maxSteps) {
    
    if (height <= 1)
        return 1;
    
    int total = 0;
    for (int i = 1; i <= min(maxSteps, height); ++i){
        total += staircaseTraversal(height - i, maxSteps);
    }
    return total;
}


int main(){
    int height, maxSteps;
    cin >> height >> maxSteps;

    cout << staircaseTraversal(height, maxSteps);
}