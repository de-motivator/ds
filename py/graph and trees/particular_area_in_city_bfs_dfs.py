from collections import deque

# Define nodes and mapping for matrix
nodes = ['A','B','C','D','E']
index = {nodes[i]: i for i in range(len(nodes))}
n = len(nodes)

# --- Adjacency List for BFS ---
adj_list = {
    'A': ['B','C'],
    'B': ['A','D'],
    'C': ['A','D','E'],
    'D': ['B','C','E'],
    'E': ['C','D']
}

def bfs(start):
    visited = {node: False for node in nodes}
    order = []
    q = deque([start])
    visited[start] = True

    while q:
        u = q.popleft()
        order.append(u)
        for v in adj_list[u]:
            if not visited[v]:
                visited[v] = True
                q.append(v)
    return order


# --- Adjacency Matrix for DFS ---
adj_matrix = [[0]*n for _ in range(n)]
edges = [('A','B'),('A','C'),('B','D'),('C','D'),('C','E'),('D','E')]

for u,v in edges:
    i,j = index[u], index[v]
    adj_matrix[i][j] = adj_matrix[j][i] = 1  # undirected

visited_matrix = [False]*n
dfs_order = []

def dfs_matrix(u_idx):
    visited_matrix[u_idx] = True
    dfs_order.append(nodes[u_idx])
    for v_idx in range(n):
        if adj_matrix[u_idx][v_idx] == 1 and not visited_matrix[v_idx]:
            dfs_matrix(v_idx)


# --- Run BFS and DFS ---
start = 'A'
print("BFS order:", ' '.join(bfs(start)))

dfs_order.clear()
visited_matrix = [False]*n
dfs_matrix(index[start])
print("DFS order:", ' '.join(dfs_order))
