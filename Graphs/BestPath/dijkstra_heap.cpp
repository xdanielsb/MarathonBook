#include <iostream> 
#include <queue>
#include <vector>
#define forn(i,a) for (int i=0; i<a ; i++)
using namespace std;

#define INF 20000000

struct edge{
	int to, weight;
	edge(){}
	edge(int _to, int _weight){
		to = _to;
		weight = _weight;
	}
	bool operator < (edge e) const {
		return weight > e.weight;
	}
};

typedef vector < edge > ve;
typedef vector < ve > vve;
typedef vector < int > vi;
typedef priority_queue< edge> pq;


inline void show(vve &adj, int nodes){
    //Show the vertex
    forn(i,nodes){
        cout << " Node:" << i << endl;
        forn (j, adj[i].size()){
            cout << "\t" << adj[i][j].to << endl;
        }
    }

}

/*MAGIC OF DIJKSTRA USING PRIORITY QUEUES AND BFS
 * 
 */
inline void dijkstra(vve &adj, int src, int num_nodes){
    
    vi dist = vi(num_nodes+1,INF);
	pq  q;
    
    //by default
    q.push(edge(src,0));
    dist[src] = 0;

    //apply bfs
    while(!q.empty()){
        edge top = q.top();
        q.pop();
        int u = top.to;
        for(int i=0;i<adj[u].size();i++){
            int v = adj[u][i].to;
            if(dist[u] + adj[u][i].weight < dist[v]){
                dist[v] = dist[u] + adj[u][i].weight;
                q.push(edge(v,dist[v]));
            }
        }
    }

    //Show results of distances
    cout << "Distancias desde el origen " << src << endl;
    forn(i, num_nodes){
        cout <<"Costo al nodo: " << i << " ="<< dist[i] << endl;
        
    }

}

int main(){
    

    int nodes, vertex, from, to, weight;
    //Read the number of nodes and vertex
    cin >> nodes >> vertex;

    vve adj(nodes);

    //Read the connections
    forn(i, vertex){
        cin >> from >> to >> weight;
        adj[from].push_back(edge(to, weight));
    }   


    
   // show(adj, nodes);
    int src = 1;
    dijkstra(adj, src, nodes);

    return 0;

}