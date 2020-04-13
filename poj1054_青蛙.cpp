#include<iostream>
#include<algorithm>
using namespace std;
const int MN = 5001;
int R,C;
bool map[MN][MN];
struct Node{
	int x,y;
	bool operator <(const Node n){
		if(x != n.x) return x < n.x;
		else return y < n.y;
	}
}a[MN];

inline int func(int x0, int y0, int dx, int dy){
	int X,Y,step = 2;
	X = x0 + dx;
	Y = y0 + dy;
	while(X <= R && Y >= 1 && Y <= C){
		if(!map[X][Y]) return 0;
		X += dx;
		Y += dy;
		step++;
	}
	return step;
}

int main(){
	//freopen("in.txt","r",stdin);
	int n,i,j,step,max = 2;
	int dx,dy,x0,y0;
	while(~scanf("%d%d%d",&R,&C,&n)){
		memset(map,0,sizeof(map));
		for(i = 0; i < n; i++){
			scanf("%d%d",&x0,&y0);
			a[i].x = x0;
			a[i].y = y0;
			map[x0][y0] = true; 
		}
		sort(a,a + n);
		for(i = 0; i < n - 1; i++){
			for(j = i + 1; j < n; j++){
				dx = a[j].x - a[i].x;
				dy = a[j].y - a[i].y;
				x0 = a[i].x - dx;
				y0 = a[i].y - dy;
				if(x0 >= 1&& y0 >= 1 && y0 <= C) continue;
				if(a[i].x + max * dx > R) break;
				y0 = a[i].y + max * dy;
				if(y0 < 1 || y0 > C) continue;
				step = func(a[j].x,a[j].y,dx,dy);
				if(step > max) max = step;

			}
		}
		if(max == 2) printf("0\n");
		else printf("%d\n",max);
	}
}