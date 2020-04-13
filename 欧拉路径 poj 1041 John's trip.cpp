#include<iostream>
using namespace std;
const int MN = 46;
int deg[MN];
struct{
	int v,next,z;
	bool vis;
}edge[MN << 10];
int map[MN], ep = 1;
void inline adde(int u, int v,int z){
	edge[ep].v = v;
	edge[ep].next = map[u];
	edge[ep].z = z;
	edge[ep].vis = false;
	map[u] = ep++;
}
int x,y,z;
int sta[MN << 10],top;
void dfs(int u){
	while(true){
		int mm = INT_MAX,j = 0;
		for(int i = map[u]; i != -1; i = edge[i].next){
			if(!edge[i].vis && mm > edge[i].z) {
				mm = edge[i].z;
				j = i;
			}
		}
		if(mm == INT_MAX) break;
		edge[j].vis = true;
		edge[j ^ 1].vis = true;
		dfs(edge[j].v);
		sta[top++] = mm;
	}
}
int main(){
	//freopen("in.txt","r",stdin); 
	int i,j,sx;
	while(scanf("%d%d",&x,&y),x){
		memset(map,-1,sizeof(map)); ep = 0;top = 0;
		memset(deg,0,sizeof(deg));
		scanf("%d",&z);
		adde(x,y,z);
		adde(y,x,z);
		sx = min(x,y);
		deg[x]++; deg[y]++;
		while(scanf("%d%d",&x,&y),x){
			scanf("%d",&z);
			adde(x,y,z);
			adde(y,x,z);
			deg[x]++; deg[y]++;
		}
		for(i = 0; i < MN; i++){
			//printf("deg[%d]: %d\n",i,deg[i]);
			if(deg[i] & 1) {
				printf("Round trip does not exist.\n");
				break;
			}
		}
		if(i >= MN){
			dfs(sx);
			for(j = top - 1; j > 0; j--){
				printf("%d ",sta[j]);
			}
			printf("%d\n",sta[j]);
		}
	}
	return 0;
}