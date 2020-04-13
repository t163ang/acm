#include<iostream>
#include<algorithm>
using namespace std;
struct Edge{
	int x,y,w;
	bool operator<(const Edge e){
		return w < e.w;
	}
}edge[100000];
int par[110];
int rank[110];
void init(){
	for(int i = 0; i < 110; i++){
		par[i] = i;
		rank[i] = 0;
	}
}

int find(int x){
	if(x != par[x]) par[x] = find(par[x]);
	return par[x];
}

void un(int a,int b){
	if(rank[a] > rank[b]){
		par[b] = a;
	}else{
		par[a] = b;
		if(rank[a] == rank[b]) rank[b]++;
	}
}
int kruskal(int n){
	int k = 1,len = 0;
	init();
	for(int i = 0; k < n; i++){
		int a = edge[i].x, b = edge[i].y,w =edge[i].w;
		int x = find(a), y = find(b);
		if(x != y) {
			un(x,y);
			len += w;
			k++;
		}
	}
	return len;
}
int main(){
	//freopen("in.txt","r",stdin);
	int n,i,j,m;
	while(~scanf("%d",&n)){
		int k = 0;
		for(i = 0; i < n; i++){
			for(j = 0; j < n; j++){
				scanf("%d",&m);
				if(i == j) continue;
				edge[k].x = i; 
				edge[k].y = j; 
				edge[k].w = m;
				k++;
			}		
		}
		sort(edge,edge + k);
		printf("%d\n",kruskal(n));
	}
	return 0;
}