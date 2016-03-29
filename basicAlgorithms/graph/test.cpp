#include"graph_new.h"
#include<iostream>
#include<fstream>
void test();
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
	std::cout<<std::endl;
	test();
}
void test(){
	std::ifstream in("input02.txt");
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(in.rdbuf());
	int V, E;
	std::cin>>V>>E;
	int v, w;
	Graph G(V, true);
	// std::cout<<(G.get_digraph() ? 1 : 0)<<std::endl;
	while(std::cin>>v>>w){
		G.insert(v, w);
	}
	std::vector<int> topoSeq = G.TopoSort();
	std::cout<<"TopoSort: "<<std::endl;
	for(auto it = topoSeq.begin(); it!=topoSeq.end(); it++){
		std::cout<<*it<<" ";
	}
	std::cout<<std::endl;
	std::cin.rdbuf(cinbuf);
}