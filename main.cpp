#include <iostream>
#include "MenuManager.h"
#include "MenuItem.h"
#include "Graph.h"

Graph g;

void readFile(){
    g.readGraphFromFile("../graph.txt");
}
void printGraph(){
    cout << "Graph:" << endl;
    if (g.isEmpty()){
        cout<<"Graph is empty"<<endl;
    }
    else{
        g.printGraph();
    }
}
void addVertex(){
    int v;
    cout<<"Enter vertex: ";
    cin>>v;
    if (v>g.findMax()+1){
        cout<<"Next vertex to enter is "<< g.findMax()+1<<endl;
        addVertex();
    }
    else{
        g.addVertex(v);
    }
}
void addEdge(){
    int v1;
    int v2;
    cout<<"Enter vertex from: ";
    cin>>v1;
    cout<<"Enter vertex to: ";
    cin>>v2;
    if (v1>g.findMax() || v2>g.findMax() || v1==v2){
        cout<<"Max vertex is "<< g.findMax()<<endl;
        cout<<"You cant connect the same vertecies"<<endl;
        addEdge();
    }
    else{
        g.addEdge(v1,v2);
    }
}
void DFS(){
    int v;
    cout<<"Enter vertex: ";
    cin>>v;
    if (v>g.findMax()){
        cout<<"Max vertex is "<< g.findMax()<<endl;
        DFS();
    }
    else{
        g.DFS(v);
    }
}
void task(){
    int v;
    cout<<"Enter vertex: ";
    cin>>v;
    if (v>g.findMax()){
        cout<<"Max vertex is "<< g.findMax()<<endl;
        task();
    }
    else{
        if (g.canConvertToTree(v)){
            cout<<"WE CAN"<<endl;
        }
        else{
            cout<<"WE CAN'T"<<endl;;
        }
    }

}
void deleteVertex(){
    int v;
    cout<<"Enter vertex: ";
    cin>>v;
    if (v>g.findMax()){
        cout<<"Max vertex is "<< g.findMax()<<endl;
        deleteVertex();
    }
    else{
        g.removeVertex(v);
    }
}


int main() {
    MenuManager menuManager;
    menuManager.addMenuItem(MenuItem("Read from file", readFile));
    menuManager.addMenuItem(MenuItem("Print tree", printGraph));
    menuManager.addMenuItem(MenuItem("Add vertex", addVertex));
    menuManager.addMenuItem(MenuItem("Add edge", addEdge));
    menuManager.addMenuItem(MenuItem("DFS", DFS));
    menuManager.addMenuItem(MenuItem("Task variant 6", task));
    menuManager.addMenuItem(MenuItem("Delete vertex", deleteVertex));
    menuManager.showMenu();

    return 0;
}
