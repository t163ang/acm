#include<iostream>
using namespace std;
const int MN = 1 << 16;
bool state[MN + 100];
int count[MN + 100];
int que[MN << 1],qh,qt;
int change(int p,int st){
	st ^= 1 << p;
	//ио
	if(p - 4 >= 0){
		st ^= 1 << (p - 4);
	}
	//об
	if(p + 4 < 16){
		st ^= 1 << (p + 4);
	}
	//вС
	if(p % 4 != 0 && p - 1 >= 0){
		st ^= 1 << (p - 1);
	}
	//ср
	if((p + 1) % 4 != 0 && p + 1 < 16){
		st ^= 1 << (p + 1);
	}
	return st;
}
void bfs(int st){
	qh = qt = 0;
	que[qt++] = st;
	state[st] = true;
	while(qh != qt){
		int u = que[qh++];
		for(int i = 0; i < 16; i++){
			int tmp = change(i,u);
			if(!state[tmp]){
				que[qt++] = tmp;
				state[tmp] = true;
				count[tmp] = count[u] + 1;
				if(tmp == 0 || tmp == MN - 1){
					printf("%d\n",count[tmp]);
					return;
				}
			}
		}
	}
	puts("Impossible");
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,num;
	char c;
	for(i = 0,num = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
			c = getchar();
			if(c == 'b'){
				num |= 1 << (i * 4 + j);
			}
		}
		getchar();
	}
	if(num == 0 || num == MN - 1) {
		puts("0");
	}else{
		memset(count,0,sizeof(count));
		memset(state,0,sizeof(state));
		bfs(num);
	}
	return 0;
}