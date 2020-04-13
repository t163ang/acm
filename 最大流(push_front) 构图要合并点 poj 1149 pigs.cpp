#include<iostream>
#include<queue>
using namespace std;

const int MN = 1024;
const int INF = 1 << 30;
int n,m;
int G[MN][MN],S,T;
int pigHouse[MN],pigUse[MN];

int h[MN],e[MN];
struct Node{
	int v;
	bool operator < (const Node a)const{
		return h[v] < h[a.v];
	}
	Node(int v):v(v){}
};

bool inque[MN];
priority_queue<Node> que;
void push(int u, int v){
	int delta = min(e[u],G[u][v]);
	G[u][v] -= delta;
	G[v][u] += delta;
	e[u] -= delta;
	e[v] += delta;
	if(v != S && v != T && !inque[v]){
		que.push(Node(v));
		inque[v] = true;
	}
}
void discharge(int u){
	while(e[u] > 0){
		int mm = INF;
		for(int v = S; v <= T && e[u] > 0; v++){
			if(G[u][v]){
				if(h[u] == h[v] + 1){
					push(u,v);
				}
				if(mm > h[v]) mm = h[v];
			}
		}
		if(e[u] > 0) h[u] = mm + 1;
	}
}

int maxflow(){
	memset(h,0,sizeof(h));
	memset(e,0,sizeof(e));
	memset(inque,0,sizeof(inque));
	h[S] = T; e[S] = INF;
	for(int v = 1; v <= T; v++){
		if(G[S][v]){
			push(S,v);
		}
	}
	while(!que.empty()){
		int u = que.top().v; que.pop(); inque[u] = false;
		discharge(u);
	}
	return e[T];
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,k,tmp;
	while(~scanf("%d%d",&n,&m)){
		S = 0, T = m + 1;
		for(i = 1; i <= n; i++){
			scanf("%d",&pigHouse[i]);
		}
		//construct graph ����Ĺ�ͼ̫������,�򵥵�˵�Ǻϲ���
		//��һ�㿴��ˮ�⣨simlar to push_relabe������Ϊ�˿���one after another ��
	   //���Կ����Ƚ�ȫ��pig���˵�һ���򿪵ģ�Ȼ������ߣ���ͬ������Ȧ�����Դ��������
		memset(G,0,sizeof(G));
		memset(pigUse,0,sizeof(pigHouse));
		for(i = 1; i <= m; i++){//customer
			scanf("%d",&k);
			for(j = 1; j <= k; j++){//keys
				scanf("%d",&tmp);//a key to tmp pigHouse
				if(pigUse[tmp]){
					G[pigUse[tmp]][i] = INF;
				}else{
					G[S][i] += pigHouse[tmp];
					pigUse[tmp] = i;
				}
			}
			scanf("%d",&tmp); //want to buy
			G[i][T] = tmp;
		}
		printf("%d\n",maxflow());
	}
	return 0;
}