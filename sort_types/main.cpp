#include <iostream>
#include <random>
#include <chrono>

using namespace std;

int count;
int n;

/// to swap two integers
void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}
/// print array
void print(int array[], int m) {
    for (int i = 0; i < m; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
/// simple sort
void booble_sort(int array[], int m) {
    for (int i = 0; i < m; i++) {
        for (int j = i; j < m; j++) {
            if (array[i] < array[j]) {
                swap(array[i], array[j]);
            }
        }
    }
}
/// quick sort, hard
void qsort(int array[], int begin, int end) {
    /// элемент по Хоару
    int a_p = array[(begin + end) / 2];
    /// указатели
    int l = begin;
    int r = end;
    /// основной цикл сортировки
    do {
        while (array[l] < a_p) {
            l++;
            count++; /// step counter
        }
        while (array[r] > a_p) {
            r--;
            count++; /// step counter
        }
        if (l <= r) {
            swap(array[l], array[r]);
            l++;
            r--;
            count++;
        }
    } while (l <= r);
    /*
    cout << array[l] << " " << array[r] << "  ";
    print(array, n);
     */
    if (r - begin > 0) {
        qsort(array, begin, r);
    }
    if (end - l > 0) {
        qsort(array, l, end);
    }
}
/// help for heapsort
void heap_help(int array[], int m, int i) {
    int largest = i;
    int right = 2 * i + 2;
    int left = 2 * i + 1;
    if (right < m){
        if (array[largest] < array[right]){
            largest = right;
        }
    }
    if (left < m){
        if (array[largest] < array[left]){
            largest = left;
        }
    }
    if (largest != i) {
        swap(array[largest], array[i]);
        heap_help(array, m, largest);
    }
    count++; /// step counter
}
/// heapsort, hard hard
void heapsort(int array[], int m) {
    for (int i = m / 2 - 1; i >= 0; i--)
        heap_help(array, m, i);
    for (int i = m - 1; i >= 0; i--) {
        swap(array[i], array[0]);
        heap_help(array, i, 0);
    }
}
/// fill array with random numbers
void fill(int array[], int m) {
    random_device dev;
    mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(0, 100);
    for (int i = 0; i < m; i++) {
        array[i] = dist(rng);
    }
}
/// copy array1 to array2
void copy(int array1[], int array2[], int n) {
    for (int i = 0; i < n; i++) {
        array2[i] = array1[i];
    }
}


int main() {
    cout << "write the length of array" << endl;
    cin >> n;
    int *array1 = new int[n];
    int *array2 = new int[n];
    fill(array1, n);
    copy(array1, array2, n);
    //print(array1, n);
    count = 0;
    heapsort(array1, n);
    cout << "heapsort: " << count << endl;
    count = 0;
    qsort(array2, 0, n - 1);
    cout << "qsort: " << count << endl;
    //print(array1, n);
    //print(array2, n);

}
