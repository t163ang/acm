#include<cstdio>
#include<algorithm>
using namespace std;

const int MN = 15024;
int par[MN],rank[MN];
long long ans;
struct Edge{
	int a,b;
	int w;
	bool operator < (const Edge e)const{
		return w < e.w;
	}
}edge[MN];
void init(){
	for(int i = 0; i < MN; i++){
		par[i] = i;
		rank[i] = 1;
	}
}

int find(int x){
	if(x != par[x]) return par[x] = find(par[x]);
	return par[x];
}

void un(int a, int b, int w){
	a = find(a), b = find(b);
   if(a == b) return;
	if(rank[a] > rank[b]) {
		par[b] = a;
		ans += w;
		ans +=(long long)(w + 1) * (rank[a] * rank[b] - 1);//妈的，又是没有long long先保存结果，他妈的
		rank[a] += rank[b];
	}else{
		par[a] =  b;
		ans += w;
		ans +=(long long)(w + 1) * (rank[a] * rank[b] - 1);
		rank[b] += rank[a];
	}
}


int main()
{
	//freopen("in.txt","r",stdin);
	int i,n,t;
	scanf("%d",&t);
	while(t--)
	{
		init();
		scanf("%d",&n);
		for(i = 0; i < n - 1; i++){
			scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].w);
		}
		sort(edge, edge + (n - 1));
		ans = 0;
		for(i =0 ;i < n - 1; i++){
			int a = find(edge[i].a ), b = find(edge[i].b),w = edge[i].w;
			un(a,b,w);
		}
		printf("%lld\n",ans);
	}

	return 0;
}
