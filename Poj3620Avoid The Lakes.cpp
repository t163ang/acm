#include<iostream>
using namespace std;
/*
Input

  * Line 1: Three space-separated integers: N, M, and K
  * Lines 2..K+1: Line i+1 describes one submerged location with two space separated integers that are its row and column: R and C
  
	Output
	
	  * Line 1: The number of cells that the largest lake contains.¡¡
	  
		Sample Input
		
		  3 4 5
		  3 2
		  2 2
		  3 1
		  2 3
		  1 1
*/
int n,m,k;
int a[300][300];
int tmp;
int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};

bool place(int x, int y){
	if(!a[x][y]) return false;
	if(x <= 0 || x > n) return false;
	if(y <= 0 || y > m) return false;
	return true;
}


void dfs(int x, int y){
	a[x][y] = 0;
	tmp++;
	for(int i = 0; i < 4; i++){
		int x0 = x + dir[i][0];
		int y0 = y + dir[i][1];
		if(place(x0,y0)) dfs(x0,y0);
	}
}
int main(){
	int i,j;
	
	while(scanf("%d%d%d",&n,&m,&k) != EOF){
		memset(a,0,sizeof(a));
		for(i = 1; i <= k; i++){
			int x,y;
			scanf("%d%d",&x,&y);
			a[x][y] = 1;	
		}
/*
		for(i = 1; i <= n; i++){
			for(j = 1; j <= m; j++){
				printf("%d ",a[i][j]);
			}
			puts("");
		}
*/
		int max = -1;
		for(i = 1; i <= n; i++){
			for(j = 1; j <= m; j++){
				if(a[i][j]){
					tmp = 0;
					dfs(i,j);
					max = max > tmp ? max : tmp;
				}
			}
		}
		printf("%d\n",max);	
	}
	return 0;
	
}