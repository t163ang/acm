#include<iostream>
using namespace std;
const int MN = 200004;
const int BASE = 100000;
const int INF = 1 << 30;
int dp[MN];
int S[105];
int F[105];
int V;
int L;
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,n;
	while(~scanf("%d",&n)){

		for(i = 0,V = 0; i < n; i++){
			scanf("%d%d",S + i,F + i);
			if(S[i] > 0)
				V += S[i];
			if(S[i] < 0)
				L += S[i];
		}
		for(i = 0; i < MN; i++){
			dp[i] = -INF;
		}	

		dp[BASE] = 0;

		for(i = 0; i < n; i++){
			int cost = S[i];
			if(cost > 0){
				//计算至L因为有负数，当dp[i]的i值有效范围是0 - V
				for(j = V; j >= L; j--){ 
					int x = BASE + j;
					if(dp[x - cost] > -INF){
						if(dp[x - cost] + F[i] > dp[x]){
							dp[x] = dp[x - cost] + F[i];
						}
					}
				}
			}else{
				for(j = L; j <= V ; j++){
					int x = BASE + j;
					if(dp[x - cost] > -INF){
						if(dp[x - cost] + F[i] > dp[x]){
							dp[x] = dp[x - cost] + F[i];
						}
					}
				}
			}
		}
		int maxx = 0;
		for(i = V;i >= 0;i--){
			int x = BASE + i;
			if(dp[x] >= 0 && maxx < dp[x] + i){
				maxx = dp[x] + i;
			}
		}
		printf("%d\n",maxx);
	}
	return 0;
}

