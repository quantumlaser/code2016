//ͷ�ļ��������̶������ͽṹ�Լ�����������Ҫ��ͷ�ļ�����Ҫ�غ궨�塢�����ռ�
#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
using namespace std;
const INF 65535//�궨��һ��������ֵ��������ʾ����֮�䲻��ͨ
//��¼ÿ�η��ʵĵ÷֣������ʵľ���	
struct View
{
	int score;
	int m;
	int *num;//=new int[m];
	View *next;
};	
//�߽ṹ��Ĭ��begin<end��
struct EDGE
{
	int begin;
	int end;
	int weight;
};
//����ͼ��
class GRAPH
{
	int Vcnt,Ecnt;//����ͼ�Ķ�����������
	bool digraph;//�ж���������ͼ
	bool *visited;//�洢�Ƿ����
	int *like;//�洢�øж�
	std::vector<int> adj;//ʹ������ģ�嶨���������INF��ʾ�߲���ͨ����0��ʾ�Լ����Լ�����ʵ���ֱ�ʾ�ľ��ǳ���
public:
	GRAPH(int V,int *like,bool digraph=false);//���캯����ȱʡΪ����ͼ
	int V()const{return Vcnt;}//ȡ����
	int E()const{return Ecnt;}//ȡ����
	bool directed()const{return digraph;}//�ж���������
	bool ifvisited(int v){return visited[v];}//�ж��Ƿ����
	void setvisited(int v){visited[v]=true;}//���Ϊ�ѷ���
	int getlike(int v){return like[v];}//��ȡ�øж�
	void insert(int v,int w,int length);//�����
	int getedge(int v,int w){return adj[v*Vcnt+w];};//�ж��Ƿ���ڱ�
	void remove(int v,int w);//�Ƴ���
	int FirstAdjVex(int v);//ȡ����ĵ�һ���ڽӶ���
	int NextAdjVex(int v,int w);//ȡv��w�����һ���ڽӶ���	
};

//����ʹ�õ����к�����
GRAPH ViewGRAPH(GRAPH &G);//��üݳ��۹�ͼ
void DFS(GRAPH &G,int v);//������ȱ���ͼ
View * FindPath(GRAPH &G);//�ҵ��ݳ��۹�·��
void Floyd(GRAPH &G,int *&d,int *&p);//��ȫԴ���·�����Ż�����Դ���·������������·���ȱ���ֵ����ֱ��ֹͣ�ô�ѭ�������Ż���
int minEdge(EDGE *pEdge,int num);//����̱�
void Prim(GRAPH &G,EDGE *&mst,int &length,int &count);//����С������
bool IFin(int *num,int n);//�ж�n�Ƿ���������
void InsertView(View *&pHead,View *p);//����һ������·��
void PrintView(View *&pHead,ofstream &fout);//�������·��
void FindHos(int V,int *d,ofstream &fout);//����֪ȫԴ���·���������£��ҳ�ҽԺλ�á�

//���еĺ���
inline GRAPH::GRAPH(int V,int *love,bool digraph):Vcnt(V),Ecnt(0),digraph(digraph)//���캯��
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


