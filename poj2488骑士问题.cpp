#include<iostream>
#include<queue>
#include<utility>

//输出要注意 字典序 因此搜索顺序要弄好！
int dx[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
int dy[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
char pathy[30];
int  pathx[30];
int n,p,q;
int pat, tot;
bool find;
int visited[30][30];
void dfs(int x, int y){
	if(find || visited[x][y] || x < 0 || x >= p || y < 0 || y >= q) return;
	visited[x][y] = 1;
	pathx[pat] = x, pathy[pat++] = y + 'A';
	if(pat >= tot){
		find = true;
		for(int j = 0; j < pat; j++){
			printf("%c%d",pathy[j],pathx[j] + 1);
		}
		puts("");
	}
	for(int i = 0; i < 8; i++){
		dfs(x + dx[i], y + dy[i]);
	}
	pat--;
	visited[x][y] = 0;
}

//
//bool dfs(int x, int y){
//	if(visited[x][y] || x < 0 || x >= p || y < 0 || y >= q) return false;
//	visited[x][y] = 1;
//	pathx[pat] = x, pathy[pat++] = y + 'A';
//	if(pat >= tot){
//		for(int j = 0; j < pat; j++){
//			printf("%c%d",pathy[j],pathx[j] + 1);
//		}
//		puts("");
//		return true;
//	}
//	for(int i = 0; i < 8; i++){
//		if(dfs(x + dx[i], y + dy[i])) return true;
//	}
//	pat--;
//	visited[x][y] = 0;
//	return false;
//}

//#define PAIR std::pair<int,int> 
//bool place(int x, int y){
//	if(visited[x][y] || x < 0 || x >= p || y < 0 || y >= q) return false;
//	return true;
//}
//void bfs(){
//	std::queue<PAIR > que; 
//	que.push(PAIR(0,0));
//	visited[0][0] = true;
//	while(!que.empty()){
//		int x = que.front().first, y = que.front().second;
//		que.pop();
//		pathx[pat] = x, pathy[pat++] = y + 'A';
//		for(int j = 0; j < 8; j++){
//			int x2 = x + dx[j], y2 = y + dy[j];
//			if(place(x2,y2)) {
//				visited[x2][y2] = 1;
//				que.push(PAIR(x2,y2));
//			}
//		}
//	}
//	if(pat < tot) return;
//	else find = true;
//	for(int j = 0; j < pat; j++){
//		printf("%c%d",pathy[j],pathx[j] + 1);
//	}
//	puts("");
//}

int main(){
	int i;
	scanf("%d",&n);
	for(i = 1; i <= n; i++){
		scanf("%d%d",&p,&q);
		memset(visited,0,sizeof(visited));
		pat = 0, tot = p * q;
		find = false;
		printf("Scenario2 #%d:\n",i);
		dfs(0,0);
		//bfs();
		if(!find)  printf("impossible\n");	
		puts("");
	}

}
