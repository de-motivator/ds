# E-Commerce Customer Account Search System

# Sample customer account IDs
customer_ids = [101, 205, 309, 412, 523, 634, 745, 856, 967]

# 1️⃣ Linear Search Function
def linear_search(arr, key):
    for i in range(len(arr)):
        if arr[i] == key:
            return i  # Return index if found
    return -1  # Not found

# 2️⃣ Binary Search Function
def binary_search(arr, key):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == key:
            return mid
        elif arr[mid] < key:
            low = mid + 1
        else:
            high = mid - 1
    return -1

# ---- MAIN EXECUTION ----
key = int(input("Enter customer ID to search: "))

# Perform Linear Search
index_linear = linear_search(customer_ids, key)
if index_linear != -1:
    print(f"[Linear Search] Customer ID {key} found at index {index_linear}")
else:
    print(f"[Linear Search] Customer ID {key} not found.")

# Perform Binary Search
index_binary = binary_search(customer_ids, key)
if index_binary != -1:
    print(f"[Binary Search] Customer ID {key} found at index {index_binary}")
else:
    print(f"[Binary Search] Customer ID {key} not found.")
