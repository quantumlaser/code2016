#ifndef GRAPH_FUTURE_H
#define GRAPH_FUTURE_H
#include "graph.h"
#include <map>
struct gNodeFuture : public gNode{
    int edgeId;
    gNodeFuture *next;
    gNodeFuture(int id, int v, int w, gNodeFuture *t) : gNode(v, w, NULL){
        edgeId = id;
        next = t;
    }
};
typedef gNodeFuture* gLinkFuture;
class GraphFuture : public Graph{
    int minCost;
    bool debug; //debug决定是否输出一些中间过程
    clock_t startTime;
    std::vector<int> bestPath; // 最优路径的顶点序列
    std::vector<int> bestEdgePath; // 最优路径的边序列
    std::map<int ,int > vertIdMap;// source Id -> Graph Id
    std::vector<int> passVert; //demand 顶点序列
    std::vector<gLinkFuture> adj;
public:
    GraphFuture(bool dig = false): Graph(dig){
        minCost = MAX_INT_NUM;
        startTime = clock();
    }
    void set_debug(bool de){debug = de;}
    bool get_debug() {return debug;}
    clock_t get_startTime(){ return startTime;}

    void insertVertId(int num); //插入顶点索引，生成自增ID
    int getVertId(int num){return vertIdMap[num];}; // 获取顶点ID

	void initAdj(); //根据顶点数，初始化边向量

    void insert(int id, int v, int w, int weight = 1);
    void insert(int edge[4]); // 插入边

    void initPassVert(std::vector<int> v); // 根据要求的顶点索引生成Graph中的顶点ID
    int FindEdgeId(int v, int w);
    std::vector<int> getBestEdgePath(); //

    void BruteForceBFS();
    void BruteForceDFS();

    void printAllEdge();
    void printPassVert();
    void printBestEdgePath();
};

#endif
