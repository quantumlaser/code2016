#include"Graph.h"
GRAPH ViewGRAPH(GRAPH &G)
{
	GRAPH G_1=G;
	for(int i=0;i<G_1.V();i++)
	{
		for(int j=i;j<G_1.V();j++)
		{
			if((G_1.getlike(i)==0||G_1.getlike(j)==0)&&(i!=j)) 
			{
				G_1.remove(i,j);
			}
		}
	}
	return G_1;
}
void DFS(GRAPH &G,int v)
{
	G.setvisited(v);
	for(int t=G.FirstAdjVex(v);t!=-1;t=G.NextAdjVex(v,t))
	{
		if(G.ifvisited(t)==false) DFS(G,t);
	}
}
bool IFin(int *num,int n)
{
	int len=sizeof(num)/sizeof(int);
	for(int i=0;i<len;i++)
	{
		if(n==num[i]) return true;
	}
	return false;
}

void InsertView(View *&pHead,View *p)
{
	View *q=NULL,*r=NULL;
	if(pHead==NULL)
	{
		pHead=p;
		return ;
	}
	if(p->score>=pHead->score)
	{
		q=p;
		pHead=p;
		pHead->next=q;
		return ;
	}
	r=pHead;
	q=r->next;
	while(q!=NULL)
	{
		if(p->score<q->score)
		{
			r=q;
			q=q->next;
		}
		else break;
	}
	r->next=p;
	p->next=q;
	return ;
}

View * FindPath(GRAPH &G_1)
{
	int V=G_1.V(),i=0;
	int *h=new int[V];//t=0,k=0,len=0;
	View *pHead=NULL;//置空头结点
	for(i=0;i<V;i++) 
	{
		h[i]=-1;
	}
	i=0;
	int next=0,t=-1,k=0,j=0;//用t=-1标志未找到下一个可观光点
	while(next!=-1)//当没有下一个观光点结束循环
	{
		t=-1;//标记寻找下一个未遍历
		View *pNode=new View;
		pNode->num=new int[V];
		pNode->score=0;
		pNode->m=0;
		pNode->next=NULL;
		//i++;
		DFS(G_1,next);
		//for(j=0;j<V;j++) cout<<G_1.ifvisited(j)<<" ";cout<<endl;
		//k=0;
		for(j=next,k=0;j<V;j++)
		{
			if(G_1.ifvisited(j)==true&&(IFin(h,j)==false))
			{
				pNode->score=pNode->score+G_1.getlike(j);
				//pNode->m++;
				pNode->num[k]=j;
				k++;
				h[i]=j;
				i++;
			}
			else
			{
				if(t==-1&&(G_1.getlike(j)!=0)) t=j;
				//标记已找到下一个开始循环点
			}

		}
		k--;
		i;
		next=t;
		pNode->m=k;
		//for(int x=0;x<=k;x++) cout<<pNode->num[x]<<" ";cout<<endl<<"h= ";
		//for(int x=0;x<i;x++) cout<<h[x]<<" ";cout<<endl;
		InsertView(pHead,pNode);
	}
	return pHead;
}

void PrintView(View *&pRoot,ofstream &fout)
{
	View *p=pRoot;
	//ofstream fout(name);
	int i=0;
	while(p!=NULL)
	{
		i++;
		p=p->next;
	}
	fout<<"A"<<endl<<i<<endl;
	p=pRoot;
	while(p!=NULL)
	{
		fout<<p->score<<" (";
		for(i=0;i<p->m;i++) fout<<p->num[i]<<" ";
		fout<<p->num[i]<<")"<<endl;
		p=p->next;
	}
	fout<<"#"<<endl;
}

void Floyd(GRAPH &G,int *&d,int *&p)
{
	for(int v=0;v<G.V();v++)
	{
		for(int w=0;w<G.V();w++)
		{
			d[v*G.V()+w]=G.getedge(v,w);
			p[v*G.V()+w]=v;
		}
	}
	//for(int i=0;i<G.V();i++){for(int j=0;j<G.V();j++) cout<<d[i*G.V()+j]<<" ";cout<<endl;}
	for(int i=0;i<G.V();i++)
	{
		for(int s=0;s<G.V();s++)
		{
			for(int t=0;t<G.V();t++)
			{
				if(d[s*G.V()+t]>d[s*G.V()+i]+d[i*G.V()+t])
				{
					d[s*G.V()+t]=d[s*G.V()+i]+d[i*G.V()+t];
					p[s*G.V()+t]=p[i*G.V()+t];
				}
			}
		}
	}
	//cout<<endl;for(int i=0;i<G.V();i++){for(int j=0;j<G.V();j++) cout<<d[i*G.V()+j]<<" ";cout<<endl;}
}

void FindHos(int V,int *d,ofstream &fout)
{
	int i,j,minlen=INF,len,num;
	for(i=0;i<V;i++)
	{
		len=0;
		for(j=0;j<V;j++)
		{
			if(d[i*V+j]>len) len=d[i*V+j];
		}
		if(len<minlen)
		{
			minlen=len;
			num=i;
		}
	}
	fout<<"B"<<endl<<num<<" "<<minlen<<endl<<"#"<<endl;
}





int minEdge(EDGE *pEdge,int num)
{
	int min=INF;
	int minElem=-1;
	for(int i=0;i<num;i++)
	{
		if(!pEdge[i].weight) continue;
		if(pEdge[i].weight<min)
		{
			min=pEdge[i].weight;
			minElem=i;
		}
	}
	return minElem;
}

void Prim(GRAPH &G,EDGE *&mst,int &length,int &edgeCount)
{
	EDGE *pEdge;
	pEdge=new EDGE[G.V()];
	int v=0;
	length=0;
	for(int i=0;i<G.V();i++)
	{
		pEdge[i].begin=v;
		pEdge[i].end=i;
		pEdge[i].weight=G.getedge(v,i);
	}
	pEdge[v].weight=0;
	edgeCount=0;
	for(int i=1;i<G.V();i++)
	{
		int edgeNum=minEdge(pEdge,G.V());
		mst[edgeCount]=pEdge[edgeNum];
		int b=mst[edgeCount].begin,e=mst[edgeCount].end;
		if(b>e) 
		{
			mst[edgeCount].begin=e;
			mst[edgeCount].end=b;
		}
		edgeCount++;
		length=pEdge[edgeNum].weight+length;
		v=pEdge[edgeNum].end;
		pEdge[v].weight=0;
		for(int j=0;j<G.V();j++)
		{
			if(G.getedge(v,j)<pEdge[j].weight)
			{
				pEdge[j].begin=v;
				pEdge[j].weight=G.getedge(v,j);
			}
		}
	}
	delete []pEdge;
}
/*
void PrintPath(EDGE *&mst,int V,int len,int count,char *name)
{
	ofstream fout(name);
	fout<<"C"<<endl<<count<<" "<<len<<endl;
	for(int i=0;i<V;i++)
	{
		for(int j=i;j<V;j++)
		{
			for(int k=0;k<count;k++)
			{
				if(mst[k].begin==i&&mst[k].end==j) 
				{
					fout<<i<<" "<<j<<" ";
					fout<<mst[k].weight<<endl;
					cout<<i<<" "<<j<<" ";
					cout<<mst[k].weight<<endl;
				}
			}
		}
	}
	fout<<"#"<<endl;
}*/






