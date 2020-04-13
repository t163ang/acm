#include<iostream>
using namespace std;
const int MN = 100004;
int N, ans; char str[MN][5];
int convert(char s[]){
	int ans = 0; int i = 1;
	if(strlen(s)==3) {ans = 9; i=2;}
	switch(s[i]){
		case 'D': ans += 13;break;
		case 'H': ans += 13 * 2;break;
		case 'S': ans += 13 * 3;break;
	}
	if(strlen(s)==3) return ans;
	switch(s[0]){
		case 'A': break;
		case 'J': ans += 10;break;
		case 'Q':ans += 11;break;
		case 'K': ans += 12; break;
		default: ans += s[0] - '0' - 1;
	}
	return ans;
}

struct Node{
	Node *next[54];
	Node(){
		for(int i = 0; i < 54; i++) next[i] = NULL;
	}
}*root;

void insert(){
	Node *p = root;
	for(int i = 0; i < N; i++){
		int n = convert(str[i]);
		if(!(p -> next[n])){ans++; p -> next[n] = new Node();}
		p = p -> next[n];
	}
}

int main(){
	//freopen("in.txt","r",stdin);
	int i,j,n;
	while(scanf("%d",&n),n){
		ans = 0; root = new Node();
		for(j = 0; j < n; j++){
			scanf("%d",&N);
			for(i = N - 1; i >=0; i--){
				scanf("%s",str[i]);
			}
			insert();
		}
		printf("%d\n",ans);
	}
	return 0;
}