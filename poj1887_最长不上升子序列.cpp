#include<iostream>
using namespace std;
const int MN = 1000;
int dp[MN];
int TC = 1;
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int n,len;
	while(scanf("%d",&n), n != -1){
		//memset(dp,0,sizeof(dp));
		len = 0;
		dp[++len] = n;
		while(scanf("%d",&n), n != -1){
			if(n < dp[len]) dp[++len] = n;
			else{
				int L = 1, R = len, mid;
				while(L <= R){
					int mid = (L + R) >> 1;
					if(dp[mid] > n) L = mid + 1;
					else R = mid - 1;
				}
				dp[L] = n;
			}
		}
		printf("Test #%d:\n  maximum possible interceptions: %d\n\n",TC++,len);
	}
	return 0;
}