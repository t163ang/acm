#include<iostream>
#include<algorithm>
using namespace std;
int partition(int a[], int p, int r){
	int i,j,x = a[r];
	for(i = j = p; j < r; j++){
		if(a[j] >= x){
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
const int MN = 12024;
int n,m,CA = 1;
int arr[MN],tmp[MN];
bool cmp(const int a, const int b){
	return a > b;
}
int main(){
	//freopen("in.txt","r",stdin);
	while(scanf("%d%d",&n,&m),n){
		int i,j,k;
		for(i = 0; i < m; i++){
			scanf("%d",arr + i);
		}
		qsort(arr,0,m - 1);
	//	for(i = 0; i < m; i++) printf("%d ",arr[i]);
		k = 0; j = n * m;
		for(i = 0; i < m; i++,j--){
			while(j != arr[i]){
				tmp[k++] = j--;
			}
		}
		//for(i = 0; i < k; i++) printf("%d\n",tmp[i]);
		int cnt = 0;
		for(i = 0,j = 0; i < m; i++){
			if(arr[i] > tmp[j] || j >= k) cnt++;//不加j >= k数组可能越界,pay attention 上次做题有max = -INT_MAX存在负数不能是0
			else j++;
		}
	    printf("Case %d: %d\n",CA++,cnt);
	}
	return 0;
}