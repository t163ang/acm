#include<iostream>
using namespace std;
const int MN = 10024;
struct{
	int v,w,next;
}edge[MN << 10];
int map[MN],ep = 1;
void adde(int s, int v,int w){
	edge[ep].v = v;
	edge[ep].w = w;
	edge[ep].next = map[s];
	map[s] = ep++;
}
bool vis[MN];
int h[MN],dp[MN],que[MN];
void dfs(int u){
	vis[u] = true; h[u] = 0;
	for(int i = map[u]; i ; i = edge[i].next){
		int v = edge[i].v;
		if(vis[v]) continue;
		dfs(v);
		if(h[u] < h[v] + edge[i].w) h[u] = h[v] + edge[i].w;
	}
}


void bfs(){
	int head = 0, tail = 0;
	memset(vis,0,sizeof(vis));
	que[tail++] = 1;
	dp[1] = 0;
	while(head != tail){
		int u = que[head++];
		vis[u] = true;
		for(int i = map[u]; i ; i = edge[i].next){
			int v = edge[i].v;
			if(vis[v]) continue;
			dp[v] = dp[u]; int tmp;
			for(int j = map[u]; j ; j = edge[j].next){
				int q = edge[j].v;
				if(vis[q]) continue;
				if(q == v){
					tmp = edge[j].w; 
					continue;
				}
				if(dp[v] < h[q] + edge[j].w) dp[v] = h[q] + edge[j].w;//哈一开始时一直没想明h[q] + edge[j].w 就可以有方向了
			}
			dp[v] += tmp;
			que[tail++] = v;
		}
	}
} 
int main(){
	//freopen("in.txt","r",stdin);
	int n;
	while(~scanf("%d",&n)){
		memset(map,0,sizeof(map)); ep = 1;
		int a,b,i;
		for(i = 2; i <= n; i++){
			scanf("%d%d",&a,&b);
			adde(i,a,b); adde(a,i,b);
		}
		memset(vis,0,sizeof(vis));
		dfs(1);
		bfs();
		for(i = 1; i <= n; i++){
			printf("%d\n",max(dp[i],h[i]));
		}
	}
	return 0;
}