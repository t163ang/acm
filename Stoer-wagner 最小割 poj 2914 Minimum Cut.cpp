#include<iostream>
#include<queue>
using namespace std;

const int MN = 1024;
int N,M,n;

bool vis[MN]; int d[MN];
int G[MN][MN];
bool combine[MN];
int mincut;
//注意不要用邻接表，因为合并时要新建一条边，若果那样有点麻烦
void dij(){
	memset(d,0,sizeof(d));
	memset(vis,0,sizeof(vis));
	int S,T = -1,i,j;
	for(i = 0; i < n; i++){//执行n次因为第一次从源从发
		int max = -INT_MAX, tmp = -1;
		for(j = 0; j < N; j++){
			if(!vis[j] && !combine[j] && d[j] > max)
				max = d[j],tmp = j;
		}
		S = T; T = tmp; vis[T] = true;
		for(j = 0; j < N; j++){
			if(!vis[j] && !combine[j]) d[j] += G[T][j];
		}
	}

	//merge
	combine[T] = true;	
	for(j = 0; j < N; j++){
		if(!combine[j] && j != S){
			G[S][j] += G[T][j];
			G[j][S] += G[j][T];
		}
	}
	if(mincut > d[T]) mincut = d[T];
}

void inline stoer_wagner(){
	memset(combine,0,sizeof(combine));
	mincut = INT_MAX;
	n = N;
	while(n > 1){
		dij();
		n--;
	}
	printf("%d\n",mincut);
}
int main(){
	//freopen("in.txt","r",stdin);
	while(~scanf("%d%d",&N,&M)){
		memset(G,0,sizeof(G));
		while(M--){
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			G[a][b] += c;
			G[b][a] += c;
		}
		stoer_wagner();
	}
	return 0;
}
