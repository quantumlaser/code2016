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
	//����ͼ�������:�����ﶨ��һ��like�洢�øжȣ�·���߶�ȡ����
	int V,E,i=0;
	fin>>V>>E;
	int *like=new int[V];
	for(i=0;i<V;i++)
	{
		fin>>like[i];
	}
	GRAPH G(V,like,false);//����ͼ
	
	delete []like;
	int v,w,weight;
	while(fin>>v>>w>>weight)
	{
		G.insert(v,w,weight);//�����
	}
	fin.close();

	//��������
	GRAPH G_1=ViewGRAPH(G);//��üݳ�����ͼ
	View *pHead=FindPath(G_1);//��üݳ�·������ͷ���
	PrintView(pHead,fout);//���·��
	//�ҳ�ҽԺ
	int *d=new int[V*V],*p=new int[V*V];//��¼·��
	Floyd(G,d,p);//Floyd�㷨���ȫԴ���·��	
	//cout<<endl;for(int i=0;i<G.V();i++){for(int j=0;j<G.V();j++) cout<<d[i*G.V()+j]<<" ";cout<<endl;}//���������·��
	FindHos(V,d,fout);//�ҳ�ҽԺ
	//�̹��ˣ�ʹ��Prim�㷨
	EDGE *mst=new EDGE[E];//�洢��
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