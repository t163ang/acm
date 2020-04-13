#include<iostream>
#include<cmath>
using namespace std;
const int MN = 50;
int len[MN];
bool dp[1602][1602];

int hailen(int a,int b, int c){
	double p = (a + b + c) / 2.0;
	int ans = 100 * sqrt((double)(p * (p - a) * (p - b) * (p - c)));
	return ans;
}
int main(){
	//freopen("in.txt","r",stdin);
	int n,i,j,k,mlen;
	while(~scanf("%d",&n)){
		mlen = 0;
		for(i = 0; i < n; i++){
			scanf("%d",len + i);
			mlen += len[i];
		}
		memset(dp,false,sizeof(dp));
		dp[0][0] = true;
		for(i = 0; i < n; i++){
			int L = len[i];
			for(j = mlen; j >= 0; j--){
				for(k = mlen - j; k >= 0; k--){
					if(!dp[j][k]){
						if(j >= L){
							dp[j][k] = dp[j][k] || dp[j - L][k];
						}
						if(k >= L){
							dp[j][k] = dp[j][k] || dp[j][k - L];
						}
					}	
				}
			}
		}

		int max = -1;
		for(j = 1; j < mlen; j++){
			for(k = 1; k < mlen - j -1; k++){
				i = mlen - j - k;
				if(dp[j][k] && i + j > k && i + k > j && k + j > i){			
					int h = hailen(i,j,k);
					if(max < h) max = h;
				}
			}
		}
		printf("%d\n",max);
	}
	return 0;
}