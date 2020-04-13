/*
[PKU 1236]
1. �����г��ȵĵ������ɢ, �����ٶ��ٸ�����ɢ����ͼ.
2. ��Ӷ������߱��ǿ��ͨͼ.

��ǿ��ͨ����, Ȼ������, ����ÿ�������Ⱥͳ���, ͳ�����Ϊ0�ͳ���Ϊ0�ĵ�, �ֱ��
Ϊin, out.
����1: ���in.
����2: ��ֻ��һ��ǿ��ͨ����, �����0, �������max(in, out).
//˼����ΪʲôҪ����ͨ������������ÿһ����������Ϊ0����أ�������Ϊû�ж������һ����ͨ��������������ͨ�������޷�����
//Ϊʲômax(in,out)����һ��ͼ��������ͨ������inΪ0˵�������ͨ�����޷���������outΪ0��˵�����޷���������ͨ����
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
		//������ĳ����
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
		//��ͳ��������ͨ�����ĳ����Ϊ���ܺ�
		int IN = 0,OUT = 0;
		for(i = 0; i < B; i++){//B��ͨ������
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

