#include<iostream>
#include<algorithm>
using namespace std;

struct A{
    char c[30];
    int count;
    bool operator<(const A &p)const{
        return count > p.count;
    }
}str[2000];
int main(){
    int n;
    int i,j,k;
    char s[30];
    while(scanf("%d",&n) && n){
        getchar();
        k = 0;
        memset(str,0,sizeof(str));
        for(i = 0; i < n; i++){
            gets(s);
            for(j = 0; j < k; j++ ){
                if(strcmp(s, str[j].c) == 0) {
                    str[j].count++;
                    break;
                }
            }
            if(j >= k) {
                strcpy(str[k].c,s);
                k++;
            }
        }
        sort(str,str + n);
        printf("%s\n",str[0].c);
    }
    return 0;
}