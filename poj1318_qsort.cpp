#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MN = 1000;
const char X[8] = "XXXXXX";
const char S[8] = "******";
char dir[102][MN];
char words[MN][MN];
int cmp(const void *a,const void *b){
	char *str1 = (char *)a, *str2 = (char *)b;
	return strcmp(str1,str2);
}
int main(){
	//freopen("in.txt","r",stdin);
	int n = 0,m = 0;
	do{
		scanf("%s",dir[n]);
	}while(strcmp(dir[n++],X));

	qsort(dir,n,sizeof(dir[0]),cmp);
	do{
		scanf("%s",words[m]);
		sort(words[m],words[m] + strlen(words[m]));
	}while(strcmp(words[m++],X));

	for(int i = 0; i < m - 1; i++){
		bool flag = true;
		for(int j = 1; j < n; j++){
			char tmp[MN];
			strcpy(tmp,dir[j]);
			sort(tmp,tmp + strlen(dir[j]));
			if(!strcmp(words[i],tmp)){
				puts(dir[j]);
				flag = false;
			}
		}
		if(flag) puts("NOT A VALID WORD");
		puts(S);
	}
	return 0;
}