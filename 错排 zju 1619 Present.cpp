#include<iostream>
//#include<cfloat>
using namespace std;
const int MN = 120;
double F[MN] = {1,0,1}; //F[0]是处理n == m的情况F[1] == 0 ? 因为1个人只能坐自己的座位，所以错排为0
int n,m;
int main(){
	//freopen("in.txt","r",stdin);
	int i;
	for(i = 3; i < 101; i++) F[i] = (i- 1)*(F[i - 1] + F[i - 2]);
	while(~scanf("%d%d",&n,&m)){
		double tmp = F[n - m];
		for(i = 2; i <= n - m; i++) tmp /= i;
		for(i = 2; i <= m; i++) tmp /= i;
		printf("%.8lf\n",tmp);
	}
	return 0;
}

//第一步，“错排” 1 号元素（将 1 号元素排在第 2 至第 n 个位置之一），有 n - 1 
//种方法。 
//
//第二步，“错排”其余 n - 1 个元素，按如下顺序进行。视第一步的结果，若 1 
//号元素落在第 k 个位置，第二步就先把 k 号元素“错排”好， k 
//号元素的不同排法将导致两类不同的情况发生：（ 1 ） k 号元素排在第 1 
//个位置，留下的 n - 2 个元素在与它们的编号集相等的位置集上“错排”，有 f(n -2) 
//种方法；（ 2 ） k 号元素不排第 1 个位置，这时可将第 1 个位置“看成”第 k 
//个位置，于是形成（包括 k 号元素在内的） n - 1 个元素的“错排”，有 f(n - 1) 
//种方法。据加法原理，完成第二步共有 f(n - 2)+f(n - 1) 种方法。 
//
//根据乘法原理， n 个不同元素的错排种数 
//
//f(n) = (n-1)[f(n-2)+f(n-1)] (n>2) 

//P = C(N,M) * F[N - M] / A(N,N);
//C(N,M) = A(N,M) / M! 
//故 P = A(N,M) * F[N - M]/ A(N,N) * M! = F[N - M] / (N-M)! * M !