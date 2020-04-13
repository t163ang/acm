#include<iostream>
using namespace std;
int t,cur,curn,curx[10],x[10] = {0}; //x记录刀切位置
char num[10];
int getN(int dao){
	int sum,ans = 0;
	for(int i = dao; i > 0; i--){
		int s = x[i],e = x[i - 1];
		sum = 0;
		for(int j = s; j < e; j++){
			int n = num[j] - '0';
			sum *= 10;
			sum += n;
		}
		ans += sum;
	}
	return ans;
}
/*
dao：表示第几刀，初始值：1
m: 表示剩余块数,初始值：字符数
*/
void dfs(int dao, int m){
	if(m <= 0){
		int n = getN(dao - 1);
		if(n <= t){
			if(n > cur){
				cur = n;
				curn = 1;
				memcpy(curx,x,sizeof(x));
				curx[9] = dao - 1;
			}else if(n == cur){
				curn++;
			}
		}
	}
	for(int i = 0; i < m; i++){
		x[dao] = i;
		dfs(dao + 1, i);
	}
}

bool check(int len){
	int sum = 0;
	for(int i = 0; i < len; i++){
		sum += num[i] - '0';
	}
	return sum > t;
}

void prans(){
	printf("%d",cur);
	for(int i = curx[9]; i > 0; i--){
		int s = curx[i], e = curx[i - 1];
		printf(" ");
		for(int j = s; j < e; j++){
			printf("%c",num[j]);
		}
	}
	puts("");
}
int main(){
	//freopen("in.txt","r",stdin);
	while(scanf("%d%s",&t,num),t){
		int len = strlen(num);
		x[0] = len; 
		cur = 0;
		if(check(len)){
			printf("error\n");
		}
		else{
			dfs(1,len);
			if(curn != 1) {
				printf("rejected\n");
			}else{
				prans();
			}
		}
	}
	return 0;
}