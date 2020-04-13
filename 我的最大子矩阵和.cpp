#include<iostream>
using namespace std;
const int MN = 100;
int map[MN][MN];
int dp[MN][MN];
int N,M;
int main(){
	freopen("in.txt","r",stdin);
	int i,j,k;
	scanf("%d%d",&N,&M);
	memset(dp,0,sizeof(dp));
	for(i = 1; i <= N; i++){
		for(j = 1; j <= M; j++){
			scanf("%d",&map[i][j]);
		}
	}
	int MAX = INT_MIN, sum;
	for(i = 1; i <= N; i++){
		for(j = 1; j <= M; j++){
			sum = 0;
			for(k = j; k <= M; k++){
				sum += map[i][k];
				dp[j][k] = max(dp[j][k] + sum ,sum);
				//printf("%d\n",dp[j][k]);
				if(MAX < dp[j][k]) MAX = dp[j][k];
			}
		}
	}
	printf("%d\n",MAX);
	return 0;
}
//运行时间是O(N * M^2):N是行、M是列
/*----------------------------------------------------pku AC 证明--------------------------------------------*/
//#include<iostream>
//using namespace std;
//const int MN = 124;
//int map[MN][MN];
//int dp[MN][MN];
//int N;
//int main(){
//	//freopen("in.txt","r",stdin);
//	int i,j,k;
//	while(~scanf("%d",&N)){
//		memset(dp,0,sizeof(dp));
//		for(i = 1; i <= N; i++){
//			for(j = 1; j <= N; j++){
//				scanf("%d",&map[i][j]);
//			}
//		}
//		int MAX = INT_MIN, sum;
//		for(i = 1; i <= N; i++){
//			for(j = 1; j <= N; j++){
//				sum = 0;
//				for(k = j; k <= N; k++){
//					sum += map[i][k];
//					dp[j][k] = max(dp[j][k] + sum ,sum);
//					//printf("%d\n",dp[j][k]);
//					if(MAX < dp[j][k]) MAX = dp[j][k];
//				}
//			}
//		}
//		printf("%d\n",MAX);
//	}
//	return 0;
//}
//
////To the Max
////Time Limit: 1000MS  Memory Limit: 10000K 
////Total Submissions: 21965  Accepted: 11396 
////
////Description
////
////Given a two-dimensional array of positive and negative integers, a sub-rectangle is any contiguous sub-array of size 1*1 or greater located within the whole array. The sum of a rectangle is the sum of all the elements in that rectangle. In this problem the sub-rectangle with the largest sum is referred to as the maximal sub-rectangle. 
////As an example, the maximal sub-rectangle of the array: 
////
////0 -2 -7 0 
////9 2 -6 2 
////-4 1 -4 1 
////-1 8 0 -2 
////is in the lower left corner: 
////
////9 2 
////-4 1 
////-1 8 
////and has a sum of 15. 
////
////Input
////
////The input consists of an N * N array of integers. The input begins with a single positive integer N on a line by itself, indicating the size of the square two-dimensional array. This is followed by N^2 integers separated by whitespace (spaces and newlines). These are the N^2 integers of the array, presented in row-major order. That is, all numbers in the first row, left to right, then all numbers in the second row, left to right, etc. N may be as large as 100. The numbers in the array will be in the range [-127,127].
////Output
////
////Output the sum of the maximal sub-rectangle.
////Sample Input
////
////4
////0 -2 -7 0 9 2 -6 2
////-4 1 -4  1 -1
////
////8  0 -2
////Sample Output
////
////15
