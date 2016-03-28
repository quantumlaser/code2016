#include"Graph.h"
#include<fstream>
#include<stdlib.h>
int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		cout<<"Wrong input!Try again."<<endl;
		exit(1);
	}
	ifstream fin(argv[1]);
	ofstream fout(argv[2]);
	if(!fin) {cout<<"Can't open the file."<<endl; exit(1);}
	//建立图，输入边:在这里定义一个like存储好感度；路径边读取加入
	int V,E,i=0;
	fin>>V>>E;
	int *like=new int[V];
	for(i=0;i<V;i++)
	{
		fin>>like[i];
	}
	GRAPH G(V,like,false);//构造图
	
	delete []like;
	int v,w,weight;
	while(fin>>v>>w>>weight)
	{
		G.insert(v,w,weight);//插入边
	}
	fin.close();

	//遍历游览
	GRAPH G_1=ViewGRAPH(G);//获得驾车游览图
	View *pHead=FindPath(G_1);//获得驾车路线链表头结点
	PrintView(pHead,fout);//输出路线
	//找出医院
	int *d=new int[V*V],*p=new int[V*V];//记录路径
	Floyd(G,d,p);//Floyd算法求得全源最短路径	
	//cout<<endl;for(int i=0;i<G.V();i++){for(int j=0;j<G.V();j++) cout<<d[i*G.V()+j]<<" ";cout<<endl;}//测试输出地路径
	FindHos(V,d,fout);//找出医院
	//铺光纤，使用Prim算法
	EDGE *mst=new EDGE[E];//存储边
	int length=0,count=0;
	Prim(G,mst,length,count);
	fout<<"C"<<endl<<count<<" "<<length<<endl;
	for(int i=0;i<count;i++) fout<<mst[i].begin<<" "<<mst[i].end<<" "<<mst[i].weight<<endl;
	fout<<"#"<<endl;
	//PrintPath(mst,V,length,count,argv[2]);
	fout.close();
	//system("Pause");
	return 0;
	
}