#include<iostream>
using namespace std;
const int INF = 1 << 30;
const int MN = 120;
int value[MN];
int cost[MN];
int dp[MN][MN]; // dp[怪物数][容耐度]，大小是最大经验值
int n,m,k,s;//经验值，保留的忍耐度，怪的种数和最多的杀怪数
int ans;
void inline CompletePack(int cost, int weight){
	for(int i = 1; i <= s; i++){
		for(int j = cost; j <= m; j++){
			dp[i][j] = max(dp[i][j],dp[i - 1][j - cost] + weight);
			if(dp[i][j] >= n){
				if(ans > j) ans = j;
			}
		}
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	int i;
	while(~scanf("%d%d%d%d",&n,&m,&k,&s)){
		for(i = 1; i <= k; i++){
			scanf("%d%d",value + i, cost + i);
		}
		memset(dp,0,sizeof(dp));
		for(i = 1,ans = INF; i <= k; i++){
			CompletePack(cost[i],value[i]);
		}
		if(ans < INF) printf("%d\n",m - ans);
		else printf("-1\n");
	}
}

