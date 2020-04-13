#include<iostream>
#include<cstdio>
using namespace std;
const int MN = 100024;
int V;
bool dp[MN];
int num[MN];
int value[MN];

inline void ZeroOnePack(int cost){
	for(int i = V; i >= cost; i--){
		dp[i] = dp[i] || dp[i - cost];
	}
}

inline void CompletePack(int cost){
	for(int i = cost; i <= V; i++){
		dp[i] = dp[i] || dp[i - cost];
	}
}	

inline void MultiplePack(int cost,int amount){
	if(cost * amount >= V){
		CompletePack(cost);
		return;
	}
	int k = 1;
	while(k < amount){
		ZeroOnePack(k * cost);
		amount -= k;
		k *= 2;
	}
	ZeroOnePack(amount * cost);
}

int main(){
	//freopen("in.txt","r",stdin);
	int i,n;
	while(scanf("%d%d",&n,&V),n){
		for(i = 0; i < n; i++){
			scanf("%d",value + i);
		}
		for(i = 0; i < n; i++){
			scanf("%d",num + i);
		}
		dp[0] = true;
		for(i = 1; i <= V; i++){
			dp[i] = false;
		}
		for(i = 0; i < n; i++){
			MultiplePack(value[i],num[i]);
		}

		int sum = 0;
		for(i = 1; i <= V; i++){
			if(dp[i]) sum++;
		}
		printf("%d\n",sum);
	}
	return 0;
}

//O(NV)Ëã·¨
//int main(){
//	freopen("in.txt","r",stdin);
//	int n,m;
//	int a[101],c[101];
//	int num[100001];
//	bool flag[100001];
//	int i,j,k,ans;
//	while(scanf("%d%d",&n,&m),n){
//		for(i = 0; i < n; i++){
//			scanf("%d",a + i);
//		}
//		for(i = 0; i < n; i++){
//			scanf("%d",c + i);
//		}
//		ans = 0;
//		memset(flag,0,sizeof(flag));
//		flag[0] = true;
//
//		for(i = 0; i < n; i++){
//			memset(num,0,sizeof(num));
//			if(a[i] > m) break;
//			for(j = a[i]; j <= m; j++){
//				if(!flag[j] && flag[j - a[i]] && num[j - a[i]] < c[i]){
//					flag[j] = true;
//					ans++;
//					num[j] = num[j - a[i]] + 1;
//				}
//			}
//		}
//		printf("%d\n",ans);
//	}
//	return 0;
//}
