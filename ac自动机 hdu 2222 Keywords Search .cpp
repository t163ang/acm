#include<iostream>
using namespace std;
const int MN = 10000;
char des[1000005];

struct Node{
	int cnt;
	Node *next[26];
	Node *fail;
	void init(){
		cnt = 0; fail = 0;
		memset(next,0,sizeof(next));
	}
}node[2000000];//这个申请内存，好像不是真正分配，只有当有语法执行时(如memset(node,0,sizeof(node)), 此时memory limit exceed)，才分配给它
int ep = 0;
Node *super = &node[0],*root = &node[1];

void insert(char *str){
	Node *p = root;
	while(*str){
		int n = *str - 'a';
		if(!(p->next[n])) {
			node[ep].init();
			p ->next[n] = node + ep++;
		}
		str++;
		p = p ->next[n];
	}
	p -> cnt++;
}

Node *que[10000];
void acfail(){
	int i,head = 0, tail = 0; Node *p, *u;
	for(i = 0; i < 26; i++) super -> next[i] = root;
	root->fail = super;
	que[tail++] = root;
	while(head != tail){
		p = que[head]; head = (head + 1) % MN;		
		for(i = 0; i < 26; i++){
			if(!(p -> next[i])) continue;	
			u = p ->fail;
			while(!(u ->next[i])){
				u = u -> fail;
			}
			p -> next[i] -> fail = u ->next[i];
			que[tail] = p -> next[i];
			tail = (tail + 1) % MN;
		}
	}
}

int query(char *str){
	Node *p = root;
	int ans = 0;
	while(*str){
		int n = *str - 'a';
		while(!(p -> next[n])) p = p -> fail;
		p = p -> next[n];
		Node *q = p;
		while(q != root && q -> cnt != -1){//当-1时终止是因为回溯到根的所有结点到已计算了
			ans += q -> cnt;
			q -> cnt = -1;
			q = q -> fail;
		}
		str++;
	}
	return ans;
}

int main(){
	//freopen("in.txt","r",stdin);
	int i,n,t; scanf("%d",&t);
	while(t--){
		memset(root ->next,0,sizeof(root -> next));
		//不能直接用memset(node,0,sizeof(node));
		ep = 2;
		scanf("%d",&n);
		char str[60];
		for(i = 0; i < n; i++){
			scanf("%s",str);
			insert(str);
		}
		acfail();
		scanf("%s",des);
		printf("%d\n",query(des));
	}
	return 0;
}
