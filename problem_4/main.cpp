#include <iostream>
using namespace std;

int n;

string start(){
    // you should first define n, then call start
    string s;
    const char C = 'A';
    char c = C;
    for (int j=n; j > 1; j--){
        c = C + n - j;
        s = s + c;
    }
    c = (C + n - 1);
    s = s + c;
    for (int i=(n-2); i >= 0; i--){
        c = C + i;
        s = s + c;
    }
    return s;
}

string foo(string s){
    // you should first define n, then call foo
    int i = 0;
    bool f = true;
    while (i <= 2*(n-1)){
        if (s[i] == ' '){
            s[i-1] = ' ';
            s[2*(n-1) - i + 1] = ' ';
            f = false;
            break;
        }
        i++;
    }
    if (f){
        s[n-1] = ' ';
    }
    return s;
}

int main() {
    cin >> n;
    string s;
    s = start();
    for (int i = 0; i < n; i++){
        cout << s << endl;
        s = foo(s);
    }
    return 0;
}
