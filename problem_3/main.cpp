#include <iostream>

using namespace std;

void foo(int& b) {
    int a = 0;
    while (b > 0) {
        a = 10*a + b % 10;
        b = b / 10;
    }
    b = a;
}

int main() {
    int a;
    cin >> a;
    int &b = a;
    foo(b);
    cout << a;
    return 0;
}
