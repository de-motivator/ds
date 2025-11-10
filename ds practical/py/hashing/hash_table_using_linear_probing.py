SIZE = 10
table = [None] * SIZE

def hash_func(key):
    return key % SIZE

def insert_key(key):
    i = hash_func(key)
    for j in range(SIZE):
        idx = (i + j) % SIZE
        if table[idx] is None:
            table[idx] = key
            print(f"Inserted {key} at index {idx}")
            return
    print("Hash table full!")

def search_key(key):
    i = hash_func(key)
    for j in range(SIZE):
        idx = (i + j) % SIZE
        if table[idx] == key:
            print(f"Found {key} at index {idx}")
            return
    print("Key not found")

def delete_key(key):
    i = hash_func(key)
    for j in range(SIZE):
        idx = (i + j) % SIZE
        if table[idx] == key:
            table[idx] = None
            print(f"Deleted {key} from index {idx}")
            return
    print("Key not found")

def display():
    print("\n--- Hash Table ---")
    for i in range(SIZE):
        print(i, ":", table[i] if table[i] is not None else "EMPTY")

# --- Example Usage ---
insert_key(11)
insert_key(21)
insert_key(31)
insert_key(4)
display()
search_key(21)
delete_key(31)
display()
