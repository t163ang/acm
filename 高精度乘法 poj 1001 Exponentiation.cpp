#include<iostream>
using namespace std;
const int MN = 131;// ×î¶à(10 ^ 6) ^25 = 130Î»
int len,muls[30],muln[MN];
int change(char *s){
	len = strlen(s) - 1; int i,j,k = 0; 
	for(i = len,j = 0; i >= 0; i--){
		if(s[i] != '.'){
			muln[j] = s[i] - '0';
			muls[j] = muln[j];
			j++;
		}else{
			k = j;
		}

	}
	if(k == 0) len++;
	return k;
}

void mul(){
	int tmp[MN],i,j; 
	memset(tmp,0,sizeof(tmp));
	for(i = 0; i < len; i++){
		for(j = 0; j < MN; j++){
			tmp[i + j] += muls[i] * muln[j];
		}
	}
	int c = 0;
	for(i = 0; i < MN; i++){
		int w = tmp[i] + c;
		muln[i] = w % 10;
		c = w / 10;
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	char s[30]; int i,j,n;
	while(~scanf("%s%d",s,&n)){
		memset(muln,0,sizeof(muln));
		j = change(s);
		for(i = 2; i <= n; i++){
			mul();
		}
		int beg = 0;
		while(!muln[beg] && beg < MN) beg++;
		int end = MN;
		while(!muln[end] && end) end--;
		int mid = n * j;
		if(end < mid) end = mid - 1;
		while(end >= mid){
			printf("%d",muln[end--]);
		}
		if(mid > 0 && mid >= beg + 1) printf(".");
		while(end >= beg) printf("%d",muln[end--]);
		puts("");
	}
	return 0;
}