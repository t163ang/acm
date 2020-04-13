#include<iostream>
using namespace std;
const int MN = 10024;
const int INF = 1 << 30;
int value[MN];
int weight[MN];
int dp[MN];
int V;
inline void CompletePack(int cost,int weight){
	for(int i = cost; i <= V; i++){
		dp[i] = min(dp[i],dp[i - cost] + weight);
	}
}


int main(){
	//freopen("in.txt","r",stdin);
	int i,n,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&i,&V);
		V -= i;
		scanf("%d",&n);
		for(i = 0; i < n; i++){
			scanf("%d%d",value + i,weight + i);
		}

		dp[0] = 0;
		for(i = 1; i <= V; i++) dp[i] = INF;

		for(i = 0; i < n; i++){
			CompletePack(weight[i],value[i]);
		}
		if(dp[V] < INF) printf("The minimum amount of money in the piggy-bank is %d.\n",dp[V]);
		else printf("This is impossible.\n");
	}
	return 0;
}