#include<iostream>
using namespace std;
const int n[4] = {23,28,33},tot = 28 * 33 * 23;
const int m[4] = {33 * 28,23 * 33,23 * 28};
int ans[4];
int p,e,i,d,CA = 1;
inline int getp(int a, int i){//被求数的余数a
	int dlta = m[i];
	int inc = dlta;
	while(inc % a != 1){
		inc += dlta;
	}
	return inc;
}
inline void init(){
	for(int i = 0; i < 3; i++){
		ans[i] = getp(n[i],i);
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,g[42]; init();
	while(scanf("%d%d%d%d",&g[0],&g[1],&g[2],&d),d != -1){
		int sum = 0;
		for(i = 0; i < 3; i++){
			sum += ans[i] * g[i];
		}
		sum =(sum - d + tot) % tot;
		if(sum == 0) printf("Case %d: the next triple peak occurs in %d days.\n",CA++,tot);
		else printf("Case %d: the next triple peak occurs in %d days.\n",CA++,sum);
	}
	return 0;
}
