#ifndef GRAPH_NEW_H
#define GRAPH_NEW_H
#include<vector>

/*
#include<limits>
const int INT_INF = std::numeric_limits<int>::max();
*/
struct gNode{
	int vert;
	int weight;
	gNode *next;
	gNode(int v, int w, gNode *t){
		vert = v;
		weight = w;
		next = t;
	}
};
typedef gNode* gLink;
class Graph{
	int vertCount;
	int edgeCount;
	bool digraph;
	std::vector<bool> visited;
	std::vector<gLink> adj;
public:
	Graph():
		vertCount(0), edgeCount(0), digraph(false){}
	Graph(int V, bool dig = false);
	inline int get_vertexCount(){ return vertCount;}
	inline void set_vertexCount(int vert){ vertCount = vert;}
	inline int get_edgeCount(){ return edgeCount;}
	inline void set_edgeCount(int edge){ edgeCount = edge;}
	inline int get_digraph(){ return digraph;}
	inline int get_visited(int vert){ return visited[vert];}
	inline int set_visited(int vert){ visited[vert] = true;}
	inline gLink get_adj(int vert){ return adj[vert];};
	
	void insert(int v, int w, int weight = 1);
	bool CheckEdge(int v, int w) {
		for (gLink g = adj[v]->next; g != nullptr; g=g->next) {
			if (g->vert == w)
				return true;
		}
		return false;
	}
	
	void clear_visited(){ visited.assign(vertCount, false);}
	
	void DFS(int vert = 0);
	void BFS(int vert = 0);
	std::vector<int> TopoSort();

};

inline Graph::Graph(int V, bool dig){
	vertCount = V;
	edgeCount = 0;
	digraph = dig;
	visited.assign(V,false);
	for(int i=0; i < V; i++){
		gNode* node = new gNode(i, 0, nullptr);
		adj.push_back(node);
	}
}

inline void Graph::insert(int v, int w, int weight){
	adj[v]->next = new gNode(w, weight, adj[v]->next);
	edgeCount++;
	if(!digraph) adj[w]->next = new gNode(v, weight, adj[w]->next);
}
#endif