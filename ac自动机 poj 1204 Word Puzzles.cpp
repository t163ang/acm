#include<iostream>
using namespace std;
const int MN = 1024;
int dir[20][2] = {{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1}};
int L,C,W,WN,DX,DY; 
char DI;
char puz[MN][MN], str[MN]; 
struct Node{
	int cnt;
	Node *fail, *next[28];
	void init(){
		cnt = 0;fail = 0;
		for(int i = 0 ;i < 26; i++) next[i] = 0;
	}
}node[2000000]; int ep = 2;

struct{
	int x,y;
	char d;
}result[MN];
Node *root = &node[0], *super = &node[1];
void insert(char *str){
	Node *p = root; int len = strlen(str);
	for(int i = len - 1; i >=0; i--){//逆向建图
		int n = str[i] - 'A';
		if(!(p ->next[n])){
			node[ep].init();
			p ->next[n] = node + ep++;
		}
		p = p -> next[n];
	}
	p -> cnt = WN;
}
Node *que[MN];
void acfail(){
	int i,head = 0, tail = 0;
	Node *p,*q;
	for(i = 0; i < 26; i++) super->next[i] = root;
	root ->fail = super;
	que[tail++] = root;
	while(head != tail){
		p = que[head]; head = (head + 1) % MN;
		for(i = 0; i < 26; i++){
			if(!(p -> next[i])) continue;
			q = p ->fail;
			while(!(q -> next[i])) q = q -> fail;
			p -> next[i] ->fail  = q -> next[i];
			que[tail] = p ->next[i]; tail = (tail + 1) % MN; 
		}

	}
}

inline bool place(int x, int y){
	if(x >=0 && y >= 0 && x < L && y < C) return true;
	return false;
}

void search(int x, int y,char str[][MN]){//逆向搜索一条直线
	Node *p = root, *q;
	while(true){
		int n = str[x][y] - 'A';
		while(!(p -> next[n])) p = p -> fail;
		p = p -> next[n];
		q = p;
		while(q != root){
			int m = q -> cnt;
			if(m > 0){
				result[m].x = x;
				result[m].y = y;
				result[m].d = DI;
			}
			q = q -> fail;
		}
		if(place(x + DX, y + DY)) x += DX, y += DY; 
		else break;
	}
}
// Accepted 12760K 422MS C++ 2950B
int main(){
	freopen("in.txt","r",stdin);
	while(~scanf("%d%d%d",&L,&C,&W)){
		for(WN = 0; WN < 26; WN++) root -> next[WN] = 0;
		for(WN = 0; WN < L; WN++){
			scanf("%s",puz[WN]);
		}
		for(WN = 1; WN <= W; WN++){
			scanf("%s",str);
			insert(str);
		}
		acfail(); int i = 0;
		for(i = 0; i < L; i++){
			DI = 'G';search(i,0,puz);
		}
		for(i = 0; i < L; i++){
			DI = 'C';search(i,C - 1,puz);
		}
		for(i = 0; i < C; i++){
			DI = 'A';search(0,i,puz);	
		}
		for(i = 0; i < C; i++){
			DI = 'E';search(L - 1,i,puz);
		}
		for(i = 0; i < L; i++){
			DI = 'H';search(i,0,puz);
		}
		for(i = 0; i < C; i++){
			DI ='H';search(0,i,puz);
		}
		for(i = L - 1; i >= 0; i--){
			DI = 'D';search(i,C - 1,puz);
		}
		for(i = C - 1; i >= 0; i--){
			 DI ='D';search(L - 1,i,puz);
		}
		for(i = L - 1; i >= 0; i--){
			DI = 'F';search(i,0,puz);
		}
		for(i = 0; i < C; i++){
			 DI ='F'; search(L - 1,i,puz);
		}
		for(i = 0; i < L; i++){
			DI = 'B';search(i,C - 1,puz);	
		}
		for(i = C - 1; i >= 0; i--){
			DI ='B';search(0,i,puz); 
		}
		for(WN = 1; WN <= W; WN++){
			printf("%d %d %c\n",result[WN].x,result[WN].y,result[WN].d);
		}
	}
	return 0;
}
//也可以对四条边八个方向search,方便点
// Accepted 12760K 1047MS C++ 2634B
//for(DI = 'A'; DI <= 'H'; DI++){
//	int i;
//	for(i = 0; i < L; i++)
//		search(i,0,puz);
//	for(i = L - 1; i >= 0; i--)
//		search(i,0,puz);
//	for(i = 0; i < L; i++)
//		search(i,C - 1,puz);
//	for(i = L - 1; i >= 0; i--)
//		search(i,C - 1,puz);

//	for(i = 0; i < C; i++)
//		search(0,i,puz);
//	for(i = C - 1; i >= 0; i--)
//		search(0,i,puz);
//	for(i = 0; i < C; i++)
//		search(L - 1,i,puz);
//	for(i = C - 1; i >= 0; i--)
//		search(L - 1,i,puz);
//}