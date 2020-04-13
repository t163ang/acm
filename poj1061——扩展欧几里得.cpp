#include<iostream>
using namespace std;

struct EE{
	__int64 d,x,y;
	EE(__int64  d,__int64  x,__int64  y):d(d),x(x),y(y){}
};

inline __int64  mod(__int64  a, __int64 b){
	if(a > 0) return a % b;
	else return a % b + b;
}

__int64  gcd(__int64 a, __int64  b){ //a b是任意的非负整数
	if(b == 0) return a;
	return gcd(b,mod(a,b));
}

EE Extended_Euclid(__int64  a,__int64  b){
	if(b == 0){
		return EE(a,1,0);
	}
	EE ee = Extended_Euclid(b,a % b);
	return EE(ee.d,ee.y,ee.x - (a / b) * ee.y);
}

/*
	由题目易知(m - n)*z = y - x (mod L),即az = b (mod L)转化为求z
*/
int main(){
	//freopen("in.txt","r",stdin);
	__int64 x,y,m,n,L;
	while(~scanf("%I64d%I64d%I64d%I64d%I64d",&x,&y,&m,&n,&L)){
		__int64  a = m - n,b = y - x;
		EE ee = Extended_Euclid(a,L);
		if(b % ee.d == 0){
			__int64 x0 = mod(ee.x * (b / ee.d),L);
			printf("%I64d\n",x0);
		}else{
			puts("Impossible\n");
		}
	}
	return 0;
}