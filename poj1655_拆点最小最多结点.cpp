#include<iostream>
using namespace std;
const int MN = 20024;
int n,minn,node;
bool vis[MN];
struct{
	int v,w,next;
}edge[MN << 1];
int head[MN],pn;
inline void adde(int u,int v){
	edge[pn].v = v;
	edge[pn].w = 0;
	edge[pn].next = head[u];
	head[u] = pn++;
}
//一篇计算子树结点数，一篇求min{max(max(子树), n - sum(子树) - 1)}
int dfs(int r){
	vis[r] = true;
	int num = 0,v;
	for(int i = head[r]; i ; i = edge[i].next){
		v = edge[i].v;	
		if(!vis[v]){
			int m = dfs(v);
			num += m;
			edge[i].w = m;
		}
	}
	return num + 1;
}

void dfs2(int r){
	vis[r] = true;
	int maxx = 0,sum = 0;
	for(int i = head[r]; i ; i = edge[i].next){
		int v = edge[i].v;
		int w = edge[i].w;
		if(maxx < w){
			maxx = w;
		}
		sum += w;
		if(!vis[v]) dfs2(v);
	}
	if(maxx < n - 1 - sum){
		maxx = n - 1 - sum;
	}
	if(minn > maxx){
		minn = maxx;
		node = r;
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,t,x,y;
	scanf("%d",&t);
	while(t--){
		memset(head,0,sizeof(head));
		pn = 1;
		scanf("%d",&n);
		for(i = 1; i < n; i++){
			scanf("%d%d",&x,&y);
			adde(x,y);
			adde(y,x);
		}
		memset(vis,0,sizeof(vis));
		dfs(1);
		memset(vis,0,sizeof(vis));
		minn = INT_MAX;
		dfs2(1);
		printf("%d %d\n",node,minn);
	}
	return 0;
}