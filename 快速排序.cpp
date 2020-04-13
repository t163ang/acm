#include<iostream>
using namespace std;
const int N = 10;
int partition(int a[], int p, int r){
	int i,j,x = a[r];
	for(i = j = p; j < r; j++){
		if(a[j] < x){
			swap(a[j],a[i]);
			i++;
		}
	}
	swap(a[i],a[r]);
	return i;
}

void qsort(int a[], int p, int r){
	if(p < r){
		int m = partition(a,p,r);
		qsort(a,p,m - 1);
		qsort(a,m + 1,r);
	}
}

int main(){
	int a[N] = {5,4,3,2,1,0};
	qsort(a,0,5);
	for(int i = 0; i <= 5; i++) printf("%d ",a[i]);
}