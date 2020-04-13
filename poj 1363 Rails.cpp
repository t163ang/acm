#include<iostream>
#include<algorithm>
using namespace std;
const int MN =  1024;
int n;
int stack[MN],top;
int que[MN],head,tail;
int main(){
	//freopen("in.txt","r",stdin);
	int i,j,k; bool sec = false;
	while(scanf("%d",&n),n){
		if(sec) puts("");
		while(true){
			scanf("%d",&k);
			if(k == 0) {break;}
			top = head = tail = 0;
			for(i = 1; i <= n; i++){
				que[tail++] = i;
			}
			stack[top++] = -1;
			for(i = 1; i <= n; i++){			
				if(k == stack[top - 1]){
					top--;
				}else if(k > stack[top - 1]){
					while(head != tail && que[head] != k){		
						stack[top++] = que[head++];
					}
					if(head == tail) break;
					else head++;

				}else break;
				if(i < n) scanf("%d",&k);
			}
			if(i <= n) printf("No\n");
			else printf("Yes\n");
			while(i++ < n) scanf("%d",&k);
		}
		sec =true;
	}
	return 0;
}