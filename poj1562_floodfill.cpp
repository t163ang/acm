#include<iostream>
using namespace std;
const int MN = 102;
char chart[MN][MN];
bool vis[MN][MN];
int m,n;
void dfs(int i, int j){
	vis[i][j] = true;
	if(i > 0 && !vis[i - 1][j] && chart[i - 1][j] == '@'){
		dfs(i - 1,j);
	}
	if(i < m - 1 && !vis[i + 1][j]&& chart[i + 1][j] == '@'){
		dfs(i + 1,j);
	}
	if(j > 0 && !vis[i][j - 1]&& chart[i][j - 1] == '@'){
		dfs(i,j - 1);
	}
	if(j < n - 1 && !vis[i][j + 1]&& chart[i][j + 1] == '@'){
		dfs(i,j + 1);
	}
	
	if(i > 0 && j > 0 && !vis[i - 1][j - 1] && chart[i - 1][j - 1] == '@'){
		dfs(i - 1,j - 1);
	}
	
	if(i > 0 && j < n - 1 && !vis[i - 1][j + 1] && chart[i - 1][j + 1] == '@'){
		dfs(i - 1, j + 1);
	}
	if(i < m - 1 && j > 0 && !vis[i + 1][j - 1] && chart[i + 1][j - 1] == '@'){
		dfs(i + 1, j - 1);
	}
	if(i < m - 1 && j < n - 1 && !vis[i + 1][j + 1] && chart[i + 1][j + 1] == '@'){
		dfs(i + 1, j + 1);
	}

}
int main(){
	//freopen("in.txt","r",stdin);
	while(scanf("%d%d",&m,&n),m){
		for(int i = 0; i < m; i++){
			scanf("%s",chart[i]);
		}
		int ans = 0;
		memset(vis,0,sizeof(vis));
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(!vis[i][j] && chart[i][j] == '@'){
					ans++;
					dfs(i,j);
				}
			}
		}
		printf("%d\n",ans);
	}

}