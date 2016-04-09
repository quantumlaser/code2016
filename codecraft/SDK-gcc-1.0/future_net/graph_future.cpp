#include "graph.h"
#include <queue>
#include <algorithm>
#include <iostream>
struct Path{
    std::vector<int> path;
    unsigned int passCnt;
    int cost;
    Path(){passCnt = 0; cost = 0;}
    Path(const Path & pa){
        path = pa.path;
        passCnt = pa.passCnt;
        cost = pa.cost;
    }
};

void printVec(std::vector<int> v);
void printPath(Path & pa);

void Graph::BruteForceSearch(){
    std::queue<Path> que;
    Path first;
    first.path.push_back(passVert[0]);
    first.passCnt = 1;
    que.push(first);
    while(!que.empty() && ((double)(clock() - startTime) / CLOCKS_PER_SEC) <MAX_RUNNING_TIME){
        Path pa = que.front();
        //printVec(pa.path);
        //printPath(pa);
        for(gLink g = adj[pa.path.back()]->next; g!=NULL; g=g->next){
            Path newPa(pa);
            if(std::find(newPa.path.begin(), newPa.path.end(), g->vert) != newPa.path.end())
                continue; // Loop
            if(g->vert == passVert[1] && newPa.passCnt != passVert.size()-1)
                continue; // go to end without enough pass vert.
            if(std::find(passVert.begin(), passVert.end(), g->vert) != passVert.end())
                newPa.passCnt++;
            newPa.cost = newPa.cost + g->weight;
            newPa.path.push_back(g->vert);
            //std::cout<<"passcnt: "<<newPa.passCnt<<"\n";
            if(newPa.passCnt == passVert.size()){
                if(newPa.cost < minCost){
                    if(debug){
                        std::cout<<"find better path:\n";
                        printPath(newPa);
                    }
                    minCost = newPa.cost;
                    bestPath = newPa.path;
                }
                continue; // if all pass, don't find more.
            }
            que.push(newPa);
        }
        que.pop();
    }
}

void printVec(std::vector<int> v){
    for(unsigned int i =0; i< v.size(); i++)
        std::cout<<v[i]<<" ";
    std::cout<<"\n";
}

void printPath(Path & pa){
    std::cout<<"Path: ";
    for(unsigned int i =0; i< pa.path.size(); i++)
        std::cout<<pa.path[i]<<" ";
    std::cout<<"\n";
    std::cout<<"cost: "<<pa.cost<<"\n";
    std::cout<<"passCnt: "<<pa.passCnt<<"\n\n";
}
