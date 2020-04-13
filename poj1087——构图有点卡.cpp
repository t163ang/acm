/*
ID: tangzq
PROG: poj1087
LANG: C++
*/
#include<iostream>
#include<string>
#include<map>
using namespace std;
const int INF = 1 << 30;
const int MN = 620;
map<string,int> fun;
int cap[MN][MN];
int n,m,k;
int S = 0,T;

bool vis[MN];
int que[MN],qh,qt;
int pre[MN];
bool bfs(){
	qh = qt = 0;
	memset(vis,0,sizeof(vis));
	vis[S] = true;
	que[qt++] = S;
	while(qh != qt){
		int u = que[qh++];
		for(int v = S; v <= T; v++){
			if(!vis[v] && cap[u][v] > 0){
				vis[v] = true;
				pre[v] = u;
				que[qt++] = v;
				if(v == T){
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
		int t = T,minn = INT_MAX;
		while(t != S){
			if(cap[pre[t]][t] < minn){
				minn = cap[pre[t]][t];
			}
			t = pre[t];
		}
		t = T;
		while(t != S){
			cap[pre[t]][t] -= minn;
			cap[t][pre[t]] += minn;
			t = pre[t];
		}
		sum += minn;
	}
	printf("%d\n",m - sum);
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j;
	char inp[30],inp2[30];
	while(~scanf("%d",&n)){
		memset(cap,0,sizeof(cap));
		for(i = 1; i <= n; i++){
			scanf("%s",inp);
			cap[S][i] = 1;
			fun[inp] = i;
		}	
		scanf("%d",&m);
		T = n + m + 1;
		for(i = 1; i <= m; i++){
			scanf("%s%s",inp,inp2);
			j = n + i;
			if(fun.find(inp2) == fun.end()){
				fun[inp2] = T++;
			}
			cap[fun[inp2]][j] = INF;
		}
		scanf("%d",&k);
		for(i = 1; i <= k; i++){
			scanf("%s%s",inp,inp2);
			if(fun.find(inp) == fun.end()){
				fun[inp] = T++;
			}
			if(fun.find(inp2) == fun.end()){
				fun[inp2] = T++;
			}
			cap[fun[inp2]][fun[inp]] = INF;
		}
		for(i = 1; i <= m; i++){
			j = i + n;
			cap[j][T] = 1;
		}
		solve();
	}
	return 0;
}