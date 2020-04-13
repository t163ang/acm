/*
��Ŀ�������ǵ���ͼ����Դ������������·��ʱ������ͼ���෴������㵽Դ���÷���ͼ��
*/
#include<iostream>
#include<queue>
using namespace std;
const int MN = 1000024;
const int INF = 1 << 30;
struct{
	int v,cost,next;
}edge[MN << 4];
int head[MN];
int head2[MN];
int pn,p,q;
void inline adde(int u,int v,int cost,int *head){
	edge[pn].v = v;
	edge[pn].cost = cost;
	edge[pn].next = head[u];
	head[u] = pn++;
}
__int64 dist[MN];//���鿪С�˻���__int64����wa
bool inque[MN];
queue<int> que;
__int64 spfa(int *head){
	memset(inque,0,sizeof(inque));
	memset(dist,-1,sizeof(dist));
	dist[1] = 0;
	que.push(1);
	while(!que.empty()){
		int u = que.front(); que.pop();
		inque[u] = false;
		for(int i = head[u]; i ; i = edge[i].next){
			int v = edge[i].v, tmp = dist[u] + edge[i].cost;//Ҳ�����м���̴���int��Χ
			if(dist[u] != -1 && (tmp < dist[v] || dist[v] == -1)){
				dist[v] = tmp;
				if(!inque[v]){
					inque[v] = true;
					que.push(v);
				}
			}
		}
	}
	__int64 ans = 0;
	for(int i = 2;i <= p; i++){
		ans += dist[i];
	}
	return ans;
}
int main(){
	//freopen("in.txt","r",stdin);
	int n,i,a,b,c;
	scanf("%d",&n);
	while(n--){
		pn = 1;
		memset(head,0,sizeof(head));
		memset(head2,0,sizeof(head2));
		scanf("%d%d",&p,&q);
		for(i = 0; i < q; i++){
			scanf("%d%d%d",&a,&b,&c);
			adde(a,b,c,head);
			adde(b,a,c,head2);
		}
		printf("%I64d\n",spfa(head) + spfa(head2));
	}
	return 0;
}