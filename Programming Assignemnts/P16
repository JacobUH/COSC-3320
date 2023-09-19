// d1210a1f-53d7-4381-9367-2bbb85c5d9bf

#include <iostream>
using namespace std;

int lastRemaining(int n) {
    if (n == 1) {
        return 1;
    }
    return 2 * (n / 2 + 1 - lastRemaining(n / 2));
}

int main() {
    int num;
    cin >> num;
    cout << lastRemaining(num) << endl;
    return 0;
}
