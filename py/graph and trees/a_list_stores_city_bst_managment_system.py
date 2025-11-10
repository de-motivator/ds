class Node:
    def __init__(self, city, population):
        self.city = city
        self.population = population
        self.left = None
        self.right = None

def insert(root, city, population):
    if root is None:
        return Node(city, population)
    if city < root.city:
        root.left = insert(root.left, city, population)
    elif city > root.city:
        root.right = insert(root.right, city, population)
    else:
        print("City already exists!")
    return root

def find_min(node):
    while node.left:
        node = node.left
    return node

def delete_city(root, city):
    if not root:
        return root
    if city < root.city:
        root.left = delete_city(root.left, city)
    elif city > root.city:
        root.right = delete_city(root.right, city)
    else:
        if not root.left:
            return root.right
        elif not root.right:
            return root.left
        temp = find_min(root.right)
        root.city, root.population = temp.city, temp.population
        root.right = delete_city(root.right, temp.city)
    return root

def update_population(root, city, new_pop):
    if root is None:
        print("City not found.")
        return
    if city < root.city:
        update_population(root.left, city, new_pop)
    elif city > root.city:
        update_population(root.right, city, new_pop)
    else:
        root.population = new_pop
        print(f"Population updated for {city} to {new_pop}")

def display_ascending(root):
    if root:
        display_ascending(root.left)
        print(f"{root.city} ({root.population})")
        display_ascending(root.right)

def display_descending(root):
    if root:
        display_descending(root.right)
        print(f"{root.city} ({root.population})")
        display_descending(root.left)

def search_city(root, city):
    comparisons = 0
    while root:
        comparisons += 1
        if city == root.city:
            print(f"{city} found with population {root.population}")
            return comparisons
        elif city < root.city:
            root = root.left
        else:
            root = root.right
    print(f"{city} not found.")
    return comparisons

def height(root):
    if not root:
        return 0
    return 1 + max(height(root.left), height(root.right))

# --- MAIN ---
root = None
root = insert(root, "Mumbai", 20000000)
insert(root, "Pune", 6000000)
insert(root, "Delhi", 19000000)
insert(root, "Chennai", 9000000)

print("\nCities in Ascending Order:")
display_ascending(root)

print("\nCities in Descending Order:")
display_descending(root)

print("\nSearching for 'Pune'...")
cmp = search_city(root, "Pune")
print("Comparisons made:", cmp)

print("\nUpdating population of 'Delhi'...")
update_population(root, "Delhi", 20000000)

print("\nDeleting 'Chennai'...")
root = delete_city(root, "Chennai")

print("\nCities after deletion:")
display_ascending(root)

print("\nMaximum comparisons (worst case):", height(root))
