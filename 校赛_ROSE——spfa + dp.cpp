#include<iostream>
#include<queue>
using namespace std;
const int INF = 0x7fffffff;
const int MN = 1024;
int n,m,S,T;
struct{
	int v,c,next;
}edge[10000000];
int head[1002],pn;
void adde(int u,int v,int c){
	edge[pn].v = v;
	edge[pn].c = c;
	edge[pn].next = head[u];
	head[u] = pn++;
}
int dp[MN];
bool inque[MN];
queue<int> que;
/*
由题可知dp[v]=max(min(dp[u],w[u][v]),dp[v])而这个是在图上dp的，
可以使用spfa算法将dp[v]看成dist[v]即是最短路问题。
*/
void spfa(){
	memset(dp,0,sizeof(dp));
	memset(inque,0,sizeof(inque));
	que.push(S);
	dp[S] = INF;
	while(!que.empty()){
		int u = que.front(); que.pop();
		inque[u] = false;
		for(int i = head[u]; i ; i = edge[i].next){
			int v = edge[i].v,c = edge[i].c;
			if(min(dp[u],c) > dp[v]){
				dp[v] = min(dp[u],c);
				if(!inque[v]){
					inque[v] = true;
					que.push(v);
				}
			}
		}
	}
	printf("%d\n",dp[n]);
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,i,j,a,b,w;
	scanf("%d",&t);
	while(t--){
		memset(head,0,sizeof(head));
		pn = 1;
		scanf("%d%d",&n,&m);
		S = 1; T = n;
		for(i = 1; i <= m; i++){
			scanf("%d%d%d",&a,&b,&w);
			adde(a,b,w);
			adde(b,a,w);
		}
		spfa();
	}
}

//February 14th every year is the Western Valentine's Day. Valentine's Day is called “qingrenjie” in China, on this day lovers give each other chocolates, cards and roses to express their love or friendship.
//Qiu is a boy from Jiangmen, on February 14th he is going to visit a friend Jun, Jun is a girl who loves roses very much. In order to keep up with trends, Qiu want to give Jun a branch of flower as gift. For this special day and special meaning, the number of roses of any branch should be an integer which consist of several 9s, such as 9, 99, 999… (at most nine 9s). After Qiu’s research, there are many ways from his home to Jun’s home, but there is a limit in every road, that is to say if you take too many roses (more than the limit), you can’t go through this load. Furthermore, roses are very expensive (9.9$ each (>_<)), so Qiu did not want to throw any roses away.
//In order to please Jun, Qiu ask you a clever acmer to help him, calculate that how many roses he can send most from his house to Jun’s house through these roads?
// 
//Hint:
//1．Be in sure that there have a way from 1 to N.
//2．Have great data entry questions, please use scanf to read data.
//3．There is only one road between u and v.
//
//Input
//The first line is a number T, then T-case below.
//In every case there are two number N,M in the first line.(2 <= N <= 1000, 1 <= M <= 50000) express there has N point in the map,(Qiu is always No.1,Jun is always No.N), and there are M undirected roads in the map.
//After that, there are M lines, each line there are 3 numbers (u,v,w),express that there is an undirected road between u and v, and the road’s limit is w.(it means if you have x roses, then (x <= w) you can go through this road).
//
//Output
//Output how many roses Qiu can send most to Jun.
//
//Sample Input	Sample Output
//2
//3 2
//1 2 999
//2 3 99
//3 3
//1 2 999
//2 3 99
//3 1 9999	99
//9999

///*
//边有约束图
//还有一种解法，是用枚举 + bfs
//因为只有9、99、。。。。999999999九种可能，所以可以将这些边限制枚举出来，再构图。
//并利用bfs求连通
//*/
//#include <cstdio>
//#include <queue>
//using namespace std;
//
//const int maxn = 1010;
//const int maxm = 100010;
//const int Ma = 999999999;
//const int Mi = 9;
//int n, m;
//
//struct Edge{
//	int v, cost, next;
//}et[maxm];
//int eh[maxn], tot;
//
//bool vist[maxn];
//
//void add(int u, int v, int cost) {
//	Edge e = {v, cost, eh[u]};
//	et[tot] = e;
//	eh[u] = tot++;
//}
//
//bool bfs(int x) {
//	queue<int> que;
//	memset(vist, false, sizeof(vist));
//	que.push(1);
//	vist[1] = true;
//	while (!que.empty()) {
//		int u = que.front();
//		que.pop();
//		for (int i = eh[u]; i !=-1; i = et[i].next) {
//			int v = et[i].v, cost = et[i].cost;
//			if (!vist[v] && cost >= x) {
//				if (v == n) return true;
//				vist[v] = true;
//				que.push(v);
//			}
//		}
//	}
//	return false;
//}
//
//void solve() {
//	int res = 9;
//	for (int x = Mi; x <= Ma; x = x * 10 + 9)
//		if (bfs(x) == true) res = x;
//	printf("%d\n", res);
//}
//
//int main() {
//	int T;
//	scanf("%d", &T);
//	int a, b, c;
//	while (T--) {
//		memset(eh, -1, sizeof(eh));
//		tot = 0;
//		scanf("%d %d", &n, &m);
//		for (int i = 1; i <= m; i++) {
//			scanf("%d %d %d", &a, &b, &c);
//			add(a, b, c), add(b, a, c);
//		}
//		solve();
//	}
//	return 0;
//}

