//
//  Graph.h
//  Graphs
//
//  Created by Sebas Neira Gzz on 06/11/20.
//  Copyright © 2020 Sebas Neira Gzz. All rights reserved.
//

#ifndef Graph_h
#define Graph_h
#include <queue>
#include <stack>


template <class T>
struct Edge{
    T vertex;
    int weight;
};

template<class T>
class Graph {
private:
    int findVertex (T vertex);
    void DFSR(T vertex, vector<bool> &status);
    int minWeight(vector<int> &weight, vector<bool> &status);
    
public:
    vector < vector<Edge<T>> > adjList;
    vector<T> vertices;
    Graph(vector<T> list);
    Graph(vector <vector<T>> list);
    void BFS(T vertex);
    void BFS1(T vertex);
    void DFS(T vertex);
    void print();
    void addEdge(T source, T target);
    void shortestPath(T vertex);
    void getAdjList(T source);
};


template<class T>
Graph<T>::Graph(vector<T> list){
    for (auto source : list){
        vertices.push_back(source);
    }
    
    sort(vertices.begin(),vertices.end());
    
    vector< vector<Edge<T>> > tempList(vertices.size());
    adjList = tempList;
}

template<class T>
Graph<T>::Graph(vector< vector<T> > list){
    int source = 0;
    int target = 1;
    int weight = 2;
    
    // Crear vector de vertices
    for (vector<T> edge : list){
        T temp = edge[source];
        int pos = findVertex(temp);
        if(pos < 0){
            vertices.push_back(temp);
        }
        temp = edge[target];
        pos = findVertex(temp);
        if(pos < 0){
            vertices.push_back(temp);
        }
    }
    
    //Ordena el vector de vertices
    sort(vertices.begin(),vertices.end());
    
    /*Agregar los vertices a la lista de adyacencias
    for(auto vertex : vertices){
        vector< Edge<T> > temp;
        Edge<T> edge;
        edge.vertex = vertex;
        edge.weight = 0;
        temp.push_back(edge);
        adjList.push_back(temp);
    }*/
    
    //Crear lista de adyacencias del tamaño de la cantidad de vertices.
    vector< vector<Edge<T>> > tempList(vertices.size());
    adjList = tempList;
    
    
    //Agregar los destinos a la lista de adyacencias
    for (auto path : list){
        int pos = findVertex(path[source]);
        Edge<T> edge;
        edge.vertex = path[target];
        edge.weight = path[weight];
        adjList[pos].push_back(edge);
    }
}
    
template<class T>
int Graph<T>::findVertex(T vertex){
    typename vector<T>::iterator it;
    it = find(vertices.begin(), vertices.end(), vertex);
        if (it != vertices.end()){
            return it - vertices.begin();
        } else {
            return -1;
        }
    }

template<class T>
void Graph<T>::print(){
    for (int v=0; v<vertices.size(); v++) {
        cout << vertices[v] << " -> ";
        for(auto edge : adjList[v]) {
            cout << "{" << edge.vertex << "│" <<  edge.weight << "} ";
        }
        cout << endl;
    }
}

template<class T>
void Graph<T>::BFS(T vertex) {
    vector<bool> status(vertices.size(),false);
    queue<T> q;
    //agregamos el primer vertice a la fila
    int pos = findVertex(vertex);
    if (pos >= 0) {
        q.push(vertices[pos]);
        //le cambiamos el status al primer vertice
        status[pos] = true;
        while(!q.empty()) {
            T vertex = q.front();
            cout << vertex << " ";
            int pos = findVertex(vertex);
            for(auto adj : adjList[pos]) {
                pos = findVertex(adj.vertex);
                if(!status[pos]) {
                    q.push(adj.vertex);
                    status[pos] = true;
                }
            }
            q.pop();
        }
        cout << endl;
    }
}

template<class T>
void Graph<T>::BFS1(T vertex) {
    int pos = findVertex(vertex);
    if (pos >= 0){
        vector<bool> status(vertices.size(),false);
        queue<int> q;
        // agregamos el primer vertice a la fila
        q.push(pos);
        //le cambiamos el status al primer vertice
        status[pos] = true;
        while (!q.empty()) {
            int vertex = q.front();
            cout << vertices[vertex] << " ";
            for(auto adj: adjList[vertex]) {
                int pos = findVertex(adj.vertex);
                if(!status[pos]) {
                q.push(pos);
                status[pos] = true;
                }
            }
            q.pop();
        }
        cout << endl;
    }
}

template<class T>
void Graph<T>::DFS(T vertex){
    int pos = findVertex(vertex);
    if (pos >= 0){
        vector<bool> status(vertices.size(),false);
        DFSR(vertices[pos],status);
        cout << endl;
    }
}

template<class T>
void Graph<T>::DFSR(T vertex, vector<bool> &status){
    int pos = findVertex(vertex);
    if(!status[pos]) {
        cout << vertex << " ";
        status[pos] = true;
        for (auto adj : adjList[pos]) {
            int posAdj = findVertex(adj.vertex);
            if (!status[posAdj]) {
                DFSR(adj.vertex,status);
            }
        }
    }
}

template<class T>
int Graph<T>::minWeight(vector<int> &weight, vector<bool> &status){
    int min = INT_MAX;
    int pos = -1;
    for(int v=0; v<vertices.size(); v++) {
        if(!status[v]){
            if(min > weight[v]) {
                pos = v;
                min = weight[v];
            }
        }
    }
    return pos;
}

template<class T>
void Graph<T>::shortestPath(T vertex){
    int pos = findVertex(vertex);
    if (pos >= 0) {
        vector<bool> status(vertices.size(),false);
        vector<int> weight(vertices.size(),INT_MAX);
        vector<int> path(vertices.size(),-1);
        
        weight[pos] = 0;
        
        int next = pos;
        while(next >= 0) {
            status[next] = true;
            
            for(int v=0; v<adjList[next].size();v++){
                int posAdj = findVertex(adjList[next] [v].vertex);
                if(!status[posAdj]) {
                    if(weight[posAdj] > weight[next] + adjList[next] [v].weight) {
                        weight[posAdj] = weight[next] + adjList[next][v].weight;
                        path[posAdj] = next;
                    }
                }
            }
            next = minWeight(weight, status);
        }
        
        for(int v=0; v<vertices.size(); v++){
            cout << "Path: " << endl;
            stack<int> sp;
            sp.push(v);
            int p = path[v];
            while(p>=0){
                sp.push(p);
                p = path[p];
            }
            
            while(!sp.empty()){
                cout << sp.top() << " ";
                sp.pop();
            }
            cout << endl << "Weight:\n" <<  weight[v] << endl <<endl;
        }
    }
}

template<class T>
void Graph<T>::addEdge(T source, T target){
    int posSource = source.find(':');
    int posTarget = source.find(':');
    
    string sourceIp = source.substr(0,posSource);
    string sourceTarget = target.substr(0,posTarget);
    
    
    int pos = findVertex(sourceIp);
    Edge<T> edge;
    edge.vertex = sourceTarget;
    edge.weight = 0;
    adjList[pos].push_back(edge);
}

template<class T>
void Graph<T>::getAdjList(T source){
    int pos = findVertex(source);
    cout << vertices[pos] << " -> ";
    for(auto edge : adjList[pos]) {
        cout << "{" << edge.vertex << "│" <<  edge.weight << "} ";
    }
    cout << endl;
}
#endif /* Graph_h */
