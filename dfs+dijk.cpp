#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
/*
Description

Christmas is coming to KCM city. Suby the loyal civilian in KCM city is preparing a big neat Christmas tree. The simple structure of the tree is shown in right picture.

The tree can be represented as a collection of numbered nodes and some edges. The nodes are numbered 1 through n. The root is always numbered 1. Every node in the tree has its weight. The weights can be different from each other. Also the shape of every available edge between two nodes is different, so the unit price of each edge is different. Because of a technical difficulty, price of an edge will be (sum of weights of all descendant nodes) × (unit price of the edge).

Suby wants to minimize the cost of whole tree among all possible choices. Also he wants to use all nodes because he wants a large tree. So he decided to ask you for helping solve this task by find the minimum cost.

Input

The input consists of T test cases. The number of test cases T is given in the first line of the input file. Each test case consists of several lines. Two numbers v, e (0 ≤ v, e ≤ 50000) are given in the first line of each test case. On the next line, v positive integers wi indicating the weights of v nodes are given in one line. On the following e lines, each line contain three positive integers a, b, c indicating the edge which is able to connect two nodes a and b, and unit price c.

All numbers in input are less than 216.

Output

For each test case, output an integer indicating the minimum possible cost for the tree in one line. If there is no way to build a Christmas tree, print “No Answer” in one line.

Sample Input

2
7 7
200 10 20 30 40 50 60
1 2 1
2 3 3
2 4 2
3 5 4
3 7 2
3 6 3
1 5 9
Sample Output

15
1210
Source




*/
#define N 100
typedef pair<int,int> PAIR;
struct {
	int v;
	int cost;		//每条边的权值
	int next;		
	int unit;		//题目unit
}edge[N];
int map[N];
int ep = 1;

int weight[N];
int dist[N];
int v,e;
int a,b,c;


bool visited[N];
void dfs(int i){
	visited[i] = true;
	int j;
	for(j = map[i]; j != 0; j = edge[j].next){
		if(!visited[edge[j].v]) dfs(edge[j].v);
	}

	for(j = map[i]; j != 0; j = edge[j].next){
		weight[i] += weight[edge[j].v]; 
	}
	for(j = map[i]; j != 0; j = edge[j].next){
		edge[j].cost = edge[j].unit * weight[edge[j].v];
	}
}

int main(){
	int t;
	int i,j,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&v,&e);
		memset(map,0,sizeof(map));
		memset(weight,0,sizeof(weight));
		for(i = 1; i <= v; i++) scanf("%d",&weight[i]);
		for(i = 1; i <= e; i++){
			scanf("%d%d%d",&a,&b,&c);
			edge[ep].v = b;
			edge[ep].cost = 0;
			edge[ep].unit = c;
			edge[ep].next = map[a];
			map[a] = ep++;
		}
		
		memset(visited,0,sizeof(visited));
		dfs(1);

		priority_queue<PAIR ,vector<PAIR>,greater<PAIR >> que;		
		for(i = 1; i <= v; i++) dist[i] = INT_MAX;

		dist[1] = 0;
		que.push(PAIR(0,1));
		int count = 0;

		while(!que.empty() && count <= v){
			int len = que.top().first, u = que.top().second; 
			que.pop();
			count++;
			if(len > dist[u]) continue;
			for(i = map[u]; i != 0; i = edge[i].next){
				if(len + edge[i].cost < dist[edge[i].v]) dist[edge[i].v] = len + edge[i].cost;
				que.push(PAIR(dist[edge[i].v],edge[i].v));
			}
		}
		int ans = 0;
		for(j = 2; j <= v; j++) ans += dist[j];
		printf("%d\n",ans);
	}

}
