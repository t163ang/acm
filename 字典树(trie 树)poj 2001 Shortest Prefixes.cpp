#include<iostream>
using namespace std;
char str[1024][30];
struct Node{
	int cnt;
	Node *next[26];
	Node(){
		cnt = 1;
		for(int i = 0; i < 26; i++) next[i] = NULL;
	}
}root;

void insert(char *str){
	Node *p = &root;
	for(int i = 0;str[i];i++){
		int n = str[i] - 'a';
		if(p->next[n]) p->next[n]->cnt++;
		else p->next[n] = new Node();
		p = p ->next[n];
	}
}

int search(char *str){
	Node *p = &root; int i;
	for(i = 0; str[i]; i++){
		int n = str[i] - 'a';
		if(p ->next[n] -> cnt == 1) return i;
		p = p ->next[n];
	}
	return i - 1;
}

int main(){
	//freopen("in.txt","r",stdin);
	int i,j, n = 0;
	while(~scanf("%s",str[n])){
		insert(str[n++]);
	}
	for(i =0; i < n; i++){
		int m = search(str[i]);
		printf("%s ",str[i]);
		for(j = 0; j <= m; j++){
			printf("%c",str[i][j]);
		}
		puts("");
	}
}