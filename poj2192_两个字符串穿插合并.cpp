#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MN = 202;
char stra[MN];
char strb[MN];
char strc[MN];
bool dp[MN][MN];

int main(){
	//freopen("in.txt","r",stdin);
	int i,j,t;
	scanf("%d",&t);
	for(int n = 1; n <= t; n++){		
		int lena = 0, lenb = 0;
		scanf("%s%s%s",stra,strb,strc);	
		memset(dp,0,sizeof(dp));
		dp[0][0] = true;
		lena = strlen(stra); lenb = strlen(strb);
		for(i = 0; i <= lena; i++){
			for(j = 0; j <= lenb; j++){
				if(i > 0 && dp[i - 1][j] && stra[i - 1] == strc[i + j - 1]){
					dp[i][j] = true;
				}
				if(j > 0 && dp[i][j - 1] && strb[j - 1] == strc[i + j - 1]){
					dp[i][j] = true;
				}
			}
		}
		printf("Data set %d: %s\n",n,dp[lena][lenb] ? "yes" : "no");
	}
	return 0;
}