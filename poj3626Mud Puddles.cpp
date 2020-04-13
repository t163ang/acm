#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
/*

Input
 
 (X, Y) (-500 ¡Ü X ¡Ü 500; -500 ¡Ü Y ¡Ü 500). He can see all N (1 ¡Ü N ¡Ü 10,000) 

* Line 1: Three space-separate integers: X, Y, and N.
* Lines 2..N+1: Line i+1 contains two space-separated integers: Ai and Bi

Output

* Line 1: The minimum distance that Farmer John has to travel to reach Bessie without stepping in mud.

Sample Input

1 2 7
0 2
-1 3
3 1
1 1
4 2
-1 1
2 2
Sample Output

11


*/
typedef struct Point{
	int x,y;
	int len;
	Point(int i, int j){
		x = i;
		y = j;
	}
}Point;
char a[1500][1500];
int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int x,y,n;


bool place(int x, int y){
	if(a[x][y] == '#') return false;
	if(x < 0|| x > 1000 || y < 0 || y > 1000) return false;
	return true;
}
int main(){	
	int i,j,k;
	queue<Point> que;
	while(scanf("%d%d%d",&x,&y,&n) != EOF){
		x += 500, y += 500;
		memset(a,0,sizeof(a));
		for(i = 0; i < n; i++){
			scanf("%d%d",&j,&k);
			a[j + 500][k + 500] = '#';
		}
		int x1,y1,x0,y0,len;
		Point point(500,500);
		point.len = 0;
		a[500][500] = '#';
		que.push(point);
		while(!que.empty()){
			point = que.front();
			que.pop();
			x1 = point.x;
			y1 = point.y;
			len = point.len;
			if(x1 == x && y1 == y) {
				printf("%d\n",len);
				break;
			}
			for(i = 0; i < 4; i++){
				x0 = x1 + dir[i][0];
				y0 = y1 + dir[i][1];			
				if(place(x0,y0)){
					a[x0][y0] = '#';
					point.x = x0;
					point.y = y0;
					point.len = len + 1;
					que.push(point);			
				}
			}
		}
	}
	

	return 0;
}