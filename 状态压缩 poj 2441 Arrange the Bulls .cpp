#include<iostream>
using namespace std;
const int MN = 20;
int dp[2][(1 << MN) + 4];
int rec[MN + 2];
int n,m,p;
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,k;
	while(~scanf("%d%d",&n,&m)){
		scanf("%d",&p);
		memset(rec,0,sizeof(rec));
		memset(dp[0],0,sizeof(dp[0]));
		for(i = 0; i < p; i++){
			scanf("%d",&k);
			dp[0][1 << (k - 1)] = 1;
		}
		for(i = 1; i < n; i++){
			scanf("%d",&p);
			for(j = 0; j < p; j++){
				scanf("%d",&k);
				rec[i] |= 1 << (k - 1);
			}
		}

		for(i = 1; i < n; i++){
			memset(dp[i & 1],0,sizeof(dp[i & 1]));
			int tmp = rec[i];
			for(j = 0; j < m; j++){
				if((1 << j) & tmp){
					for(k = 1; k < (1 << m); k++){
						if(k & (1 << j)) continue;
						dp[i & 1][k | (1 << j)] += dp[(i - 1) & 1][k];
					}
				}
			}
		}
		int ans = 0;j = 1 << m; k  = (n - 1) & 1;
		for(i = 0; i < j ;i++){
			ans += dp[k][i];
		}
		printf("%d\n",ans);

	}
	return 0;
}

//pkkj��
//#include <stdio.h>
//#include <string.h>
//#define N 21
//int dp[2][0x100000],map[N][N];
//
//int main() {
//    int n, m, valid;
//    int bn, i, j, k, s, p, pos, next, sum = 0;
//    scanf("%d %d", &n, &m);
//    valid = (1 << m) - 1;
//    memset(dp, 0, sizeof(dp));
//    memset(map, 0, sizeof(map));
//    for (i = 1; i <= n; ++i) {
//        scanf("%d", &bn);
//        for (j = 0; j < bn; ++j) {
//            scanf("%d", &pos);
//            map[i][pos] = 1;
//        }
//    }
//    dp[0][0] = 1, s = 0, p = 1;
//    /* ö��ţ */
//    for (i = 1; i <= n; i++) {
//        for (j = 0; j <= valid; j++)
//            /* ö��״̬�������״̬������ֵ����DP */
//            if (dp[s][j] != 0) {
//                for (k = 1; k <= m; k++)
//                    /*ö��barn*/
//                    if (map[i][k]) { /*�����ţ�ܹ����䵽��barn*/
//                        /*
//                        * ���j״̬�ܹ��Ƴ���״̬
//                        * ��λ����Ƚ�����⣺
//                        * ���磬j��1010�� ������2��barn��ţ��4��barn��ţ�����ԣ����Ҫ��ţ��ֻ����2��3�����
//                        * ����k=2����ô��1 << (k - 1) ��0010��0010 | 1010 = 1010�� ���䣬��next = j����ζ�Ÿ�ţ���Ѿ���ţ�ˡ�
//                        * ������k��3, ��ô��1 << (k - 1) ��0100��0100 | 1010 = 1110�� �ı䣬��next != j����ζ�Ÿ�ţ��û��ţ�ˣ�����һ��״̬λ��1110�С�
//                        */
//                        next = j | (1 << (k - 1));
//                        if (next != j) {
//                            dp[p][next] += dp[s][j];
//                        }
//                    }
//                dp[s][j] = 0; /*�����������*/
//            }
//        s = 1 - s, p = 1 - p; /*������������û�*/
//    }
//    for (i = 0; i <= valid; ++i)
//        sum += dp[s][i];
//    printf("%d\n", sum);
//    return 0;
//}