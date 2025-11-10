#include <iostream>
#include <string>
using namespace std;

// Function to compute average borrowed books
float averageBorrowed(int borrowed[], int n) {
    int total = 0;
    for (int i = 0; i < n; i++)
        total += borrowed[i];
    return (float)total / n;
}

// Function to find highest and lowest borrowed books
void findHighLow(string books[], int count[], int m) {
    int maxIndex = 0, minIndex = 0;
    for (int i = 1; i < m; i++) {
        if (count[i] > count[maxIndex]) maxIndex = i;
        if (count[i] < count[minIndex]) minIndex = i;
    }
    cout << "Highest borrowed book: " << books[maxIndex] << endl;
    cout << "Lowest borrowed book: " << books[minIndex] << endl;
}

// Function to count members with 0 borrowings
int countZero(int borrowed[], int n) {
    int c = 0;
    for (int i = 0; i < n; i++)
        if (borrowed[i] == 0) c++;
    return c;
}

// Function to find most frequent borrow count (mode)
void mostFrequent(string books[], int count[], int m) {
    int freq[100] = {0};  // frequency array
    for (int i = 0; i < m; i++)
        freq[count[i]]++;

    int modeVal = count[0];
    for (int i = 1; i < m; i++) {
        if (freq[count[i]] > freq[modeVal])
            modeVal = count[i];
    }

    cout << "Most frequent borrow count: " << modeVal << endl;
    cout << "Books with this count:" << endl;
    for (int i = 0; i < m; i++) {
        if (count[i] == modeVal)
            cout << books[i] << endl;
    }
}

int main() {
    string members[] = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank"};
    int borrowed[] = {5, 0, 3, 5, 2, 0};
    int n = 6;

    string books[] = {"Book A", "Book B", "Book C", "Book D", "Book E"};
    int count[] = {10, 4, 7, 1, 4};
    int m = 5;

    cout << "Average books borrowed: " << averageBorrowed(borrowed, n) << endl;
    findHighLow(books, count, m);
    cout << "Members with 0 books: " << countZero(borrowed, n) << endl;
    mostFrequent(books, count, m);

    return 0;
}
