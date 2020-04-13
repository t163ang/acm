#include<iostream>
#include<cstring>
using namespace std;
const int MN = 102;
char stra[MN][30];
char strb[MN][30];
int dp[MN][MN];
int main(){
	//freopen("in.txt","r",stdin);
	char str[30];
	int i,j;
	while(~scanf("%s",str)){		
		int lena = 0, lenb = 0;
		strcpy(stra[lena++],str);
		while(true){
			scanf("%s",str);
			if(strcmp(str,"#")){
				strcpy(stra[lena++],str);
			}else break;
		}
		
		while(true){
			scanf("%s",str);
			if(strcmp(str,"#")){
				strcpy(strb[lenb++],str);
			}else break;
		}

		for(i = 0; i <= lena; i++) dp[i][lenb] = 0;
		for(j = 0; j <= lenb; j++) dp[lena][j] = 0;

		for(i = lena - 1; i >=0 ; i--){
			for(j = lenb - 1; j >= 0; j--){
				if(!strcmp(stra[i],strb[j])) dp[i][j] = dp[i + 1][j + 1] + 1;
				else dp[i][j] = max(dp[i + 1][j],dp[i][j + 1]);	
			}
		}

		i = 0, j = 0;
		while(i < lena){
			while(j < lenb){
				if(dp[i][j] == dp[i + 1][j + 1] + 1){
					printf("%s ",stra[i]);
					i++; j++;
				}else if(dp[i][j] == dp[i + 1][j]){
					i++;
				}else{
					j++;
				}
			}
		}
		puts("");
		//printf("%d\n",dp[0][0]);

	}
	return 0;
}