/*
ID: davidro2
PROG: poj2289
LANG: C++
*/
#include<iostream>
using namespace std;
const int MN = 1508;
const int INF = 1 << 30;
int N,M,S,T,cap[MN][MN];
int map[MN][MN];
void inline congrap(int mid){
	for(int k = 0; k < M; k++){
		cap[N + k][T] = mid;
	}
	memcpy(map,cap,sizeof(cap));
}
int h[MN],num[MN],pre[MN];
int que[MN],qh,qt;
void bfs(){
	qh = qt = 0;
	memset(h,-1,sizeof(h));
	memset(num,0,sizeof(num));
	num[0] = 1;
	h[T] = 0;
	que[qt++] = T;
	while(qh != qt){
		int u = que[qh++];
		for(int v = 0; v <= T; v++){
			if(map[v][u] > 0 && h[v] == -1){
				h[v] = h[u] + 1;
				num[h[v]]++;
				que[qt++] = v;
			}
		}
	}
}

int find(int u){
	for(int v = 0; v <= T; v++){
		if(map[u][v] > 0 && h[u] == h[v] + 1){
			return v;
		}
	}
	return -1;
}

int relabel(int u){
	int minn = INF;
	for(int v = 0; v <= T; v++){
		if(map[u][v] > 0 && minn > h[v]){
			minn = h[v];
		}
	}
	if(minn != INF) return minn + 1;
	return T + 1;
}

bool sap(){
	bfs();
	int i = S,j,flow = 0;
	while(h[S] <= T){
		j = find(i);
		if(j >= 0){
			pre[j] = i;
			i = j;
			if(i == T){
				int minn = INF;
				i = T;
				while(i != S){
					minn = min(minn,map[pre[i]][i]);
					i = pre[i];
				}
				i = T;
				while(i != S){
					map[pre[i]][i] -= minn;
					map[i][pre[i]] += minn;
					i = pre[i];
				}
				flow += minn;
			}
		}else{
			int m = relabel(i);
			num[h[i]]--;
			num[m]++;
			if(num[h[i]] == 0) return flow == N;
			h[i] = m;
			if(i != S) i = pre[i];
		}
	}
	return flow == N;
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,k;	
	char name[MN];
	while(scanf("%d%d",&N,&M),N + M){
		S = N + M; T = N + M + 1;
		memset(cap,0,sizeof(cap));
		for(i = 0; i < N; i++){
			scanf("%s",name);
			cap[S][i] = 1;
			while(scanf("%d",&k)){
				cap[i][N + k] = 1;
				if(getchar() == '\n') break;
			}
		}
		int L = 1, R = N;
		while(L <= R){
			int mid = (L + R ) >> 1;
			congrap(mid);
			if(sap()){
				R = mid - 1;
			}else{
				L = mid + 1;
			}
		}
		printf("%d\n",L);
	}
	return 0;
}