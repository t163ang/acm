#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MN = 5002;
char stra[MN];
char strb[MN];
int dp[2][MN];
int main(){
	freopen("in.txt","r",stdin);
	int i,j,n;
	while(~scanf("%d",&n)){		
		scanf("%s",stra);
		for(i = 0; i < n; i++) strb[n - 1 - i] = stra[i];
		int lena = n, lenb = n;
		memset(dp,0,sizeof(dp));
		for(i = lena - 1; i >=0 ; i--){
			for(j = lenb - 1; j >= 0; j--){
				int i2 = i & 1, i3 = !i2;
				if(stra[i] == strb[j]) dp[i2][j] = dp[i3][j + 1] + 1;
				else dp[i2][j] = max(dp[i3][j],dp[i2][j + 1]);	
			}
		}
		printf("%d\n",n - dp[0][0]);

	}
	return 0;
}