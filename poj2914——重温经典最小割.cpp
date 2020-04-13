/*
ID: davidro2
PROG: poj2914
LANG: C++
*/
#include<iostream>
using namespace std;
const int MN = 524;
int map[MN][MN];
int n,m,V;
int w[MN];
bool combine[MN];
bool vis[MN];
int madj(int &s,int &t){
	memset(w,0,sizeof(w));
	memset(vis,0,sizeof(vis));
	for(int i = 0; i < V; i++){
		int u = -1,maxx = -1;
		for(int j = 0; j < V; j++){
			if(!combine[j] && !vis[j] && w[j] > maxx){
				maxx = w[j];
				u = j;
			}
		}
		if(u == -1) return w[t];
		vis[u] = true; s = t; t = u;
		for(int j = 0; j < V;j++){
			if(!combine[j] && !vis[j]){
				w[j] += map[t][j];
			}
		}
	}
	return w[t];
}
int minCut(){
	int ans = INT_MAX;
	memset(combine,0,sizeof(combine));
	for(int i = 1; i < V; i++){
		int s = -1,t = -1,cut;
		cut = madj(s,t);
		combine[t] = true;
		if(ans > cut) ans = cut;
		for(int j = 0; j < V; j++){
			if(!combine[j]){
				map[s][j] += map[t][j];
				map[j][s] += map[j][t];
			}
		}
	}
	return ans;
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,a,b,c;
	while(~scanf("%d%d",&n,&m)){
		memset(map,0,sizeof(map));
		for(i = 0; i < m; i++){
			scanf("%d%d%d",&a,&b,&c);
			map[a][b] += c;
			map[b][a] += c;
		}
		V = n;
		printf("%d\n",minCut());
	}
	return 0;
}