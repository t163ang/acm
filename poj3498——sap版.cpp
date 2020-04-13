/*
ID: davidro2
PROG: poj3498
LANG: C++
*/
#include<iostream>
#include<cmath>
using namespace std;
int N,pe,S = 0,T;
double D;
const int MN = 204;
const int INF = 1 << 30;
int cap[MN][MN];
int map[MN][MN];
int X[MN],Y[MN];
double inline getD(int x, int y ,int x1,int y1){
	double dx = x1 - x, dy = y1 - y;
	return sqrt(dx * dx + dy * dy);
}

void addedge(){
	double dist;
	for(int i = 1; i < N; i++){
		for(int j = i + 1; j <= N; j++){
			dist = getD(X[i],Y[i],X[j],Y[j]);
			if(dist <= D){
				cap[j + N][i] = INF;
				cap[i + N][j] = INF;
			}
		}
	}
}
int que[1000000],qh,qt;
int h[MN],num[MN];
int pre[MN];
void init(){
	qh = qt = 0;
	memset(h,-1,sizeof(h));
	memset(num,0,sizeof(num));
	h[T] = 0;
	que[qt++] = T;
	while(qh != qt){
		int u = que[qh++];
		for(int v = S; v <= 2 * N; v++){
			if(h[v] == -1 && map[v][u] > 0){
				h[v] = h[u] + 1;
				que[qt++] = v;
				num[h[v]]++;
			}
		}
	}
}

int find(int u){
	for(int v = S; v <= 2 * N; v++){
		if(map[u][v] > 0 && h[u] == h[v] + 1){
			return v;
		}
	}
	return -1;
}

int relable(int u){
	int minn = INF;
	for(int v = S; v <= 2 * N; v++){
		if(map[u][v] > 0 && minn > h[v]){
			 minn = h[v];
		}
	}
	if(minn != INF) return minn + 1;
	return 2 * N + 1;
}
int flow(){
	init();
	memset(pre,-1,sizeof(pre));
	int i = S,j,flow = 0;
	while(h[S] <= 2 * N){
		j = find(i);
		if(j >= 0){
			pre[j] = i;
			i = j;
			if(i == T){
				int minn = INF;
				i = T;
				while(i != S){
					if(minn > map[pre[i]][i]) minn = map[pre[i]][i];
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
			int m = relable(i);
			num[m]++;
			num[h[i]]--;
			if(num[h[i]] == 0) return flow;
			h[i] = m;
			if(i != S){
				i = pre[i];
			}
		}
	}
	return flow;
}
int main(){
	//freopen("in.txt","r",stdin);
	int t,i,c,d;
	scanf("%d",&t);
	while(t--){
		scanf("%d%lf",&N,&D);
		memset(cap,0,sizeof(cap));
		pe = 0;
		for(i = 1; i <= N; i++){
			scanf("%d%d%d%d",X + i,Y + i,&c,&d);
			cap[S][i] = c;
			pe += c;
			cap[i][i + N] = d;
		}
		addedge();
		/*
			Ã¶¾Ù»ãµã
		*/
		bool flag = true;
		for(T = 1; T <= N; T++){
			memcpy(map,cap,sizeof(cap));
			int tmp = flow();
			if(tmp == pe){
				printf("%d ",T - 1);
				flag = false;
			}
		}
		if(flag) puts("-1");
		else puts("");
	}
	return 0;
}