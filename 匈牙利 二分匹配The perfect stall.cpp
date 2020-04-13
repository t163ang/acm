#include<iostream>
using namespace std;
const int MN = 224;
struct{
	int v,next;
}edge[MN << 7];
int map[MN],ep = 1;
inline void adde(const int &s, const int &d){
	edge[ep].v = d;
	edge[ep].next = map[s];
	map[s] = ep++;
}
int N,M;
int match[MN];
bool vis[MN];
bool dfs(int p){
	int i,v;
	for(i = map[p]; i; i = edge[i].next){
		v = edge[i].v;
		if(!vis[v]){
			vis[v] = true;
			if(match[v] == -1 || dfs(match[v])){
				match[v] = p;
				return true;
			}
		}
	}
	return false;
}
void mat(){
	memset(match,-1,sizeof(match));
	int ans = 0;
	for(int i = 1; i <= N; i++){
		memset(vis,0,sizeof(vis));
		if(dfs(i)) ans++;
	}
	printf("%d\n",ans);
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j;
	while(~scanf("%d%d",&N,&M)){
		memset(map,0,sizeof(map));
		ep = 1;
		for(i = 1; i <= N; i++){
			int si,st;
			scanf("%d",&si);
			for(j = 0; j < si;j++){
				scanf("%d",&st); 
				adde(i,st);
			}
		}
		mat();
	}
	return 0;
}
