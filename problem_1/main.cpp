#include <iostream>

using namespace std;

bool polindrom(int a) {
    int a1 = 0;
    int ax = a;
    while (ax > 0) {
        a1 = a1 * 10 + ax % 10;
        ax = ax / 10;
    }
    return a1 == a;
}

bool prime(int a) {
    bool f = true;
    for (int i = 2; i * i <= a; ++i) {
        if ((a % i) == 0) {
            f = false;
            break;
        }
    }
    return f;
}

int main() {
    int n;
    int a;
    cin >> n;
    for (int j = 0; j < n; ++j) {
        cin >> a;
        string s1, s2;
        if (polindrom(a)) {
            s2 = "POLINDROM";
        } else {
            s2 = "NOT POLINDROM";
        }
        if (prime(a)) {
            s1 = "PRIME ";
        } else {
            s1 = "NOT PRIME ";
        }
        cout << s1 << s2 << endl;
    }
}
