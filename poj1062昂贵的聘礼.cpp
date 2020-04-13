#include<iostream>
using namespace std;

int xb[200];
int xi;
int a[200][200];
int p,l,x;
int m,n;

bool place(int i, int j){
	if(a[i][j] <= 0) return false;
	for(int k = 1; k <= xi; k++){
		if(abs(a[j][0] -a[xb[k]][0]) > m || (j != i && j == xb[k])) return false;
	}
	return true;
}
int backtrack(int i){
	int cost,min = INT_MAX;
	xb[++xi] = i;
	for(int j = 1; j <= n; j++){
		if(place(i,j)){	
			if(i != j) cost = backtrack(j) + a[i][j];
			else cost = a[j][j];
			if(min > cost) min = cost;
			
		}
	}
	--xi;
	return min;
}


int main(){	
	int i,j,k;
	while(scanf("%d%d",&m,&n) != EOF){
		memset(a,0,sizeof(a));
		for(i = 1; i <= n; i++){
			scanf("%d%d%d",&p,&l,&x);
			a[i][i] = p;
			a[i][0] = l;
			for(j = 1; j <= x; j++){
				scanf("%d",&k);
				scanf("%d",&a[i][k]);
			}
		}
		xi = 0;
		printf("%d\n",backtrack(1));
	}
	return 0;
}