# Real-Time Event Processing System using Queue

from collections import deque

# Queue to store events
event_queue = deque()

# 1️⃣ Add an Event
def add_event(event):
    event_queue.append(event)
    print("Event added:", event)

# 2️⃣ Process Next Event (FIFO)
def process_event():
    if not event_queue:
        print("No events to process.")
    else:
        event = event_queue.popleft()
        print("Processed event:", event)

# 3️⃣ Display Pending Events
def display_events():
    if not event_queue:
        print("No pending events.")
    else:
        print("Pending events:", list(event_queue))

# 4️⃣ Cancel an Event (remove if not processed)
def cancel_event(event):
    if event in event_queue:
        event_queue.remove(event)
        print("Canceled event:", event)
    else:
        print("Event not found or already processed.")

# --- Example usage ---
add_event("Login Request")
add_event("File Upload")
add_event("Payment Transaction")
display_events()

process_event()
display_events()

cancel_event("File Upload")
display_events()
