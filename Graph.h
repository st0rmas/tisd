#include <iostream>
#include <list>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
#include "Queue.h"

using namespace std;

struct Vertex{
    int value;
    vector<int> edges;
};
class Graph {
protected:

private:
    vector<Vertex> vertices;
    bool findVertex(int v){
        for (int i = 0; i < vertices.size(); ++i) {
            if (vertices[i].value==v) return true;
        }
        return false;
    }

public:
    bool* visited {new bool[vertices.size()]};
    bool isEmpty(){
        return vertices.empty();
    }
    Graph(){
    }
    void addVertex(int value){
        Vertex vertex;
        vertex.value=value;
        vertices.push_back(vertex);
    }
    void addEdge(int v1, int v2){
        if (findVertex(v1)) {
            vertices[v1 - 1].edges.push_back(v2);

        } else {
            cout << "Vertex doesn't exist" << endl;
        }
    }
    void printGraph(){
        sortVertices();
        for (int i = 0; i < vertices.size(); ++i) {
            cout<<"Vertex "<<vertices[i].value<<" connections with: ";
            for (int j = 0; j < vertices[i].edges.size(); ++j) {
                cout<<vertices[i].edges[j]<<" ";
            }
            cout<<endl;
        }
    }
    void sortVertices(){
        for (int i = 0; i < vertices.size(); ++i) {
            for (int j = i; j < vertices.size(); ++j) {
                if (vertices[i].value>vertices[j].value){
                    swap(vertices[i], vertices[j]);
                }
            }
        }
    }

    vector<Vertex> getVertices(){
        return vertices;
    }
    void DFS(int startVertex) {
        for (int i = 0; i < vertices.size(); ++i) {
            visited[i] = false;
        }
        DFSUtil(startVertex);
    }
    void DFSUtil(int v) {
        visited[v - 1] = true;
        cout << v<< " ";

        for (int i = 0; i < vertices[v - 1].edges.size(); ++i) {
            int neighbor = vertices[v - 1].edges[i];
            if (!visited[neighbor - 1]) {
                DFSUtil(neighbor);
            }
        }
    }
    void DFSUtilWithoutCout(int v) {
        visited[v - 1] = true;

        for (int i = 0; i < vertices[v - 1].edges.size(); ++i) {
            int neighbor = vertices[v - 1].edges[i];
            if (!visited[neighbor - 1]) {
                DFSUtilWithoutCout(neighbor);
            }
        }
    }
    bool canConvertToTree(int startVertex) {
        for (int i = 0; i < vertices.size(); ++i) {
            visited[i] = false;
        }
        DFSUtilWithoutCout(startVertex);
        for (int i = 0; i < vertices.size(); ++i) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;
    }


    void readGraphFromFile(const string& filename) {
        ifstream inputFile(filename);
        string line;
        while (getline(inputFile, line)) {
            istringstream iss(line);
            int vertex;
            iss >> vertex;
            addVertex(vertex);
            int neighbor;
            while (iss >> neighbor) {
                addEdge(vertex, neighbor);
            }
        }
        inputFile.close();
    }
    int findMax(){
        int max = vertices[0].value;
        for (int i = 1; i < vertices.size(); ++i) {
            if (vertices[i].value>max){
                max = vertices[i].value;
            }
        }
        return max;
    }
    void removeVertex(int v) {
        if (findVertex(v)) {
            vertices[v - 1].edges.clear();

            vertices.erase(vertices.begin() + v - 1);
        } else {
            cout << "Vertex doesn't exist" << endl;
        }
    }


};



