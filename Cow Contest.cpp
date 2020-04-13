#include<iostream>
using namespace std;
/*
Cow Contest
Time Limit: 1000MS  Memory Limit: 65536K 
Total Submissions: 3089  Accepted: 1614 

Description

N (1 ¡Ü N ¡Ü 100) cows, conveniently numbered 1..N, are participating in a programming contest. As we all know, some cows code better than others. Each cow has a certain constant skill rating that is unique among the competitors.

The contest is conducted in several head-to-head rounds, each between two cows. If cow A has a greater skill level than cow B (1 ¡Ü A ¡Ü N; 1 ¡Ü B ¡Ü N; A ¡Ù B), then cow A will always beat cow B.

Farmer John is trying to rank the cows by skill level. Given a list the results of M (1 ¡Ü M ¡Ü 4,500) two-cow rounds, determine the number of cows whose ranks can be precisely determined from the results. It is guaranteed that the results of the rounds will not be contradictory.

Input

* Line 1: Two space-separated integers: N and M
* Lines 2..M+1: Each line contains two space-separated integers that describe the competitors and results (the first integer, A, is the winner) of a single round of competition: A and B

Output

* Line 1: A single integer representing the number of cows whose ranks can be determined
¡¡

Sample Input

5 5
4 3
4 2
3 2
1 2
2 5

Sample Output

2

Source

USACO 2008 January Silver
*/

int n,m;
int main(){
	int i,j,k;
	while(scanf("%d%d",&n,&m) != EOF){
		int p[120][120] = {0};
		for(i = 0; i < m; i++){
			scanf("%d%d",&j,&k);
			p[j][k] =  1; //p[j][k]±íÃ÷j win k
		}
		for(k = 1; k <= n; k++){
			for(i = 1; i <= n; i++){
				for(j = 1; j <= n; j++){
					if(!p[i][j]) p[i][j] =  p[i][k] && p[k][j];
				}
			}
		}


		//for(i = 1; i <= n; i++){
		//	for(j = 1; j <= n; j++){
		//		printf("%d ",p[i][j]);
		//	}
		//	puts("");
		//}

		int ans = 0, temp;
		for(i = 1; i <= n; i++){
			temp = 0;
			for(j = 1; j <= n; j++){
				if(p[i][j] || p[j][i]) temp++;
			}
			if(temp == n - 1) ans++;
		}
		printf("%d\n",ans);
	}

}