#include<iostream>
using namespace std;
const int MN = 52;
struct{
	bool dir[4];//west,north,east,south.
}room[MN][MN];
bool visited[MN][MN];
int m,n,r;
void dfs(int x, int y){
	visited[x][y] = true;
	r++;
	if(!room[x][y].dir[0] && !visited[x][y - 1]){
		dfs(x,y - 1);
	}
	if(!room[x][y].dir[1] && !visited[x - 1][y]){
		dfs(x - 1,y);
	}
	if(!room[x][y].dir[2] && !visited[x][y + 1]){
		dfs(x,y + 1);
	}
	if(!room[x][y].dir[3] && !visited[x + 1][y]){
		dfs(x + 1,y);
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	int i,j,num,maxr;
	while(~scanf("%d%d",&m,&n)){
		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				scanf("%d",&num);
				if(num & 8) room[i][j].dir[3] = true;
				else room[i][j].dir[3] = false;
				
				if(num & 4) room[i][j].dir[2] = true;
				else room[i][j].dir[2] = false;
				
				if(num & 2) room[i][j].dir[1] = true;
				else room[i][j].dir[1] = false;
				
				if(num & 1) room[i][j].dir[0] = true;
				else room[i][j].dir[0] = false;
			}
		}
		memset(visited,false,sizeof(visited));
		maxr = 0;num = 0;
		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				if(!visited[i][j]){
					num++;
					r = 0;
					dfs(i,j);
					if(maxr < r) maxr = r;
				}
			}
		}
		printf("%d\n%d\n",num,maxr);
	}
	return 0;
}