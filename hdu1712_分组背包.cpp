#include<iostream>
using namespace std;
const int MN = 108;
int A[MN][MN];
int dp[MN];//���鿪С����hdu����runtime error����wa��,poj���ݿ�С�˻�runtime error��

int main(){
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k;
	memset(A,0,sizeof(A));
	while(scanf("%d%d",&n,&m),n + m){
		for(i = 1; i <= n; i++){
			for(j = 1; j <= m; j++){
				scanf("%d",*(A + i) + j);
			}
		}
		memset(dp,0,sizeof(dp));
		//ע������Ƿ��鱳������A[1][1] = 2,A[1][2] = 3,A[1][3] = 4,
		//��ȻA[1][1] + A[1][2] > A[1][3]�����鱳��ѡ����ߣ����ر���ѡ��ǰ2����ӡ� 
		//�����Ƿ��鱳�����Ƕ��ر�����ѭ��˳��Ӧ���ȱ������������ͬ�ڷ�����ѡһ��������ѡ���.
		for(i = 1; i <= n; i++){
			for(j = m; j >= 1; j--){//����
				int max = 0;
				for(k = j; k >= 0;k--){ //����
					if(max < dp[j - k] + A[i][k]) max = dp[j - k] + A[i][k];
				}
				dp[j] = max;
			}
		}
		printf("%d\n",dp[m]);
	}
	return 0;
}