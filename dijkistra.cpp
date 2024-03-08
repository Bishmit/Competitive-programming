#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

const int INF = INT_MAX;

// Function to perform Dijkstra's algorithm
void dijkstra(int n, int x, vector<set<pair<int, int> > > & adj, vector<int>& distance) {
    set<pair<int, int>> s;  // Set: {distance, vertex}
    vector<bool> processed(n + 1, false);

    // Initialize distances to infinity for all vertices
    for (int i = 1; i <= n; i++) {
        distance[i] = INF;
    }

    // Set the distance to the source vertex to 0
    distance[x] = 0;
    // Insert the source vertex into the set with distance 0
    s.insert({0, x});

    // Dijkstra's algorithm
    while (!s.empty()) {
        // Extract the vertex with the minimum distance from the set
        int a = s.begin()->second;
        s.erase(s.begin());

        // Skip this vertex if it has already been processed
        if (processed[a]) {
            continue;
        }

        // Mark the vertex as processed
        processed[a] = true;

        // Explore neighbors of the current vertex
        for (auto u : adj[a]) {
            int b = u.first, w = u.second;

            // Relaxation step: Update the distance to the neighbor if a shorter path is found
            if (distance[a] + w < distance[b]) {
                // Remove the old value from the set
                s.erase({distance[b], b});
                // Update the distance
                distance[b] = distance[a] + w;
                // Insert the updated value into the set
                s.insert({distance[b], b});
            }
        }
    }
}

int main() {
    int n, m;  // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> n;

    // Adjacency list representation of the graph using sets
    vector<set<pair<int, int>>> adj(n + 1);
    vector<int> distance(n + 1);

    cout << "Enter the number of edges: ";
    cin >> m;

    cout << "Enter the edges in the format 'from to weight':" << endl;
    for (int i = 0; i < m; i++) {
        int from, to, weight;
        cin >> from >> to >> weight;
        // Add the edges to the adjacency list
        adj[from].insert({to, weight});
        adj[to].insert({from, weight});  // Assuming an undirected graph
    }

    int sourceVertex;
    cout << "Enter the source vertex: ";
    cin >> sourceVertex;

    // Call Dijkstra's algorithm
    dijkstra(n, sourceVertex, adj, distance);

    // Print the shortest distances from the source vertex
    cout << "Vertex\t\tDistance from source vertex" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << "\t\t\t" << distance[i] << endl;
    }

    return 0;
}