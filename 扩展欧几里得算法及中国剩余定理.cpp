#include<iostream>
using namespace std;
/*
	欧几里得算法
	基于以下定理：gcd(a,b) = gcd(b,a mod b) gcd(a,0) = |a|
*/
int gcd(int a, int b){ //a b是任意的非负整数
	if(b == 0) return a;
	return gcd(b,a % b);
}
/*
	扩展欧几里得算法的推广形式
	递归：d' = gcd(b,a % b);
	because: d = gcd(a,b) = d' = gcd(b,a % b)
	so:		 d = d'= bx' + (a % b)y'= bx' + (a - a / b)y' = ay' + b(x' - (a / b) * y')
	so:	     d = d' x = y' y = x' - (a / b) * y' 
*/
struct EE{
	int d,x,y;
	EE(int d,int x,int y):d(d),x(x),y(y){}
};

EE Extended_Euclid(int a,int b){
	if(b == 0){
		return EE(a,1,0);
	}
	EE ee = Extended_Euclid(b,a % b);
	return EE(ee.d,ee.y,ee.x - (a / b) * ee.y);
}
/*
	ax = b(mod n)求x
	假设d = ax' + ny'
*/

inline int mod(int a, int b){
	if(a > 0) return a % b;
	else return a % b + b;
}
void modular_liner_equation_solve(int a, int b,int n){
	EE ee = Extended_Euclid(a,n);
	if(b % ee.d == 0){ // 当且仅当d | b :d整除b方程有解
		int x0 = mod(ee.x * (b / ee.d),n);
		for(int i = 0; i < ee.d; i++){//若有解则存在d = gcd(a,n)个解
			printf("%d ",mod(x0 + (i * n / ee.d),n));
		}
		puts("");
	}else{
		puts("no answer!");
	}
}

/*
中国剩余定理:
x = a1 (mod m1)
x = a2 (mod m2)
...
x = ak (mod mk)
记M = m1 * m2 * ... mk
=>Mi = M / mi
则gcd(Mi,mi) = 1，由扩展欧几里得有: Mi * xi + mi * yi = 1，解出xi,yi
即Mi * xi = 1 (mod mi), Mi * xi = 0 (mod mj),j != i
则res = a1 * M1 * x1 + a2 * M2 * x2 + ....an * Mn * xn为一个解
求(0,M)的一个解只要 res = (res + M) % M;
*/
const int MN = 100;
int a[MN],m[MN];
int chnrm(int nn){//nn是个数,返回最小非负整数解
	int M = 1,res = 0,Mi,i;
	for(i = 0; i < nn; i++){
		M *= m[i];
	}
	for(i = 0; i < nn; i++){
		Mi = M / m[i];
		EE ee = Extended_Euclid(Mi,m[i]);
		res += (a[i] * Mi * ee.x) % M;
	}
	return (res + M) % M;
}

int main(){
	//int a = 10,b = 2;
	//cout << gcd(b,a) << endl;
	//EE ee = Extended_Euclid(99,78);
	//cout << ee.d << " " << ee.x << " " << ee.y << endl; 
	//modular_liner_equation_solve(14,30,100);
	//测试中国剩余定理
	a[0] = 2; m[0] = 3;
	a[1] = 3; m[1] = 5;
	a[2] = 2; m[2] = 7;
	printf("%d\n",chnrm(3));
	return 0;
}