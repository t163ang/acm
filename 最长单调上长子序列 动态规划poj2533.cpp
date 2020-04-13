#include<iostream>
using namespace std;
const int MN = 1024;
int w[MN];
int dp[MN];
//dp[i] = max(0 <= j <= i - 1){1, dp[j] + 1(w[j] < w[i])} 
int main(){
	//freopen("in.txt","r",stdin);
	int n,i,j;
	while(scanf("%d",&n) != EOF){
		for(i = 0; i < n; i++){
			scanf("%d",&w[i]);
		}
		dp[0] = 1; //只有一个数w[0]
		for(i = 1; i < n; i++){
			dp[i] = 1;
			for(j = 0; j < i; j++){
				if(w[i] > w[j] && dp[i] <= dp[j]) dp[i] = dp[j] + 1;
			}
		}
		int max = 0;
		for(i = 0; i < n; i++) if(max < dp[i]) max = dp[i];
		printf("%d\n",max);
	}
	return 0;
}
/*
Longest Ordered Subsequence
Time Limit: 2000MS  Memory Limit: 65536K 
Total Submissions: 14543  Accepted: 6175 

Description

A numeric sequence of ai is ordered if a1 < a2 < ... < aN. Let the subsequence of the given numeric sequence (a1, a2, ..., aN) be any sequence (ai1, ai2, ..., aiK), where 1 <= i1 < i2 < ... < iK <= N. For example, sequence (1, 7, 3, 5, 9, 4, 8) has ordered subsequences, e. g., (1, 7), (3, 4, 8) and many others. All longest ordered subsequences are of length 4, e. g., (1, 3, 5, 8).

Your program, when given the numeric sequence, must find the length of its longest ordered subsequence.
Input

The first line of input file contains the length of sequence N. The second line contains the elements of sequence - N integers in the range from 0 to 10000 each, separated by spaces. 1 <= N <= 1000 
Output

Output file must contain a single integer - the length of the longest ordered subsequence of the given sequence. 
Sample Input

7
1 7 3 5 9 4 8
Sample Output

4

*/