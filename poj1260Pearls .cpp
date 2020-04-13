#include<iostream>

//res[i] = min ( res[k] +(a[k+1]+a[k+2]+...+a[i]+10) ¡ÁP[i])£¬k=1,¡­.i-1;
//dp[i] = min(dp[k] + (sum[i] - sum[k] + 10) * p[i]) (dp[0] = 0,sum[0] = 0, 0 <= k <= i - 1) 
 int c;
int sum[200],a[200],p[200],dp[200];

int main(){
	int t,i,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&c);
		sum[0] = 0;
		for(i = 1; i <= c; i++){
			scanf("%d%d",&a[i],&p[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		dp[0] = 0;
		for(i = 1; i <= c; i++){
			dp[i] = (sum[i] + 10) * p[i];
			for( k = 1; k < i; k++){
				int tmp = dp[k] + (sum[i] - sum[k] + 10 ) * p[i];
				if(dp[i] > tmp) dp[i] = tmp;
			}
		}
		printf("%d\n",dp[c]);
	}
}
