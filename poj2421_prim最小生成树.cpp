#include<iostream>
using namespace std;
const int MN = 510;
int dist[MN][MN];
int lowcost[MN];
bool vis[MN];
int prim(int n){
	memset(vis,0,sizeof(vis));
	int i,j,u = 0,len = 0;
	vis[u] = true;
	for(i = 0; i < n; i++){
		lowcost[i] = dist[u][i];
	}
	for(j = 1; j < n; j++){
		int min = INT_MAX;
		for(i = 0; i < n; i++){
			if(!vis[i] && lowcost[i] < min){
				min = lowcost[i];
				u = i;
			}
		}
		len += lowcost[u];
		vis[u] = true;
		for(i = 0; i < n; i++){
			if(!vis[i] && lowcost[i] > dist[u][i]){
				lowcost[i] = dist[u][i];
			}
		}
	}
	return len;
}
int main(){
	//freopen("in.txt","r",stdin);
	int n,i,j,m;
	while(~scanf("%d",&n)){
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				scanf("%d",dist[i] + j);
			}
		}
		scanf("%d",&m);
		for(i = 0; i < m; i++){
			int x,y;
			scanf("%d%d",&x,&y);
			dist[x - 1][y - 1] = 0;
			dist[y - 1][x - 1] = 0;
		}
		printf("%d\n",prim(n));
	}
	return 0;
}