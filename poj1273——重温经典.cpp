#include<iostream>
using namespace std;
const int MN = 220;
int n,m;
int cap[MN][MN];//网络流一般使用数组
int pre[MN];
bool vis[MN];
int que[MN],qh,qt;
bool bfs(){
	qh = qt = 0;
	memset(vis,0,sizeof(vis));
	que[qt++] = 1;
	vis[1] = true;
	while(qh != qt){
		int u = que[qh++];
		for(int v = 1; v <= m; v++){
			if(!vis[v] && cap[u][v] > 0){				
				vis[v] = true;
				que[qt++] = v;
				pre[v] = u;
				if(v == m){
					return true;
				}
			}
		}
	}
	return false;
}
void solve(){
	int sum = 0;
	while(bfs()){
		int t = m,minn = INT_MAX;
		while(t != 1){
			if(minn > cap[pre[t]][t]) minn = cap[pre[t]][t];
			t = pre[t];
		}
		t = m;
		while(t != 1){
			cap[pre[t]][t] -= minn;
			cap[t][pre[t]] += minn;
			t = pre[t];
		}
		sum += minn;
	}
	printf("%d\n",sum);
}
int main(){
	freopen("in.txt","r",stdin);
	int i,a,b,c;
	while(~scanf("%d%d",&n,&m)){
		memset(cap,0,sizeof(cap));
		for(i = 0; i < n; i++){
			scanf("%d%d%d",&a,&b,&c);
			cap[a][b] += c;	//有向图
		}
		solve();
	}
	return 0;
}