#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform Topological Sorting using Kahn's Algorithm (BFS)
vector<int> topologicalSort(int V, vector<vector<int>> &adj) {
    vector<int> inDegree(V, 0);
    vector<int> topoOrder;
    queue<int> q;

    // Compute in-degree for each node
    for (int i = 0; i < V; i++) {
        for (int neighbor : adj[i]) {
            inDegree[neighbor]++;
        }
    }

    // Push all nodes with in-degree 0 into the queue
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Process nodes in BFS manner
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        // Decrease in-degree of neighbors
        for (int neighbor : adj[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If topological order does not include all vertices, there's a cycle
    if (topoOrder.size() != V) {
        cout << "The graph contains a cycle! Topological sorting is not possible." << endl;
        return {};
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
    if (!topoOrder.empty()) {
        cout << "Topological Sort Order: ";
        for (int node : topoOrder) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}

