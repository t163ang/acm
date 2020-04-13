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

//pkkj的
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
//    /* 枚举牛 */
//    for (i = 1; i <= n; i++) {
//        for (j = 0; j <= valid; j++)
//            /* 枚举状态，如果该状态曾经有值，则DP */
//            if (dp[s][j] != 0) {
//                for (k = 1; k <= m; k++)
//                    /*枚举barn*/
//                    if (map[i][k]) { /*如果该牛能够分配到该barn*/
//                        /*
//                        * 如果j状态能够推出新状态
//                        * 该位运算比较难理解：
//                        * 例如，j是1010， 代表着2号barn有牛，4号barn有牛，明显，如果要放牛，只能往2，3里面放
//                        * 例如k=2，那么，1 << (k - 1) ＝0010，0010 | 1010 = 1010， 不变，即next = j，意味着该牛栏已经有牛了。
//                        * 再例如k＝3, 那么，1 << (k - 1) ＝0100，0100 | 1010 = 1110， 改变，即next != j，意味着该牛栏没有牛了，且下一个状态位于1110中。
//                        */
//                        next = j | (1 << (k - 1));
//                        if (next != j) {
//                            dp[p][next] += dp[s][j];
//                        }
//                    }
//                dp[s][j] = 0; /*清理滚动数组*/
//            }
//        s = 1 - s, p = 1 - p; /*滚动数组变量置换*/
//    }
//    for (i = 0; i <= valid; ++i)
//        sum += dp[s][i];
//    printf("%d\n", sum);
//    return 0;
//}