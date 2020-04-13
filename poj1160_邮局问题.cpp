#include<iostream>
using namespace std;
const int MN = 302;
int dp[MN][MN];
int d[MN][MN];
int dist[MN];
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,k;
	int p,v;
	scanf("%d%d",&v,&p);
	for(i = 1; i <= v; i++){
		scanf("%d",dist + i);
	}

	memset(d,0,sizeof(d));
	for(i = 1; i <= v; i++){
		for(j = i + 1; j <= v; j++){
			int mid = (i + j) >> 1;
			for(k = i; k <= j; k++){
				d[i][j] += abs(dist[k] - dist[mid]); 
			}
		}
	}

	for(j = 1; j <= v; j++){
		dp[1][j] = d[1][j]; 
	}
	for(i = 2; i <= p; i++){
		for(j = i; j <= v; j++){
			//dp[i][j] = min{dp[i - 1][k] + d[j][k]};
			int min = INT_MAX,tmp;
			for(k = i - 1; k < j; k++){
				tmp = dp[i - 1][k] + d[k + 1][j];
				if(min > tmp) min = tmp;
			}
			dp[i][j] = min;
		}
	}
	printf("%d\n",dp[p][v]);
	return 0;
}