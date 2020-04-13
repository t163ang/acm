#include<iostream>
using namespace std;
const int MN = 8000000;
int bond[20];
int interest[20];
int dp[MN];
int V;
inline void CompletePack(int cost,int weight){
	for(int i = cost; i <= V; i++){
		dp[i] = max(dp[i],dp[i - cost] + weight);
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	int i,j,n,T,money,year;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&money,&year);
		scanf("%d",&n);
		for(i = 0; i < n; i++){
			scanf("%d%d",bond + i,interest + i);
			bond[i] /= 1000;
		}
		V = money / 1000; //Ҫ���������ܵõ�����Ϣ����bond��1000�ı�����������money�����������bond��Ҳ����1000�ı����ġ�
		for(j = 0; j < year; j++){
			memset(dp,0,(V + 1) * sizeof(int));
			for(i = 0; i < n; i++){
				CompletePack(bond[i],interest[i]);
			}
			money += dp[V];
			V = money / 1000;
		}
		printf("%d\n",money);
	}
	return 0;
}