#include<iostream>
using namespace std;
const int MN = 20 * 1000000;
bool dp[MN];
int cc[MN],V;

int main(){
	//freopen("in.txt","r",stdin);
	int i,j,n,b;
	while(~scanf("%d%d",&n,&b)){
		V = 0;
		for(i = 0; i < n; i++){
			scanf("%d",cc + i);
			V += cc[i];
		}
		dp[0] = true;
		for(i = 1; i <= V; i++) dp[i] = false;
		for(i = 0; i < n; i++){
			int C = cc[i];
			for(j = V; j >= C; j--){
				dp[j] = dp[j] || dp[j - C];
			}
		}
		for(j = b; j <= V; j++){
			if(dp[j]) {
				printf("%d\n",j - b);
				break;
			}
		}
	}
	return 0;
}