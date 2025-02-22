#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

#define INF INT_MAX // Define Infinity

// Function to implement Floyd-Warshall Algorithm
void floydWarshall(vector<vector<int>> &graph, int V) {
    vector<vector<int>> dist = graph; // Distance matrix

    // Floyd-Warshall Algorithm
    for (int k = 0; k < V; k++) {        // Intermediate vertex
        for (int i = 0; i < V; i++) {    // Start vertex
            for (int j = 0; j < V; j++) { // End vertex
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Print the shortest distance matrix
    cout << "Shortest distances between all pairs of vertices:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF) 
                cout << "INF ";
            else 
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 4;
    vector<vector<int>> graph = {
        {0, 3, INF, 5},
        {2, 0, INF, 4},
        {INF, 1, 0, INF},
        {INF, INF, 2, 0}
    };

    floydWarshall(graph, V);

    return 0;
}

