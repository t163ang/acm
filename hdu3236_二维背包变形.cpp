#include<iostream>
using namespace std;
const int MN = 308;
int TN = 1;
int V1,V2,n;
int price[MN];
int happy[MN];
int s[MN];
int dp0[508][58]; //没有免费,dp[i][j]代表花费(i,j)得到的最大价值。
int dp1[508][58]; //有且仅有一件免费的。

//这个问题有有必取和不必取,免费和不免费，不免费还分有coupon1和coupon2比较复杂,所以将它们分类讨论.
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int i,j,k;
	while(scanf("%d%d%d",&V1,&V2,&n),V1 + V2 + n){
		for(i = 0; i < n; i++){
			scanf("%d%d%d",price + i,happy + i, s + i);
		}
		memset(dp0,0,sizeof(dp0));
		memset(dp1,0,sizeof(dp1));

			//必取
		int tot = 0;
		for(i = 0; i < n; i++){		
			if(!s[i]) continue;//这里学识了，除了可以将不同类的分开存储，也可以同一存储，并加一判断位
			int cost = price[i],weight = happy[i];	
			tot += weight;
			for(j = V1; j >= 0; j--){
				for(k = V2; k >= 0; k--){
					//免费
					dp1[j][k] = dp0[j][k] + weight;
					//coupon1
					if(j >= cost){
						dp0[j][k] = dp0[j - cost][k] + weight;
						dp1[j][k] = max(dp1[j - cost][k] + weight,dp1[j][k]);
					}
					//coupon2
					if(k >= cost){
						dp0[j][k] = dp0[j][k - cost] + weight;
						dp1[j][k] = max(dp1[j][k - cost] + weight,dp1[j][k]);
					}
				}
			}
		}
		if(dp1[V1][V2] != tot) {
			printf("Case %d: ",TN++);
			printf("-1\n\n");
			continue;
		}
		
		//不必取
		for(i = 0; i < n; i++){		
			if(s[i]) continue;
			int cost = price[i],weight = happy[i];	
			for(j = V1; j >= 0; j--){
				for(k = V2; k >= 0; k--){
					//免费
					if(dp0[j][k] >= tot && dp0[j][k] + weight > dp1[j][k])
					dp1[j][k] = dp0[j][k] + weight;
					//coupon1
					if(j >= cost){
						if(dp0[j - cost][k] >= tot && dp0[j - cost][k] + weight > dp0[j][k]){
							dp0[j][k] = dp0[j - cost][k] + weight;
						}
						if(dp1[j - cost][k] >= tot && dp1[j - cost][k] + weight > dp1[j][k]){
							dp1[j][k] = dp1[j - cost][k] + weight;
						}						
					}
					//coupon2
					if(k >= cost){
						if(dp0[j][k - cost] >= tot && dp0[j][k - cost] + weight > dp0[j][k]){
							dp0[j][k] = dp0[j][k - cost] + weight;
						}
						if(dp1[j][k - cost] >= tot && dp1[j][k - cost] + weight > dp1[j][k]){
							dp1[j][k] = dp1[j][k - cost] + weight;
						}
					}
				}
			}
		}
		printf("Case %d: ",TN++);
		printf("%d\n\n",dp1[V1][V2]);
	}
	return 0;
}
