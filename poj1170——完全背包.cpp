#include<iostream>
using namespace std;
const int INF = 1 << 30;
int dp[6][6][6][6][6];
int code[1010],num[6];
void init(){
	int i,j,k,x,y;
	for(i = 0; i <= 5; i++){
		for(j = 0; j <= 5; j++){
			for(k = 0; k <= 5; k++){
				for(x = 0; x <= 5; x++){
					for(y = 0; y <= 5; y++){
						dp[i][j][k][x][y] = INF;
					}
				}
			}
		}
	}
	dp[0][0][0][0][0] = 0;
}
void CompletePack(int p1,int p2,int p3,int p4,int p5,int weight){
	for(int i = p1; i <= 5; i++){
		for(int j = p2; j <= 5; j++){
			for(int k = p3; k <= 5; k++){
				for(int x = p4; x <= 5; x++){
					for(int y = p5; y <= 5; y++){
						dp[i][j][k][x][y] = min(dp[i][j][k][x][y],dp[i - p1][j - p2][k - p3][x - p4][y - p5] + weight);
					}
				}
			}
		}
	}
}
int main(){
	//freopen("in.txt","r",stdin);	
	int n,i,j,b,s,parm[6];
	init();
	memset(num,0,sizeof(num));
	scanf("%d",&b);
	for(i = 0; i < b; i++){
		memset(parm,0,sizeof(parm));
		scanf("%d%d%d",&s,num + i, parm + 5);
		code[s] = i;
		parm[i] = 1;
		CompletePack(parm[0],parm[1],parm[2],parm[3],parm[4],parm[5]);
	}
	scanf("%d",&s);
	for(i = 0; i < s; i++){
		scanf("%d",&n);
		memset(parm,0,sizeof(parm));
		int c,k;
		for(j = 0; j < n; j++){
			scanf("%d%d",&c,&k); 
			parm[code[c]] = k;
		}
		scanf("%d",parm + 5);
		CompletePack(parm[0],parm[1],parm[2],parm[3],parm[4],parm[5]);
	}
	printf("%d\n",dp[num[0]][num[1]][num[2]][num[3]][num[4]]);
	return 0;
}