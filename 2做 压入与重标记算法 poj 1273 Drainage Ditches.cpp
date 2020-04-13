#include<iostream>
using namespace std;
const int MN = 1024;
int h[MN],e[MN], s,t,n,G[MN][MN];//nΪ�������,G[i][j]�����������c(i,j)
int que[MN],head,tail;
bool inque[MN];
void inline push(int u, int v){
	int d = min(e[u],G[u][v]);
	G[u][v] -= d;
	G[v][u] += d;
	e[u] -= d;
	e[v] += d;
	if(v != t && v != s && !inque[v]){
		que[tail] = v;
		tail = (tail + 1) % MN; 
		inque[v] = true;
	}
}
void inline relabel(int u, int m){
	if(m < INT_MAX) h[u] = m + 1;
	que[tail] = u; tail = (tail + 1) % MN;
	inque[u] = true;
}

void init(){
	memset(h,0,sizeof(h));
	memset(e,0,sizeof(e));
	memset(inque,0,sizeof(inque));
	h[s] = n;
	e[s] = INT_MAX;
	head = tail = 0;
}

int push_relabel(){
	init();
	inque[s] = true;
	que[tail++] = s;
	while(head != tail){
		int u = que[head]; head = (head + 1) % MN;
		inque[u] = false;  int mm = INT_MAX;
		for(int v = 1; v <= n && e[u] > 0; v++){
			if(G[u][v]){
				if(u == s || h[u] == h[v] + 1){
					push(u,v);
				}
				if(mm > h[v]) mm = h[v];
			}
		}
		if(e[u] > 0 && u != s && u != t) relabel(u,mm);//������ѹ�뵽���ڶ��㵽ѹ���ˣ���������u����������һ��Ҫ�ر�ǲſ������������
	}
	return e[t];
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,k,w,m;
	while(~scanf("%d%d",&m,&n)){
		memset(G,0,sizeof(G));
		s = 1, t = n;
		for(i = 0; i < m; i++){
			scanf("%d%d%d",&j,&k,&w);
			G[j][k] += w;
		}
		printf("%d\n",push_relabel());
	}
}

//�Ӹ����Ż���ûʲôЧ�����Ժ�������
//#include<iostream>
//#include<queue>
//using namespace std;
//const int MN = 1024;
//int h[MN],e[MN], s,t,n,G[MN][MN];//nΪ�������,G[i][j]�����������c(i,j)
//int que[MN],head,tail;
//
//struct Node{
//	int v;
//	bool operator < (const Node a) const{
//		return h[v] < h[a.v];
//	}
//	Node(int u):v(u){}
//};
//priority_queue<Node> pque;
//bool inque[MN];
//void inline push(int u, int v){
//	int d = min(e[u],G[u][v]);
//	G[u][v] -= d;
//	G[v][u] += d;
//	e[u] -= d;
//	e[v] += d;
//	if(v != t && v != s && !inque[v]){
//		//que[tail] = v;
//		//tail = (tail + 1) % MN; 
//		pque.push(Node(v));
//		inque[v] = true;
//	}
//}
//void inline relabel(int u, int m){
//	if(m < INT_MAX) h[u] = m + 1;
//	//que[tail] = u; tail = (tail + 1) % MN;
//	inque[u] = true;
//	pque.push(Node(u));
//}
//
//void init(){
//	memset(h,0,sizeof(h));
//	memset(e,0,sizeof(e));
//	memset(inque,0,sizeof(inque));
//	h[s] = n;
//	e[s] = INT_MAX;
////	head = tail = 0;
//}
//
//int push_relabel(){
//	init();
//	inque[s] = true;
//	//que[tail++] = s;
//	pque.push(Node(s));
//	while(!pque.empty()){
//		//int u = que[head]; head = (head + 1) % MN;
//		int u = pque.top().v; pque.pop();
//		inque[u] = false;  int mm = INT_MAX;
//		for(int v = 1; v <= n && e[u] > 0; v++){
//			if(G[u][v]){
//				if(u == s || h[u] == h[v] + 1){
//					push(u,v);
//				}
//				if(mm > h[v]) mm = h[v];
//			}
//		}
//		if(e[u] > 0 && u != s && u != t) relabel(u,mm);
//	}
//	return e[t];
//}
//int main(){
//	//freopen("in.txt","r",stdin);
//	int i,j,k,w,m;
//	while(~scanf("%d%d",&m,&n)){
//		memset(G,0,sizeof(G));
//		s = 1, t = n;
//		for(i = 0; i < m; i++){
//			scanf("%d%d%d",&j,&k,&w);
//			G[j][k] += w;
//		}
//		printf("%d\n",push_relabel());
//	}
//}