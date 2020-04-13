#include<iostream>
using namespace std;
const int MN = 102;
int area[MN][MN];
int dp[MN][MN];
bool vis[MN][MN];
bool visited[MN][MN];
int ans;
int dfs(int i, int j){
	int tmp,max = 0;
	if(area[i][j] > area[i - 1][j]){
		if(vis[i - 1][j]) tmp = dp[i - 1][j];
		else  tmp = dfs(i - 1, j);
		max = max > tmp ? max : tmp;
	}

	if(area[i][j] > area[i + 1][j]){
		if(vis[i + 1][j]) tmp = dp[i + 1][j];
		else tmp = dfs(i + 1, j);
		max = max > tmp ? max : tmp;
	}

	if(area[i][j] > area[i][j - 1]){
		if(vis[i][j - 1]) tmp = dp[i][j - 1];
		else tmp = dfs(i, j - 1);
		max = max > tmp ? max : tmp;
	}

	if(area[i][j] > area[i][j + 1]){
		if(vis[i][j + 1]) tmp = dp[i][j + 1];
		else tmp = dfs(i, j + 1);
		max = max > tmp ? max : tmp;
	}

	dp[i][j] = max + 1;
	vis[i][j] = true;
	if(ans <= max) ans = max + 1;
	return (max + 1);
}
int main(){
	//freopen("in.txt","r",stdin);
	int r,c;
	int i,j;
	scanf("%d%d",&r,&c);
	for(i = 1; i <= r; i++){
		for(j= 1; j <= c; j++){
			scanf("%d",*(area + i) + j);
		}
	}
	memset(vis,0,sizeof(vis));
	memset(dp,0,sizeof(dp));

	ans = -1;
	//四周围一周高度为0的区域，简化判断
	for(i = 1; i <= c; i++) {
		vis[0][i] = true;
		vis[r + 1][i] = true;
	}
	for(i = 0; i <= r + 1; i++){
		vis[i][0] = true;
		vis[i][c + 1] = true;
	}
	//深搜了,因为是连通的，所心一次dfs即可
	for(i = 1; i <= r; i++){
		for(j = 1; j <= c; j++){
			if(!vis[i][j]){
				dfs(i,j);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}