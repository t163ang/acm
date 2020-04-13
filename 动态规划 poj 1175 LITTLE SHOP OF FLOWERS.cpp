#include<iostream>
using namespace std;
const int MN = 1024;
int dp[MN];
int inp[MN][MN];
int main(){
	//freopen("in.txt","r",stdin);
	int f,v,i,j,max;
	while(~scanf("%d%d",&f,&v)){
		for(i = 1; i <= f; i++){
			for(j = 1; j <= v; j++){
				scanf("%d",*(inp + i) + j);
			}
		}
		memset(dp,0,sizeof(dp));
		for(i = 1; i <= f; i++){
			for(int k = v; k >= i; k--){
				max = -INT_MAX;//注意有负数
				for(int s = i - 1; s < k; s++){
					if(max < dp[s] + inp[i][k]) max = dp[s] + inp[i][k];
				}
				dp[k] = max;
			}
		}
		max = -INT_MAX; 
		for(i = f; i <= v; i++) {
			if(max < dp[i]) max = dp[i];
		}
		printf("%d\n",max);
	}
}