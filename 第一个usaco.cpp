/*
ID: davidro2
PROG: ride
LANG: C++
*/
#include<cstdio>
#include<iostream>
#include<cstring>
#include <fstream>
using namespace std;
char a[100], b[100];

int hash(char *p){
	int ans = 1;
	while(*p){
		ans =(ans * (*p - 'A' + 1)) % 47;
		p++;
	}
	return ans % 47;
}
int main(){
	freopen("ride.in","r",stdin);
	freopen("ride.out","w",stdout);
	while(~scanf("%s%s",a,b)){
		if(hash(a) == hash(b)) printf("GO\n");
		else printf("STAY\n");
	}
}