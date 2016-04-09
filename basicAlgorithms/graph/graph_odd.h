//头文件包含工程定义的类和结构以及函数名、必要的头文件、必要地宏定义、命名空间
#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
using namespace std;
const INF 65535//宏定义一个无穷大的值，用来表示两点之间不连通
//记录每次访问的得分，及访问的景点	
struct View
{
	int score;
	int m;
	int *num;//=new int[m];
	View *next;
};	
//边结构，默认begin<end；
struct EDGE
{
	int begin;
	int end;
	int weight;
};
//定义图类
class GRAPH
{
	int Vcnt,Ecnt;//定义图的顶点数、边数
	bool digraph;//判断有向、无向图
	bool *visited;//存储是否访问
	int *like;//存储好感度
	std::vector<int> adj;//使用向量模板定义的链表，用INF表示边不连通，用0表示自己到自己，其实数字表示的就是长度
public:
	GRAPH(int V,int *like,bool digraph=false);//构造函数，缺省为无向图
	int V()const{return Vcnt;}//取顶点
	int E()const{return Ecnt;}//取边数
	bool directed()const{return digraph;}//判断有向无向
	bool ifvisited(int v){return visited[v];}//判断是否访问
	void setvisited(int v){visited[v]=true;}//标记为已访问
	int getlike(int v){return like[v];}//获取好感度
	void insert(int v,int w,int length);//插入边
	int getedge(int v,int w){return adj[v*Vcnt+w];};//判断是否存在边
	void remove(int v,int w);//移除边
	int FirstAdjVex(int v);//取顶点的第一个邻接顶点
	int NextAdjVex(int v,int w);//取v在w后的下一个邻接顶点	
};

//工程使用的所有函数名
GRAPH ViewGRAPH(GRAPH &G);//获得驾车观光图
void DFS(GRAPH &G,int v);//深度优先遍历图
View * FindPath(GRAPH &G);//找到驾车观光路线
void Floyd(GRAPH &G,int *&d,int *&p);//求全源最短路径（优化：求单源最短路径，当最长的最短路径比保存值更大，直接停止该次循环，克优化）
int minEdge(EDGE *pEdge,int num);//求最短边
void Prim(GRAPH &G,EDGE *&mst,int &length,int &count);//求最小生成树
bool IFin(int *num,int n);//判断n是否在数组里
void InsertView(View *&pHead,View *p);//插入一条游览路线
void PrintView(View *&pHead,ofstream &fout);//输出游览路线
void FindHos(int V,int *d,ofstream &fout);//在已知全源最短路径的条件下，找出医院位置。

//类中的函数
inline GRAPH::GRAPH(int V,int *love,bool digraph):Vcnt(V),Ecnt(0),digraph(digraph)//构造函数
{
	//Vcnt=V;
	//Ecnt=0;
	adj.assign(V*V,INF);
	for(int i=0;i<V;i++)
	{
		adj[i*V+i]=0;
	}
	//digraph=dig;
	visited=new bool[V];
	like=new int[V];
	for(int i=0;i<V;i++)
	{
		like[i]=love[i];
		visited[i]=false;
	}
}
inline void GRAPH::insert(int v,int w,int length)
{
	if(adj[v*Vcnt+w]==INF) Ecnt++;
	adj[v*Vcnt+w]=length;
	if(!digraph) adj[w*Vcnt+v]=length;
}

inline void GRAPH::remove(int v,int w)
{
	if(adj[v*Vcnt+w]!=INF) Ecnt--;
	adj[v*Vcnt+w]=INF;
	if(!digraph) adj[w*Vcnt+v]=INF;
}

inline int GRAPH::FirstAdjVex(int v)
{
	int w=0;
	while(w<Vcnt&&(adj[v*Vcnt+w]==INF||adj[v*Vcnt+w]==0)) w++;
	if(w==Vcnt) return -1;
	else return w;
}

inline int GRAPH::NextAdjVex(int v,int w)
{
	int u=w+1;
	while(u<Vcnt&&(adj[v*Vcnt+u]==0||adj[v*Vcnt+u]==INF)) u++;
	if(u==Vcnt) return -1;
	else return u;
}

#endif


