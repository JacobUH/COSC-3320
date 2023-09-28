// 7b257f24-3fa6-4cf2-812d-ed45ae48b9a2

#include <iostream>
#include <vector>
using namespace std;

// backtracking
vector<int> steppingNumbers(int low, int high) {
    vector<int> steppingNums;

    for (int num = low; num <= high; ++num) {
        int prevDigit = -1;
        int temp = num;
        bool isStepping = true;

        while (temp > 0) {
            int curDigit = temp % 10;

            if (prevDigit != -1 && abs(prevDigit - curDigit) != 1) {
                isStepping = false;
                break;
            }

            prevDigit = curDigit;
            temp /= 10;
        }

        if (isStepping) {
            steppingNums.push_back(num);
        }
    }

    return steppingNums;
}

int main() {
    int low, high;
    cin >> low >> high;
    vector<int> combinations = steppingNumbers(low, high);

    for (int i : combinations)
        cout << i << " ";

    return 0;
}
