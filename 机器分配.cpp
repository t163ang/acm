#include<iostream>
using namespace std;
const int MN = 124;
int w[MN][MN];
int dp[MN][MN];
int m = MN, n = MN;
int main(){
	freopen("in.txt","r",stdin);
	int i,j,k;
	while(~scanf("%d%d",&m,&n)){
		for(i = 1; i <= n; i++){
			for(j = 1; j <= m; j++){
				scanf("%d",&w[i][j]);
			}
		}
		memset(dp[0],0,sizeof(dp[0]));
		for(i = 1; i <= n; i++){
			dp[i][0] = 0;
			for(j = 1; j <= m; j++){
				for(int v = 0; v <= j; v++){
					int tmp =  dp[i - 1][v] + w[i][j - v];//下标所表示的变量具有无后性的 ， 可排序!!!
					if(dp[i][j] < tmp) dp[i][j] = tmp;//dp[next1][next2] = 做一选择{dp[无后性previous前一变量1][无后性前一变量2][。。。] + 状态转移} （其中选择：max or min or choice(w(i)权重或度量）
				}
			}
		}
		printf("%d\n",dp[n][m]);
	}
	return 0;
}