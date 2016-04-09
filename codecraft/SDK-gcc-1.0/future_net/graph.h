#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <map>
#include <stdlib.h>
#include "time.h"

/*
#include<limits>
const int INT_INF = std::numeric_limits<int>::max();
*/
#define  MAX_VERT_NUM 601
#define  MAX_INT_NUM 0x7fffffff
#define MAX_RUNNING_TIME 9.5
struct gNode{
	int edgeId;
	int vert;
	int weight;
	gNode *next;
	gNode(int v, int w, gNode *t){
		vert = v;
		weight = w;
		next = t;
	}
	gNode(int id, int v, int w, gNode *t){
		edgeId = id;
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
	int minCost;
	bool debug;
	clock_t startTime;
	std::vector<bool> visited;
	std::vector<int> bestPath;
	std::vector<int> bestEdgePath;
	std::map<int ,int > vertIdMap;// source Id -> Graph Id
	//int edgeId[MAX_VERT_NUM][MAX_VERT_NUM]; // store the map between edge id and id; do not use at now.
	std::vector<gLink> adj;

	std::vector<int> passVert;
public:
	Graph():
		vertCount(0), edgeCount(0), digraph(false){}
	Graph(int V, bool dig = false);
	Graph(bool dig = false) { digraph = dig; vertCount = 0;
		edgeCount =0; minCost = MAX_INT_NUM; startTime = clock();}
	int get_vertexCount(){ return vertCount;}
	void set_vertexCount(int vert){ vertCount = vert;}
	int get_edgeCount(){ return edgeCount;}
	void set_edgeCount(int edge){ edgeCount = edge;}
	int get_digraph(){ return digraph;}
	int get_visited(int vert){ return visited[vert];}
	void set_visited(int vert){ visited[vert] = true;}
	gLink get_adj(int vert){ return adj[vert];};
	void initAdj();
	void set_debug(bool de){debug = de;}
	bool get_debug() {return debug;}
	clock_t get_startTime(){ return startTime;}

	void initPassVert(std::vector<int> v);

	gLink FindFirstAdj(int vert) { return adj[vert]->next;}
	gLink FindNextAdj(int v, int w);

	int FindEdgeId(int v, int w);

	std::vector<int> getBestEdgePath();

	void insert(int v, int w, int weight = 1);
	void insert(int id, int v, int w, int weight = 1);
	void insert(int edge[4]);

	void insertVertId(int num);
	int getVertId(int num){return vertIdMap[num];};

	bool CheckEdge(int v, int w) ;

	void clear_visited(){ visited.assign(vertCount, false);}

	void DFS(int vert = 0);
	void BFS(int vert = 0);
	std::vector<int> TopoSort();

	void BruteForceSearch();

	void printAllEdge();
	void printPassVert();
	void printBestEdgePath();

};

#endif
