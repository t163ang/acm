#include<iostream>
#include<stack>
using namespace std;

char *code[12] = {"063","010","093","079","106","103","119","011","127","107"};
int getn(char cmps[]){
	for(int j = 0; j <= 9;j++){
		if(!strcmp(code[j],cmps)) return j;		
	}
	return 0;
}
int main(){
	char s[80];
	int i,j;
	while(scanf("%s",s)){		
		if(!strcmp(s,"BYE")) break;
		int strlen;
		int a = 0,b = 0;
		printf("%s",s);
		for(i = 0; s[i] != '+'; i += 3){
			char str[4] = {0};
			str[0] = s[i],str[1] = s[i + 1],str[2] = s[i + 2];
			int tmp = getn(str);
			a *= 10;
			a += tmp;
		}
		for(i++; s[i] != '='; i += 3){
			char str2[4] = {0};
			str2[0] = s[i],str2[1] = s[i + 1],str2[2] = s[i + 2];
			int tmp = getn(str2);
			b *= 10;
			b += tmp;
		}
		int result = a + b;
		stack<int> sta;
		while(result > 0){
			sta.push(result % 10);
			result /= 10;
		}
		while(!sta.empty()){
			printf("%s",code[sta.top()]);
			sta.pop();
		}
		puts("");
			
	}
	return 0;
}

/*
#include<cstdio>
#include<cstring>

int code[10]={63,10,93,79,106,103,119,11,127,107};
int code2[200];
void print(int x)
{
    if(x==0)return;
    print(x/10);
    printf("%03d",code[x%10]);
}
int main()
{
    //freopen("in","r",stdin);
    code2[63]=0;
    code2[10]=1;
    code2[93]=2;
    code2[79]=3;
    code2[106]=4;
    code2[103]=5;
    code2[119]=6;
    code2[11]=7;
    code2[127]=8;
    code2[107]=9;
    char str[10000];
    while(~scanf("%s",str),str[0]!='B')
    {
        printf("%s",str);
        int op[2]={0},*p=op;
        for(int i=0;str[i];i++){
            if(str[i]<='9'&&str[i]>='0')
            {
                int tmp = (str[i]-'0')*100+(str[i+1]-'0')*10+(str[i+2]-'0');
                *p=(*p)*10+code2[tmp];
                i+=2;
            }
            else p++;
            if(str[i]=='=')break;
        }
    //    printf("%d %d\n",op[0],op[1]);
        print(op[0]+op[1]);
        puts("");
    }
    return 0;
}
*/