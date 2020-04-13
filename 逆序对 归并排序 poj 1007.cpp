#include<iostream>
#include<algorithm>
using namespace std;
const int MN = 1024;
struct DNA{
	char s[MN];
	int len;
	bool operator < (const DNA d) const{
		return len < d.len;
	}
}dna[MN];
int ans,n,m;
char str[MN];
void merge(int L, int M, int R){
	int i = L, j = M + 1, k = 0; char tmp[MN];
	while(i <= M && j <= R){
		if(str[i] <= str[j]){
			tmp[k++] = str[i++];
		}else {
			ans += M - i + 1;
			tmp[k++] = str[j++];
		}
	}
	while(i <= M) tmp[k++] = str[i++];
	while(j <= R) tmp[k++] = str[j++];
	for(i = L, k = 0; i <= R; i++){
		str[i] = tmp[k++];
	}
}

void mergeSort(int L, int R){
	if(L < R){
		int M = (L +  R) >> 1;
		mergeSort(L,M);
		mergeSort(M + 1, R);
		merge(L,M,R);
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j;
	while(~scanf("%d%d",&n,&m)){
		for(i = 0; i < m; i++){
			scanf("%s",str);
			strcpy(dna[i].s,str);
			ans = 0; mergeSort(0,n - 1);
			dna[i].len = ans;
		}
		stable_sort(dna,dna + m); //stl:stable_sort is stable: it preserves the relative ordering of equivalent elements.
		for(i = 0; i < m; i++){
			puts(dna[i].s);
		}
	}
	return 0;
}