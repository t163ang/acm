#include<iostream>
#include<queue>
using namespace std;
const int MN = 1024;
int e[MN], h[MN];
int n,m,S,T;
struct{
	int v,c,next;
}edge[MN << 10];
int map[MN]; int ep;

void adde(int u, int v,int c){
	edge[ep].v = v;
	edge[ep].c = c;
	edge[ep].next = map[u];
	map[u] = ep++;
}
struct Node{
	int v;
	bool operator < (const Node n) const{
		return h[v] < h[n.v];
	}
	Node(int u):v(u){}
};
bool inque[MN];
priority_queue<Node> que;

void discharge(int u){
	int v,d,minn;
	while(e[u] > 0){//while做法是relabe_to_front 没有while则是是push_relabe
		minn = INT_MAX;
		for(int i = map[u]; i != -1 && e[u] > 0; i = edge[i].next){
			if(edge[i].c <= 0) continue;// 这个要记住一定要有因为程序方便并c == 0一样存在边
			v = edge[i].v;
			if(h[u] == h[v] + 1){
				d = min(e[u],edge[i].c);
				edge[i].c -= d;
				edge[i^1].c += d;
				e[u] -= d;
				e[v] += d;
				if(v != S && v != T && !inque[v]) {
					que.push(Node(v));
					inque[v] = true;
				}
			}
			if(minn > h[v]) minn = h[v];
		}
		if(e[u] > 0) h[u] = minn + 1; //若不用while循环则这里push(Node(u))即可
	}
}

int push_relabel(){
	memset(h,0,sizeof(h));
	memset(e,0,sizeof(e));
	memset(inque,0,sizeof(inque));
	h[S] = n; e[S] = INT_MAX;
	for(int i = map[S]; i != -1; i = edge[i].next){
		int u = edge[i].v;
		int d = edge[i].c;
		edge[i].c -= d;
		edge[i^1].c += d;
		e[S] -= d;
		e[u] += d;
		if(u != S && u != T && !inque[u]){ que.push(Node(u)); inque[u] = true;}
	}
	while(!que.empty()){
		int u = que.top().v; que.pop(); inque[u] = false;
		discharge(u);
	}
	return e[T];
}
int main(){
	//freopen("in.txt","r",stdin); 
	int i,j,k,w,m;
	while(~scanf("%d%d",&m,&n)){
		memset(map,-1,sizeof(map)); ep = 0;
		S = 1, T = n;
		for(i = 0; i < m; i++){
			scanf("%d%d%d",&j,&k,&w);
			adde(j,k,w);
			adde(k,j,0);
		}
		printf("%d\n",push_relabel());
	}
}
//或简单点
//#include<iostream>
//#include<queue>
//using namespace std;
//const int MN = 1024;
//int e[MN], h[MN];
//int n,m,S,T;
//struct{
//	int v,c,next;
//}edge[MN << 10];
//int map[MN]; int ep;
//
//void adde(int u, int v,int c){
//	edge[ep].v = v;
//	edge[ep].c = c;
//	edge[ep].next = map[u];
//	map[u] = ep++;
//}
//struct Node{
//	int v;
//	bool operator < (const Node n) const{
//		return h[v] < h[n.v];
//	}
//	Node(int u):v(u){}
//};
//bool inque[MN];
//priority_queue<Node> que;
//
//void discharge(int u){
//	int v,d,minn;
//	while(e[u] > 0){//while做法是relabe_to_front 没有while则是是push_relabe
//		minn = INT_MAX;
//		for(int i = map[u]; i != -1 && e[u] > 0; i = edge[i].next){
//			if(edge[i].c <= 0) continue;// 这个要记住一定要有因为程序方便并c == 0一样存在边
//			v = edge[i].v;
//			if(h[u] == h[v] + 1 || u == S){
//				d = min(e[u],edge[i].c);
//				edge[i].c -= d;
//				edge[i^1].c += d;
//				e[u] -= d;
//				e[v] += d;
//				if(v != S && v != T && !inque[v]) {
//					que.push(Node(v));
//					inque[v] = true;
//				}
//			}
//			if(minn > h[v]) minn = h[v];
//		}
//		if(u == S) return;
//		if(e[u] > 0) h[u] = minn + 1; //若不用while循环则这里push(Node(u))即可
//	}
//}
//
//int push_relabel(){
//	memset(h,0,sizeof(h));
//	memset(e,0,sizeof(e));
//	memset(inque,0,sizeof(inque));
//	h[S] = n; e[S] = INT_MAX;
//	//for(int i = map[S]; i != -1; i = edge[i].next){
//	//	int u = edge[i].v;
//	//	int d = edge[i].c;
//	//	edge[i].c -= d;
//	//	edge[i^1].c += d;
//	//	e[S] -= d;
//	//	e[u] += d;
//	//	if(u != S && u != T && !inque[u]){ que.push(Node(u)); inque[u] = true;}
//	//}
//	que.push(Node(S));
//	while(!que.empty()){
//		int u = que.top().v; que.pop(); inque[u] = false;
//		discharge(u);
//	}
//	return e[T];
//}
//int main(){
//	//freopen("in.txt","r",stdin); 
//	int i,j,k,w,m;
//	while(~scanf("%d%d",&m,&n)){
//		memset(map,-1,sizeof(map)); ep = 0;
//		S = 1, T = n;
//		for(i = 0; i < m; i++){
//			scanf("%d%d%d",&j,&k,&w);
//			adde(j,k,w);
//			adde(k,j,0);
//		}
//		printf("%d\n",push_relabel());
//	}
//}