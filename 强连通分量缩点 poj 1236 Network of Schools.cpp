/*
[PKU 1236]
1. 凡是有出度的点就能扩散, 问最少多少个点扩散整个图.
2. 求加多少条边变成强连通图.

求强连通分量, 然后缩点, 计算每个点的入度和出度, 统计入度为0和出度为0的点, 分别记
为in, out.
问题1: 输出in.
问题2: 若只有一个强连通分量, 则输出0, 否则输出max(in, out).
//思考：为什么要求连通分量，而不是每一个顶点的入度为0情况呢，这是因为没有顶点进入一个连通分量，则整个连通分量均无法到达
//为什么max(in,out)，画一下图，几个连通分量，in为0说明别的连通分量无法到达它，out为0的说明它无法到达别的连通分量
*/
#include<iostream>
using namespace std;

const int MN = 124;
int N;
bool adj[MN][MN];

int Stack[MN], top;
bool instack[MN];
int dfn[MN],low[MN],Scc[MN],B,D;
void visit(int i){
	int j; D++;
	low[i] = dfn[i] = D;	
	Stack[top++] = i;
	instack[i] = true;
	for(j = 1; j <= N; j++){
		if(!adj[i][j]) continue;
		if(!dfn[j]){
			visit(j);
			if(low[i] > low[j]) low[i] = low[j]; 
		}else if(instack[j]&&dfn[j] < low[i]) low[i] = dfn[j];
	}
	if(dfn[i] == low[i]){
		do{
			j = Stack[--top];
			instack[j] = false;
			Scc[j] = B;
		}while(j != i); B++;
	}
}
void dfs(){
	int i;
	B = D = top = 0;
	memset(instack,0,sizeof(instack));
	memset(dfn,0,sizeof(dfn));
	for(i = 1; i <= N; i++){
		if(!dfn[i]) visit(i);
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	int i,j;
	while(~scanf("%d",&N)){
		memset(adj,0,sizeof(adj));
		for(i = 1; i <= N; i++){
			while(scanf("%d",&j),j){
				adj[i][j] = true;
			}
		}
		dfs();
		//求缩点的出入度
		int in[MN] = {0}, out[MN] = {0};
		for(i = 1; i <= N; i++){
			for(j = 1; j <= N; j++){
				if(adj[i][j] && Scc[i] != Scc[j]) {
					in[Scc[j]]++;
					out[Scc[i]]++;
				}
			}
		}
		if(B == 1){
			printf("1\n0\n");
			continue;
		}
		//求统计所有连通分量的出入度为零总和
		int IN = 0,OUT = 0;
		for(i = 0; i < B; i++){//B连通分量数
			if(!in[i]) IN++;
			if(!out[i]) OUT++;
		}
		printf("%d\n",IN);
		printf("%d\n",IN > OUT ? IN : OUT);
	}
	return 0;
}


//The first line contains an integer N: the number of schools in the network (2 <= N <= 100). 
//The schools are identified by the first N positive integers.
//Each of the next N lines describes a list of receivers. The line i+1 contains the identifiers of the receivers 
//of school i. Each list ends with a 0. An empty list contains a 0 alone in the line.
//
//Output
//Your program should write two lines to the standard output. The first line should contain one positive integer: the solution of subtask A. The second line should contain the solution of subtask B. 
//Sample Input
//
//5
//2 4 3 0
//4 5 0
//0
//0
//1 0

