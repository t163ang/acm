//��Ŀ���⣺�����ɣ𵽣��ͣá��ġ��š��ɡ�����ɡ�p--z�����ַ����ǺϷ��ľ��ӣ����á��ġ��š����е�һ���������Ϸ��ľ��������һ���ǣ���Ϊһ���Ϸ��ľ��ӣ�Nֻ����һ���Ϸ��ľ�����ϳ�һ���Ϸ��ľ��ӡ�
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