#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the determinant of a matrix
double determinant(vector<vector<int>>& matrix, int n) {
    if (n == 1) {
        return matrix[0][0];
    }
    if (n == 2) {
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    }

    double det = 0;
    vector<vector<int>> submatrix(n, vector<int>(n));

    for (int x = 0; x < n; x++) {
        int subi = 0;
        for (int i = 1; i < n; i++) {
            int subj = 0;
            for (int j = 0; j < n; j++) {
                if (j == x) {
                    continue;
                }
                submatrix[subi][subj] = matrix[i][j];
                subj++;
            }
            subi++;
        }
        det += (x % 2 == 0 ? 1 : -1) * matrix[0][x] * determinant(submatrix, n - 1);
    }

    return det;
}

// Function to calculate the number of spanning trees using Kirchhoff's Theorem
int numberOfSpanningTrees(vector<vector<int>>& graph) {
    int n = graph.size();

    // Step 1: Create the Laplacian matrix
    vector<vector<int>> laplacian(n, vector<int>(n, 0));

    // Fill the Laplacian matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                // Diagonal element = degree of the vertex
                for (int k = 0; k < n; k++) {
                    if (graph[i][k] == 1) {
                        laplacian[i][i]++;
                    }
                }
            } else if (graph[i][j] == 1) {
                laplacian[i][j] = -1;
            }
        }
    }

    // Step 2: Remove the last row and column to get the cofactor matrix
    vector<vector<int>> cofactor(n - 1, vector<int>(n - 1));
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            cofactor[i][j] = laplacian[i][j];
        }
    }

    // Step 3: Calculate the determinant of the cofactor matrix
    return determinant(cofactor, n - 1);
}

int main() {
    // Example graph (Adjacency Matrix)
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int spanningTrees = numberOfSpanningTrees(graph);
    cout << "Number of Spanning Trees: " << spanningTrees << endl;

    return 0;
}

