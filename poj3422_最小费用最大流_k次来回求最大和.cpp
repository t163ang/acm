#include<iostream>
using namespace std;
const int MN = 5524;
int cost[MN][MN];
int n,k;

struct Edge{
	int u,v,w,c;
	Edge *next,*rev;
}edge[10000000],*head[MN];
int S,T,pn;
const int INF = 1 << 30;
void adde(int u,int v,int w,int c){
	edge[pn].u = u;
	edge[pn].v = v;
	edge[pn].w = w;
	edge[pn].c = c;
	edge[pn].next = head[u];
	edge[pn].rev = edge + pn + 1;
	head[u] = edge + pn++;

	edge[pn].u = v;
	edge[pn].v = u;
	edge[pn].w = 0;
	edge[pn].c = -c;
	edge[pn].next = head[v];
	edge[pn].rev = edge + pn - 1;
	head[v] = edge + pn++;
}
void init(int s,int t){
	memset(head,NULL,sizeof(head));
	S = s;
	T = t;
	pn = 0;
}
/*
返回最大流的最小费用
*/
Edge *pre[MN];
bool inque[MN];
int dis[MN],que[10000000],qh,qt;
bool spfa(){
	qh = qt = 0;
	memset(inque,0,sizeof(inque));
	fill(dis,dis + T + 1,INF);
	dis[S] = 0;
	que[qt++] = S;
	while(qh != qt){
		int u = que[qh++];
		inque[u] = false;
		for(Edge *e = head[u]; e != NULL; e = e->next){
			int v= e->v;
			if(e->w > 0 && dis[u] != INF && (dis[u] + e->c) < dis[v]){
				dis[v] = dis[u] + e->c;
				pre[v] = e;
				if(!inque[v]){
					inque[v] = true;
					que[qt++] = v;
				}
			}
		}
	}
	return dis[T] != INF;
}
int feeflow(){
	int ans = 0;
	while(spfa()){
		int p = T,minn = INT_MAX;
		while(p != S){
			Edge* e = pre[p];
			minn = min(minn,e->w);
			p = e->u;
		}
		p = T;
		while(p != S){
			Edge* e = pre[p];
			e->w -= minn;
			e->rev->w += minn;
			p = e->u;
		}
		ans += minn * dis[T];
	}
	return -ans;
}


int main(){
	//freopen("in.txt","r",stdin);
	int i,j,t,x,y,r,d;
	while(~scanf("%d%d",&n,&k)){
		for(i = 0; i < n; i++){
			for(j = 0; j < n;j++){
				scanf("%d",cost[i] + j);
			}
		}
		init(2 * n * n, 2 * n * n + 1);
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				t = i * n + j;
				x = 2 * t;
				y = x + 1;
				r = 2 * (t + 1);
				d = 2 * (t + n);
				adde(x,y,1,-cost[i][j]);
				adde(x,y,k - 1,0);
				if(j + 1 < n){
					adde(y,r,k,0);
				}
				if(i + 1 < n){
					adde(y,d,k,0);
				}
			}
		}
		adde(S,0,k,0);
		adde(S - 1,T,k,0);
		printf("%d\n",feeflow());
	}
	return 0;
}