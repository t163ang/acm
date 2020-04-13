#include<iostream>
using namespace std;
const int INF = 1 << 30;
const int MN = 120;
int value[MN];
int cost[MN];
int dp[MN][MN]; // dp[������][���Ͷ�]����С�������ֵ
int n,m,k,s;//����ֵ�����������Ͷȣ��ֵ�����������ɱ����
int ans;
void inline CompletePack(int cost, int weight){
	for(int i = 1; i <= s; i++){
		for(int j = cost; j <= m; j++){
			dp[i][j] = max(dp[i][j],dp[i - 1][j - cost] + weight);
			if(dp[i][j] >= n){
				if(ans > j) ans = j;
			}
		}
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	int i;
	while(~scanf("%d%d%d%d",&n,&m,&k,&s)){
		for(i = 1; i <= k; i++){
			scanf("%d%d",value + i, cost + i);
		}
		memset(dp,0,sizeof(dp));
		for(i = 1,ans = INF; i <= k; i++){
			CompletePack(cost[i],value[i]);
		}
		if(ans < INF) printf("%d\n",m - ans);
		else printf("-1\n");
	}
}

