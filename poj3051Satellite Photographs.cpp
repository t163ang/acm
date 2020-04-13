#include<iostream>
using namespace std;


#include<iostream>
using namespace std;
/*
Input
Sample Input

10 5
..*.....**
.**..*****
.*...*....
..****.***
..****.***
Sample Output

16

*/
int w,h;
char a[3000][200];
int tmp;
int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};

bool place(int x, int y){
	if(a[x][y] != '*')  return false;
	if(x <= 0 || x > h) return false;
	if(y <= 0 || y > w) return false;
	return true;
}


void dfs(int x, int y){
	a[x][y] = '.';
	tmp++;
	for(int i = 0; i < 4; i++){
		int x0 = x + dir[i][0];
		int y0 = y + dir[i][1];
		if(place(x0,y0)) dfs(x0,y0);
	}
}
int main(){
	int i,j;	
	while(scanf("%d%d",&w,&h) != EOF){
	//	memset(a,0,sizeof(a));
		for(i = 1; i <= h; i++){
			scanf("%s",a[i] + 1);	
		}
/*
		for(i = 1; i <= h; i++){
			for(j = 1; j <= w; j++){
				printf("%c ",a[i][j]);
			}
			puts("");
		}
*/
		int max = -1;
		for(i = 1; i <= h; i++){
			for(j = 1; j <= w; j++){
				if(a[i][j] == '*'){
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