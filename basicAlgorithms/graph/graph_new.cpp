#include"graph_new.h"
#include<iostream>
#include<queue>
#include<list>

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

std::vector<int> Graph::TopoSort(){
	std::queue<int> cq;
	std::vector<int> degree;
	std::vector<int> topoSeq;
	degree.assign(vertCount, 0);
	for(int i = 0; i < vertCount; i++){
		for(gLink g = adj[i]->next; g!=nullptr; g=g->next){
			degree[g->vert]++;
		}
	}
	for(int i = 0; i < vertCount; i++){
		if(degree[i] == 0){
			cq.push(i);
		}
		//std::cout<<"degree: "<<degree[i]<<std::endl;
	}
	int temp;
	while(!cq.empty()){
		temp = cq.front();
		cq.pop();
		topoSeq.push_back(temp);
		//std::cout<<"sort: "<<temp<<std::endl;
		for(gLink g = adj[temp]->next; g != nullptr; g=g->next){
			degree[g->vert]--;
			if(degree[g->vert] == 0) cq.push(g->vert);
		}
	}
	return topoSeq;
}