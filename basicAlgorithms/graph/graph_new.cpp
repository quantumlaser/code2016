#include"graph_new.h"
#include<iostream>
#include<queue>
void Graph::insert(int v, int w, int weight){
	adj[v]->next = new gNode(w, weight, adj[v]->next);
	edgeCount++;
	if(!digraph) adj[w]->next = new gNode(v, weight, adj[w]->next);
}

void Graph::DFS(int vert){
	visited[vert] = true;
	// std::cout<<"visit: "<<vert<<std::endl;
	for( gLink g = adj[vert]->next; g!=nullptr; g=g->next){
		if(!visited[g->vert])
			DFS(g->vert);
	}
}

void Graph::BFS(int vert){
	visited[vert] = true;
	// std::cout<<"visit: "<<vert<<std::endl;
	std::queue<int> cq;
	cq.push(vert);
	int temp;
	while(!cq.empty()){
		temp = cq.front();
		cq.pop();
		for(gLink g = adj[temp]->next; g!=nullptr; g=g->next){
			if(!visited[g->vert]){
				visited[g->vert] = true;
				// std::cout<<"visit: "<<g->vert<<std::endl;
				cq.push(g->vert);
			}
		}
	}
}