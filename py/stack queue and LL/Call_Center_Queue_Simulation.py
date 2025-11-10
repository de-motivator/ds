from collections import deque

# Queue to store calls (customerID, callTime)
call_queue = deque()

# Add a call to the queue
def addCall(customerID, callTime):
    call_queue.append((customerID, callTime))
    print("Call added - Customer ID:", customerID, "Call Time:", callTime, "minutes")

# Answer the first call in the queue
def answerCall():
    if not call_queue:
        print("No calls to answer.")
    else:
        call = call_queue.popleft()
        print("Answered call - Customer ID:", call[0], "Call Time:", call[1], "minutes")

# View all calls currently in the queue
def viewQueue():
    if not call_queue:
        print("No calls in the queue.")
    else:
        print("Current calls in queue:")
        for call in call_queue:
            print("Customer ID:", call[0], "| Call Time:", call[1], "minutes")

# Check if queue is empty
def isQueueEmpty():
    if not call_queue:
        print("Queue is empty.")
    else:
        print("Queue is not empty.")

# --- Example usage ---
addCall(101, 5)
addCall(102, 3)
addCall(103, 8)
viewQueue()

answerCall()
viewQueue()

isQueueEmpty()
