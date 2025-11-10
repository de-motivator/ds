#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Call {
    int customerID;
    int callTime;
};

queue<Call> callQueue;

// Add a call
void addCall(int id, int time) {
    Call newCall = {id, time};
    callQueue.push(newCall);
    cout << "Call added - Customer ID: " << id << " Call Time: " << time << " minutes\n";
}

// Answer the first call
void answerCall() {
    if (callQueue.empty())
        cout << "No calls to answer.\n";
    else {
        Call c = callQueue.front();
        callQueue.pop();
        cout << "Answered call - Customer ID: " << c.customerID
             << " Call Time: " << c.callTime << " minutes\n";
    }
}

// View all calls in queue
void viewQueue() {
    if (callQueue.empty())
        cout << "No calls in the queue.\n";
    else {
        cout << "Current calls in queue:\n";
        queue<Call> temp = callQueue;
        while (!temp.empty()) {
            Call c = temp.front();
            cout << "Customer ID: " << c.customerID
                 << " | Call Time: " << c.callTime << " minutes\n";
            temp.pop();
        }
    }
}

// Check if queue is empty
void isQueueEmpty() {
    if (callQueue.empty())
        cout << "Queue is empty.\n";
    else
        cout << "Queue is not empty.\n";
}

int main() {
    addCall(101, 5);
    addCall(102, 3);
    addCall(103, 8);
    viewQueue();

    answerCall();
    viewQueue();

    isQueueEmpty();

    return 0;
}
