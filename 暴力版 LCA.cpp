#include<iostream>
#include<vector>
using namespace std;
//查询次数为Q，那么为O(Qn) Q很大时就爆了…,这一题Q = 1 ^-^
const int MN = 10024;
vector<int> g[MN];
int level[MN],par[MN];
int t,n,a,b;
void dfs(int v, int dep){
	int i,len = g[v].size();
	for(i = 0; i < len; i++){
		int u = g[v][i];
		level[u] = dep + 1; 
		dfs(u,dep + 1);
	}
}

void solve(int a, int b){
	if(level[a] > level[b]) swap(a,b);
	while(level[b] > level[a]) b = par[b];
	while(a != b){
		a = par[a];
		b = par[b];
	}
	printf("%d\n",a);
}
int main(){
	//freopen("in.txt","r",stdin);
	scanf("%d",&t);
	int i;
	while(t--){
		scanf("%d",&n);
		memset(g,0,sizeof(g));
		memset(par,0,sizeof(par));
		for(i = 1; i < n; i++){
			scanf("%d%d",&a,&b);
			par[b] = a;
			g[a].push_back(b);
		}
		for(i = 1; i <= n; i++){
			if(!par[i]){
				par[i] = i;
				level[i] = 1;
				dfs(i,1);
			}
		}
		scanf("%d%d",&a,&b);
		solve(a,b);
	}

}