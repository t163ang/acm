#include<iostream>
using namespace std;
const int MN = 100024;
int G[28][28],indeg[MN],outdeg[MN],N;
char str[MN];
bool vis[28];
void dfs(int x){
	vis[x] = true;
	N++;
	for(int i = 0; i < 26; i++){
		if(!vis[i] && G[x][i]){
			dfs(i);
		}
	}
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int t; scanf("%d",&t);
	while(t--){
		memset(G,0,sizeof(G));
		memset(indeg,0,sizeof(indeg));
		memset(outdeg,0,sizeof(outdeg));
		int i,n,in,out; scanf("%d",&n);
		for(i = 0; i < n; i++){
			scanf("%s",str);
			out = str[0] - 'a'; in = str[strlen(str) - 1] - 'a';
			G[in][out] = 1;
			G[out][in] = 1;
			indeg[in]++; outdeg[out]++;
		}
		int np = 0,sx = -1; bool fir = true;
		for(i = 0; i < 26 ;i++){
			if(indeg[i] || outdeg[i]){
				np++;
				if(fir) {sx = i; fir = false;}
			}
		}
		memset(vis,0,sizeof(vis));
		N = 0;
		dfs(sx); 
		if(N != np){
			puts("The door cannot be opened.");
			continue;
		}

		int odds = 0,odde = 0,ne = 0,nt = 0;
		for(i = 0; i < 26; i++){
			if(outdeg[i] == 0 && indeg[i] == 0) continue;
			nt++;
			if(outdeg[i] == indeg[i] +  1){
				odds++;
			}else if(indeg[i] == outdeg[i] + 1){
				odde++;
			}else if(indeg[i] == outdeg[i]){
				ne++;		
			}
		}
		if(odds == 1 && odde == 1 && ne == nt - 2|| ne == nt){	
			printf("Ordering is possible.\n"); 
		}else printf("The door cannot be opened.\n");
	}
	return 0;
}
