#include <iostream>
#include <cstring>
#include <random>
#include <chrono>

using namespace std;
const double inf = 1e27;
/*
struct Student {
    float score = 0.0f;
    char name[20] = " ";
};

std::ostream &operator<<(std::ostream &os, const Student &s) {
    os << s.name << " " << s.score;
    return os;
}

void swap(Student &a, Student &b) {
    Student tmp = a;
    a = b;
    b = tmp;
}

bool operator<(const Student &s1, const Student &s2) {
    return (s1.score < s2.score);
}

bool operator>(const Student &s1, const Student &s2) {
    return (s2 < s1);
}

/// quick sort, hard
void qsort(Student array[], int begin, int end) {
    /// элемент по Хоару
    Student a_p = array[(begin + end) / 2];
    /// указатели
    int l = begin;
    int r = end;
    /// основной цикл сортировки
    do {
        while (array[l] < a_p) {
            l++;
        }
        while (array[r] > a_p) {
            r--;
        }
        if (l <= r) {
            swap(array[l], array[r]);
            l++;
            r--;
        }
    } while (l <= r);

    if (r - begin > 0) {
        qsort(array, begin, r);
    }
    if (end - l > 0) {
        qsort(array, l, end);
    }
}

void print(Student array[], int m, float M) {
    for (int i = 0; i < m; i++) {
        if (array[i].score > M){
            cout << array[i] << endl;
        }
    }
    cout << endl;
}

void print(Student array[], int m) {
    for (int i = 0; i < m; i++) {
        cout << array[i] << endl;
    }
    cout << endl;
}

void name(char name[], int m) {
    random_device dev;
    mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<char> dist('A', 'Z');
    for (int i = 0; i < m; i++) {
        name[i] = dist(rng);
    }
}

void fill(Student array[], int m) {
    random_device dev;
    mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(40, 100);
    for (int i = 0; i < m; i++) {
        array[i].score = dist(rng) / 20.0f;
        name(array[i].name, 5);
    }
}

int main() {
    int n;
    double f;
    cout << "write n and M" << endl;
    cin >> n >> f;
    Student *stud = new Student[n];
    fill(stud, n);
    print(stud, n);
    qsort(stud, 0, n - 1);
    print(stud, n, f);
    return 0;
}
*/

struct Line {
    int x1, x2, y1, y2;
    float k;
};

int min(int a, int b){
    return (a < b) ? a : b;
}

int max(int a, int b){
    return (a > b) ? a : b;
}

float koef(Line line){
    float k;
    if (line.x1 == line.x2){
        k = inf;
    }
    else{
        k = float(line.y2-line.y1)/float(line.x2 - line.x1);
    }
    return k;
}

float get_x(Line l1, Line l2){
    float x;
    int x1 = l1.x1, x2 = l1.x2, x3 = l2.x1, x4 = l2.x2;
    int y1 = l1.y1, y2 = l1.y2, y3 = l2.y1, y4 = l2.y2;
    x = float((x1*y2 - y1*x2)*(x3 - x4) - (x1 - x2)*(x3*y4 - x4*y3))/float((x1-x2)*(y3-y4) - (y1 - y2)*(x3 - x4));
    return x;
}

float get_y(Line l1, Line l2){
    float y;
    int x1 = l1.x1, x2 = l1.x2, x3 = l2.x1, x4 = l2.x2;
    int y1 = l1.y1, y2 = l1.y2, y3 = l2.y1, y4 = l2.y2;
    y = float((x1*y2 - y1*x2)*(y3 - y4) - (y1 - y2)*(x3*y4 - x4*y3))/float((x1-x2)*(y3-y4) - (y1 - y2)*(x3 - x4));
    return y;
}

bool check(float x, float y, Line l1, Line l2){
    bool f;
    if ((x <= max(l1.x1, l1.x2)) and (x >= min(l1.x1, l1.x2)) and (x <= max(l2.x1, l2.x2)) and (x >= min(l2.x1, l2.x2)) and
        (x <= max(l1.y1, l1.y2)) and (x >= min(l1.y1, l1.y2)) and (x <= max(l2.y1, l2.y2)) and (x >= min(l2.y1, l2.y2))){
        f = true;
    }
    else{
        f = false;
    }
    return f;
}

ostream &operator<<(ostream &os, const Line &s) {
    os << "(" << s.x1 << ", " << s.y1 << "), (" << s.x2 << ", " << s.y2 << ")";
    return os;
}

int main() {
    int n;
    cout << "Write the number of lines" << endl;
    cin >> n;
    Line *lines = new Line[n];
    cout << "And now, write lines, using format: x1, y1, x2, y2" << endl;
    for (int i = 0; i < n; i++){
        cin >> lines[i].x1 >> lines[i].y1 >> lines[i].x2 >> lines[i].y2;
        lines[i].k = koef(lines[i]);
    }

    for (int i = 0; i < n-1; i++){
        float k_i = lines[i].k;
        for (int j = i+1; j < n; j++){
            float p_x, p_y;
            float k_j = lines[j].k;
            if (k_i == k_j){
                if ((check(lines[i].x1, lines[i].y1, lines[i], lines[j]) or check(lines[i].x2, lines[i].y2, lines[i], lines[j])
                or check(lines[j].x1, lines[j].y1, lines[i], lines[j]) or check(lines[i].x2, lines[j].y2, lines[i], lines[j]))
                and ((lines[i].y1 - lines[i].k*lines[i].x1) == (lines[j].y1 - lines[j].k*lines[j].x1))){
                    cout << "cross with parallel lines: " << i+1 << " and " << j+1 << endl;
                }
            }
            else{
                p_x = get_x(lines[i], lines[j]);
                p_y = get_y(lines[i], lines[j]);
                if (check(p_x, p_y, lines[i], lines[j])){
                    cout << "cross: (" << p_x << " ," << p_y << ") with lines " << i+1 << " and " << j+1 << endl;
                }
            }
        }
    }

    cout << "Array of lines: " << endl;
    for (int i = 0; i < n; i++) {
        cout << lines[i] << endl;
    }
    delete[] lines;
}
