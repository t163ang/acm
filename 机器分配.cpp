#include<iostream>
using namespace std;
const int MN = 124;
int w[MN][MN];
int dp[MN][MN];
int m = MN, n = MN;
int main(){
	freopen("in.txt","r",stdin);
	int i,j,k;
	while(~scanf("%d%d",&m,&n)){
		for(i = 1; i <= n; i++){
			for(j = 1; j <= m; j++){
				scanf("%d",&w[i][j]);
			}
		}
		memset(dp[0],0,sizeof(dp[0]));
		for(i = 1; i <= n; i++){
			dp[i][0] = 0;
			for(j = 1; j <= m; j++){
				for(int v = 0; v <= j; v++){
					int tmp =  dp[i - 1][v] + w[i][j - v];//�±�����ʾ�ı��������޺��Ե� �� ������!!!
					if(dp[i][j] < tmp) dp[i][j] = tmp;//dp[next1][next2] = ��һѡ��{dp[�޺���previousǰһ����1][�޺���ǰһ����2][������] + ״̬ת��} ������ѡ��max or min or choice(w(i)Ȩ�ػ������
				}
			}
		}
		printf("%d\n",dp[n][m]);
	}
	return 0;
}