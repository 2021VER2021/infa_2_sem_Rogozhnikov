#include <iostream>
#include <random>
#include <chrono>

using namespace std;
int n;
random_device dev;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<int> dist(0, 100);


/// to swap two integers
void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

/// print array
void print(int array[], int n){
    for (int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}

/// simple sort
void booble_sort(int array[], int n){
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++){
            if (array[i] < array[j]){
                swap(array[i], array[j]);
            }
        }
    }
}

/// quick sort
void qsort(int array[], int begin, int end){
    /// элемент по Хоару
    int a_p = array[(begin + end)/2];
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
        if (l <= r){
            swap(array[l], array[r]);
            l++;
            r--;
        }
    } while (l <= r);
    /*
    cout << array[l] << " " << array[r] << "  ";
    print(array, n);
     */
    if (r - begin > 0){
        qsort(array, begin, r);
    }
    if (end - l > 0){
        qsort(array, l, end);
    }
}

/// fill array with random numbers
void fill(int array[], int n){
    for (int i = 0; i < n; i++){
        array[i] = dist(rng);
    }
}


int main() {
    cout << "write the length of array" << endl;
    cin >> n;
    int *array = new int[n];
    fill(array, n);
    print(array, n);
    qsort(array, 0, n-1);
    print(array, n);
}
