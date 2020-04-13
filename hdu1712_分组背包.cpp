#include<iostream>
using namespace std;
const int MN = 108;
int A[MN][MN];
int dp[MN];//数组开小了在hdu不会runtime error而是wa的,poj数据开小了会runtime error的

int main(){
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k;
	memset(A,0,sizeof(A));
	while(scanf("%d%d",&n,&m),n + m){
		for(i = 1; i <= n; i++){
			for(j = 1; j <= m; j++){
				scanf("%d",*(A + i) + j);
			}
		}
		memset(dp,0,sizeof(dp));
		//注意这个是分组背包，例A[1][1] = 2,A[1][2] = 3,A[1][3] = 4,
		//虽然A[1][1] + A[1][2] > A[1][3]，分组背包选择后者，多重背包选择前2者相加。 
		//无论是分组背包还是多重背包，循环顺序都应是先背包后次数，不同在分组是选一个，多重选多个.
		for(i = 1; i <= n; i++){
			for(j = m; j >= 1; j--){//背包
				int max = 0;
				for(k = j; k >= 0;k--){ //天数
					if(max < dp[j - k] + A[i][k]) max = dp[j - k] + A[i][k];
				}
				dp[j] = max;
			}
		}
		printf("%d\n",dp[m]);
	}
	return 0;
}