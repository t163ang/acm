//第一个状态压缩!!!!
#include<iostream>
int dp[2][(1 << 12) + 2];
int rec[13];
int m,n,i,j,k;
int main(){
	while(~scanf("%d%d",&m,&n)){
		memset(rec,0,sizeof(rec));
		memset(dp[0],0,sizeof(dp[0]));
		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				scanf("%d",&k);
				rec[i] <<= 1;
				rec[i] |= 1 - k;
			}
		}
		int tmp = rec[0];
		for(j = 0; j < (1 << n); j++) {
			if(j & tmp || (j << 1) & j || (j >> 1) & j) continue;
			dp[0][j]++;
		}
		for(i = 1; i < m; i++){
			tmp = rec[i];
			memset(dp[i & 1],0,sizeof(dp[i & 1]));
			for(j = 0; j < (1 << n); j++){
				if(j & tmp || (j << 1) & j || (j >> 1) & j) continue;
				for(k = 0; k < (1 << n); k++){
					if(j & k) continue;
					dp[i & 1][j] += dp[(i - 1) & 1][k];
				}
			}
		}
		int ans = 0; k = (m - 1) & 1;
		for(i = 0; i < (1 << n); i++){
			ans = (ans + dp[k][i]) % 100000000;
		}
		printf("%d\n",ans);
	}
	return 0;
}

//#include<iostream>
//using namespace std;
//const int MN = 13;
//int dp[MN][1 << MN];
//int rec[MN];
//int m,n;
//int main(){
//	//freopen("in.txt","r",stdin);
//	int i,j,k;
//	while(~scanf("%d%d",&m,&n)){
//		memset(rec,0,sizeof(rec));
//		memset(dp,0,sizeof(dp));
//		for(i = 0; i < m; i++){
//			for(j = 0; j < n; j++){
//				scanf("%d",&k);
//				rec[i] <<= 1;
//				rec[i] |= 1 - k;
//			}
//		}
//		int tmp = rec[0];
//		for(j = 0; j < (1 << n); j++) {
//			if(j & tmp || (j << 1) & j || (j >> 1) & j) continue;
//			dp[0][j]++;
//		}
//
//		for(i = 1; i < m; i++){
//			tmp = rec[i];
//			for(j = 0; j < (1 << n); j++){
//				if(j & tmp || (j << 1) & j || (j >> 1) & j) continue; //状态j非法
//				for(k = 0; k < (1 << n); k++){
//					if(j & k) continue;//j和k非法,若k是非法呢？不用怕dp[i - 1][k] = 0
//					dp[i][j] += dp[i - 1][k];
//				}
//			}
//		}
//		int ans = 0;
//		for(i = 0; i < (1 << n); i++){
//			ans = (ans + dp[m - 1][i]) % 100000000;
//		}
//		printf("%d\n",ans);
//	}
//	return 0;
//}

//别人的参考一下
//struct Line{
//
//    int num;
//
//    int state[1024];
//
// }line[15];//对应第i行有Num中情况符合条件，都记录在state中 
//int dp[15][1024]={0};
//int m, n;
//void GetState( int i, int tmp )
//
//{
//
//    int j;
//    int num = 0;
//    for ( j=0; j<(1<<n); j++ )
//
//    {
//
//       if ( (j<<1)&j || (j>>1)&j )
//
//           continue;//若有两个连续的0不予考虑 
//
//       if ( tmp&j )//tmp是能否种草的状态，0表示可以，1不可以 
//
//           continue;
//
//     line[i].state[num++] = j;//j是一种可行的状态 
//
//    }
//
//    line[i].num = num;//对于第I行有多少中情况符合条件 
//
//}
//
//int main ()
//
//{
//    int i, j, k;
//    int a;
//    scanf("%d %d", &m, &n );
//    for ( i=0;i<m;i++)//m行的处理 
//    {
//       int tmp = 0;
//       for ( j=0; j<n; j++ )
//       { 
//      scanf("%d", &a );
//      tmp = (tmp<<1) + 1-a;
//       }
//       GetState( i, tmp );
//    }
//    for ( i=0; i<line[0].num; i++ )
//      dp[0][i] = 1;  
//    for ( i=1; i<m; i++ )
//    for (j=0;j<line[i].num;j++)
//       {
//           dp[i][j] = 0;
//           for ( k=0; k<line[i-1].num; k++ )
//           {
//              if ( (line[i].state[j])&(line[i-1].state[k]) )
//     continue;//如果有两头母牛会相邻则去掉这一种情况 
//              dp[i][j]+=dp[i-1][k];//否则相加 
//     }
//       }
//    int ans = 0;
//    for ( i=0; i<line[m-1].num; i++)
//       ans = (ans+dp[m-1][i])%100000000;//在最后一行中将所有的值相加 
//    printf("%d\n", ans );
//    return 0;
//
//}
