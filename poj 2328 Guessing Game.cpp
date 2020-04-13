#include<iostream>
using namespace std;
int n;
int inp[100000];
char str[100000][24];
int main(){
	//freopen("in.txt","r",stdin);
	while(scanf("%d",&n),n){
		inp[0] = n;
		int i,j = 0;
		while(scanf("%*s%s",str[j]),strcmp(str[j],"on")){
			scanf("%d",&inp[++j]);
		}
		int w = inp[j];
		for( i = 0; i < j; i++){
			if(w <= inp[i] && strcmp(str[i],"high")) break;
			if(w >= inp[i] && strcmp(str[i],"low")) break;
		}
		if(i < j) puts("Stan is dishonest");
		else puts("Stan may be honest");
	}
	return 0;
}