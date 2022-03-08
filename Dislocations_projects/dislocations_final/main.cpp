///? maybe kill before step, maybe can spawn on edges, maybe...

///-1 - death; 0 - no; 1 - one; 2 - two...
#include <iostream>
#include <random>
#include <chrono>

using namespace std;

const int n_x_max = 20;             /// max width of crystal
const int n_y_max = 20;             /// max height of crystal

int n_x = 9;
int n_y = 9;

const int empty = 0;
const int death = -1;

const long test_number = 100000;     /// number of simulations
const int disslocations = 2;    /// number of disslocations at the start

int number_diss = 0; /// currant number of disslocations
int steps;           /// currant number of steps
float average = 0.0;   /// answer
long sum = 0;        /// average = sum / test_number

int field[n_x_max + 2][n_y_max + 2] = {0};  /// main array of sells state, with 0 on edges
int field_action[n_x_max + 2][n_y_max + 2] = {0}; /// action check

///special
int pr = 0;

/// Периодические граничные условия по направлениям:
/// 1) поменять функции change_x и change_y

void debug() {
    for (int i = 1; i < n_x + 1; i++) {
        for (int j = 1; j < n_y + 1; j++) {
            if (field[i][j] != death) { cout << field[i][j]; }
            else { cout << "#"; }
        }
        cout << endl;
    }
    cout << endl;
}

int change_x(int x, int delta) {
    return ((x + delta > 0) ? ((x + delta - 1) % n_x + 1) : (n_x));
}

int change_y(int y, int delta) {
    return ((y + delta > 0) ? ((y + delta - 1) % n_y + 1) : (n_y));
}

bool kill(int a) {
    return (a != empty);
}

bool step(int a) {
    return (a == empty);
}

void start() {
    ///make start area, with no diss and stopped diss
    for (int i = 1; i < n_x + 1; i++) {
        for (int j = 1; j < n_y + 1; j++) {
            field[i][j] = empty;
        }
    }

    for (int i = 0; i < n_y + 2; i++) { ///!!!
        field[0][i] = death;
        field[n_x + 1][i] = death;
    }

    for (int i = 0; i < n_x + 2; i++) {
        field[i][0] = death;
        field[i][n_y + 1] = death;
    }

}

void step(int rand_result, int x_coord, int y_coord) {
    switch (rand_result) {
        case 0: {
            if (step(field[change_x(x_coord, 1)][y_coord])) {
                field[x_coord][y_coord] -= 1;
                field[change_x(x_coord, 1)][y_coord] += 1;
            }
            break;
        }
        case 1: {
            if (step(field[change_x(x_coord, -1)][y_coord])) {
                field[x_coord][y_coord] -= 1;
                field[change_x(x_coord, -1)][y_coord] += 1;
            }
            break;
        }
        case 2: {
            if (step(field[x_coord][change_y(y_coord, 1)])) {
                field[x_coord][y_coord] -= 1;
                field[x_coord][change_y(y_coord, 1)] += 1;
            }
            break;
        }
        case 3: {
            if (step(field[x_coord][change_y(y_coord, -1)])) {
                field[x_coord][y_coord] -= 1;
                field[x_coord][change_y(y_coord, -1)] += 1;
            }
            break;
        }
        default: {
        }
    }
}

bool check_for_kill(int x_coord, int y_coord) {
    bool f = true;
    if (field[x_coord][y_coord] >= 1) {
        if (kill(field[change_x(x_coord, 1)][y_coord])) { f = false; }
        if (kill(field[change_x(x_coord, -1)][y_coord])) { f = false; }
        if (kill(field[x_coord][change_y(y_coord, 1)])) { f = false; }
        if (kill(field[x_coord][change_y(y_coord, -1)])) { f = false; }
    }
    return f;
}

void mainloop() {
    /// init parameters
    number_diss = 0;
    steps = 0;

    /// init random
    random_device dev;
    mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

    /// generator for directions
    uniform_int_distribution<int> dist(0, 3 + pr); /// if last >3 then it will pass some steps

    /// generator for x coord, and disslocation can't be killed instantly by edges
    uniform_int_distribution<int> dist_n_x(2, n_x - 1);

    /// generator for y coord, and disslocation can't be killed instantly by edges
    uniform_int_distribution<int> dist_n_y(2, n_y - 1);

    start();

    //debug();

    /// put disslocations on a field
    while (number_diss < disslocations) { ///at yhe start only one in a cell
        int x_coord = dist_n_x(rng);
        int y_coord = dist_n_y(rng);
        if (field[x_coord][y_coord] == empty) {
            field[x_coord][y_coord] += 1;
            number_diss++;
        }
    }

    //debug();
    /// main part
    while (number_diss > 0) {

        /// destroy action (every disslocation can potentially move)
        for (int i = 1; i < n_x + 1; i++) {
            for (int j = 1; j < n_y + 1; j++) {
                if (field[i][j] != death) {
                    field_action[i][j] = field[i][j];
                } else {
                    field_action[i][j] = -1;
                }

            }
        }

        //debug();

        /// step stage, disslocations try to move
        for (int i = 1; i < n_x + 1; i++) {
            for (int j = 1; j < n_y + 1; j++) { ///while FIXIT
                int m = field_action[i][j];
                for (int k = 0; k < m; k++) {
                    if (field_action[i][j] > 0) {
                        int result = dist(rng);
                        step(result, i, j);
                    }
                    field_action[i][j] -= 1;
                }
            }
        }

        debug();

        /// kill loop, merging disslocations to each other, or to edges
        for (int i = 1; i < n_x + 1; i++) {
            for (int j = 1; j < n_y + 1; j++) {
                if (not(check_for_kill(i, j))) {
                    number_diss -= field[i][j];
                    field[i][j] = death;
                }
            }
        }

        /// increasing number of steps in one run steps
        steps += 1;
    }

    /// increase sum
    sum = sum + steps;

    //debug();
}

void one_loop() {
    for (int k = 4; k < n_y_max; k++) {
        n_x = k;
        n_y = k;
        sum = 0;
        /// do simulation 'test_number' times
        for (long i = 0; i < test_number; i++) {
            mainloop();
        }
        /// calculate average value, and show it
        average = float(sum) / float(test_number);
        cout << "[" << average << "," << k << "," << float(pr) / float(pr + 3) << "]," << endl;
    }
}

void prop_data() {
    for (int y = 0; y < 10; y++) {
        pr = y;
        cout << "[" << endl;
        one_loop();

        cout << "]," << endl;
    }
}

int main() {
    mainloop();
}