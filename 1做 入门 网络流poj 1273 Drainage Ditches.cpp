#include<iostream>
using namespace std;
const int MN = 400;
int que[MN];
bool visited[MN];
int head,tail;
int map[MN][MN];
int pre[MN];
int N,M;
bool bfs(){
	int i,j,k;
	memset(visited,0,sizeof(visited));
	head = tail = 0;
	que[tail++] =  1;
	visited[1] = true;
	while(head != tail){
		k = que[head++];
		for(i = 1; i <= M; i++){
			if(!visited[i] && map[k][i]){
				pre[i] = k;
				if(i == M) return true;
				que[tail++] = i;
				visited[i] =  true;
			}
		}
	}
	return false;
}

int solve(){
	int i,j,k, ans = 0;
	while(bfs()){
		i = M, j = INT_MAX;
		while(i != 1){//search least
			k = map[pre[i]][i];
			if(j > k) j = k;
			i = pre[i];
		}
		i = M;
		ans += j;
		while(i != 1){
			map[pre[i]][i] -= j;
			map[i][pre[i]] += j;
			i = pre[i];
		}
	}
	return ans;
}
int main(){
	freopen("in.txt","r",stdin);
	int i,j,k,w;
	while(~scanf("%d%d",&N,&M)){
		memset(map,0,sizeof(map));
		for(i = 0; i < N; i++){
			scanf("%d%d%d",&j,&k,&w);
			map[j][k] += w;
		}
		printf("%d\n",solve());
	}
}

