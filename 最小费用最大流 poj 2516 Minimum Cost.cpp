#include<iostream>
using namespace std;
const int INF = 1 << 30;
const int MN = 104;
int n,m,k;
int S,T,mcost;
int shop[MN][MN],total[MN];
int suply[MN][MN];
int G[MN][MN];
int cost[MN][MN];
int que[MN << 10],head,tail;
int d[MN],pre[MN];
bool inque[MN], vis[MN];
bool spfa(){
	fill(d,d + MN,INF);
	memset(inque,0,sizeof(inque));
	head = tail = 0;
	d[S] = 0;
	que[tail++] = S;
	while(head != tail){
		int u = que[head++]; inque[u] = false;
		for(int v = 1; v <= T; v++){
			if(G[u][v]){
				if(d[u] + cost[u][v] < d[v]){
					d[v] = d[u] + cost[u][v];
					pre[v] = u;
					if(!inque[v]){
						inque[v] = true;
						que[tail++] = v;
					}
				}
			}
		}
	}
	return d[T] != INF;
}

void build(int k){
	int i,j;
	memset(G,0,sizeof(G));
	memset(cost,0,sizeof(cost));
	for(i = 1; i <= n; i++){
		G[S][i] = shop[i][k];
		for(j = 1; j <= m; j++){
			scanf("%d",&cost[i][n + j]);
			cost[n + j][i] = -cost[i][n + j];	
			G[i][n + j] = shop[i][k];
			G[n + j][T] = suply[j][k];
		}
	}
}
bool mincost(int k){
	build(k);
	int maxflow = 0;
	while(spfa()){
		int x = T,min = INF;
		while(x){
			if(min > G[pre[x]][x]) min = G[pre[x]][x];
 			x = pre[x];
		}
		x = T;
		while(x){
			G[pre[x]][x] -= min;
			G[x][pre[x]] += min;
			x = pre[x];
		}
		maxflow += min;
		mcost += min * d[T];
	}
	if(maxflow != total[k]) return false;
	return true;
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j;
	while(scanf("%d%d%d",&n,&m,&k),n){
		memset(total,0,sizeof(total));
		for(i = 1; i <= n; i++){
			for(j = 1; j <= k; j++){
				scanf("%d",&shop[i][j]);
				total[j] += shop[i][j];
			}
		}
		for(i = 1; i <= m; i++){
			for(j = 1; j <= k; j++){
				scanf("%d",&suply[i][j]);
			}
		}
		S = 0,T = n + m + 1; mcost = 0;
		for(i = 1; i <= k; i++){	
			if(!mincost(i)) {
				printf("-1\n");
				break;
			}
		}
		if(i > k) printf("%d\n",mcost);
		else for(i++; i <= k; i++){
			build(i);
		}
	}
	return 0;
}