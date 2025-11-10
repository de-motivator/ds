import sys

# Number of locations
V = 5
# Graph represented as adjacency matrix (time between locations)
# 0 means no direct route
graph = [
    [0, 2, 0, 6, 0],
    [2, 0, 3, 8, 5],
    [0, 3, 0, 0, 7],
    [6, 8, 0, 0, 9],
    [0, 5, 7, 9, 0]
]

def prim_mst(graph):
    V = len(graph)
    selected = [False]*V
    parent = [-1]*V
    key = [sys.maxsize]*V

    key[0] = 0  # Start from node 0 (like location A)

    for _ in range(V-1):
        # Find minimum key vertex not yet included in MST
        min_val = sys.maxsize
        u = -1
        for v in range(V):
            if not selected[v] and key[v] < min_val:
                min_val = key[v]
                u = v

        selected[u] = True

        # Update keys of adjacent vertices
        for v in range(V):
            if graph[u][v] and not selected[v] and graph[u][v] < key[v]:
                key[v] = graph[u][v]
                parent[v] = u

    # Display result
    total_time = 0
    print("Minimum routes for pizza delivery:")
    for i in range(1, V):
        print(f"Location {chr(parent[i]+65)} -> {chr(i+65)}  time = {graph[i][parent[i]]}")
        total_time += graph[i][parent[i]]
    print("Total minimum delivery time:", total_time)

# Run
prim_mst(graph)
