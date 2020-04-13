#include<iostream>
using namespace std;
const int MN = 124;
const int ML = 1024;
const int INF = 1 << 30;
int time[MN];
int weight[MN];
int dp[MN][ML];
int N,M,L;

void inline ZeroOnePack(int cost,int weight){
	for(int i = M; i >= 1; i--){
		for(int j = L; j >= cost; j--){		
			if(dp[i - 1][j - cost] > -INF && dp[i - 1][j - cost] + weight > dp[i][j]){
				dp[i][j] = dp[i - 1][j - cost] + weight;
			}
		}
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&N,&M,&L);
		for(i = 0; i < N; i++){
			scanf("%d%d",time + i,weight + i);
		}
		for(i = 0; i <= M; i++){
			for(j = 0; j <= L; j++){
				dp[i][j] = -INF;
			}
		}
		dp[0][0] = 0;
		for(i = 0; i < N; i++){
			ZeroOnePack(time[i],weight[i]);
		}
		int max = 0;
		for(i = 0; i <= L; i++){
			if(max < dp[M][i]) max = dp[M][i];
		}
		printf("%d\n",max);
	}
	return 0;
}