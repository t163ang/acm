#include<iostream>
using namespace std;
const int MN = 424;
const int S = 0, T = MN - 10;
int map[MN][MN];
int pre[MN],vis[MN];
int N,M;
int i,j,k;
int que[MN << 1],head,tail;
bool bfs(){
	head = tail = 1;
	que[tail++] = S; 
	int i,j;
	memset(vis,0,sizeof(vis));
	vis[0] = true;
	while(head != tail){
		int v = que[head++];
		for(i = 0; i <= T; i++){
			if(!vis[i] && map[v][i]){
				pre[i] = v;
				if(i == T) return true;
				vis[i] = true;
				que[tail++] = i;
			}
		}
	}
	return false;
}


void maxflow(){
	int ans = 0;
	while(bfs()){
		int x = T, min = INT_MAX;
		while(x != S){
			if(min > map[pre[x]][x]) min = map[pre[x]][x];
			x = pre[x]; 
		}
		ans += min; x = T;
		while(x != S){
			map[pre[x]][x] -= min;
			map[x][pre[x]] += min;
			x = pre[x];
		}
	}
	printf("%d\n",ans);
}
int main(){
	//freopen("in.txt","r",stdin);
	while(~scanf("%d%d",&N,&M)){
		memset(map,0,sizeof(map));
		for(i = 1; i <= N; i++){
			int si,st;
			map[0][i] = 1;
			scanf("%d",&si);
			for(j = 0; j < si;j++){
				scanf("%d",&st); 
				map[i][N + st] = 1;
				map[N + st][T] = 1;
			}
		}
		maxflow();
	}
	return 0;
}
