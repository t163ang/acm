/*
ID: davidro2
PROG: poj3498
LANG: C++
*/
#include<iostream>
#include<cmath>
#include<queue>
using namespace std;
int N,pe,S = 0,T;
double D;
const int MN = 204;
const int INF = 1 << 30;
int cap[MN][MN];
int map[MN][MN];
int X[MN],Y[MN];
struct Point{
	int v,h;
	Point(int a,int b):v(a),h(b){}
	friend bool operator<(Point p1,Point p2){
		return p1.h < p2.h;
	}
};
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
//priority_queue<Point> que;
int que[1000000],qh,qt;
bool inque[MN];
int h[MN],e[MN];
void push(int u,int v){
	int d = min(map[u][v],e[u]);
	e[u] -= d;
	e[v] += d;
	map[u][v] -= d;
	map[v][u] += d;
	if(!inque[v] && v != S && v != T){
		//Point p = Point(v,h[v]);
		//que.push(p);
		que[qt++] = v;
		inque[v] = true;
	}
}

void discharge(int u){
	while(true){
		int minn = INF;
		for(int v = S; v <= 2 * N; v++){
			if(map[u][v] > 0){
				if(h[u] == h[v] + 1){
					push(u,v);
					if(e[u] == 0) break;
				}
				if(minn > h[v]) minn = h[v];
			}
		}
		if(e[u] > 0) h[u] = minn + 1;
		else break;
	}
}
bool flow(){
	memset(inque,0,sizeof(inque));
	memset(h,0,sizeof(h));
	memset(e,0,sizeof(e));
	e[S] = INF;
	h[S] = 2 * N + 1;
	qh = qt = 0;
	for(int v = 1; v <= N; v++){
		if(map[S][v] > 0){
			push(S,v);
		}
	}
	while(qt != qh){
		//Point p = que.top(); que.pop();
		int u = que[qh++];
		inque[u] = false;
		discharge(u);
	}
	if(e[T] == pe) return true;
	return false;
}
int main(){
	//freopen("in.txt","r",stdin);
	int t,i,j,c,d;
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
			if(flow()){
				printf("%d ",T - 1);
				flag = false;
			}
		}
		if(flag) puts("-1");
		else puts("");
	}
	return 0;
}