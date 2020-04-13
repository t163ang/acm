/*
刚开始，以为可以用贪心做，即从大到小排个序，每次分配最大至使用时间最小的那个
但后来发现这样做是不能求最优解的，事实上，NP问题的多机调度就是使用这种贪心方法求
近似最优解。
比如4 3 3 2 2 2,如果贪心则会得出是4 + 2 和 3 + 3 + 2,而最优解显然是4 + 3, 3 + 2 + 2
这题可以看做最优二机调度最优解，使用dp求每种color花费最接近总时间的一半，即使两
机分配的时间最可能均等，这样总时间最小。
*/
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<cstdio>
using namespace std;
map<string,int> hash;
int chart[20][200];
int sum[20];
bool dp[50 * 1001];
int main(){
	//freopen("in.txt","r",stdin);
	int m,n,i,j,k,t;
	char col[30];
	while(scanf("%d%d",&m,&n),m + n){
		for(i = 0; i < m; i++){
			scanf("%s",col);
			hash[col] = i;
			chart[i][0] = 0;
			sum[i] = 0;
		}
		for(i = 0; i < n; i++){
			scanf("%d%s",&t,&col);
			int tmp = hash[col];
			int cnt = ++chart[tmp][0];
			chart[tmp][cnt] = t;
			sum[tmp] += t;
		}
		int ans = 0;
		for(i = 0; i < m; i++){
			int V = sum[i] >> 1;
			for(j = 0; j <= V;j++){
				dp[j] = false;
			}
			dp[0] = true;
			int cnt = chart[i][0];
			for(j = 1; j <= cnt; j++){
				int C = chart[i][j];
				for(k = V; k >= C; k--){
					dp[k] = dp[k] || dp[k - C];
				}
			}
			for(k = V; k >= 0; k--){
				if(dp[k]){
					ans += sum[i] - k;
					break;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}