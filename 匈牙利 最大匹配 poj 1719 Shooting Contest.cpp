#include<iostream>
using namespace std;
const int MN = 1024;
//exactly one white square is hit in each column 所以竞争资源是列，行去竞争列（行匹配列）
struct{
	int v,next;
}edge[MN << 10];
int map[MN],ep;
void adde(int u, int v){
	edge[ep].v = v;
	edge[ep].next = map[u];
	map[u] = ep++;
}
int r,c;
int match[MN];
bool vis[MN];
int col[MN];
bool dfs(int p){
	for(int i = map[p]; i ; i = edge[i].next){
		int v = edge[i].v;
		if(!vis[v]){
			vis[v] = true;
			if(!match[v] || dfs(match[v])){
				match[v] = p;
				return true;
			}
		}
	}
	return false;
}
void mat(){
	int ans = 0;
	memset(match,0,sizeof(match));
	for(int i = 1; i <= r; i++){
		memset(vis,0,sizeof(vis));
		if(dfs(i)) ans++;
	}
	if(ans < r) printf("NO\n");
	else{
		for(int i = 1; i <= c; i++){
			if(match[i]) printf("%d ",match[i]);
			else printf("%d ",col[i]);
		}
		puts("");
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	int blo; scanf("%d",&blo);
	while(blo--){
		memset(map,0,sizeof(map)); ep = 1;
		scanf("%d%d",&r,&c);
		for(int i = 1; i <= c; i++){
			int a,b;
			scanf("%d%d",&a,&b);
			adde(a,i);
			adde(b,i);
			col[i] = a;
		}
		mat();
	}
	return 0;
}