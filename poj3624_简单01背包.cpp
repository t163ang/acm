#include<iostream>
using namespace std;
const int MN = 12884;
int dp[MN];
int cost[MN];
int weight[MN];
int V;
inline void ZeroOnePack(int cost,int weight){
	for(int i = V; i >= cost; i--){
		dp[i] = max(dp[i],dp[i - cost] + weight);
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	int i,n,m;
	scanf("%d%d",&n,&V);
	for(i = 0; i < n; i++){
		scanf("%d%d",cost + i,weight + i);
	}
	for(i = 0; i <= V; i++) dp[i] = 0;
	for(i = 0; i < n; i++){
		ZeroOnePack(cost[i],weight[i]);
	}
	printf("%d\n",dp[V]);
	return 0;
}