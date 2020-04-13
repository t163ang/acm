#include<iostream>
using namespace std;
const int MN = 1024;
struct {
	int v,w,next;
}edge[MN << 6];
int map[MN],ep;
void adde(int s, int d, int w){
	edge[ep].v = d;
	edge[ep].w = w;
	edge[ep].next = map[s];
	map[s] = ep++;
}

int n,m;
int c[MN];
int que[MN],head,tail,dist[MN];
bool inque[MN]; int lev[MN];

void spfa(){
	memset(dist,128,sizeof(dist));
	memset(inque,0,sizeof(inque));
	memset(lev,0,sizeof(lev));
	head = tail = 0;
	que[tail++] = 0;
	dist[0] = 0;
	inque[0] = true;
	lev[0]++;
	bool flag = true;
	while(head != tail){
		int u = que[head]; head = (head + 1) % MN;
		inque[u] = false;
		for(int i = map[u]; i ; i = edge[i].next){
			int v = edge[i].v, w = edge[i].w;
			if(dist[u] + w > dist[v]){
				dist[v] = dist[u] + w;
				if(!inque[v]){
					inque[v] = true;
					que[tail] = v;
					lev[v]++;
					if(lev[v] >= n){printf("Bad Estimations\n");flag = false; break;}//理论上是无限循环，但因为int表示范围，所以不会无限变大
					tail = (tail + 1) % MN;
				}
			}
		}
	}
	 if(flag) printf("%d\n",dist[n]);
}
//在 zju 的C++系统里， 不存在 __int64, 所以只能用 long long 
int main(){
	//freopen("in.txt","r",stdin);
	int i;
	while(~scanf("%d%d",&n,&m)){
		memset(map,0,sizeof(map)); ep = 1;
		for(i = 1; i <= n; i++){
			scanf("%d",&c[i]);
		}
		for(i = 1; i <= m; i++){
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			adde(u - 1,v,w);
		}
		for(i = 1; i <= n; i++){
			adde(i - 1, i,0);
			adde(i, i - 1, -c[i]);
		}
		spfa();
	}
	return 0;
}
