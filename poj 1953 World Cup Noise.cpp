#include<iostream>
using namespace std;
const int MN = 50;
int CA = 1;
int one[MN],zero[MN];
//已知关系从发找答案
void inline init(){
	one[1] = zero[1] = 1;
	for(int i = 2; i <= 45; i++){
		one[i] = one[i - 1] + zero[i - 1];
		zero[i] = one[i - 1];
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	init();
	int n,T; scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("Scenario #%d:\n%d\n\n",CA++,one[n] + zero[n]);
	}
	return 0;
}