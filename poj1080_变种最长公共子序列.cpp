#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MN = 102;
char stra[MN];
char strb[MN];
int dp[MN][MN];
int table[5][5] = {{5,-1,-2,-1,-3},{-1,5,-3,-2,-4},{-2,-3,5,-2,-2},{-1,-2,-2,5,-1},{-3,-4,-2,-1,0}};
int CC['Z'];
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,t;
	//将基因字母转化为table下标，并将空格定义了'B'
	CC['A'] = 0; CC['C'] = 1; CC['G'] = 2; CC['T'] = 3; CC['B'] = 4;
	scanf("%d",&t);
	while(t--){		
		int lena = 0, lenb = 0;
		scanf("%d%s%d%s",&lena,stra,&lenb,strb);	
		dp[lena][lenb] = 0;
		for(i = lenb - 1; i >= 0; i--){
			dp[lena][i] = dp[lena][i + 1] + table[ CC['B'] ][ CC[strb[i]] ];
		}
		for(i = lena - 1; i >= 0; i --){
			dp[i][lenb] = dp[i + 1][lenb] + table[ CC[stra[i]] ][ CC['B'] ];
		}
		for(i = lena - 1; i >=0 ; i--){
			for(j = lenb - 1; j >= 0; j--){
				dp[i][j] = max(dp[i + 1][j + 1] + table[ CC[stra[i]] ][ CC[strb[j]] ],
					max(dp[i + 1][j] + table[ CC[stra[i]] ][ CC['B'] ],dp[i][j + 1] + table[ CC['B'] ][ CC[strb[j]] ])); //复杂的table[CC[stra[]]]最好写一个函数
			}
		}
		printf("%d\n",dp[0][0]);

	}
	return 0;
}