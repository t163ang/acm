#include<iostream>
using namespace std;
const int MN = 21;
int N,M,L,CT = 1,B; //B只是用作移位个数
bool stone[MN][MN];
bool body[MN][MN]; //被body覆盖的
bool state[MN][MN][1 << 14]; //用位来表示状态，判断状态时就可以直接比较

struct Node{
	int x,y,z,step;
	void set(int a, int b, int c,int s){
		x = a;
		y = b;
		z = c;
		step = s;
	}
}node;
/*
z为当前蛇的状态，dir为移动方向:上00,下10,左11,右01
返回移动后方向.
*/
int move(int z,int dir){
	dir <<= B;
	z >>= 2;
	z |= dir;
	return z;
}
void setBody(int x, int y, int z){
	memset(body,false,sizeof(body));
	body[x][y] = true;
	for(int i = B; i >= 0; i -= 2){
		int b = z & (3 << i);
		b >>= i;
		if(b == 0){
			x--;
		}else if(b == 1){
			y++;
		}else if(b == 2){
			x++;
		}else{
			y--;
		}
		body[x][y] = true;
	}
}
Node que[MN * MN * (1 << 14)];
int qh,qt,sx,sy,sz;
void bfs(){
	qh = qt = 0;
	node.set(sx,sy,sz,0);
	que[qt++] = node;
	while(qh != qt){
		node = que[qh++];
		int x = node.x, y = node.y,z = node.z,s = node.step;
		setBody(x,y,z);	
		if(x > 1 && !stone[x - 1][y] && !body[x - 1][y]){		
			if(x == 2 && y == 1){
				printf("%d\n",s + 1);
				return;
			}
			int tmpz = move(z,2);
			if(!state[x - 1][y][tmpz]){
				state[x - 1][y][tmpz] = true;
				node.set(x - 1,y,tmpz,s + 1);
				que[qt++] = node;
			}
		}

		if(y > 1 && !stone[x][y - 1] && !body[x][y - 1]){
			if(y == 2 && x == 1){
				printf("%d\n",s + 1);
				return;
			}
			int tmpz = move(z,1);
			if(!state[x][y - 1][tmpz]){
				state[x][y - 1][tmpz] = true;
				node.set(x,y - 1,tmpz,s + 1);
				que[qt++] = node;
			}
		}

		if(x < N && !stone[x + 1][y] && !body[x + 1][y]){
			int tmpz = move(z,0);
			if(!state[x + 1][y][tmpz]){
				state[x + 1][y][tmpz] = true;
				node.set(x + 1,y,tmpz,s + 1);
				que[qt++] = node;
			}
		}

		if(y < M && !stone[x][y + 1] && !body[x][y + 1]){
			int tmpz = move(z,3);
			if(!state[x][y + 1][tmpz]){
				state[x][y + 1][tmpz] = true;
				node.set(x,y + 1,tmpz,s + 1);
				que[qt++] = node;
			}
		}
	}
	printf("-1\n");
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,x,y,s;
	while(scanf("%d%d%d",&N,&M,&L),N){
		B = (L - 2) << 1;
		scanf("%d%d",&sx,&sy);
		int px = sx, py = sy;
		for(i = 1,sz = 0; i < L; i++){
			scanf("%d%d",&x,&y);			
			sz <<= 2;
			//上00,下10,左01,右11
			if(x > px) sz |= 2;
			if(y < py) sz |= 3;
			if(y > py) sz |= 1;
			px = x; py = y;
		}
		memset(state,0,sizeof(state));
		state[sx][sy][sz] = true;
		scanf("%d",&s);
		memset(stone,0,sizeof(stone));
		for(i = 0; i < s; i++){
			scanf("%d%d",&x,&y);
			stone[x][y] = true;
		}
		printf("Case %d: ",CT++);
		if(sx == 1 && sy == 1) printf("0\n");
		else bfs();
	}

	return 0;
}