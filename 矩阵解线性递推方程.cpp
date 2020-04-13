#include<iostream>
using namespace std;
// (F[n],F[n-1],F[n-2],S[n-1]) (3 1 0 1, 2 0 1 0 , 7 0 0 0, 0 0 0 1) = (F[n + 1],F[n],F[n],S[n])
struct Matrix{
	int mat[16][16];
	Matrix operator * (Matrix b){
		Matrix C; int sum;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j < 4; j++){
				sum = 0;
				for(int k = 0; k < 4; k++){
					sum += mat[i][k] * b.mat[k][j]; 
				}
				C.mat[i][j] = sum % 2009;
			}
		}
		return C;
	}
};

Matrix A;
void Power(Matrix &R, int k){
	if(k == 1) {R = A; return;}
	Power(R, k >> 1);
	R = R * R;
	if(k & 1) R = R * A;
}


int main(){
	//freopen("in.txt","r",stdin);
	int m,n,c1 = 1; 
	scanf("%d",&m);
	int a[16][16] ={{3,1,0,1},{2,0,1,0},{7,0,0,0},{0,0,0,1}};
	memcpy(A.mat, a, sizeof(a));
	Matrix R;
	int s[3] ={1,4,9};
	while(m--){
		scanf("%d",&n);
		if(n < 3){printf("Case %d: %d\n",c1++,s[n]); continue;}
		Power(R, n - 1);
		int ans = 5 * R.mat[0][3] + 3 * R.mat[1][3] + 1 * R.mat[2][3] + 4 * R.mat[3][3];
		printf("Case %d: %d\n",c1++,ans % 2009);
	}
}