class Student:
    def __init__(self, roll, name, marks):
        self.roll = roll
        self.name = name
        self.marks = marks
        self.next = None

head = None

# Add student
def add_student(roll, name, marks):
    global head
    new_student = Student(roll, name, marks)
    new_student.next = head
    head = new_student
    print("Student added successfully.")

# Delete student
def delete_student(roll):
    global head
    if not head:
        print("No records found.")
        return
    if head.roll == roll:
        head = head.next
        print("Student deleted.")
        return
    temp = head
    while temp.next and temp.next.roll != roll:
        temp = temp.next
    if not temp.next:
        print("Student not found.")
    else:
        temp.next = temp.next.next
        print("Student deleted.")

# Update student
def update_student(roll, name, marks):
    temp = head
    while temp:
        if temp.roll == roll:
            temp.name = name
            temp.marks = marks
            print("Record updated.")
            return
        temp = temp.next
    print("Student not found.")

# Search student
def search_student(roll):
    temp = head
    while temp:
        if temp.roll == roll:
            print(f"Roll No: {temp.roll}, Name: {temp.name}, Marks: {temp.marks}")
            return
        temp = temp.next
    print("Student not found.")

# Sort records
def sort_records(by_marks=False, descending=False):
    global head
    if not head:
        return
    swapped = True
    while swapped:
        swapped = False
        temp = head
        while temp.next:
            a = temp.marks if by_marks else temp.roll
            b = temp.next.marks if by_marks else temp.next.roll
            if (a > b and not descending) or (a < b and descending):
                temp.roll, temp.next.roll = temp.next.roll, temp.roll
                temp.name, temp.next.name = temp.next.name, temp.name
                temp.marks, temp.next.marks = temp.next.marks, temp.marks
                swapped = True
            temp = temp.next
    print("Records sorted.")

# Display all
def display_records():
    if not head:
        print("No records to display.")
        return
    temp = head
    print("\n--- Student Records ---")
    while temp:
        print(f"Roll No: {temp.roll}, Name: {temp.name}, Marks: {temp.marks}")
        temp = temp.next

# --- Example usage ---
add_student(1, "Alice", 85)
add_student(2, "Bob", 75)
add_student(3, "Charlie", 92)

display_records()
search_student(2)
update_student(2, "Bob Smith", 80)
delete_student(1)
sort_records(by_marks=True, descending=False)
display_records()
