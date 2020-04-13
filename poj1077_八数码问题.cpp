#include<iostream>
using namespace std;
int puzz[10],x;
int cantor[10] = {40320,5040,720,120,24,6,2,1,1};//����չ��
const int MN = 362882;
bool visited[MN];
int que[MN],head,tail;
int pre[MN];//��¼ǰһ��
char dir[MN];//��¼����
char path[MN]; //���·��
int finct = -1;
//����Ƿ��н�
bool check(){
	int sum = 0;
	for(int i = 0; i < 9; i++){
		if(i == x) continue;
		for(int j = 0; j < i; j++){
			if(j != x && puzz[j] > puzz[i]) sum++;
		}
	}
	if(sum & 1) return false;
	else return true;
}

//����չ�����������ǵڼ�����
inline int Can(){
	int sum = 0;
	for(int i = 0; i < 8; i++){
		int tmp = 0;
		for(int j = i + 1; j < 9; j++){
			if(puzz[j] < puzz[i]) tmp++;
		}
		sum += tmp * cantor[i];
	}
	return sum;
}

//�濵��չ������
int revCan(int ct){
	int i,j,v,u,ans;
	bool used[10] = {0};
	for(i = 0; i < 9; i++){
		v = ct / cantor[i];
		for(j = 1,u = 0; j <= 9; j++){		
			if(!used[j]){
				u++;
			}
			if(u == v + 1){			
				used[j] = true;
				puzz[i] = j;
				if(j == 9) ans = i;
				break;
			}
		}
		ct -= v * cantor[i];
	}
	return ans;
}


bool isok(){
	for(int i = 0; i < 9; i++){
		if(puzz[i] != i + 1) return false;
	}
	return true;
}

void bfs(int x){
	head = tail = 0;
	int u,ct,ut = Can();
	visited[ut] = true;
	pre[ut] = -1;
	que[tail++] = ut;
	while(tail != head){		
		ut = que[head++];
		u = revCan(ut);
		if(u - 3 >=0){//����
			swap(puzz[u - 3],puzz[u]);
			ct = Can();
			if(!visited[ct]){
				que[tail++] = ct;
				visited[ct] = true;
				pre[ct] = ut;
				dir[ct] = 'u';
				if(isok()) {finct = ct; break;}
			}
			swap(puzz[u - 3],puzz[u]);
		}

		if(u + 3 < 9){//����
			swap(puzz[u + 3],puzz[u]);
			ct = Can();			
			if(!visited[ct]){
				que[tail++] = ct;
				visited[ct] = true;
				pre[ct] = ut;
				dir[ct] = 'd';
				if(isok()) {finct = ct; break;}
			}
			swap(puzz[u + 3],puzz[u]);
		}

		if(u != 3 && u != 6 && u - 1 >=0){//����
			swap(puzz[u - 1],puzz[u]);
			ct = Can();		
			if(!visited[ct]){
				que[tail++] = ct;
				visited[ct] = true;
				pre[ct] = ut;
				dir[ct] = 'l';
				if(isok()) {finct = ct; break;}
			}
			swap(puzz[u - 1],puzz[u]);
		}

		if(u != 2 && u != 5 && u + 1 < 9){//����
			swap(puzz[u + 1],puzz[u]);
			ct = Can();		
			if(!visited[ct]){
				que[tail++] = ct;
				visited[ct] = true;
				pre[ct] = ut;
				dir[ct] = 'r';
				if(isok()) {finct = ct; break;}
			}
			swap(puzz[u + 1],puzz[u]);
		}
	}
}

void print_path(){
	int i = finct,n = 0;
	while(pre[i] != -1){
		path[n++] = dir[i];
		i = pre[i];
	}
	for(i = n - 1; i >= 0; i--){
		printf("%c",path[i]);
	}
	puts("");
}
int main(){
	//freopen("in.txt","r",stdin);
	char c;
	for(int i = 0; i < 9; i++){
		scanf("%c ",&c);
		if(c != 'x'){
			puzz[i] = c - '0'; 
		}else{
			puzz[i] = 9;
			x = i;
		}
	}
	if(check() && !isok()){
		bfs(x);
		if(finct != -1){
			print_path();
		}else{
			printf("unsolvable\n");
		}
	}else{
		printf("unsolvable\n");
	}
	return 0;
}
