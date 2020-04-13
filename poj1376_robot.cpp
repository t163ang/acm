#include<iostream>
#include<queue>
using namespace std;
const int MN = 52;
bool map[MN][MN];
int m,n,sx,sy,dx,dy;
int state[MN][MN][4];
int dirx[4] ={-1,0,1,0};
int diry[4] ={0,1,0,-1};
int dl[4] = {3,0,1,2};
int dr[4] = {1,2,3,0};
struct Node{
	int x,y,d,step;
	void set(int a, int b, int c,int s){
		x = a;
		y = b;
		d = c;
		step = s;
	}
}node;
queue<Node> que;
inline bool place(int x, int y){
	return (x > 0 && x < m && y > 0 && y < n);
}
void bfs(){
	while(!que.empty()) que.pop();
	que.push(node);
	while(!que.empty()){
		node = que.front(); que.pop();
		int x = node.x, y = node.y, d = node.d, s = node.step;
		if(x == dx && y == dy){
			printf("%d\n",s);
			return;
		}
		int px = x, py = y;
		for(int i = 1; i <= 3; i++){
			px += dirx[d]; py += diry[d];
			if(map[px][py]) break;
			if(place(px,py) && !state[px][py][d]){
				node.set(px,py,d,s + 1);
				state[px][py][d] = true;
				que.push(node);
			}
		}
		if(!state[x][y][ dl[d] ]){
			node.set(x,y,dl[d],s + 1);
			state[x][y][ dl[d] ] = true;
			que.push(node);
		}

		if(!state[x][y][ dr[d] ]){
			node.set(x,y,dr[d],s + 1);
			state[x][y][ dr[d] ] = true;
			que.push(node);
		}
	}
	printf("-1\n");
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,c;
	while(scanf("%d%d",&m,&n),m || n){
		memset(map,0,sizeof(map));
		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				scanf("%d",&c);
				if(c == 1){ //将复合图转换成单一图
					map[i][j] = true;
					map[i + 1][j] = true;
					map[i][j + 1] = true;
					map[i + 1][j + 1] = true;
				}
			}
		}
		char dir[10];
		scanf("%d%d%d%d %s",&sx,&sy,&dx,&dy,dir);
		if(dir[0] == 'n') i = 0;
		else if(dir[0] == 'e') i = 1;
		else if(dir[0] == 's') i = 2;
		else i = 3;
		memset(state,0,sizeof(state));
		node.set(sx,sy,i,0);
		state[sx][sy][i] = true;
		bfs();
	}
}