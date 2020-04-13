#include<iostream>
#include<algorithm>
using namespace std;

int partition(int a[], int p, int r){
	int x = a[r],i = p;
	for(int j = p; j < r; j++){
		if(a[j] < x){
			if(j != i) swap(a[j],a[i]);
			i++;
		}
	}
	swap(a[i],a[r]);
	return i;
}

int partition2(int a[], int p, int r){
	int x = a[r];
	int i = p - 1;
	for(int j = p; j <= r - 1; j++){
		if(a[j] <= x) {
			i = i + 1;
			swap(a[j], a[i]);
		}
	}
	swap(a[i + 1],a[r]);
	return i + 1;
}

void quicksort(int a[], int p, int r){
	if(p < r){
		int q = partition(a,p,r);
		quicksort(a,p,q - 1);
		quicksort(a,q + 1, r);
	}
}

int main(){	
	int n;
	int a[4];
	cin >> n;
	while(n--){
	cin >> a[0] >> a[1]>> a[2];
	quicksort(a,0,2);
	if(a[0] * a[0] + a[1] * a[1] == a[2] * a[2]) cout << 1;
	else cout << 0;
	cout << endl;
	}	
	return 0;
}