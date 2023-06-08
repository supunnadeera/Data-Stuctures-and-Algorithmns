#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define V 6
#define MAX 999


int minKey(vector<int>& key, vector<bool>& visited) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index; 
}

void printMST(vector<int>& parent, vector<vector<int>>& graph,int startNode) {
    cout << "Minimum Spanning Tree:\n";
    for (int i = 0; i < V; i++)
        if(i!=startNode){
            cout << "Node " << parent[i] << " - Node " << i << " : " << graph[i][parent[i]] << endl;
        }
}

void primMST(vector<vector<int>>& graph, int startNode) {
    vector<int> parent(V);          
    vector<int> key(V, MAX);    
    vector<bool> visited(V, false);  

    key[startNode] = 0;
    parent[startNode] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, visited);
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph,startNode);
}

int main() {
    vector<vector<int>> graph = {{0, 3, MAX, MAX, MAX, 1},
                              {3, 0, 2, 1, 10, MAX},
                              {MAX, 2, 0, 3, MAX, 5},
                              {MAX, 1, 3, 0, 5, MAX},
                              {MAX, 10, MAX, 5, 0, 4},
                              {1, MAX, 5, MAX, 4, 0}};

    int startNode = 0; 

    primMST(graph, startNode);

    return 0;
}
