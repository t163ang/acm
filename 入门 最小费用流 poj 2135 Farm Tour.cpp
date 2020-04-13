#include<iostream>
using namespace std;
const int MN = 1024;
const int INF = 1 << 30;
struct{
	int u,v,w,c,next;
}Edge[MN << 10];
int map[MN],ep = 1;
////ע��˫������������������˫��߻���ر�ʱ���͵����ڽӱ�����
void adde(int u, int v, int w, int c = 1){
	Edge[ep].u = u;
	Edge[ep].v = v;
	Edge[ep].w = w;
	Edge[ep].c = c;
	Edge[ep].next = map[u];
	map[u] = ep++;

	Edge[ep].u = v;
	Edge[ep].c = 0;
	Edge[ep].v = u;
	Edge[ep].w = -w;
	Edge[ep].next = map[v];
	map[v] = ep++;
}
int n,m;
int d[MN];bool inque[MN];
int que[MN]; int pre[MN];
bool spfa(){
	int i,tail = 0,head = 0;
	fill(d,d + MN,INF);
	memset(inque,0,sizeof(inque));
	memset(pre,-1,sizeof(pre));
	d[0] = 0; inque[0] = true;
	que[tail++] = 0;
	while(head != tail){
		int u = que[head]; head = (head + 1) % MN; inque[u] = false;
		for(i = map[u]; i != -1; i = Edge[i].next){
			int v = Edge[i].v, c = Edge[i].c;
			if(c > 0 &&d[u] + Edge[i].w < d[v]){
				d[v] = d[u] + Edge[i].w;
				pre[v] = i;
				if(!inque[v]){
					inque[v] = true;
					que[tail] = v;
					tail = (tail + 1) % MN;
				}
			}

		}
	}
	return d[n + 1] != INF;
}

void mincost(){
	int x, ans = 0;
	while(spfa()){
		x = pre[n + 1];
		ans += d[n + 1];
		while(x != -1){
			Edge[x].c -= 1;
			Edge[x ^ 1].c += 1;
			x = pre[Edge[x].u];
		}
	}
	printf("%d\n",ans);
}
int main(){
	//freopen("in.txt","r",stdin);
	while(~scanf("%d%d",&n,&m)){
		memset(map,-1,sizeof(map)); ep = 0;
		int u,v,w;
		for(int i = 0; i < m; i++){
			scanf("%d%d%d",&u,&v,&w);
			adde(u,v,w);
			adde(v,u,w);
		}
		adde(0,1,0,2); 
		adde(n,n + 1,0,2);
		mincost();
	}
	return 0;
}
//
////��С������
////��ͼ�ؼ�����ӳ���Դ�㣬�������
////������Ҫ��һ���������յ�������·����2��·����֮�������ÿ��·ֻ�ܾ���һ��
////��һ��������ת��Ϊ��2������㵽�յ�
////�ڶ�����������ҹ��������뵱�����ã�����������Ϊ1��Ϊ�˱�֤ÿ��·ֻ����һ��
////����Դ�����������Ϊ2���յ�ͳ����������Ϊ2��ʹ�������2��·
////���յ�mincost��Ϊ��
////ע��˫������������������˫��߻���ر�ʱ���͵����ڽӱ�����
//#include<iostream>
//#include<queue>
//using namespace std;
//const int MAXN = 1003;
//const int MAXM = 40005;
//const int INF = 1000000000;
//int mincost,maxflow;
//int N,M;
//int U[MAXM],V[MAXM],cap[MAXM],flow[MAXM],cost[MAXM],next[MAXM];
//int head[MAXN],pre[MAXN],Edge[MAXN],dis[MAXN];
//int m;
//void addEdge(int u,int v,int Cap,int Cost)
//{
//	flow[m] = flow[m+1] = 0;
//	V[m] = v;
//	U[m] = u;
//	cap[m] = Cap;
//	cost[m] = Cost;
//	next[m] = head[u];
//	head[u] = m++;
//	
//	V[m] = u;
//	U[m] = v;
//	cap[m] = 0;
//	cost[m] = -Cost;
//	next[m] = head[v];
//	head[v] = m++;
//}
//void buildGraph()
//{
//	scanf("%d%d",&N,&M);
//	int u,v,c;
//	m = 0;
//	memset(head,-1,sizeof(head));
//	while(M--)
//	{
//		scanf("%d%d%d",&u,&v,&c);
//		addEdge(u,v,1,c);
//		addEdge(v,u,1,c);
//	}
//	addEdge(0,1,2,0);
//	addEdge(N,N+1,2,0);
//}
//void MCMF(int st,int ed)
//{
//	queue<int> q;
//	memset(flow,0,sizeof(flow));
//	mincost = maxflow = 0;
//	for(;;)
//	{
//		bool inq[MAXN];
//		for(int i = st;i <= ed;++i)		dis[i] = (i == st ? 0 : INF);
//		memset(inq,0,sizeof(inq));
//		q.push(st);
//		while(!q.empty())
//		{
//			int u = q.front();	q.pop();
//			inq[u] = 0;
//			for(int e = head[u];e != -1;e = next[e])
//			{
//				if(cap[e] > flow[e] && dis[u] + cost[e] < dis[V[e]])
//				{
//					dis[V[e]] = dis[u] + cost[e];
//					pre[V[e]] = U[e]; 
//					Edge[V[e]] = e;
//					if(!inq[V[e]])
//					{
//						q.push(V[e]);
//						inq[V[e]] = 1;
//					}
//				}
//			}
//		}//SPFA����
//		if(dis[ed] == INF)	break;
//		int delta = INF;//deltaΪ�ɸĽ���
//		for(int u = ed;u != st;u = pre[u])
//			delta = min(delta,cap[Edge[u]] - flow[Edge[u]]);//�������·���ıߣ����޸ĿɸĽ���
//		for(int u = ed;u != st;u = pre[u])
//		{
//			flow[Edge[u]] += delta;//������������
//			flow[Edge[u] ^ 1] -= delta;//ͨ�����1ȡ�÷���ߵ���ţ������·�������
//		}
//		mincost += dis[ed] * delta;
//		maxflow += delta;
//	}
//}
//	
//int main()
//{
//	//freopen("in.txt","r",stdin);
//	buildGraph();
//	MCMF(0,N+1);
//	printf("%d\n",mincost);
//	return 0;
//}