#include<iostream>
using namespace std;
const int MN = 80;
struct{
	int x,y;
}pre[MN][MN];
char map[MN][MN];
int quex[MN * MN],head,tail;
int quey[MN * MN];
bool visited[MN][MN];
int w,h,x1,y1,x2,y2,T;
bool bfs(){
	int u,v,x,y;
	memset(visited,0,sizeof(visited));
	visited[x1][y1] = true;
	head = tail = 0;
	quex[tail] = x1; 
	quey[tail++] = y1;
	while(head != tail){
		u = quex[head];
		v = quey[head++];

		x = u; y = v;
		while(y >= 1 && !visited[x][y - 1] && map[y - 1][x] != 'X'){				
			y--;
			quex[tail] = x;
			quey[tail++] = y;
			visited[x][y] = true;
			pre[x][y].x = u;
			pre[x][y].y = v;
			if(x == x2 && y == y2) {
				return true;
			}
		}

		x = u; y = v;
		while(y <= h && !visited[x][y + 1] && map[y + 1][x] != 'X'){
			y++;
			quex[tail] = x;
			quey[tail++] = y;
			visited[x][y] = true;
			pre[x][y].x = u;
			pre[x][y].y = v;
			if(x == x2 && y == y2){
				return true;
			}
		}
		
		x = u; y = v;
		while(x <= w && !visited[x + 1][y]  && map[y][x + 1] != 'X'){
			x++;
			quex[tail] = x;
			quey[tail++] = y;
			visited[x][y] = true;
			pre[x][y].x = u;
			pre[x][y].y = v;
			if(x == x2 && y == y2){
				return true;
			}		
		}

		x = u; y = v;
		while(x >= 1 && !visited[x - 1][y]  && map[y][x - 1] != 'X'){
			x--;
			quex[tail] = x;
			quey[tail++] = y;
			visited[x][y] = true;
			pre[x][y].x = u;
			pre[x][y].y = v;
			if(x == x2 && y == y2){
				return true;
			}			
		}
	}
	return false;
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j;
	while(scanf("%d%d",&w,&h),w + h){
		memset(map,' ',sizeof(map));
		getchar();
		for(i = 1; i <= h; i++){
			for(j = 1; j <= w; j++){
				scanf("%c",*(map + i) + j);
			}
			getchar();
		}
		int k = 1,seg,tmp;
		printf("Board #%d:\n",++T);
		while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2),x1 + x2 + y1 + y2){
			map[y2][x2] = ' ';
			if(bfs()) {
				seg = 0; i = x2; j = y2;
				while(j != y1 || i != x1){
					tmp = pre[i][j].y;
					i = pre[i][j].x;
					j = tmp;
					seg++;
				}
				printf("Pair %d: %d segments.\n",k++,seg);
			}else {
				printf("Pair %d: impossible.\n",k++);
			}
			map[y2][x2] = 'X';
		}
		puts("");
	}
	return 0;
}