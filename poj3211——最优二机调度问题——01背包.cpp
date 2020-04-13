/*
�տ�ʼ����Ϊ������̰���������Ӵ�С�Ÿ���ÿ�η��������ʹ��ʱ����С���Ǹ�
�����������������ǲ��������Ž�ģ���ʵ�ϣ�NP����Ķ�����Ⱦ���ʹ������̰�ķ�����
�������Ž⡣
����4 3 3 2 2 2,���̰�����ó���4 + 2 �� 3 + 3 + 2,�����Ž���Ȼ��4 + 3, 3 + 2 + 2
������Կ������Ŷ����������Ž⣬ʹ��dp��ÿ��color������ӽ���ʱ���һ�룬��ʹ��
�������ʱ������ܾ��ȣ�������ʱ����С��
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