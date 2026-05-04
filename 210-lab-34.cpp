// Comsc 210 | Lab 34 | Martha S Villalta

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h> // Dijkstra's algorithm.
using namespace std;

const int SIZE = 7;

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
        for(int i = 0; i < adjList.size(); i++) {
            cout << i << " --> ";
            for(Pair v : adjList[i]) {
                cout << "(" << v.first << ", " << v.second << ") ";
            }
            cout << endl;
        }
    }

    // DFS:
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

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
        {0,1,12}, {0,2,8}, {0,3,21},
        {2,3,6}, {2,6,2}, {2,4,4}, {2,5,5},
        {5,6,6}, {4,5,9}
    };

    Graph g(edges);
    cout << "Graph's adjacency list:\n";
    g.printGraph();

    cout << "\nDFS starting from vertex 0:\n";
    g.DFS(0);

    cout << "BFS starting from vertex 0:\n";
    g.BFS(0);

    return 0;
}

//YESSSSS! so exciting, it was just me being dumb
// okay, now,from requirements, i need DFS and BFS. follow my mindmap psuedo!