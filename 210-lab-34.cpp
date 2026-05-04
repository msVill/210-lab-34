// Comsc 210 | Lab 34 | Martha S Villalta

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h> // Dijkstra's algorithm.
using namespace std;

const int SIZE = 9; //updated

struct Edge {
    int src, dest, weight;
};

typedef pair<int, int> Pair;

class Graph {
    vector<vector<Pair>> adjList;

    public:

    //Constructor:
    Graph(vector<Edge> const &edges) {
        adjList.resize(SIZE);

        for(auto &edge : edges) {
            int src = edge.src;
            int dest = edge.dest;
            int weight = edge.weight;

            adjList[src].push_back(make_pair(dest, weight));
            adjList[dest].push_back(make_pair(src, weight));

        }
    }

    // print the graph:
    void printGraph() {
        cout << "Campus Navigation Network:\n";
        cout << "==================================\n";
        for(int i = 0; i < adjList.size(); i++) {
            cout << "Location " << i << " connects to:\n";
        
            for(Pair v : adjList[i]) {
               cout << " --> Location " << v.first
                    << " (Distance: " << v.second << ")\n";
            }
            cout << endl;
        }
    }

    // DFS:
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << "Visiting Location " << v << endl;

        for(Pair neighbor : adjList[v]) {
            if(!visited[neighbor.first]) {
                DFSUtil(neighbor.first, visited);
            }
        }
    }

    void DFS(int start) {
        vector<bool> visited(adjList.size(), false);
        DFSUtil(start, visited);
        cout << endl;
    }

    void BFS(int start) {
        vector<bool> visited(adjList.size(), false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while(!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for(Pair neighbor : adjList[v]) {
                if(!visited[neighbor.first]) {
                    visited[neighbor.first] = true;
                    q.push(neighbor.first);
                }
            }
        }
        cout << endl;
    }

};

int main() {

    vector<Edge> edges = {
        {0,1,8}, {0,2,21}, {1,2,6},
        {1,3,5}, {1,4,4}, {2,7,11},
        {2,8,8}, {3,4,9}, {5,6,10},
        {5,7,15}, {5,8,5}, {6,7,3},
        {6,8,7}
    };

    Graph g(edges);
    cout << "Graph's adjacency list:\n";
    g.printGraph();

    cout << "\nRoute Exploration (DFS) starting from Campus Hub 0:\n";
    cout << "Purpose: Exploring possible walking paths through campus\n";
    g.DFS(0);

    cout << "\nLevel-by-Level Exploration (BFS) from Campus Hub 0:\n";
    cout << "Purpose: Checking nearest reachable buildings first\n";
    g.BFS(0);

    return 0;
}

//YESSSSS! so exciting, it was just me being dumb
// okay, now,from requirements, i need DFS and BFS. follow my mindmap psuedo!