 //这一题要求的是N！中末尾0的个数，其实也就是所包含因子10的个数。
//10=5*2，因子10的个数也就是因子2的个数与因子5的个数中较小的那个，
//N！=1*2*3...*N，其中2的因子个数一定不少于5的因子个数，所以要求的其实就是N！中所包含的5的因子个数。
#include<iostream>
using namespace std;
/*
	求N!末尾0的个数
*/
int main(){
	freopen("in.txt","r",stdin);
	int i,j,t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int sum = 0;
		for(i = 5; i <= n; i *= 5){
			sum += n / i;
		}
		printf("%d\n",sum);
	}
	return 0;
}
