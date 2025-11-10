# Library Borrowing Management System

# Sample data: dictionary of members and the number of books they borrowed
members_borrow = {
    "Alice": 5,
    "Bob": 0,
    "Charlie": 3,
    "David": 5,
    "Eve": 2,
    "Frank": 0
}

# Sample data: dictionary of books and how many times they have been borrowed
book_borrow_count = {
    "Book A": 10,
    "Book B": 4,
    "Book C": 7,
    "Book D": 1,
    "Book E": 4
}

# 1️⃣ Compute average number of books borrowed by all members
def average_books_borrowed(borrow_data):
    total = sum(borrow_data.values())
    count = len(borrow_data)
    avg = total / count
    return avg

# 2️⃣ Find book with highest and lowest number of borrowings
def find_high_low_borrowed_books(book_data):
    highest = max(book_data, key=book_data.get)
    lowest = min(book_data, key=book_data.get)
    return highest, lowest

# 3️⃣ Count members who have not borrowed any books
def count_non_borrowers(borrow_data):
    count = sum(1 for x in borrow_data.values() if x == 0)
    return count

# 4️⃣ Find the most frequently borrowed book count (mode of borrow counts)
from collections import Counter
def most_frequent_borrow_count(book_data):
    freq = Counter(book_data.values())
    mode_count = freq.most_common(1)[0][0]
    # Return all books having that borrow count
    most_frequent_books = [book for book, cnt in book_data.items() if cnt == mode_count]
    return most_frequent_books, mode_count

# ---- MAIN EXECUTION ----
print("Average books borrowed per member:", average_books_borrowed(members_borrow))

high, low = find_high_low_borrowed_books(book_borrow_count)
print(f"Most borrowed book: {high}")
print(f"Least borrowed book: {low}")

print("Number of members who borrowed no books:", count_non_borrowers(members_borrow))

books, count = most_frequent_borrow_count(book_borrow_count)
print(f"Most frequent borrow count: {count}, Books: {books}")
