SIZE = 10
table = [[] for _ in range(SIZE)]

def hash_func(key):
    return key % SIZE

def insert(key, value):
    i = hash_func(key)
    table[i].append([key, value])
    print(f"Inserted ({key}, {value}) at {i}")

def search(key):
    i = hash_func(key)
    for k, v in table[i]:
        if k == key:
            print("Found:", v)
            return
    print("Not found")

def delete(key):
    i = hash_func(key)
    for pair in table[i]:
        if pair[0] == key:
            table[i].remove(pair)
            print("Deleted")
            return
    print("Not found")

def display():
    for i in range(SIZE):
        print(i, ":", " -> ".join(f"({k},{v})" for k,v in table[i]) or "NULL")

insert(11,"A")
insert(21,"B")
insert(31,"C")
display()
search(21)
delete(11)
display()
