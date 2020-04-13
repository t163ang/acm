/*
#include<iostream>

using namespace std;

Input

The first line of input is an integer n (n > 0) specifying the number of cases to follow. Each case consists of three lines of input, one for each weighing. Sally has identified each of the coins with the letters A--L. Information on a weighing will be given by two strings of letters and then one of the words ``up'', ``down'', or ``even''. The first string of letters will represent the coins on the left balance; the second string, the coins on the right balance. (Sally will always place the same number of coins on the right balance as on the left balance.) The word in the third position will tell whether the right side of the balance goes up, down, or remains even. 

Output

For each case, the output will identify the counterfeit coin by its letter and tell whether it is heavy or light. The solution will always be uniquely determined. 
Sample Input

1 
ABCD EFGH even 
ABCI EFJK up 
ABIJ EFGH even 
*/
/*
wa:
int main(){	

//freopen("s.txt","w",stdout);
int n;
int i,j,k;
cin >> n;
while(n--){
int test[26] = {0};
char left[26],right[26],bla[20];
for(j = 0; j < 3; j++){
cin >> left >> right >> bla;
int len = strlen(left);
if(!strcmp(bla,"even")){		
for(i = 0; i < len; i++){
test[left[i] - 'A'] = 1;
test[right[i] - 'A'] = 1;
}
}else if(!strcmp(bla,"up")){
for(i = 0; i < len; i++){
if(test[left[i] - 'A'] == 0) test[left[i] - 'A'] = -1;
if(test[right[i] - 'A'] == 0) test[right[i] - 'A'] = -2;
}
}else{
for(i = 0; i < len; i++){
if(test[left[i] - 'A'] == 0) test[left[i] - 'A'] = -2;
if(test[right[i] - 'A'] == 0) test[right[i] - 'A'] = -1;;
}
}
}
for(i = 0 ; i < 26; i++){
if(test[i] < 0) break;
}
printf("%c is the counterfeit coin and it is %s.\n",'A' + i,test[i] == -1 ? "heavy":"light");
}
return 0;
}*/

#include"cstdio"
#include"cstring"

char left[3][7],right[3][7],result[3][5];

bool isHeavy(char x )
{
	int i;
	for(i=0;i<3;i++)
	{
		switch(result[i][0]){
		case 'u': if(strchr( left[i] , x)==NULL) return false; break;
		case 'e':if(strchr(left[i],x)!=NULL||strchr(right[i],x)!=NULL)return false;break;
		case 'd':if(strchr(right[i],x)==NULL)return false;break;
		}
	}
	return true;
}

bool isLight(char x )
{
	int i;
	for(i=0;i<3;i++)
	{
		switch(result[i][0])
		{
		case 'u':if(strchr(right[i],x)==NULL)return false;break;  //天平不平衡，说明一定存在假的
		case 'e':if(strchr(left[i],x)!=NULL||strchr(right[i],x)!=NULL)return false;break;
		case 'd':if(strchr(left[i],x)==NULL)return false;break;
		}
	}
	return true;
}

int main()
{
	int n;
	char c;
	int i;
	scanf("%d",&n);
	while(n>0)
	{
		for( i=0;i<3;i++)
			scanf("%s%s%s",left[i],right[i],result[i]);
		for(c='A';c<='L';c++)
		{
			if(isLight(c))
			{
				printf("%c is the counterfeit coin and it is light.\n",c);
				break;
			}
			if(isHeavy(c))
			{
				printf("%c is the counterfeit coin and it is heavy.\n",c);
				break;
			}

		}
		n--;

	}
	return 0;
}