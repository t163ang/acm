#include<iostream>
using namespace std;
const int MN = 10024;
const int INF = 1 << 30;
int N,M,K;
int cost[20][120];
int value[20][120];
int amount[20];
int dp[20][MN];
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,k;
	while(~scanf("%d%d%d",&N,&M,&K)){
		memset(amount,0,sizeof(amount));
		for(i = 1; i <= N; i++){
			scanf("%d",&j);
			k = ++amount[j];
			scanf("%d%d",*(cost + j ) + k, *(value + j ) + k);		
		}

		for(k = 0; k <= K; k++){
			for(j = M; j >= 0; j--){
				dp[k][j] = -INF;
			}
		}
		dp[0][0] = 0;
		
		bool flag = false;
		for(k = 1; k <= K; k++){
			int a = amount[k];
			if(a <= 0) {flag = true; break;}
			for(i = 1; i <= a; i++){
				int c = cost[k][i],v = value[k][i];
				for(j = M; j >= c; j--){
					//dp[k][j] = max{dp[k][j],dp[k - 1][j - c] + v,dp[k][j - c] + v};
					if(dp[k][j - c] > -INF && dp[k][j - c] + v > dp[k][j]) dp[k][j] = dp[k][j - c] + v;
					if(dp[k - 1][j - c] > -INF && dp[k - 1][j - c] + v > dp[k][j]) dp[k][j] = dp[k - 1][j - c] + v;
				}
			}
		}
		
		int max = -INF;
		for(j = M; j >= 0; j--){
			if(max < dp[K][j]) max = dp[K][j];
		}
		if(max == -INF || flag) {
			printf("Impossible\n");
		}else{
			printf("%d\n",max);
		}
	}
	return 0;
}