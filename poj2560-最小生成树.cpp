#include<iostream>
#include<cmath>
using namespace std;
const int MN = 110;
struct{
	double x,y;
}point[MN];
double dist[MN][MN];
double lowcost[MN];
bool vis[MN];
double prim(int n){
	memset(vis,0,sizeof(vis));
	int i,j,u = 0;
	double len = 0;
	vis[u] = true;
	for(i = 0; i < n; i++){
		lowcost[i] = dist[u][i];
	}
	for(j = 1; j < n; j++){
		int min = INT_MAX;
		for(i = 0; i < n; i++){
			if(!vis[i] && lowcost[i] < min){
				min = lowcost[i];
				u = i;
			}
		}
		len += lowcost[u];
		vis[u] = true;
		for(i = 0; i < n; i++){
			if(!vis[i] && lowcost[i] > dist[u][i]){
				lowcost[i] = dist[u][i];
			}
		}
	}
	return len;
}
int main(){
	//freopen("in.txt","r",stdin);
	int n,i,j;
	double x,y;
	while(~scanf("%d",&n)){
		for(i = 0; i < n; i++){
			scanf("%lf%lf",&x,&y);
			point[i].x = x;
			point[i].y = y;
		}
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				if(i == j){
					dist[i][j] = 0;
					continue;
				}
				double dy = point[j].y - point[i].y;
				double dx = point[j].x - point[i].x;
				dist[i][j] = sqrt(dy * dy + dx * dx);
			}
		}
		printf("%.2lf\n",prim(n));
	}
	return 0;
}