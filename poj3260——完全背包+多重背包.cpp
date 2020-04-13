#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstdio>
using namespace std;
const int MN = 1200000;
const int INF = 1 << 30;
int V,dpSell[MN],dpBuy[MN];
int Amount[MN],Cost[MN];
void ZeroOnePack(int cost, int k){
	for(int j = V; j >= cost; j--){
		if(dpBuy[j - cost] + k < dpBuy[j]){
			dpBuy[j] = dpBuy[j - cost] + k;
		}
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	int n,t,i,j;
	while(~scanf("%d%d",&n,&t)){
		for(i = 0; i < n; i++){
			scanf("%d",Cost + i);
		}
		for(i = 0; i < n; i++){
			scanf("%d",Amount + i);
		}
		V = 10000;//这个上界不会求,看别人的解题报告写的
		dpSell[0] = 0;
		dpBuy[0] = 0;
		for(i = 1; i <= V; i++){
			dpSell[i] = INF;
			dpBuy[i] = INF;
		}
		//卖家完全背包
		for(i = 0; i < n; i++){
			int C = Cost[i];
			for(j = C; j <= V; j++){
				if(dpSell[j - C] + 1 < dpSell[j]){
					dpSell[j] = dpSell[j - C] + 1;
				}
			}
		}
		//买家多重背包
		for(i = 0; i < n; i++){
			int C = Cost[i],A = Amount[i],k = 1;
			while(k < A){
				ZeroOnePack(k * C,k);
				A -= k;
				k <<= 1;
			}
			ZeroOnePack(A * C,A);
		}
		int minn = INF;
		for(i = t; i <= V; i++){
			if(dpBuy[i] != INF && dpSell[i - t] != INF &&
				dpBuy[i] + dpSell[i - t] < minn){
				minn = dpBuy[i] + dpSell[i - t];
			}
		}
		if(minn == INF) puts("-1");
		else printf("%d\n",minn);
	}
	return 0;
}