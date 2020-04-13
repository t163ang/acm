#include<iostream>
using namespace std;
//1/a = (1/b + 1/c)/ (1 - 1/(b*c))
//=> bc-1 = a(b+c)
//assume b=a+m and c=a+n (b and c is always bigger than a)
//(a+m)(a+n)-1=a(a+m+a+n)
//=> a*a+a*n+a*m+m*n-1=2*a*a+m*a+n*a
//=> m*n=a*a+1
//and then
//for(m=a;m>=1;m--)
//   if((a*a+1)%m==0)
//      break;
//n=(a*a+1)/m

int main(){
	//freopen("in.txt","r",stdin);
	unsigned long a,m,n;
	while(~scanf("%uld",&a)){
		for(m = a; m >= 1;m--){
			if((a * a + 1) % m == 0) break;
		}
		n = (a * a + 1) / m;
		printf("%d\n",a + m + a + n);
	}
	return 0;
}