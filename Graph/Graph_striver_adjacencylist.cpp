#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    
    // Initialize the adjacency list with n + 1 elements (assuming 1-based indexing)
    vector<vector<int>> adj(n + 1);

    cout << "Enter the edges (u v):" << endl;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
//here if the edge is directed then no need of adj[v].push_back(u) as u wont be the neighbour of v if unless specified
        adj[v].push_back(u);
    }

    // Print the adjacency list
    cout << "The adjacency list is:" << endl;
    for(int i = 1; i <= n; i++) {
        cout << i << ": ";
        for(int j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
