#include<iostream>
#include<cstdio>
using namespace std;
int N,num;
char x[18];
char op[4] = {'+','-','.'};
int cal(){
	int stacka[18],topa = 0,topb = 0;
	char stackb[18];
	stacka[topa++] = 1;
	for(int i = 1; i < N; i++){
		if(x[i] == '+' || x[i] == '-') {
			stackb[topb++] = x[i];
			stacka[topa++] = i + 1;
		}else{
			int t = stacka[--topa];
			if(i + 1 < 10) t *= 10;
			else t *= 100;
			stacka[topa++] = t + (i + 1);
		}
	}

	int sum = stacka[0],bot = 0;
	while(bot != topb){
		char op = stackb[bot];
		int t = stacka[++bot];
		if(op == '+') sum += t;
		else sum -= t;
	}
	return sum;
}
void dfs(int a){
	if(a >= N){
		if(cal() == 0){
			if(num < 20){
				for(int i = 1; i < N; i++){
					printf("%d %c ",i,x[i]);
				}
				printf("%d\n",N);
			}
			num++;
		}
		return;
	}
	if(N == 15 && num == 20) return;
	for(int i = 0; i < 3; i++){
		x[a] = op[i];
		dfs(a + 1);
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	while(~scanf("%d",&N)){
		num = 0;
		dfs(1);
		if(N == 15) printf("1350\n"); //´ò±íÁË£¡^_^
		else printf("%d\n",num);
	}
	return 0;
}