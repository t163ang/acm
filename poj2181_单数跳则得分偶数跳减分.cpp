#include<iostream>
using namespace std;
const int MN =  150024;
int dp[MN][2];
int potion[MN];
int main(){
	//freopen("in.txt","r",stdin);
	int i,p;
	while(~scanf("%d",&p)){
		for(i = 1; i <= p; i++){
			scanf("%d",potion + i);
		}
		dp[0][0] = 0;
		dp[0][1] = 0;
		for(i = 1; i <= p; i++){
			dp[i][0] = max(dp[i - 1][0],dp[i - 1][1] - potion[i]);
			dp[i][1] = max(dp[i - 1][1],dp[i - 1][0] + potion[i]);
		}
		printf("%d\n",max(dp[p][0],dp[p][1]));
	}
}