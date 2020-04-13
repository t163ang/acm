/*
ID: davidro2
PROG: gift1
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;
const int MN = 50;
map<string, int> hash;
int money[MN];
char name[MN][46];
int main(){
	//freopen("in.txt","r",stdin);
	freopen("gift1.in","r",stdin);
	freopen("gift1.out","w",stdout);
	int np,i,j,m,g;
	while(~scanf("%d",&np)){
		fill(money,money + MN,0);
		for(i = 0; i < np; i++){
			scanf("%s",name[i]);
			hash[name[i]] = i;
		}
		char str[45];
		for(i = 0; i < np; i++){
			scanf("%s",str);
			int n = hash[str];
			scanf("%d %d",&m,&g);
			money[n] -= m; 
			if(g == 0) continue;
			int tmp = m / g;
			money[n] += m - tmp * g;
			for(j = 0; j < g; j++){
				scanf("%s",str);
				money[hash[str]] += tmp;
			}
		}
		for(i = 0; i < np; i++){
			printf("%s %d\n",name[i],money[i]);
		}
	}
}

