#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<string> events;  // Queue to store events

// Add an event
void addEvent(string event) {
    events.push(event);
    cout << "Event added: " << event << endl;
}

// Process next event (FIFO)
void processEvent() {
    if (events.empty())
        cout << "No events to process." << endl;
    else {
        cout << "Processed event: " << events.front() << endl;
        events.pop();
    }
}

// Display all pending events
void displayEvents() {
    if (events.empty())
        cout << "No pending events." << endl;
    else {
        cout << "Pending events: ";
        queue<string> temp = events; // Copy to display without removing
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
}

// Cancel an event (simple version)
void cancelEvent(string event) {
    if (events.empty()) {
        cout << "No events to cancel." << endl;
        return;
    }

    queue<string> temp;
    bool found = false;

    // Remove event if found
    while (!events.empty()) {
        if (events.front() == event) {
            found = true;
        } else {
            temp.push(events.front());
        }
        events.pop();
    }

    events = temp;

    if (found)
        cout << "Canceled event: " << event << endl;
    else
        cout << "Event not found." << endl;
}

int main() {
    addEvent("Login Request");
    addEvent("File Upload");
    addEvent("Payment Transaction");
    displayEvents();

    processEvent();
    displayEvents();

    cancelEvent("File Upload");
    displayEvents();

    return 0;
}
