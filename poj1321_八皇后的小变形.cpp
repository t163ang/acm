/*
n皇后问题(i,j)(k,l)同一斜线可以这样表示：|i - k| == |j - l| 即 |k| == |j - l| / |i - k| = 1
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MN = 10;
int n,k,x[MN],sum;
char inp[MN][MN];
bool isPlace(int m){
	for(int i = 0; i < m;i++){
		if(x[m] == x[i]) return false;
	}
	return true;
}
void dfs(int r,int m){
	if(m >= k){
		sum++;
		return;
	}
	if(r >= n){
		return;
	}
	for(int i = 0; i < n; i++){
		if(inp[r][i] == '#'){
			x[r] = i;
			if(isPlace(r)) dfs(r + 1,m + 1);
		}
	}
	x[r] = n;//代表此行不放
	dfs(r + 1,m);
}
int main(){
	//freopen("in.txt","r",stdin);
	while(scanf("%d%d",&n,&k),n != -1 || k != -1){
		for(int i = 0; i < n; i++){
			scanf("%s",inp[i]);
		}
		sum = 0;
		dfs(0,0);
		printf("%d\n",sum);
	}
	return 0;
}
