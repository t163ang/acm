#include<iostream>
using namespace std;

const int INF = 1 << 30;
const int MN = 1121;
int dp[20][MN];
int pr[MN],pn;
bool notp[MN];
int N,V;
void inline getPrime(){
	int i,j;
	memset(notp,0,sizeof(notp));
	pn = 0;	
	for(i = 2; i < MN; i++){
		if(!notp[i]) pr[pn++] = i;
		for(j = 0; j < pn && pr[j] * i < MN; j++){
			notp[i * pr[j]] = true;
			if(i % pr[j] == 0) break;
		}
	}
}


void inline ZeroOnePack(int cost){
	for(int i = 14; i >= 1; i--){
		for(int j = 1120; j >= cost; j--){
			dp[i][j] += dp[i - 1][j - cost]; //这种计算有多少方法可以到达dp[i][j]值得注意
		}
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	int i;
	getPrime();	
	memset(dp,0,sizeof(dp));
	dp[0][0] = 1;
	for(i = 0;i < pn; i++){
		ZeroOnePack(pr[i]);
	}
	while(scanf("%d%d",&V,&N),V + N){
		printf("%d\n",dp[N][V]);
	}	
	return 0;
}

