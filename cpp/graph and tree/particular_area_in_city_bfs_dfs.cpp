#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

// Helper: map A,B,C... to 0,1,2,...
int idx(char c){ return c - 'A'; }

int main() {
    int n = 5; // nodes: A..E
    vector<vector<int>> adjList(n);

    // edges (undirected)
    vector<pair<char,char>> edges = {
        {'A','B'},{'A','C'},{'B','D'},{'C','D'},{'C','E'},{'D','E'}
    };

    // Build adjacency list
    for (auto &e: edges) {
        int u = idx(e.first), v = idx(e.second);
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // --- BFS using adjacency list ---
    vector<bool> vis(n,false);
    queue<int> q;
    vector<char> bfs_order;
    int start = idx('A');
    vis[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front(); q.pop();
        bfs_order.push_back('A' + u);
        for (int v : adjList[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }

    cout << "BFS order: ";
    for (char c : bfs_order) cout << c << ' ';
    cout << endl;


    // --- Build adjacency matrix for DFS ---
    vector<vector<int>> adjMat(n, vector<int>(n,0));
    for (auto &e: edges) {
        int u = idx(e.first), v = idx(e.second);
        adjMat[u][v] = adjMat[v][u] = 1;
    }

    vector<bool> visited(n,false);
    vector<char> dfs_order;

    function<void(int)> dfs = [&](int u){
        visited[u] = true;
        dfs_order.push_back('A' + u);
        for (int v = 0; v < n; ++v) {
            if (adjMat[u][v] && !visited[v])
                dfs(v);
        }
    };

    dfs(start);

    cout << "DFS order: ";
    for (char c : dfs_order) cout << c << ' ';
    cout << endl;

    return 0;
}
