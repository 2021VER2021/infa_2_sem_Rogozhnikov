///? maybe kill before step, maybe can spawn on edges, maybe...
#include <iostream>
#include <random>
#include <chrono>

using namespace std;

const int n_x = 50;             /// width of crystal
const int n_y = 1;             /// height of crystal

const long test_number = 100000; /// number of simulations
int disslocations = 1;    /// number of disslocations at the start

int number_diss = 0; /// currant number of disslocations
int steps;           /// currant number of steps
float average = 0;   /// answer
long sum = 0;        /// average = sum / test_number

int field[n_x + 2][n_y + 2] = {0};  /// main array of sells state, with 0 on edges
int field_action[n_x + 2][n_y + 2] = {0}; /// action check

void debug(){
    for (int i = 0; i < n_x + 2; i++) { //!!!
        for (int j = 0; j < n_y + 2; j++) {
            cout << field[i][j];
        }
        cout << endl;
    }
    cout << endl;// !!!
}

void start() {
    ///make start area, with no diss and stopped diss
    for (int i = 1; i < n_x + 1; i++) {
        field[i][1] = 1;
    }
}

void step(int rand_result, int x_coord, int y_coord) {
    switch (rand_result) {
        case 0: {
            if (field[x_coord + 1][y_coord] == 1) {
                field[x_coord][y_coord] = 1;
                field[x_coord + 1][y_coord] = 2;
                field_action[x_coord + 1][y_coord] = 1;
            }
            break;
        }
        case 1: {
            if (field[x_coord - 1][y_coord] == 1) {
                field[x_coord][y_coord] = 1;
                field[x_coord - 1][y_coord] = 2;
                field_action[x_coord - 1][y_coord] = 1;
            }
            break;
        }
    }
}

bool check_for_kill(int x_coord, int y_coord) {
    bool f = true;
    if (field[x_coord][y_coord] == 2) {
        if (field[x_coord + 1][y_coord] != 1) { f = false; }
        if (field[x_coord - 1][y_coord] != 1) { f = false; }
    }
    return f;
}

void mainloop(){
    /// init parameters
    number_diss = 0;
    steps = 0;

    /// init random
    random_device dev;
    mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

    /// generator for directions
    uniform_int_distribution<int> dist(0, 1);

    /// generator for x coord, and disslocation can't be killed instantly by edges
    uniform_int_distribution<int> dist_n_x(2, n_x - 1);

    start();

    /// put disslocations on a field
    while (number_diss < disslocations) {
        int x_coord = dist_n_x(rng);
        int y_coord = 1;
        if (field[x_coord][y_coord] == 1) {
            field[x_coord][y_coord] = 2;
            number_diss++;
        }
    }
    //debug();


    /// main part
    while (number_diss > 0) {

        /// destroy action (every disslocation can potentially move)
        for (int i = 1; i < n_x + 1; i++) {
            field_action[i][1] = 0;
        }

        /// step stage, disslocations try to move
        for (int i = 1; i < n_x + 1; i++) {
                if ((field[i][1] == 2) and (field_action[i][1] == 0)) {
                    int result = dist(rng);
                    step(result, i, 1);
                }
        }

        /// kill loop, merging disslocations to each other, or to edges
        for (int i = 1; i < n_x + 1; i++) {
                if (not(check_for_kill(i, 1))) {
                    field[i][1] = 0;
                    number_diss -= 1;
                }
        }

        /// increasing number of steps in one run steps
        steps += 1;
    }

    /// increase sum
    sum = sum + steps;

    // debug();
}

int main() {
        sum = 0;
        /// do simulation 'test_number' times
        for (long i = 0; i < test_number; i++) {
            mainloop();
        }
        /// calculate average value, and show it
        average = float(sum) / test_number;
        cout << average << endl;
}
