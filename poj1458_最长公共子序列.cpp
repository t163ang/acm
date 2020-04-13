#include<iostream>
#include<algorithm>
using namespace std;
const int MN = 10000;
char stra[MN];
char strb[MN];
int dp[MN][MN];
int main(){
	//freopen("in.txt","r",stdin);
	while(~scanf("%s",stra)){
		scanf("%s",strb);
		int lena = strlen(stra), lenb = strlen(strb);
		for(int i = 0; i <= lena; i++) dp[i][lenb] = 0;
		for(int j = 0; j <= lenb; j++) dp[lena][j] = 0;
		for(int i = lena - 1; i >=0 ; i--){
			for(int j = lenb - 1; j >= 0; j--){
				if(stra[i] == strb[j]) dp[i][j] = dp[i + 1][j + 1] + 1;
				else dp[i][j] = max(dp[i + 1][j],dp[i][j + 1]);	
			}
		}
		printf("%d\n",dp[0][0]);
	}
	return 0;
}