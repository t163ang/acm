//题目大意：句子由ｐ到ｚ和Ｃ、Ｄ、Ｅ、Ｉ、Ｎ组成。p--z单个字符都是合法的句子，当Ｃ、Ｄ、Ｅ、Ｉ中的一个与两个合法的句子组合在一起是，成为一个合法的句子，N只能与一个合法的句子组合成一个合法的句子。
#include<iostream>
using namespace std;
const int MN = 1024;
char str[MN];
int main(){
	//freopen("in.txt","r",stdin);
	int k,len,i;
	while(~scanf("%s",str)){
		len = strlen(str); k = 0;
		for(i = len - 1; i >= 0; i--){
			if(str[i] >= 'p' && str[i] <= 'z'){
				k++;
			}else if(str[i] == 'N'){
				if(!k) break;
			}else{
				if(k >= 2) k--;
				else{k = 0; break;}
			}
		}
		if(k == 1) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}