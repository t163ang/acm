#include<iostream>
using namespace std;
const int N = 40;
int n,k,m; 
struct Matrix{
	int mat[N][N];	
}R,S,A;

Matrix operator * (const Matrix &a, const Matrix &b){
	Matrix c;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			long long sum = 0;
			for(int k = 0; k < n; k++){
				sum += a.mat[i][k] * b.mat[k][j];
			}
			c.mat[i][j] = sum % m;
		}
	}
	return c;
}

Matrix operator + (const Matrix &a,const Matrix &b){
	Matrix c;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) c.mat[i][j] = (a.mat[i][j] + b.mat[i][j]) % m; 
	return c;
}
void solve(Matrix &R, Matrix &S, int k){
	if(k == 1){
		R = A;
		S = A;
		return;
	}
	solve(R,S, k >> 1);
	S = S + R * S;
	R = R * R;
	if(k & 1){ R = R * A; 	S = S + R;}
}

void pt(Matrix a){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++) printf("%d ",a.mat[i][j]);
		puts("");
	}
	puts("");
}
int main(){
	//freopen("in.txt","r",stdin);
	scanf("%d%d%d",&n,&k,&m);
	for(int i = 0; i < n; i++){ 
		for(int j = 0; j < n; j++){
			scanf("%d",&A.mat[i][j]);
			A.mat[i][j] %= m;
		}
	}
	solve(R,S,k);
	pt(S);
	return 0;
}