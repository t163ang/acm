#include<iostream>
using namespace std;
int partition(int a[], int p, int r){
	int i,j,x = a[r];
	for(i = j = p; j < r; j++){
		if(a[j] <= x){
			swap(a[j],a[i]);
			i++;
		}
	}
	swap(a[i],a[r]);
	return i;
}

void qsort(int a[], int p, int r){
	if(p < r){
		int q = partition(a,p,r);
		qsort(a,p,q - 1);
		qsort(a,q + 1,r);
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	int a[] = {2,1,2,5,4,324,234,0,0,0,0,2344,243,12,12,34,1,3,-7,3,-2,-8,-2312,234,12,213,2314,4321,213,2341,2341,243342,24321,234,433,12,34,543,7,65,5,7,56,65};
	int n = sizeof(a) / sizeof(int) - 1;
	qsort(a,0,n);
	for(int i = 0; i <= n; i++) printf("%d ",a[i]);
	return 0;
}