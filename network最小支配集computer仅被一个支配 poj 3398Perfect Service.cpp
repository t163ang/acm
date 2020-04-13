#include<iostream>
using namespace std;
const int MN =  10024;
struct {
	int v,next;
}edge[MN << 10];
int map[MN], ep = 1;
void adde(int s, int d){
	edge[ep].v = d;
	edge[ep].next = map[s];
	map[s] = ep++;
}
int dp[MN][3], vis[MN];
void dfs(int r){
	vis[r] = true;
	dp[r][0] = 1;
	dp[r][1] = 1;
	dp[r][2] = 0;
	bool flag1 = true,flag2 = false;
	int mm = INT_MAX;
	for(int i = map[r]; i ; i = edge[i].next){
		int v = edge[i].v;
		if(vis[v]) continue;
		dfs(v); flag2 = true;
		dp[r][0] += min(dp[v][0],dp[v][2]);
		dp[r][1] += min(dp[v][0],dp[v][1]);
		dp[r][2] += dp[v][1];
		if(dp[v][0] <= dp[v][1]) flag1 = false;
		else if(mm > dp[v][0] - dp[v][1]) mm = dp[v][0] - dp[v][1];
	}
	if(flag2){
		dp[r][1]--;
		if(flag1) dp[r][1] += mm;
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,n;
	while(true){
		memset(map,0,sizeof(map)); ep = 1;
		scanf("%d",&n);
		int a,b;
		for(i = 1; i < n; i++){
			scanf("%d%d",&a,&b);
			adde(a,b);adde(b,a);
		}
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
		dfs(1);
		printf("%d\n",min(dp[1][0],dp[1][1]));
		scanf("%d",&a); 
		if(a == -1) break;
	}
}