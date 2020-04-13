#include<iostream>
using namespace std;
int r,c,n;
char chart[12][12];
bool vis[12][12];
int step[12][12];
int dir['Z'][2];
void dfs(int x, int y, int s){
	if(x < 0 || x >= r || y < 0 || y >= c){
		printf("%d step(s) to exit\n",s);
		return;
	}else if(vis[x][y]){
		printf("%d step(s) before a loop of %d step(s)\n",step[x][y],s - step[x][y]);
		return;
	}
	vis[x][y] = true;
	step[x][y] = s;
	char c = chart[x][y];
	dfs(x + dir[c][0],y + dir[c][1],s + 1);
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j;
	dir['N'][0] = -1; dir['N'][1] = 0;
	dir['S'][0] = 1; dir['S'][1] = 0;
	dir['W'][0] = 0; dir['W'][1] = -1;
	dir['E'][0] = 0; dir['E'][1] = 1;
	while(scanf("%d%d%d",&r,&c,&n),r){
		for(i = 0; i < r; i++){
			scanf("%s",chart[i]);
		}
		memset(vis,0,sizeof(vis));
		memset(step,0,sizeof(step));
		dfs(0,n - 1,0);
	}
	return 0;
}