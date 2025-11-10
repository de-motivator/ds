#include <iostream>
using namespace std;

int main() {
    double salaries[10] = {55000.5, 72000.75, 48000.25, 91000.0, 66000.4,
                           83000.9, 39000.0, 102000.25, 58000.1, 47000.8};

    int n = 10;
    double temp;

    // ---- SELECTION SORT ----
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (salaries[j] < salaries[minIndex]) {
                minIndex = j;
            }
        }
        // Swap
        temp = salaries[i];
        salaries[i] = salaries[minIndex];
        salaries[minIndex] = temp;
    }

    cout << "Salaries sorted using Selection Sort (Ascending):\n";
    for (int i = 0; i < n; i++) {
        cout << salaries[i] << "  ";
    }
    cout << endl << endl;

    // ---- Reset array for Bubble Sort ----
    double salaries2[10] = {55000.5, 72000.75, 48000.25, 91000.0, 66000.4,
                            83000.9, 39000.0, 102000.25, 58000.1, 47000.8};

    // ---- BUBBLE SORT ----
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (salaries2[j] > salaries2[j + 1]) {
                temp = salaries2[j];
                salaries2[j] = salaries2[j + 1];
                salaries2[j + 1] = temp;
            }
        }
    }

    cout << "Salaries sorted using Bubble Sort (Ascending):\n";
    for (int i = 0; i < n; i++) {
        cout << salaries2[i] << "  ";
    }
    cout << endl << endl;

    // ---- TOP 5 HIGHEST SALARIES ----
    cout << "Top 5 Highest Salaries:\n";
    for (int i = n - 1; i >= n - 5; i--) {
        cout << salaries[i] << endl;
    }

    return 0;
}
