//只能c++通过
#include<iostream>
using namespace std;
const int MN = 10024;
struct Node{
	char c;
	Node *L,*R;
	Node(char x){c =x; L = NULL; R = NULL;}
	Node(){};
};
char str[MN];
Node *sta[MN]; int top;
Node *que[MN]; int head,tail;
char ans[MN]; int pi = 0;
int main(){
	//freopen("in.txt","r",stdin);
	int T,i,j,k; 
	scanf("%d",&T);
	while(T--){
		scanf("%s",str);
		top = 1;Node *nn;
		int len = strlen(str);
		for(i = 0; i < len; i++){
			if(str[i] >= 'a') sta[top++] = new Node(str[i]);
			else{
				nn = new Node(str[i]);
				nn -> R = sta[--top];
				nn -> L = sta[--top];
				sta[top++] = nn;
			}
		}
		head = tail = 1; pi = 0;
		que[tail++] = sta[--top];
		while(head != tail){
			nn = que[head++];
			ans[pi++] = nn->c;
			if(nn->L){
				que[tail++] = nn->L;
				que[tail++] = nn->R;
			}
		}

		for(i = pi - 1; i >= 0; i--){
			printf("%c",ans[i]);
		}
		puts("");
	}
	return 0;
}
//#include<iostream>
//using namespace std;
//const int MN = 10024;
//struct Node{
//	char c;
//	int L,R;
//	Node(char x){c =x; L = NULL; R = NULL;}
//	Node(){};
//}node[MN]; int ep = 1;
//char str[MN];
//int sta[MN]; int top;
//int que[MN]; int head,tail;
//char ans[MN]; int pi = 0;
//int main(){
//	//freopen("in.txt","r",stdin);
//	int T,i; 
//	scanf("%d",&T);
//	while(T--){
//		memset(node,0,sizeof(node));
//		scanf("%s",str);
//		top = ep = 1;
//		int len = strlen(str);
//		for(i = 0; i < len; i++){
//			if(str[i] >= 'a') {
//				node[ep].c = str[i];
//				sta[top++] = ep++;
//			}
//			else{
//				node[ep].c = str[i];
//				node[ep].R = sta[--top];
//				node[ep].L = sta[--top];
//				sta[top++] = ep++;
//			}
//		}
//		head = tail = 1; pi = 0;
//		que[tail++] = sta[--top];
//		while(head != tail){
//			int nn = que[head++];
//			ans[pi++] = node[nn].c;
//			if(node[nn].L > 0){
//				que[tail++] = node[nn].L;
//				que[tail++] = node[nn].R;
//			}
//		}
//
//		for(i = pi - 1; i >= 0; i--){
//			printf("%c",ans[i]);
//		}
//		puts("");
//	}
//	return 0;
//}
//G++通过
//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<string>
//using namespace std;
//string level[1 << 13];int ml;
//char str[10004]; int r;
//void dfs(int li){
//	char ch = str[r--];
//	level[li] += ch;
//	if(li > ml) ml = li;
//	if(ch <= 'Z'){
//		dfs(li + 1);
//		dfs(li + 1);
//	}
//}
//int main(){
//	//freopen("in.txt","r",stdin);
//	int t; scanf("%d",&t);
//	while(t--){
//		scanf("%s",str);
//		r = strlen(str) - 1; ml = 0;
//		dfs(0);
//		for(int i = ml; i >=0; i--){
//			printf("%s",level[i].c_str());
//			level[i].clear();
//		}
//		puts("");
//	}
//	return 0;
//}
