#include<iostream>
using namespace std;
struct EE{
	__int64 d,x,y;
	EE(__int64 d, __int64 x, __int64 y):d(d),x(x),y(y){}
};
EE Extended_Euclid(__int64 a, __int64 b){
	if(b == 0){
		return EE(a,1,0);
	}
	EE ee = Extended_Euclid(b,a % b);
	return EE(ee.d,ee.y, ee.x - (a / b) * ee.y);
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,n;
	__int64 m1,r1,m2,r2;
	while(~scanf("%d",&n)){
		scanf("%I64d%I64d",&m1,&r1);
		bool flag = true;
		for(i = 1; i < n; i++){
			scanf("%I64d%I64d",&m2,&r2);
			if(!flag) continue;
			EE ee = Extended_Euclid(m1,m2);
			if((r2 - r1) % ee.d != 0){
				flag = false;
				continue;
			}
			__int64 x = ee.x * (r2 - r1) / ee.d;
			__int64 b = m2 / ee.d;
			x = (x % b + b) % b;
			r1 = r1 + m1 * x;
			m1 = (m1 * m2) / ee.d;
		}
		if(flag) printf("%I64d\n",r1);
		else printf("-1\n");
	}
	return 0;
}
