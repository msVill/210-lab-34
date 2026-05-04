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

    void dijkstra(int start) {
        vector<int> dist(SIZE, INT_MAX);
        dist[start] = 0;

        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;
        pq.push(make_pair(0, start));

        while(!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for(Pair neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if(dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        cout << "Shortest path from Campus Hub " << start << ":\n";
        for(int i = 0; i < SIZE; i++) {
            cout << start << " -> " << i << " : " << dist[i] << endl;
        }
    }

    void primMST() {
        vector<int> key(SIZE, INT_MAX);
        vector<bool> inMST(SIZE, false);
        vector<int> parent(SIZE, -1);

        key[0] = 0;

        for(int count = 0; count < SIZE - 1; count++) {
            int u = -1;
            int minValue = INT_MAX;

            for(int i = 0; i < SIZE; i++) {
                if(!inMST[i] && key[i] < minValue) {
                    minValue = key[i];
                    u = i;
                }
            }

            inMST[u] = true;

            for(Pair neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if(!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                }
            }
        }

        cout << "\nMinimum Spanning Tree (Campus Network Optimization):\n";
        cout << "=====================================================\n";

        for(int i = 1; i < SIZE; i++) {
            cout << "Connection: Location " << parent[i]
                << " -> Location " << i
                << " | Distance: " << key[i] << endl;;
        }
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
    int choice;

    do {
        cout << "\nCampus Navigation System Menu:\n";
        cout << "1. Display Network\n";
        cout << "2. DFS Traversal\n";
        cout << "3. BFS Traversal\n";
        cout << "4. Shortest Paths (Dijkstra)\n";
        cout << "5. Minimum Spanning Tree\n";
        cout << "0. Exit\n";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                g.printGraph();
                break;

            case 2:
                g.DFS(0);
                break;

            case 3:
                g.BFS(0);
                break;

            case 4:
                g.dijkstra(0);
                break;

            case 5:
                g.primMST();
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while(choice != 0);
        
    return 0;
}

//YESSSSS! so exciting, it was just me being dumb
// okay, now,from requirements, i need DFS and BFS. follow my mindmap psuedo!