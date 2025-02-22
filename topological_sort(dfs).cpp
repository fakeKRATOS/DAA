#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform DFS and store the topological sort order
void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st) {
    visited[node] = true;

    // Visit all adjacent nodes
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, st);
        }
    }

    // After visiting all neighbors, push the current node onto the stack
    st.push(node);
}

// Function to perform Topological Sorting using DFS
vector<int> topologicalSort(int V, vector<vector<int>> &adj) {
    vector<bool> visited(V, false);
    stack<int> st;
    vector<int> topoOrder;

    // Perform DFS from every unvisited node
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    // Extract elements from stack to get the topological order
    while (!st.empty()) {
        topoOrder.push_back(st.top());
        st.pop();
    }

    return topoOrder;
}

// Main function
int main() {
    int V = 6;  // Number of vertices
    vector<vector<int>> adj(V);

    // Constructing a Directed Acyclic Graph (DAG)
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> topoOrder = topologicalSort(V, adj);

    // Print the topological ordering
    cout << "Topological Sort Order: ";
    for (int node : topoOrder) {
        cout << node << " ";
    }

    return 0;
}

