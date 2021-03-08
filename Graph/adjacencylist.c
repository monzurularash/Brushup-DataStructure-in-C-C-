
// C++ program to illustrate 
// array of vectors 
  
#include <iostream> 
#include <vector> 
using namespace std; 
 struct Node{
     int vertex;
     Node* next;
 };

Node * createNode( int vertex){
    Node* Newnode = new Node;
    Newnode->vertex = vertex;
    Newnode->next = NULL;
    return Newnode;
}

void addedge(Node* adjlist[], int src, int dest){
    Node * Newnode = createNode(dest);
    Newnode->next = adjlist[src]; // adjlist[src] is a head pointer
    adjlist[src] = Newnode;
    
    
    Newnode = createNode(src);
    Newnode->next = adjlist[dest];
    adjlist[dest] = Newnode;
    
}

struct graph{
    Node **adjlist;
    char num;
}__attribute__((packed));
// Driver code 


int main() 
{ 

    //Node *adjlist[5] = {NULL};
    
    graph * Graph = new graph;
    
    //cout << sizeof(graph) <<endl;
    
    Graph->adjlist = (Node**)malloc(5*sizeof(Node*));
    
    
    addedge(Graph->adjlist, 0,1);
    addedge(Graph->adjlist, 0,4);
    addedge(Graph->adjlist, 0,3);
    addedge(Graph->adjlist, 4,3);
    addedge(Graph->adjlist, 1,2);
    addedge(Graph->adjlist, 2,3);
    
    for (int i=0; i<5 ; i++){
        Node *tmp = Graph->adjlist[i];
        cout <<"strting vertex:" << i ;
        while(tmp!=NULL){
            cout << "-> " << tmp->vertex ;
            tmp = tmp->next;
        }
        
        cout << endl;
    }
    
    return 0; 
} 
