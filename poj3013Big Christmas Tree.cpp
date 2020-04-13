#include<iostream>
#include<queue>

using namespace std;

#define N 65536

struct{
	int v;
	int next;		
	int unit;
}edge[N << 1];
int map[N];
int ep;

const long long INF = LLONG_MAX;

int que[N << 2];
int head,tail;
bool inque[N];

int weight[N];
long long dist[N];

int  main(){
	int v,e;
	int a,b,c;
	int t,i;
	scanf("%d",&t);

	while(t--){
		scanf("%d%d",&v,&e);
		for(i = 1; i <= v; i++) {
			scanf("%d",&weight[i]);
			map[i] = 0;
		}
		ep = 1;
		for(i = 1; i <= e; i++){
			scanf("%d%d%d",&a,&b,&c);
			edge[ep].v = b;
			edge[ep].unit = c;
			edge[ep].next = map[a];
		    map[a] = ep++;
			edge[ep].v = a;
			edge[ep].unit = c;
			edge[ep].next = map[b];
		    map[b] = ep++;
		}
		
		head = tail = 0;
		for(i = 0; i <= v; i++){
			dist[i] = INF;
			inque[i] = false;
		}
		dist[1] = 0;
		inque[1] = true;
		que[tail++] = 1;
		while(head < tail){
			int u = que[head++];
			inque[u] = false;
			for(i = map[u]; i ; i = edge[i].next){
				if(dist[u] + edge[i].unit < dist[edge[i].v]){
					dist[edge[i].v] = dist[u] + edge[i].unit;
					if(!inque[edge[i].v]){
					inque[edge[i].v] = true;
					que[tail++] = edge[i].v;
				}
			}
				
			}
		}
		
		long long ans = 0;
		bool flag = false;
		for(i = 1; i <= v; i++){
			if(dist[i] == INF) {
				printf("No Answer\n");
				flag = true;
				break;
			}
			ans += weight[i] * dist[i];
		}
	    if(!flag) printf("%lld\n",ans);	
	}
	return 0;
}
