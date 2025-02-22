#include <iostream>
#include <vector>
#include <stack>
#include <limits.h>

using namespace std;

// Perform DFS to get Topological Sorting
void topologicalSort(int node, vector<vector<pair<int, int>>> &adj, vector<bool> &visited, stack<int> &st) {
    visited[node] = true;
    for (auto neighbor : adj[node]) {
        if (!visited[neighbor.first]) {
            topologicalSort(neighbor.first, adj, visited, st);
        }
    }
    st.push(node);
}

// Find Shortest Path in DAG using Topological Sorting
vector<int> shortestPathDAG(int V, vector<vector<pair<int, int>>> &adj, int src) {
    vector<bool> visited(V, false);
    stack<int> st;

    // Perform Topological Sort
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSort(i, adj, visited, st);
        }
    }

    // Initialize distances
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Process vertices in topological order
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (dist[node] != INT_MAX) {
            for (auto neighbor : adj[node]) {
                int v = neighbor.first, weight = neighbor.second;
                if (dist[node] + weight < dist[v]) {
                    dist[v] = dist[node] + weight;
                }
            }
        }
    }

    return dist;
}

int main() {
    int V = 6;
    vector<vector<pair<int, int>>> adj(V);

    // Directed edges with weights
    adj[0].push_back({1, 2});
    adj[0].push_back({4, 1});
    adj[1].push_back({2, 3});
    adj[2].push_back({3, 6});
    adj[4].push_back({2, 2});
    adj[4].push_back({5, 4});
    adj[5].push_back({3, 1});

    int source = 0;
    vector<int> shortestDistances = shortestPathDAG(V, adj, source);

    // Print shortest path distances
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Node " << i << ": " << (shortestDistances[i] == INT_MAX ? "INF" : to_string(shortestDistances[i])) << endl;
    }

    return 0;
}

