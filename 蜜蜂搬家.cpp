#include<stdio.h>
#include<string.h>
int dest;
int d[100];
int beep(int src){
	if(src == dest) return 1;
    if(src > dest) return 0;
	if(d[src] > 0) return d[src];
	return d[src] = beep(src + 1) + beep(src + 2);
}

int main(){
	int n,src;
	scanf("%d",&n);
	while(n--){
		memset(d,0,sizeof(d));
		scanf("%d%d",&src,&dest);
		printf("%d\n",beep(src));
	}
	return 0;
}