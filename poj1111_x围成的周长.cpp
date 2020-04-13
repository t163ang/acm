#include<iostream>
using namespace std;
const int MN = 24;
struct{
	int x,y;
}que[MN * MN];
int w,h,x,y;
char chart[MN][MN];
bool visited[MN][MN];
int bfs(int u,int v){
	int head = 0, tail = 0,ans = 0,x,y;
	memset(visited,0,sizeof(visited));
	visited[v][u] = true;
	que[tail].x = u;
	que[tail++].y = v;
	while(head != tail){
		x = que[head].x;
		y = que[head++].y;
		//上下左右
		if(x >= 1 && chart[y][x - 1] == 'X' && !visited[y][x - 1]){
			visited[y][x - 1] = true;
			que[tail].x = x - 1;
			que[tail++].y = y;
		}else if(x >= 1 && chart[y][x - 1] == '.' || x == 0){
			ans++;
		}

		if(x + 1 < w && chart[y][x + 1] == 'X' && !visited[y][x + 1]){
			visited[y][x + 1] = true;
			que[tail].x = x + 1;
			que[tail++].y = y;
		}else if(x + 1 < w && chart[y][x + 1] == '.' || x + 1 == w){
			ans++;
		}

		if(y >= 1 && chart[y - 1][x] == 'X' && !visited[y - 1][x]){
			visited[y - 1][x] = true;
			que[tail].x = x;
			que[tail++].y = y - 1;
		}else if(y >= 1 && chart[y - 1][x] == '.' || y == 0){
			ans++;
		}

		if(y + 1 < h && chart[y + 1][x] == 'X' && !visited[y + 1][x]){
			visited[y + 1][x] = true;
			que[tail].x = x;
			que[tail++].y = y + 1;
		}else if(y + 1 < h && chart[y + 1][x] == '.' || y + 1 == h){
			ans++;
		}
		//对角
		if(x >= 1 && y >= 1 && chart[y - 1][x - 1] == 'X' && !visited[y - 1][x - 1]){
			visited[y - 1][x - 1] = true;
			que[tail].x = x - 1;
			que[tail++].y = y - 1;
		}

		if(x + 1 < w && y + 1 < h && chart[y + 1][x + 1] == 'X' && !visited[y + 1][x + 1]){
			visited[y + 1][x + 1] = true;
			que[tail].x = x + 1;
			que[tail++].y = y + 1;
		}

		if(x >= 1 && y + 1 < h && chart[y + 1][x - 1] == 'X' && !visited[y + 1][x - 1]){
			visited[y + 1][x - 1] = true;
			que[tail].x = x - 1;
			que[tail++].y = y + 1;
		}

		if(x + 1 < w && y >= 1 && chart[y - 1][x + 1] == 'X' && !visited[y - 1][x + 1]){
			visited[y - 1][x + 1] = true;
			que[tail].x = x + 1;
			que[tail++].y = y - 1;
		}
	}
	return ans;
}
//题目要抽象了再检查是否漏掉需求
int main(){
	//freopen("in.txt","r",stdin);
	while(scanf("%d%d%d%d",&h,&w,&y,&x),w + h + x + y){//rows,cols对应的是h,w和y,x
		memset(chart,0,sizeof(chart));
		for(int i = 0; i < h; i++){
			scanf("%s",chart[i]);
		}
		printf("%d\n",bfs(x - 1,y - 1));
	}
	return 0;
}