#include<iostream>
using namespace std;

const int MN = 624;
int N,M;
int map[MN][MN];
int dpr[MN][MN];
int dpc[MN][MN];
void maxSum(){
	int i,j;
	int MAX = INT_MIN;
	memset(dpr,0,sizeof(dpr));
	memset(dpc,0,sizeof(dpc));
	for(i = 1; i <= N; i++){
		for(j = 1; j <= N; j++){
			int tmp = map[i][j - 1] + map[i][j];
			dpr[i][j] = max(dpr[i][j - 1] + map[i][j],tmp);//打横
			tmp = map[i - 1][j] + map[i][j];
			dpc[i][j] = max(dpc[i - 1][j] + map[i][j],tmp);//打竖
		//	printf("%d %d ",dpr[i][j],dpc[i][j]);
			if(i >= 2 && j >= 2) MAX = max(MAX, dpr[i][j] + dpc[i][j] - map[i][j]);//打横 + 打竖 - 多了的一个角
		}
		//puts("");
	}
	printf("%d\n",MAX);
}
int main(){
	freopen("in.txt","r",stdin);
	int i,j;
	while(~scanf("%d%d",&N,&M)){
		for(i = 1; i <= N; i++){
			for(j = 1; j <= M; j++){
				scanf("%d",&map[i][j]);
			}
		}
		maxSum();
	}
	return 0;
}