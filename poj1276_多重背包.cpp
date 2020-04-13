#include<iostream>
using namespace std;
const int MN = 100024;
int value[MN];
int num[MN];
bool dp[MN];
int V;
void ZeroOnePack(int cost){
	for(int i = V; i >= cost; i--){
		dp[i] = dp[i] || dp[i - cost];
	}
}

void CompletePack(int cost){
	for(int i = cost; i <= V; i++){
		dp[i] = dp[i] || dp[i - cost];
	}
}

void MultiplePack(int cost, int amount){
	if(cost * amount >= V){
		CompletePack(cost);
		return;
	}
	int k = 1;
	while(k < amount){
		ZeroOnePack(k * cost);
		amount -= k;
		k *= 2;
	}
	ZeroOnePack(amount * cost);
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,n;
	while(~scanf("%d",&V)){
		scanf("%d",&n);
		for(i = 0; i < n; i++){
			scanf("%d%d",num + i,value + i);
		}

		dp[0] = true;
		for(i = 1; i <= V; i++) dp[i] = false;

		for(i = 0; i < n; i++){
			MultiplePack(value[i],num[i]);
		}

		for(i = V; i >= 0; i--){
			if(dp[i]) {
				printf("%d\n",i);
				break;
			}
		}

	}
	return 0;
}