#ifndef GRAPH_NEW_H
#define GRAPH_NEW_H
#include<vector>

#include<limits>
const int INT_INF = std::numeric_limits<int>::max();

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
	Graph(int V, bool digraph = false);
	int get_vertexCount(){ return vertCount;}
	int get_edgeCount(){ return edgeCount;}
	int get_digraph(){ return digraph;}
	int get_visited(int vert){ return visited[vert];}
	int set_visited(int vert){ visited[vert] = true;}
	gLink get_adj(int vert){ return adj[vert];};
	void insert(int v, int w, int weight);
	
	void clear_visited(){ visited.assign(vertCount, false);}
	void DFS(int vert = 0);
	void BFS(int vert = 0);

};

inline Graph::Graph(int V, bool digraph){
	vertCount = V;
	edgeCount = 0;
	digraph = digraph;
	visited.assign(V,false);
	for(int i=0; i < V; i++){
		gNode* node = new gNode(i, 0, nullptr);
		adj.push_back(node);
	}
}

void DFS(Graph &G, int vert);
#endif