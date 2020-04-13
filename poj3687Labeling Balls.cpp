//#include<iostream>
//#include<queue>
//#include<vector>
//using namespace std;
//
///*
//Labeling Balls
//Time Limit: 1000MS  Memory Limit: 65536K 
//Total Submissions: 4723  Accepted: 1109 
//
//Description
//
//Windy has N balls of distinct weights from 1 unit to N units. Now he tries to label them with 1 to N in such a way that: 
//
//No two balls share the same label.
//The labeling satisfies several constrains like "The ball labeled with a is lighter than the one labeled with b".
//Can you help windy to find a solution?
//
//Input
//
//The first line of input is the number of test case. The first line of each test case contains two integers, N (1 �� N �� 200) and M (0 �� M �� 40,000). The next M line each contain two integers a and b indicating the ball labeled with a must be lighter than the one labeled with b. (1 �� a, b �� N) There is a blank line before each test case. 
//
//Output
//
//For each test case output on a single line the balls' weights from label 1 to label N. If several solutions exist, you should output the one with the smallest weight for label 1, then with the smallest weight for label 2, then with the smallest weight for label 3 and so on... If no solution exists, output -1 instead.
//
//Sample Input
//
//5
//
//4 1
//1 1
//
//4 2
//1 2
//2 1
//
//4 1
//2 1
//
//4 1
//3 2
//
//Sample Output
//
//1 2 3 4
//-1
//-1
//2 1 3 4
//1 3 2 4
//
//Source
//
//POJ Founder Monthly Contest �C 2008.08.31, windy7926778
//*/
//
//
//
//#ifndef __test
//const int N = 300;
//const int M = 50000;
//#else
//const int N = 10;
//const int M = 30;
//#endif
//
//int map[N][2];//map[i][0]��Ϊ��ȼ�¼
//int ep;
//struct Edge{
//	int v;
//	int next;
//}edge[M];
//
//int t,n,m,a,b;
//int ans[N];
////void intit(int m){
////	//��ʼ���ڽӱ�
////	for(i = 0; i < m + 100; i++){
////		edge[i] = i + 1;
////	}
////	edge[i] = -1;
////	memset(map,0,sizeof(map));
////	ep = 0;
////}
//
//
//
//void addege(int from, int to){
//	map[to][0]++;	//���++	
//	edge[ep].v = to;
//	edge[ep].next = map[from][1];
//	map[from][1] = ep;
//	ep++;
//}
//
//struct Cmp{
//	bool operator() (int a, int b){
//		return a > b;
//	}
//};
//
//bool toplogical(int a[]){
//	int count = 0;
//	priority_queue<int, vector<int>, Cmp> s;
//	int i,j;
//	for(i = 1; i <= n; i++){
//		if(!map[i][0]) s.push(i);
//	}
//	while(!s.empty()){
//		j = s.top();
//		a[count++] = j;
//		s.pop();
//		for(i = map[j][1]; i != 0;i = edge[i].next){
//			if(!(--map[edge[i].v][0])) s.push(edge[i].v);
//		}
//	} 
//	if(count < n) return false;
//	return true;
//}
//
//int main(){
//	int i;
//	scanf("%d",&t);
//	while(t--){
//		memset(map,0,sizeof(map));
//		ep = 1;
//		scanf("%d%d",&n,&m);
//	//	intit(m);
//		for(i = 1; i<= m; i++){
//			scanf("%d%d",&a,&b);
//			addege(a,b);
//		}
//		if(toplogical(ans)){
//			for(i = 0; i < n - 1; i++) printf("%d ",ans[i]);
//			printf("%d\n",ans[i]);
//		}else{
//			printf("-1\n");
//		}
//		
//	}
//
//
//}

/*
pku poj 3687 Labeling Balls ����ͼ ��������

         �������ҽӴ��ĵ�һ��������������⡣

         ��ʵ��Ŀ�е���ѽ⣬�б�ǩ1~N����С��1~N����ǩ������ȷ��С��ƥ���Ǹ���ǩ��ǰ��ǩѡ���򡣻���һ��ؼ��ǣ����ʱ��С��ǩ��������ѡ����С����Ŀһ�����Ǻ������������й�ϵ�ģ�һ���򵥵��뷨������ͼ��������ÿ�ζ��������Ϊ0�ĵ㶼�Ǵ�С�����ҡ���������ͻᷢ������ֻ��ƽ��·���Ķ���ͷ�ķ�ʽ���ܱ�֤��ȷ�ԡ���Ϊ����β���ܴ��ڵĺ�С�ı�ǩ��ƥ���˽��ص�С����α�֤����β����С��ǩ������ƥ�䣬���ǩ������ƥ���أ�һ��̰��˼·���Ǵ��ǩ����ƥ����������С��ǩ�Ϳ��Ժ;����������ƥ�䣬��Ŀ��Ҫ��Ҳ�ﵽ�ˡ���֤�����β����С��ǩƥ��������ֱ���������౳��

My Code��

*/
#include<iostream>

#define clr(a) memset(a,0,sizeof(a))
const int N = 200, M = 40000;
int g[N][N], in[N], ans[N];
int main(){
	int t,n,m,a,b,i,j,k;
	scanf("%d",&t);
	while(t--){
		clr(g);
		clr(in);
		scanf("%d%d",&n,&m);
		for(i = 0; i < m; i++){
			scanf("%d%d",&a,&b);
			if(!g[--b][--a]) g[b][a] = 1, ++in[a];
		}
		for(i = n -1; i >= 0; --i){
			for(j = n -1; j >= 0 && in[j]; --j);
			if(j < 0) break;
			ans[j] = i + 1, in[j] = -1;
			for(k = 0; k < n; k++) if(g[j][k]) --in[k];
			
		}

		if(i >= 0) printf("-1\n");
		else{
			printf("%d",ans[0]);
			for(i = 1; i < n; i++) printf(" %d",ans[i]);
			puts("");
		}
	}

}