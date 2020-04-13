#include<iostream>
#include<queue>
using namespace std;
const int MN = 220;
const int INF = 1 << 30;
int n,m;
int cap[MN][MN];
int h[MN],e[MN];
int S,T;
//int que[1000000],qh,qt;
queue<int> que;
bool inque[MN];
void push(int u, int v){
	int c = min(cap[u][v],e[u]);
	e[u] -= c;
	e[v] += c;
	cap[u][v] -= c;
	cap[v][u] += c;
	if(!inque[v] && v != T && v != S){
		//que[qt++] = v;
		que.push(v);
		inque[v] = true;
	}	
}
void discharge(int u){
	while(true){
		int minn = INT_MAX;
		for(int v = S; v <= T; v++){
			if(cap[u][v] > 0){
				if(h[u] == h[v] + 1){
					push(u,v);	
				}
				if(minn > h[v]) minn = h[v];
			}
		}
		if(e[u] <= 0) break;
		h[u] = minn + 1;
	}
}
void flow(){
	memset(h,0,sizeof(h));
	memset(e,0,sizeof(e));
	//memset(inque,0,sizeof(inque));
	//qh = qt = 0;
	e[S] = INF;
	h[S] = m; //将源点高度设为包括源点和终点的数目
	//将与源点相领的结点尽可能地push
	for(int v = S; v <= T; v++){
		if(cap[S][v]){
			push(S,v);
		}
	}
	while(!que.empty()){
		//int u = que[qh++];
		int u = que.front(); que.pop();
		inque[u] = false;
		discharge(u);
	} 
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,a,b,c;
	while(~scanf("%d%d",&n,&m)){
		memset(cap,0,sizeof(cap));
		for(i = 0; i < n; i++){
			scanf("%d%d%d",&a,&b,&c);
			cap[a][b] += c;
		}
		S = 1;
		T = m;
		flow();
		printf("%d\n",e[T]);
	}
	return 0;
}