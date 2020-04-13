#include<iostream>
using namespace std;
const int MN = 10024;
int n,m;
struct{
	int v,next;
	bool vis;
}edge[MN << 10];
int map[MN],ep;
void inline adde(int u, int v){
	edge[ep].v = v;
	edge[ep].vis = false;
	edge[ep].next = map[u];
	map[u] = ep++;
}
void dfs(int x){
	printf("%d\n",x);
	for(int i = map[x]; i != -1; i = edge[i].next){
		if(!edge[i].vis){
			edge[i].vis = true;
			edge[i^1].vis = true;
			dfs(edge[i].v);
			printf("%d\n",x);
		}
	}
	
}
int  main(){
	freopen("in.txt","r",stdin);
	int i,j;
	while(~scanf("%d%d",&n,&m)){
		memset(map,-1,sizeof(map)); ep = 0;
		int u,v;
		for(i = 0; i < m; i++){
			scanf("%d%d",&u,&v);
			adde(u,v);
			adde(v,u);
		}
		dfs(1);
	}
	return 0;
}