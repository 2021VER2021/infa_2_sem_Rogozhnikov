#include <iostream>

using namespace std;

bool foo(int s1, int s2) {
    return s1 <= s2;
}

bool left(char l) {
    return l == '(';
}

int main() {
    int n;
    int s1 = 0;
    int s2 = 0;
    cin >> n;
    char l;
    for (int i = 0; i < n; ++i) {
        cin >> l;
        if (left(l)) {
            s1++;
        } else {
            s2++;
        }
        if ((foo(s1, s2)))
            break;
    }
    if (s1 == s2) {
        cout << "TRUE";
    } else {
        cout << "FALSE";
    }
    return 0;
}
