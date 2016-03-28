#include"graph_new.h"
#include<iostream>
#include<fstream>
int main(){
	// #define testg
#ifndef testg
	std::ifstream in("input.txt");
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(in.rdbuf());
	// std::ofstream log("output1.txt");
	// std::streambuf* x = std::cout.rdbuf(log.rdbuf());
#endif
	int V, E;
	std::cin>>V>>E;
	Graph G(V, false);
	int *like=new int[V];
	for(int i=0;i<V;i++)
	{
		std::cin>>like[i];
	}
	int v, w, weight;
	while(std::cin>>v>>w>>weight){
		G.insert(v, w, weight);
	}
	for(int i=0;i<V;i++){
		gLink g = G.get_adj(i);
		while(g){
			std::cout<<g->vert<<" ";
			g = g->next;
		}
		std::cout<<std::endl;
	}
	G.DFS(0);
	G.clear_visited();
	// G.DFS(3);
	// G.clear_visited();
	G.BFS();
}