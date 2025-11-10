class Bucket:
    def __init__(self, depth, size):
        self.depth = depth       # Local depth of the bucket
        self.size = size         # Max size of bucket
        self.items = {}          # Key-value pairs

    def is_full(self):
        return len(self.items) >= self.size


class ExtendibleHashTable:
    def __init__(self, bucket_size=2):
        self.global_depth = 1
        self.bucket_size = bucket_size
        self.directory = [Bucket(1, bucket_size) for _ in range(2)]  # Two buckets initially

    def hash(self, key):
        return key & ((1 << self.global_depth) - 1)  # hash mod 2^global_depth

    def double_directory(self):
        self.directory += self.directory
        self.global_depth += 1
        print("Directory doubled. Global depth:", self.global_depth)

    def insert(self, key, value):
        index = self.hash(key)
        bucket = self.directory[index]

        # If key already exists, update value
        if key in bucket.items:
            bucket.items[key] = value
            return

        # If bucket full, split it
        if bucket.is_full():
            print("Splitting bucket at index", index)
            self.split_bucket(index)
            self.insert(key, value)  # Re-insert after split
        else:
            bucket.items[key] = value
            print(f"Inserted ({key}:{value}) in bucket {index}")

    def split_bucket(self, index):
        bucket = self.directory[index]
        local_depth = bucket.depth
        bucket.depth += 1

        # If local depth exceeds global depth → double directory
        if bucket.depth > self.global_depth:
            self.double_directory()

        # Create new bucket
        new_bucket = Bucket(bucket.depth, self.bucket_size)

        # Redistribute items
        old_items = list(bucket.items.items())
        bucket.items.clear()
        for k, v in old_items:
            new_index = self.hash(k)
            if (k & (1 << (bucket.depth - 1))):
                new_bucket.items[k] = v
            else:
                bucket.items[k] = v

        # Update directory pointers
        for i in range(len(self.directory)):
            if self.directory[i] == bucket and (i & (1 << (bucket.depth - 1))):
                self.directory[i] = new_bucket

    def search(self, key):
        index = self.hash(key)
        bucket = self.directory[index]
        return bucket.items.get(key, None)

    def delete(self, key):
        index = self.hash(key)
        bucket = self.directory[index]
        if key in bucket.items:
            del bucket.items[key]
            print(f"Deleted key {key} from bucket {index}")
        else:
            print("Key not found.")

    def display(self):
        print("\n--- Hash Table State ---")
        seen = set()
        for i, b in enumerate(self.directory):
            if id(b) not in seen:
                seen.add(id(b))
                print(f"Bucket {i} (Depth={b.depth}): {b.items}")
        print("-------------------------\n")


# Example usage
ht = ExtendibleHashTable(bucket_size=2)
ht.insert(5, "A")
ht.insert(7, "B")
ht.insert(13, "C")
ht.insert(9, "D")
ht.display()
print("Search 7:", ht.search(7))
ht.delete(13)
ht.display()
