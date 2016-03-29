#include<iostream>
#include<string>
#include <sstream>
#include<fstream>
#include<time.h>
#include<vector>
#include<queue>
#include<algorithm>
std::vector<std::string> vertName;
bool Compare(int v, int w) {
	return vertName[v] < vertName[w];
}
struct gNode {
	int vert;
	int weight;
	gNode *next;
	gNode(int v, int w, gNode *t) {
		vert = v;
		weight = w;
		next = t;
	}
};
typedef gNode* gLink;
class Graph {
	int vertCount;
	int edgeCount;
	bool digraph;
	std::vector<bool> visited;
	std::vector<gLink> adj;
public:
	Graph() :
		vertCount(0), edgeCount(0), digraph(false) {}
	Graph(int V, bool dig = false);
	inline int get_vertexCount() { return vertCount; }
	inline void set_vertexCount(int vert) { vertCount = vert; }
	inline int get_edgeCount() { return edgeCount; }
	inline void set_edgeCount(int edge) { edgeCount = edge; }
	inline int get_digraph() { return digraph; }
	inline int get_visited(int vert) { return visited[vert]; }
	inline int set_visited(int vert) { visited[vert] = true; }
	inline gLink get_adj(int vert) { return adj[vert]; };

	// void insertVertName(int i, std::string name) { vertName[i] = name; }
	void insert(int v, int w, int weight = 1);
	bool CheckEdge(int v, int w) {
		for (gLink g = adj[v]->next; g != nullptr; g=g->next) {
			if (g->vert == w)
				return true;
		}
		return false;
	}

	void clear_visited() { visited.assign(vertCount, false); }

	void DFS(int vert = 0);
	void BFS(int vert = 0);
	bool TopoSort(std::vector<int> &topoSeq);
	void printEdge();

};

inline Graph::Graph(int V, bool dig) {
	vertCount = V;
	edgeCount = 0;
	digraph = dig;
	visited.assign(V, false);
	for (int i = 0; i < V; i++) {
		gNode* node = new gNode(i, 0, nullptr);
		adj.push_back(node);
	}
}

inline void Graph::insert(int v, int w, int weight) {
	adj[v]->next = new gNode(w, weight, adj[v]->next);
	edgeCount++;
	if (!digraph) adj[w]->next = new gNode(v, weight, adj[w]->next);
}

bool Graph::TopoSort(std::vector<int> &topoSeq) {
	std::queue<int> cq;
	std::queue<int> tempq;
	std::vector<int> degree;
	// std::vector<int> topoSeq;
	degree.assign(vertCount, 0);
	for (int i = 0; i < vertCount; i++) {
		for (gLink g = adj[i]->next; g != nullptr; g = g->next) {
			degree[g->vert]++;
		}
	}
	for (int i = 0; i < vertCount; i++) {
		if (degree[i] == 0) {
			cq.push(i);
		}
		//std::cout<<"degree: "<<degree[i]<<std::endl;
	}
	int temp;
	int i = 0;
	int st;
	while (!cq.empty()) {
		st = i;
		while (!cq.empty()) {
			temp = cq.front();
			cq.pop();
			topoSeq.push_back(temp);
			i++;
			//std::cout<<"sort: "<<temp<<std::endl;
			for (gLink g = adj[temp]->next; g != nullptr; g = g->next) {
				degree[g->vert]--;
				if (degree[g->vert] == 0) tempq.push(g->vert);
			}
		}

		std::sort(topoSeq.begin() + st, topoSeq.begin() + i, Compare);
		cq = tempq;
		while (!tempq.empty()) tempq.pop();
	}
	if (cq.empty() && topoSeq.size() < vertCount)
		return false;
	return true;
}

void Graph::printEdge() {
	for (int i = 0; i < vertCount; i++) {
		std::cout << i << ": ";
		for (gLink g = adj[i]->next; g != nullptr; g = g->next) {
			std::cout << g->vert << " ";
		}
		std::cout << std::endl;
	}
}
int main() {
	// #define Str1038
#ifndef Str1038
	std::ifstream in("input02.txt");
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(in.rdbuf());
	// std::ofstream log("output1.txt");
	// std::streambuf* x = std::cout.rdbuf(log.rdbuf());
#endif
	int T, N;
	std::string name;
	std::string compList;
	std::string buf;
	std::cin >> T;
	int v, w;
	while (T--) {
		std::cin >> N;
		vertName.clear();
		Graph G(N, true);
		for (int i = 0; i < N; i++) {
			std::cin >> name;
			vertName.push_back(name);
			std::getline(std::cin, compList);
			std::stringstream ss(compList);
			while (ss >> buf) {
				v = std::stoi(buf);
				if (v != i && !G.CheckEdge(v, i)) {
					G.insert(v, i);
				}
			}
		}
		G.printEdge();
		// std::cout << std::endl;
		std::vector<int> vec ;
		if (G.TopoSort(vec)) {
			for (int i = 0; i < N; i++) {
				std::cout << vertName[vec[i]] <<std::endl;
			}
		}
		else {
			std::cout << "Error!" << std::endl;
		}
		std::cout << std::endl;

	}
}