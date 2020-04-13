#include<iostream>
using namespace std;
const int MN = 50024;
int pass[MN];
int dp[3][MN];
int sum[MN];
int mn[MN];
int main(){
	//freopen("in.txt","r",stdin);
	int i,T,n,maxn;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i = 1,sum[0] = 0; i <= n; i++){
			scanf("%d",pass + i);
			sum[i] = sum[i - 1] + pass[i];
		}
		scanf("%d",&maxn);

		for(dp[0][maxn - 1] = 0,i = maxn; i <= n; i++){
			mn[i] = sum[i] - sum[i - maxn];
			dp[0][i] = max(mn[i],dp[0][i - 1]); //因为只要前面最大的.
		}

		for(i = 2 * maxn,dp[1][2 * maxn - 1] = 0; i <= n; i++){
			dp[1][i] = 	max(dp[1][i - 1],mn[i] + dp[0][i - maxn]);
		}
		int maxx = 0;
		for(i = 3 * maxn,dp[2][3 * maxn - 1] = 0; i <= n; i++){
			dp[2][i] = max(dp[2][i - 1],mn[i] + dp[1][i - maxn]);
			if(maxx < dp[2][i]) maxx = dp[2][i];
		}

		printf("%d\n",maxx);
	}
	return 0;
}