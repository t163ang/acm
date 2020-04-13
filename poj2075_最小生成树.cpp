#include<iostream>
#include<string>
#include<map>
using namespace std;
const int MN = 300;
const int INF = 1 << 30;
map<string,int> fmap;
double dist[MN][MN];
double lowcost[MN];
bool vis[MN];
void prim(int n,double cap){
	int i,j,u = 0;
	double len = 0;
	memset(vis,0,sizeof(vis));
	vis[0] = true;
	for(i = 0; i < n; i++){
		lowcost[i] = dist[0][i];
	}

	for(j = 1; j < n; j++){
		double min = INF;
		for(i = 0; i < n; i++){
			if(!vis[i] && lowcost[i] < min){
				min = lowcost[i];
				u = i;
			}
		}
		vis[u] = true;
		len += lowcost[u];
		for(i = 0; i < n; i++){
			if(!vis[i] && lowcost[i] > dist[u][i]){
				lowcost[i] = dist[u][i];
			}
		}
	}
	if(len > cap) printf("Not enough cable\n");
	else printf("Need %.1lf miles of cable\n",len);
}

int main(){
	//freopen("in.txt","r",stdin);
	double cap,len;
	int i,n,m;
	char name[50],name2[50];
	while(~scanf("%lf",&cap)){
		scanf("%d",&n);
		for(i = 0; i < n; i++){
			scanf("%s",name);
			fmap[name] = i;
		}
		scanf("%d",&m);
		memset(dist,127,sizeof(dist));
		for(i = 0; i < m; i++){
			scanf("%s%s%lf",name,name2,&len);
			int x = fmap.find(name)->second, y = fmap.find(name2)->second;
			dist[x][y] = len;
			dist[y][x] = len;
		}
		prim(n,cap);
	}
	return 0;
}