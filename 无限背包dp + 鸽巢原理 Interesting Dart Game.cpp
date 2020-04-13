#include<iostream>
#include<algorithm>
using namespace std;
const int MN = 11000;
int m,n;
int arr[102];
int dp[MN];
//设可选的N 个数从小到大依次为a(1)、a(2) … a(N)，则在最优的取法中，小于a(N) 的数不会多于a(N) 个。
// n个数a1,a2...an,1个c 当 n >= c时 ai或aj - ai 一定能整除c 
int main(){
	//freopen("in.txt","r",stdin);
	int t; scanf("%d",&t);
	int i,j,k;
	while(t--){
		scanf("%d%d",&m,&n);
		memset(dp,127,sizeof(dp));
		for(i = 0; i < m; i++){
			scanf("%d",&arr[i]);
		}
		sort(arr,arr + m);dp[0] = 0;
		int up;
		//无限背包dp
		for(i = 0; i < m - 1; i++){
			up =  arr[i + 1] * arr[i + 1];//利用鸽巢原理剪枝
			for(j = 0; j <= up; j++){
				dp[j + arr[i]] = min(dp[j] + 1, dp[j + arr[i]]);		
			}
		}
		int u = arr[m - 1];
		up = u * u;
		int min = INT_MAX;
		for(i = 0; i <= up; i++){
			if((n - i) % u == 0 && dp[i] < (1 << 29)){
				if((n - i) / u + dp[i] < min) min = (n - i) / u + dp[i];
			}
		}
		if(min == INT_MAX) printf("-1\n");
		else printf("%d\n",min);
	}
	return 0;
}