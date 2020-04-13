#include<iostream>
using namespace std;
const int INF = 1 << 30;
const int MN = 124;
struct{
	int v,w,next;
}edge[MN * MN];
int head[MN],pn;
void adde(int u,int v,int w){
	edge[pn].v = v;
	edge[pn].w = w;
	edge[pn].next = head[u];
	head[u] = pn++;
}
int n,a,b;
int dist[MN];
bool inque[MN];
int que[1000000],qh,qt;
void spfa(){
	memset(inque,false,sizeof(inque));
	fill(dist,dist + n + 1,INF);
	qh = qt = 0;
	que[qt++] = a;
	dist[a] = 0;
	while(qh != qt){
		int u = que[qh++];
		inque[u] = false;
		for(int i = head[u]; i ; i = edge[i].next){
			int v = edge[i].v, w = edge[i].w;
			if(dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				if(!inque[v]){
					inque[v] = true;
					que[qt++] = v;
				}
			}
		}
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,k,v;
	while(~scanf("%d%d%d",&n,&a,&b)){
		memset(head,0,sizeof(head));
		pn = 1;
		for(i = 1; i <= n; i++){
			scanf("%d",&k);
			if(k == 0) continue;
			scanf("%d",&v);
			adde(i,v,0);
			for(j = 1; j < k; j++){
				scanf("%d",&v);
				adde(i,v,1);
			}
		}
		spfa();
		if(dist[b] != INF){
			printf("%d\n",dist[b]);
		}else printf("-1\n");
	}
	return 0;
}