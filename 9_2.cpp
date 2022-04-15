#include<iostream>
using namespace std;

/*Max Weight Spanning tree*/

#define V 5

int findMax(bool visited[], int weights[]){
    int index = -1;

    int maxW = INT_MIN;

    for(int i = 0; i < V; i++){
        if(visited[i] == false && weights[i] > maxW){
            maxW = weights[i];
            index = i;
        }
    }
    return index;
}

void print(int graph[V][V], int parent[]){
    int MST = 0;
    for(int i = 1; i < V; i++){
        MST += graph[i][parent[i]];
    }

    cout << "Weight: " << MST << endl;

    for(int i = 1; i < V; i++){
        cout << parent[i] << " -- " << i << " --> " << graph[i][parent[i]] << endl;
    }
}

void maximumSpanningTree(int graph[V][V]){
    bool visited[V];

    int weights[V];

    int parent[V];

    for(int i = 0; i < V; i++){
        visited[i] = false;
        weights[i] = INT_MIN;
    }

    weights[0] = INT_MAX;
    parent[0] = -1;

    for(int i = 0; i < V-1; i++){
        int maxVertex = findMax(visited, weights);
        visited[maxVertex] = true;

        for(int j = 0; j < V; j++){
            if(graph[j][maxVertex] != 0 && visited[j] == false){
                if(graph[j][maxVertex] > weights[j]){
                    weights[j] = graph[j][maxVertex];
                    parent[j] = maxVertex;
                }
            }
        }

    
    }

    print(graph, parent);
}

int main(){
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    
    maximumSpanningTree(graph);

}