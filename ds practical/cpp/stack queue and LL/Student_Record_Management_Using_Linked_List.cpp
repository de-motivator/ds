#include <iostream>
#include <string>
using namespace std;

struct Student {
    int rollNo;
    string name;
    float marks;
    Student* next;
};

Student* head = NULL;

// Add new student
void addStudent(int roll, string name, float marks) {
    Student* newNode = new Student;
    newNode->rollNo = roll;
    newNode->name = name;
    newNode->marks = marks;
    newNode->next = head;
    head = newNode;
    cout << "Student added successfully.\n";
}

// Delete student by roll number
void deleteStudent(int roll) {
    if (!head) {
        cout << "No records found.\n";
        return;
    }
    Student *temp = head, *prev = NULL;
    if (temp->rollNo == roll) {
        head = temp->next;
        delete temp;
        cout << "Student deleted.\n";
        return;
    }
    while (temp && temp->rollNo != roll) {
        prev = temp;
        temp = temp->next;
    }
    if (!temp) {
        cout << "Student not found.\n";
        return;
    }
    prev->next = temp->next;
    delete temp;
    cout << "Student deleted.\n";
}

// Update student details
void updateStudent(int roll, string newName, float newMarks) {
    Student* temp = head;
    while (temp) {
        if (temp->rollNo == roll) {
            temp->name = newName;
            temp->marks = newMarks;
            cout << "Record updated.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Student not found.\n";
}

// Search for a student
void searchStudent(int roll) {
    Student* temp = head;
    while (temp) {
        if (temp->rollNo == roll) {
            cout << "Roll No: " << temp->rollNo << ", Name: " << temp->name
                 << ", Marks: " << temp->marks << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Student not found.\n";
}

// Sort by roll number or marks
void sortRecords(bool byMarks = false, bool descending = false) {
    if (!head) return;
    for (Student* i = head; i->next != NULL; i = i->next) {
        for (Student* j = i->next; j != NULL; j = j->next) {
            bool condition = byMarks ? (i->marks > j->marks) : (i->rollNo > j->rollNo);
            if (descending) condition = !condition;
            if (condition) {
                swap(i->rollNo, j->rollNo);
                swap(i->name, j->name);
                swap(i->marks, j->marks);
            }
        }
    }
    cout << "Records sorted.\n";
}

// Display all records
void displayRecords() {
    if (!head) {
        cout << "No records to display.\n";
        return;
    }
    Student* temp = head;
    cout << "\n--- Student Records ---\n";
    while (temp) {
        cout << "Roll No: " << temp->rollNo << ", Name: " << temp->name
             << ", Marks: " << temp->marks << endl;
        temp = temp->next;
    }
}

int main() {
    addStudent(1, "Alice", 85);
    addStudent(2, "Bob", 75);
    addStudent(3, "Charlie", 92);

    displayRecords();
    cout << endl;

    searchStudent(2);
    updateStudent(2, "Bob Smith", 80);
    deleteStudent(1);

    sortRecords(true, false); // Sort by marks ascending
    displayRecords();

    return 0;
}
