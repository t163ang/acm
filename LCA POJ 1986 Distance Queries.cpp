#include<iostream>
using namespace std;
const int MN = 40002;
//��Ȼ��Ŀ���ĺ�����һ����������������tarjan�㷨����dfs��������һ��������,����Ҳ����Ӧ��tarjan,����ע��Ӧ������ģ���a-> b��b - >a
struct {
	int v,next,w;
}edge[MN * 3];
int tree[MN],query[MN],ep = 1;
void adde(int s, int v,int w, bool f = true){
	edge[ep].v = v;
	edge[ep].w = w;
	if(f){
		edge[ep].next = tree[s];
		tree[s] = ep++;
	}else{
		edge[ep].next = query[s];
		query[s] = ep++;
	}
}

int n,m;
int par[MN],vis[MN],dis[MN],dep[MN];
int find(int x){
	if(par[x] != -1) return par[x] = find(par[x]);
	return x;
}

void tarjan(int u, int d){
	int i,j,k;
	vis[u] = true;
	dep[u] = d;
	for(i = query[u]; i ; i = edge[i].next){
		j = edge[i].v, k = edge[i].w;
		if(vis[j]){
			dis[k] = dep[u] + dep[j] - (dep[find(j)] << 1);// dist(u,v) = dis(u)+dis(v)-2*dis(LCA(u,v))  *2!!
		}
	}
	for(i = tree[u]; i; i = edge[i].next){
		j = edge[i].v, k = edge[i].w;
		if(!vis[j]){
			tarjan(j,d + k);//d + k!!
			par[j] = u;
		}
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	char s[20];
	int i,j,k,a,b,c;
	while(~scanf("%d%d",&n,&m)){
		ep = 1;
		memset(tree,0,sizeof(tree));
		memset(query,0,sizeof(query));
		memset(vis,0,sizeof(vis));
		memset(par,-1,sizeof(par));
		for(i = 0; i < m; i++){
			scanf("%d%d%d %*c",&a,&b,&c);
			adde(a,b,c);
			adde(b,a,c);
		}
		scanf("%d",&k);
		for(i = 0; i < k; i++){
			scanf("%d%d",&a,&b);
			adde(a,b,i,false);
			adde(b,a,i,false);//��ס���Ҳ��˫���
		}
		tarjan(1,1);
		for(i = 0; i < k; i++){
			printf("%d\n",dis[i]);
		}
	}
	return 0;

}

/*
//���㷨������֮�����������˲��鼯��ʹ�ú͵�ǰ����Ԫ��u�йص�����ѯ�ʶ����������ó���
//�����ֲ���Ҫһһ���㣬���ƽ������ÿ��ѯ��ʱ�伸��Ϊ��������
void tarjan(int u){
	vis[u] = true;
	for(<u,v> in query){
		  if(vis[v]) ans[u][v] = find(v);
	}
	for(<u,v> in tree){
		if(!vis[v]){
			tarjan(v);
			par[v] = u;
		}
	}
}
*/