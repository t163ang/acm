#include <iostream>
using namespace std;

const int MN = 50024;
const int INF = 1 << 29;
const int inf = -INF;

struct{
	int v,w,next;
}edge[MN << 6];
int map[MN],ep = 1;

void adde(int s, int d, int w){
	edge[ep].v = d;
	edge[ep].w = w;
	edge[ep].next = map[s];
	map[s] = ep++;
}
int dist[MN],que[MN],head,tail;
bool inque[MN];

void spfa(int src, int des){
	memset(dist,0,sizeof(dist));//这里一定是-oo,不然就无法更新,若为0，则无法得到因为负边返回的边而无法更新其它边，就会变成了dij
	memset(inque,0,sizeof(inque));
	
	head = tail = 0;
	que[tail++] = src;
	dist[src] = 0;
	inque[src] = true;
	while(head  != tail){//循环不能head < tail ! 要head != tail
		int u = que[head]; head = (head + 1) % MN;
		inque[u] = false;
		for(int i = map[u]; i ; i = edge[i].next){//对每条边松驰
			int w = edge[i].w, v = edge[i].v;
			if(dist[u] + w > dist[v]){ //不能>= 若这样将有可能出现无限循环
				dist[v] = dist[u] + w;
				if(!inque[v]){
					inque[v] = true;
					que[tail] = v;
					tail = (tail + 1) % MN;
				}
			}
		}
	}
	printf("%d\n",dist[des]);
}

int main(){   
	//freopen("in.txt","r",stdin);
	int n,i,j,u,v,w;
	int src = INF, des = inf;
	while(~scanf("%d",&n)){
		memset(map,0,sizeof(map)); ep = 1;
		for(i = 0; i < n; i++){
			scanf("%d%d%d",&u,&v,&w);
			// 存在区间 a[u,v] >= w 则d[v] - d[u - 1] >= w ,为了方便u + 1, v + 1
			src = min(src,u);
			des = max(des,v + 1); 
			adde(u,v + 1,w);
		}
		for(i = src; i < des; i++){
			adde(i,i + 1,0);
			adde(i + 1, i,-1);
		}
		spfa(src,des);
	}
	return 0;
}
