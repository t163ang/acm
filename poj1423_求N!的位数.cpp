//poj 1423 Big Number
/*
	【题意】求n的阶乘的位数
	【算法】stirling公式 n!近似公式sqrt(2*pi*n) * (n/e)^n
			n!的位数是[lg1 + lg2 + .....lg(n - 1) + lg(n)] + 1;
			因为后面的式子当n很大的时候很慢，而第一条式子只能求近似解
			因此当n很小的时候不适合用，所以这里把两条公式结合起来求
			最后对第一条公式求一个lg就是位数了
*/
//#include<cstdio>
//#include<cmath>
//#include<iostream>
//using namespace std;
//#define e exp(1.0)
//#define pi acos(-1.0)
//int main(){
//	//freopen("in","r",stdin);
//	int n;
//	int T;
//	scanf("%d",&T);
//	while(T--){
//		scanf("%d",&n);
//		double ans = 0;
//		if(n<1000){
//			for(int i = 1;i<=n;i++)
//				ans += log10((double)i);
//		}else{
//			ans = log10(sqrt(2*pi*n)) + n * log10(n/e);
//		}
//		int res = (int)ans + 1;
//		printf("%d\n",res);
//	}
//	return 0;
//}
#include<iostream>
#include<cmath>
using namespace std;
const double PI = 3.1415926;
const double E = exp(1.0);
int main(){
	//freopen("in.txt","r",stdin);
	int i,t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int len = (int)(log10(sqrt(2.0 * PI * n)) + n * log10(n / E)) + 1;
		printf("%d\n",len);
	}
	return 0;
}