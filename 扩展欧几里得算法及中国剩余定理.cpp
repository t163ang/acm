#include<iostream>
using namespace std;
/*
	ŷ������㷨
	�������¶���gcd(a,b) = gcd(b,a mod b) gcd(a,0) = |a|
*/
int gcd(int a, int b){ //a b������ķǸ�����
	if(b == 0) return a;
	return gcd(b,a % b);
}
/*
	��չŷ������㷨���ƹ���ʽ
	�ݹ飺d' = gcd(b,a % b);
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
	ax = b(mod n)��x
	����d = ax' + ny'
*/

inline int mod(int a, int b){
	if(a > 0) return a % b;
	else return a % b + b;
}
void modular_liner_equation_solve(int a, int b,int n){
	EE ee = Extended_Euclid(a,n);
	if(b % ee.d == 0){ // ���ҽ���d | b :d����b�����н�
		int x0 = mod(ee.x * (b / ee.d),n);
		for(int i = 0; i < ee.d; i++){//���н������d = gcd(a,n)����
			printf("%d ",mod(x0 + (i * n / ee.d),n));
		}
		puts("");
	}else{
		puts("no answer!");
	}
}

/*
�й�ʣ�ඨ��:
x = a1 (mod m1)
x = a2 (mod m2)
...
x = ak (mod mk)
��M = m1 * m2 * ... mk
=>Mi = M / mi
��gcd(Mi,mi) = 1������չŷ�������: Mi * xi + mi * yi = 1�����xi,yi
��Mi * xi = 1 (mod mi), Mi * xi = 0 (mod mj),j != i
��res = a1 * M1 * x1 + a2 * M2 * x2 + ....an * Mn * xnΪһ����
��(0,M)��һ����ֻҪ res = (res + M) % M;
*/
const int MN = 100;
int a[MN],m[MN];
int chnrm(int nn){//nn�Ǹ���,������С�Ǹ�������
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
	//�����й�ʣ�ඨ��
	a[0] = 2; m[0] = 3;
	a[1] = 3; m[1] = 5;
	a[2] = 2; m[2] = 7;
	printf("%d\n",chnrm(3));
	return 0;
}