#include<iostream>
#include<algorithm>
using namespace std;
const int MN = 104;
char str[MN];
int main(){
	//freopen("in.txt","r",stdin);
	while(scanf("%s",str), str[0] != '#'){
		if(next_permutation(str,str + strlen(str))){
			puts(str);
		}else puts("No Successor");
	}
	return 0;
}