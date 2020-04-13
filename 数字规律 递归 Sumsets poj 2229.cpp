#include<iostream>
#include<algorithm>
using namespace std;
const int BASE = 1000000000;
const int MN = 1000010;
long long F[MN];
//讲一下推导过程：先写出前几个
 //再比较f[n]与f[n - 1] 和f[n - 2]....有什么联系
long long f(int n){
	if(n == 1) return 1;
	if(F[n]) return F[n]; 
	if(n & 1) return f(n ^ 1);
	return F[n] = (f(n - 1) + f(n >> 1))% BASE;
}


int main(){
   //freopen("in.txt", "r", stdin);
   int N;
   while(~scanf("%d",&N)){
	   memset(F,0,sizeof(F));
	   printf("%d\n",f(N) % BASE);
   }
   return 0;
}
