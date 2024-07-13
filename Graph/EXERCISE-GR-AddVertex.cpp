#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Graph {
    private:
        unordered_map<string, unordered_set<string> > adjList;
    
    public:
        void printGraph() {
            unordered_map<string, unordered_set<string>>::iterator kvPair = adjList.begin();
            //here the unordered map(hashmap was made) here key is the string the value is an unordered set and we call this map adjList
            while (kvPair != adjList.end()) {
                cout  << kvPair->first << ": [ ";  // this prints out the vertex
                unordered_set<string>::iterator edge = kvPair->second.begin();
                while (edge != kvPair->second.end()) {
                    cout  << edge->data() << " ";  // this prints out edges
                    edge++;
                }
                cout << "]" << endl;
                kvPair++;
            }
        }
        bool addVertex(string vertex){
            if(adjList.count(vertex)==0){
            //this vertex is not already in the adjacency list
                adjList[vertex];
                return true;
            }
            return false;
        }
        // WRITE ADDVERTEX MEMBER FUNCTION 


};



int main() {

    Graph* myGraph = new Graph();

    myGraph->addVertex("A");
    myGraph->addVertex("B");
    
    cout << "Graph:\n";
    myGraph->printGraph();

    /*
        EXPECTED OUTPUT:
        ----------------
        Graph:
        B: [ ]
        A: [ ]

    */ 
       
}

