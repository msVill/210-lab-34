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
            int src = edges.src;
            int dest = edges.dest;
            int weight = edges.weight;

            adjList[src].push_back(make_pair(dest, weight));
            adjList[dest].push_back(make_pair(src, weight));

        }
    }


}

int main() {

    return 0;
}