#include<iostream>
#include<queue>
#include<vector>
using namespace std;
//这个davidron 3268 Accepted 336K 16MS C++ 
const int MN = 1024;
struct{
	int v,next,w;
}edge[200024];
int ep = 1;
int map[MN];//back
int map2[MN];//go
inline void adde(int s, int v, int w){
	edge[ep].v = v;
	edge[ep].w = w;	
	edge[ep].next = map[s];
	map[s] = ep++;
	
	edge[ep].w = w;
	edge[ep].v = s;
	edge[ep].next = map2[v];
	map2[v] = ep++;
}

int n,m,x,a,b,t;
int dis[MN],dis2[MN];
bool inque[MN];

struct Road{
	int i;bool go;
	bool operator < (const Road r) const {
	   return dis[i] > dis[r.i];//关键是这里使用自定义dis[i]比较
	}
	Road(int x):i(x){}
};

void dij(bool go){
	//这个dij与spfa做法几乎一样，不过dij用了堆优化，而spfa没有
	priority_queue<Road> que;
	que.push(Road(x));
	memset(inque,0,sizeof(inque));
	memset(dis,63,sizeof(dis));
	inque[x] = true;
	dis[x] = 0;
	while(!que.empty()){
		int u = que.top().i;
		que.pop(); inque[u] = false;
		int j = go ? map2[u] : map[u];
		for( ;j; j = edge[j].next){
			int len = dis[u] + edge[j].w; 
			int v = edge[j].v;
			if(len < dis[v]){
				dis[v] = len;
				if(!inque[v]) {//这样子就可以像spfa一样做了
					que.push(Road(v));
					inque[v] = true;
				}
			}
		}
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,k;
	while(~scanf("%d%d%d",&n,&m,&x)){
		ep = 1;
		memset(map,0,sizeof(map));
		memset(map2,0,sizeof(map2));
		for(i = 0; i < m; i++){
			scanf("%d%d%d",&a,&b,&t);
			adde(a,b,t);
		}
		
		dij(false);
		memcpy(dis2,dis,sizeof(dis));
		dij(true);
		int max = 0;
		for(i = 1; i <= n; i++){
			if(i == x) continue;
			k = dis[i] + dis2[i];
			if(max < k) max = k;
		}
		printf("%d\n",max);
	}
	return 0;
}

//这个davidron 3268 Accepted 8384K 94MS C++ 
//#include<iostream>
//#include<queue>
//#include<vector>
//using namespace std;
//const int MN = 1024;
//int map[MN][MN];//back
//int map2[MN][MN];//go
//int n,m,x,a,b,t;
//int dis[MN],dis2[MN];
//bool inque[MN];
//
//struct Road{
//	int i;bool go;
//	bool operator < (const Road r) const {
//	   return dis[i] > dis[r.i];
//	}
//	Road(int x):i(x){}
//};
//
//void dij(bool go){
//	priority_queue<Road> que;
//	que.push(Road(x));
//	memset(inque,0,sizeof(inque));
//	memset(dis,63,sizeof(dis));
//	inque[x] = true;
//	dis[x] = 0;
//	while(!que.empty()){
//		int u = que.top().i;
//		que.pop(); inque[u] = false;
//		for(int j = 1; j <= n; j++){
//			int len = dis[u] + (go ? map2[u][j] : map[u][j]);
//			if(len < dis[j]){
//				dis[j] = len;
//				if(!inque[j]) {
//					que.push(Road(j));
//					inque[j] = true;
//				}
//			}
//		}
//	}
//}
//int main(){
//	//freopen("in.txt","r",stdin);
//	int i,j,k;
//	while(~scanf("%d%d%d",&n,&m,&x)){
//		memset(map,63,sizeof(map));
//		memset(map2,63,sizeof(map2));
//		for(i = 0; i < m; i++){
//			scanf("%d%d%d",&a,&b,&t);
//			map[a][b] = t;
//			map2[b][a] = t;
//		}
//		dij(false);
//		memcpy(dis2,dis,sizeof(dis));
//		dij(true);
//		int max = 0;
//		for(i = 1; i <= n; i++){
//			if(i == x) continue;
//			k = dis[i] + dis2[i];
//			if(max < k) max = k;
//		}
//		printf("%d\n",max);
//	}
//	return 0;
//}
