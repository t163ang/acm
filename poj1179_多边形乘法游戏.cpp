#include<iostream>
using namespace std;
const int MN = 52;
int dp[MN][MN][2];
int inp[MN];
char inc[MN];

inline int compute(int a,char c, int b){
	if(c == 't') return a + b;
	else return a * b;
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,k;
	int n; char c;
	while(~scanf("%d\n",&n)){
		for(i = 0; i < n; i++){
			scanf(" %c %d",inc + i,inp + i);
		}

		for(i = 0; i < n; i++){
			dp[i][i][0] = dp[i][i][1] = inp[i];
		} 
		//由于出现负数，所以做乘法时，可能负负为正，变得最大，故要保存两个数最小和最大
		for(k = 1; k <= n - 1; k++){
			for(i = 0; i < n; i++){
				j = i + k;
				int maxx = -INT_MAX,tmp,minx = INT_MAX;
				for(int x = i; x < j; x++){
					tmp = compute(dp[i][x % n][0],inc[(x + 1) % n],dp[(x + 1)% n][j % n][0]);
					if(maxx < tmp) maxx = tmp;
					if(minx > tmp) minx = tmp;
					tmp = compute(dp[i][x % n][1],inc[(x + 1) % n],dp[(x + 1)% n][j % n][1]);
					if(maxx < tmp) maxx = tmp;
					if(minx > tmp) minx = tmp;
					tmp = compute(dp[i][x % n][0],inc[(x + 1) % n],dp[(x + 1)% n][j % n][1]);
					if(maxx < tmp) maxx = tmp;
					if(minx > tmp) minx = tmp;
					tmp = compute(dp[i][x % n][1],inc[(x + 1) % n],dp[(x + 1)% n][j % n][0]);
					if(maxx < tmp) maxx = tmp;
					if(minx > tmp) minx = tmp;
				}
				dp[i][j % n][0] = maxx;
				dp[i][j % n][1] = minx;
			}
		}

		int maxx = dp[0][n - 1][0];
		for(i = 1; i < n; i++){
			if(maxx < dp[i][(i + n - 1) % n][0]) maxx = dp[i][(i + n - 1) % n][0];
		}
		printf("%d\n",maxx);
		for(i = 0; i < n; i++){
			if(maxx == dp[i][(i + n - 1) % n][0]) printf("%d ",i + 1);
		}
		puts("");
	}
	return 0;
}