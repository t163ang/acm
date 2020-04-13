#include<iostream>
using namespace std;
const int MN = 1002;
int n,b,x,y;
int room[22];
int rank[MN][22];
bool vis[22];
int match[22][MN];
int cur[22];
/*
	–Ÿ—¿¿˚∂‡÷ÿ∆•≈‰
*/
bool dfs(int u){
	for(int i = x; i <= y; i++){
		int v = rank[u][i];
		if(!vis[v]){
			vis[v] = true;
			if(cur[v] < room[v] ){
				match[v][++match[v][0]] = u;
				cur[v]++;
				return true;
			}else{
				for(int j = 1; j <= match[v][0];j++){
					if(dfs(match[v][j])){
						match[v][j] = u;
						return true;
					}
				}
			}
		}
	}
	return false;
}
bool flow(){
	for(int i = 0; i <= b; i++){
		match[i][0] = 0;
		cur[i] = 0;
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		memset(vis,0,sizeof(vis));
		if(dfs(i)) ans++;
	}
	return ans >= n;
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j;
	while(~scanf("%d%d",&n,&b)){
		for(i = 0; i < n; i++){
			for(j = 0; j < b; j++){
				scanf("%d",rank[i] + j);
			}
		}
		for(i = 1; i <= b; i++){
			scanf("%d",room + i);
		}
		int minn = INT_MAX;
		bool range[MN];
		memset(range,0,sizeof(range));
		x = y = 0;
		while(x <= y && y < b){
			if(flow()){
				if(minn > y - x + 1) minn = y - x + 1;
				++x;
			}else{
				++y;
			}
		}
		printf("%d\n",minn);
	}
	return 0;
}