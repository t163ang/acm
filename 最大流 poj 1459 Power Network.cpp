#include<iostream>
#include<queue>
//����ܺõ�ڹ�������������S��node����ʾnode����ṩ��������Ϊsuply�ܹ��ж��ٿ���֧��
//ͬ������node��T����ʾ�������consumer;һ��أ�һ��node��ʹ�����ܵ����-�ܵ��������
//ע�⵽���ⷴ���c(v,u) > 0 (һ�����0!)��������һ����
using namespace std;
const int MN = 1024;
const int INF = 1 << 30;
int n,np,nc,m,S,T;
int G[MN][MN];
int h[MN],e[MN];
struct Node{
	int v,next;
	Node(int v):v(v){}
	bool operator < (const Node n)const{
		return h[v] < h[n.v];
	}
};
bool inque[MN];
priority_queue<Node> que;
void push(int u, int v){
	int dt = min(e[u],G[u][v]);
	G[u][v] -= dt;
	G[v][u] += dt;
	e[u] -= dt;
	e[v] += dt;
	if(v != S && v != T && !inque[v]){
		que.push(Node(v)); inque[v] = true;
	}
}

void discharge(int u){
	while(e[u] > 0){
		int mh = INF,v = 0;
		for(; v <= T && e[u] > 0; v++){
			if(G[u][v]){
				if( h[u] == h[v] + 1) push(u,v);
				else if(mh > h[v]) mh = h[v];//��һ�������else����
			}
		}
		if(e[u] > 0) h[u] = mh + 1; 
	}
}
void maxflow(){
	memset(h,0,sizeof(h));
	memset(e,0,sizeof(e));
	memset(inque,0,sizeof(inque));
	while(!que.empty()) que.pop();
	h[S] = T + 1; e[S] = INF;
	for(int v = 0; v <= T; v++){
		if(G[S][v]){
			push(S,v);
		}
	}

	while(!que.empty()){
		int u = que.top().v; que.pop(); inque[u] = false;
		discharge(u);
	}
	printf("%d\n",e[T]);
}
int main(){
	//freopen("in.txt","r",stdin);
	char str[50]; int i,u,v,z;
	while(~scanf("%d%d%d%d",&n,&np,&nc,&m)){
		S = n, T = n + 1;
		memset(G,0,sizeof(G));
		for(i = 0; i < m; i++){	
			scanf("%s",str);
			sscanf(str,"(%d,%d)%d",&u,&v,&z);
			G[u][v] = z;//ע�⵽���ⷴ���c(v,u) > 0
		}
		
		for(i = 0; i < np; i++){
			scanf("%s",str);
			sscanf(str,"(%d)%d",&u,&z);
			G[S][u] = z;
		}
		
		for(i = 0; i < nc; i++){
			scanf("%s",str);
			sscanf(str,"(%d)%d",&u,&z);
			G[u][T] = z;
		}
		maxflow();
	}
	return 0;
}