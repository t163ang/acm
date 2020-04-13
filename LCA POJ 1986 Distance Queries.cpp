#include<iostream>
using namespace std;
const int MN = 40002;
//虽然题目给的好像不是一棵树，而是网，但tarjan算法本身dfs产生的是一棵生成树,所以也可以应用tarjan,并且注意应该无向的，即a-> b则b - >a
struct {
	int v,next,w;
}edge[MN * 3];
int tree[MN],query[MN],ep = 1;
void adde(int s, int v,int w, bool f = true){
	edge[ep].v = v;
	edge[ep].w = w;
	if(f){
		edge[ep].next = tree[s];
		tree[s] = ep++;
	}else{
		edge[ep].next = query[s];
		query[s] = ep++;
	}
}

int n,m;
int par[MN],vis[MN],dis[MN],dep[MN];
int find(int x){
	if(par[x] != -1) return par[x] = find(par[x]);
	return x;
}

void tarjan(int u, int d){
	int i,j,k;
	vis[u] = true;
	dep[u] = d;
	for(i = query[u]; i ; i = edge[i].next){
		j = edge[i].v, k = edge[i].w;
		if(vis[j]){
			dis[k] = dep[u] + dep[j] - (dep[find(j)] << 1);// dist(u,v) = dis(u)+dis(v)-2*dis(LCA(u,v))  *2!!
		}
	}
	for(i = tree[u]; i; i = edge[i].next){
		j = edge[i].v, k = edge[i].w;
		if(!vis[j]){
			tarjan(j,d + k);//d + k!!
			par[j] = u;
		}
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	char s[20];
	int i,j,k,a,b,c;
	while(~scanf("%d%d",&n,&m)){
		ep = 1;
		memset(tree,0,sizeof(tree));
		memset(query,0,sizeof(query));
		memset(vis,0,sizeof(vis));
		memset(par,-1,sizeof(par));
		for(i = 0; i < m; i++){
			scanf("%d%d%d %*c",&a,&b,&c);
			adde(a,b,c);
			adde(b,a,c);
		}
		scanf("%d",&k);
		for(i = 0; i < k; i++){
			scanf("%d%d",&a,&b);
			adde(a,b,i,false);
			adde(b,a,i,false);//记住这个也是双向的
		}
		tarjan(1,1);
		for(i = 0; i < k; i++){
			printf("%d\n",dis[i]);
		}
	}
	return 0;

}

/*
//“算法的巧妙之处在于利用了并查集，使得和当前处理元素u有关的所有询问都可以立即得出，
//但是又不需要一一计算，因此平均下来每次询问时间几乎为常数。”
void tarjan(int u){
	vis[u] = true;
	for(<u,v> in query){
		  if(vis[v]) ans[u][v] = find(v);
	}
	for(<u,v> in tree){
		if(!vis[v]){
			tarjan(v);
			par[v] = u;
		}
	}
}
*/