#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<string> undoStack;
stack<string> redoStack;
string document = "";

// Make a new change
void makeChange(string newText) {
    undoStack.push(document);
    document = newText;
    while (!redoStack.empty()) redoStack.pop(); // clear redo stack
    cout << "Change made.\n";
}

// Undo last change
void undoAction() {
    if (undoStack.empty()) {
        cout << "Nothing to undo.\n";
    } else {
        redoStack.push(document);
        document = undoStack.top();
        undoStack.pop();
        cout << "Undo done.\n";
    }
}

// Redo last undone change
void redoAction() {
    if (redoStack.empty()) {
        cout << "Nothing to redo.\n";
    } else {
        undoStack.push(document);
        document = redoStack.top();
        redoStack.pop();
        cout << "Redo done.\n";
    }
}

// Display document state
void displayDocument() {
    cout << "Current document state: " << document << endl;
}

int main() {
    makeChange("Hello");
    makeChange("Hello World");
    makeChange("Hello World!!!");

    displayDocument();

    undoAction();
    displayDocument();

    undoAction();
    displayDocument();

    redoAction();
    displayDocument();

    return 0;
}
