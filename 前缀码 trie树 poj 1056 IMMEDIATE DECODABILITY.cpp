#include<iostream>
using namespace std;
const int MN = 1024;
int CA = 1;
struct Node{
	Node *next[2];
	int cnt;
	Node(){
		cnt = 0;
		next[0] = next[1] = NULL;
	}
}*root;

bool insert(char *str){
	Node *p = root;
	char *q = str;
	while(*q){
		int n = *q - '0';
		if((p -> cnt) > 0) return false;
		if(!(p -> next[n])) p -> next[n] = new Node();
		p = p -> next[n];
		q++;
	}
	(p -> cnt)++;
	return true;
}
char str[MN];
int main(){
	//freopen("in.txt","r",stdin);
	root = new Node();
	bool flag = true;
	while(~scanf("%s",str)){
		if(str[0] == '9'){
			delete root;
			root = new Node();
			if(flag) printf("Set %d is immediately decodable\n",CA++);
			flag = true;
		}else{
			if(flag && !insert(str)) {
				printf("Set %d is not immediately decodable\n",CA++);
				flag = false;
			}
		}

	}
	return 0;
}
// sample input
//01
//10
//0010
//0000
//9
//01
//10
//010
//0000
//9