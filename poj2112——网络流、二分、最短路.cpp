#include<iostream>
using namespace std;
const int MN = 250;
const int INF = 1 << 30;
int n,k,c,m;
int chart[MN][MN];
int cap[MN][MN];
int S,T;
void floyd(){
	int u,i,j;
	for(u = 0; u < n; u++){
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				if(chart[i][u] != INF && chart[u][j] != INF && chart[i][u] + chart[u][j] < chart[i][j]){
					chart[i][j] = chart[i][u] + chart[u][j];
				}
			}
		}
	}
}

int Longest(){
	int i,j,L = 0;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(chart[i][j] != INF){
				if(L < chart[i][j]){
					L = chart[i][j];
				}
			}
		}
	}
	return L;
}

void construct(int L){
	int i,j;
	memset(cap,0,sizeof(cap));
	for(i = 0; i < k; i++){ //机器至汇点
		cap[i][T] = m;
	}
	for(i = k; i < n; i++){//源点至cow
		cap[S][i] = 1;
	}
	for(i = k; i < n; i++){
		for(j = 0; j < k; j++){
			if(chart[i][j] <= L){
				cap[i][j] = INF;
			}
		}
	}
}

int que[MN],qh,qt;
int pre[MN];
bool vis[MN];
bool bfs(){
	qh = qt = 0;
	memset(vis,0,sizeof(vis));
	que[qt++] = S;
	vis[S] = true;
	while(qh != qt){
		int u = que[qh++];
		for(int v = 0; v <= T; v++){
			if(!vis[v] && cap[u][v] > 0){
				vis[v] = true;
				que[qt++] = v;
				pre[v] = u;
				if(v == T){
					return true;
				}
			}
		}
	}
	return false;
}
bool flow(int L){
	construct(L);//构图
	int cow = 0;
	while(bfs()){
		int t = T, minn = INT_MAX;
		while(t != S){
			if(minn > cap[pre[t]][t]) minn = cap[pre[t]][t];
			t = pre[t];
		}
		t = T;
		while(t != S){
			cap[pre[t]][t] -= minn;
			cap[t][pre[t]] += minn;
			t = pre[t];
		}
		cow += minn;
	}
	if(cow == c) return true;
	return false;
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j;
	while(~scanf("%d%d%d",&k,&c,&m)){
		n = k + c;
		S = n; T = n + 1;
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				scanf("%d",chart[i] + j);
				if(chart[i][j] == 0 && i != j){
					chart[i][j] = INF;
				}
			}
		}
		floyd();
		int L = 0,R = Longest();
		while(L <= R){
			int mid = (L + R) >> 1;
			if(flow(mid)){
				R = mid - 1;
			}else{
				L = mid + 1;
			}
		}
		printf("%d\n",L);
	}
	return 0;
}