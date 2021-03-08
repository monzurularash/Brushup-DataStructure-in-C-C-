// Program to find Dijkstra's shortest path using 
// priority_queue in STL

 
#include<bits/stdc++.h> 
using namespace std; 
# define INF 0x3f3f3f3f 

// iPair ==> Integer Pair 
typedef pair<int, int> iPair; 

// To add an edge 
void addEdge(vector <pair<int, int> > adj[], int u, 
									int v, int wt) 
{ 
	adj[u].push_back(make_pair(v, wt)); 
	adj[v].push_back(make_pair(u, wt)); 
} 


// Prints shortest paths from src to all other vertices

/* adj[] is adjList (array of vector), int V is number of vertex, src is src vertex label*/
void shortestPath(vector<pair<int,int> > adj[], int V, int src) 
{ 
	// Create a priority queue to store vertices that 
	// are being preprocessed. This is weird syntax in C++. 
	// Refer below link for details of this syntax 
	// http://geeksquiz.com/implement-min-heap-using-stl/ 
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq; 

	// Create a vector for distances and initialize all 
	// distances as infinite (INF) 

	vector <int> dist(V,INF);

    
	// Insert source itself in priority queue and initialize 
	// its distance as 0.
	
	pq.push(make_pair(0, src)); //pq has (dist, label) pair
	
    dist[src] = 0;

	/* Looping till priority queue becomes empty (or all 
	distances are not finalized) */
	
	map <int, int> mp; // key = child, val = parent

    while(! pq.empty()){
        
        int u = pq.top().second;
        pq.pop();
        
        //vector<iPair> adjvec = adj[u]; // 
        
        for( auto i : adj[u] /*adjvec*/ ){  // i is every adj pair (label, cost)
        
            int v = i.first; // adj vertex's label
            int w = i.second; // adj vertex's weight
            
            if ( dist[v] > dist[u] + w ){
                dist[v] = dist[u] + w ;
                pq.push(make_pair(dist[v], v)); // pq contain pair of (dist, label) not (label, cost)
                
                mp[v] = u;
                
            }
        }
        
    }

	// Print shortest distances stored in dist[] 
	printf("Vertex Distance from Source\n"); 
	for (int i = 0; i < V; ++i) 
		printf("%d \t\t %d\n", i, dist[i]);
	
	
	// shortest-path
	
	for (int i =0 ; i< V; i++){
	
    	int key = i;
    	cout << "path for " << key << ":";
    	
    	while(key!=src){
        	int val = mp.find(key)->second;
        	cout << "->" << val;
        	key = val;
    	}
    	
    	cout << endl;
	}

} 

// Driver program to test methods of graph class 
int main() 
{ 
	int V = 9; 
	vector<iPair > adj[V]; 

	// making above shown graph 
	addEdge(adj, 0, 1, 4); 
	addEdge(adj, 0, 7, 8); 
	addEdge(adj, 1, 2, 8); 
	addEdge(adj, 1, 7, 11); 
	addEdge(adj, 2, 3, 7); 
	addEdge(adj, 2, 8, 2); 
	addEdge(adj, 2, 5, 4); 
	addEdge(adj, 3, 4, 9); 
	addEdge(adj, 3, 5, 14); 
	addEdge(adj, 4, 5, 10); 
	addEdge(adj, 5, 6, 2); 
	addEdge(adj, 6, 7, 1); 
	addEdge(adj, 6, 8, 6); 
	addEdge(adj, 7, 8, 7); 

	shortestPath(adj, V, 0); 

	return 0; 
} 

