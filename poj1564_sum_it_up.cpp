#include<iostream>
using namespace std;
int sum,t,m,x[20],count[20],cur[20];//cur[i]记录数字x[i]使用次数
bool isnone;
void dfs(int n){
	if(sum == t){
		bool flag = false;
		for(int i = 1; i < n; i++){
			for(int j = 0; j < cur[i]; j++){
				if(flag) printf("+");
				else flag = true;
				printf("%d",x[i]);
			}
		}
		puts("");
		isnone = false;
		return;
	}else if(n > m){
		return;
	}
	int e = count[n];
	for(int i = e; i >=  0; i--){
		cur[n] = i;
		sum += i * x[n];
		dfs(n + 1);
		sum -= i * x[n];
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,n,num,pre;
	while(scanf("%d%d",&t,&n),t){
		m = 0;pre = -3;
		for(i = 0; i < n; i++){
			scanf("%d",&num);
			if(pre != num) {
				m++;
				count[m] = 0;
			}
			pre = num;
			x[m] = num;
			count[m]++;
		}
		sum = 0;
		isnone = true;
		printf("Sums of %d:\n",t);
		dfs(1);
		if(isnone) printf("NONE\n");
	}
	return 0;
}