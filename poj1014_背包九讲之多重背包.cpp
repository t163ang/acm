#include<iostream>
using namespace std;
const int MN = 20000 * 6 + 300;
int inp[10];
int V;
bool dp[MN];
int TestCnt = 1;
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
	int i;
	while(true){
		bool flag = true;
		V = 0;
		for(i = 1; i <= 6; i++){
			scanf("%d",inp + i);
			if(inp[i] > 0) flag = false;
			V += i * inp[i];
		}
		if(flag) break;
		if(V & 1){
			printf("Collection #%d:\n",TestCnt++);
			printf("Can't be divided.\n\n");
			continue;
		}
		V =  V >> 1;
		dp[0] = true;
		for(i = 1; i <= V; i++){
			dp[i] = false;
		}
		for(i = 1; i <= 6; i++){
			if(inp[i] > 0){
				MultiplePack(i,inp[i]);
			}
		}
		printf("Collection #%d:\n",TestCnt++);
		if(dp[V]) printf("Can be divided.\n\n");
		else printf("Can't be divided.\n\n");
	}
	return 0;
}