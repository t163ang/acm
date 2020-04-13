#include<iostream>
#include<algorithm>
using namespace std;
//poj1191
char inp[16];
bool comp(char a,char b){
	int x,y;
	if(a >= 'a'){
		x = a - 'a';
		x = x * 2 + 1;
	}else{
		x = a - 'A';
		x = x * 2;
	}

	if(b >= 'a'){
		y = b - 'a';
		y = y * 2 + 1;
	}else{
		y = b - 'A';
		y = y * 2;
	}
	return (x < y);

}

int main(){
	//freopen("in.txt","r",stdin);
	int n,i,j,len;
	while(~scanf("%d",&n)){
		for(i = 0; i < n; i++){
			scanf("%s",inp);
			len = strlen(inp);
			sort(inp,inp + len,comp);
			do{
				puts(inp);
			}while(next_permutation(inp,inp + len,comp));
		}
	}
	return 0;
}

////poj1731
//#include<iostream>
//#include<algorithm>
//#include<cstring>
//using namespace std;
//char str[203];
//int main(){
//	//freopen("in.txt","r",stdin);
//	while(~scanf("%s",str)){
//		int len = strlen(str);
//		sort(str,str + len);
//		do{
//			puts(str);
//		}while(next_permutation(str,str + len));
//	}
//	return 0;
//}