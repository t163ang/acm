#include<iostream>
#include<queue>
using namespace std;
const int MN = 1024;
int h[MN],e[MN], s,t,n,G[MN][MN];//n为顶点个数,G[i][j]代表残留网络c(i,j)

struct Node{
	int v;
	bool operator <(const Node a)const{
		return h[v] < h[a.v];
	}
	Node(int u):v(u){}
};
bool inque[MN];
priority_queue<Node> pque;

void inline push(int u, int v){
	int d = min(e[u],G[u][v]);
	G[u][v] -= d;
	G[v][u] += d;
	e[u] -= d;
	e[v] += d;
	if(v != t && v != s && !inque[v]){
		pque.push(Node(v));
		inque[v] = true;
	}
}
void inline relabel(int u, int m){
	if(m < INT_MAX) h[u] = m + 1;
}

void init(){
	memset(h,0,sizeof(h));
	memset(e,0,sizeof(e));
	h[s] = n;
	e[s] = INT_MAX;
	for(int v = 1; v <= n; v++){
		if(G[s][v]){
			push(s,v);
		}
	}
}

void discharge(int u){
	while(e[u] > 0){
		int mm = INT_MAX;
		for(int v = 1; v <= n && e[u] > 0; v++){
			if(G[u][v]){
				if(h[u] == h[v] + 1){
					push(u,v);
				}
				if(mm > h[v]) mm = h[v];
			}
		}
		if(e[u] > 0) relabel(u,mm);
	}
}

int push_relabel(){
	init();
	while(!pque.empty()){
		int u = pque.top().v; pque.pop(); inque[u] = false;
		discharge(u);
	}
	return e[t];
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,k,w,m;
	while(~scanf("%d%d",&m,&n)){
		memset(G,0,sizeof(G));
		s = 1, t = n;
		for(i = 0; i < m; i++){
			scanf("%d%d%d",&j,&k,&w);
			G[j][k] += w;
		}
		printf("%d\n",push_relabel());
	}
}