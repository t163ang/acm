#include<iostream>
#include<string>
#include<cstring>
#include <stdio.h>
using namespace std;
int main(){
	/*const char* s = "iios/12DDWDFF@122";
	char buf[20];
	sscanf( s, "%*[^/]/%*d%[^@]", buf );
	printf( "%s\n", buf );

	char buf2[45] = "sdf,sdfa+sdfajhsd|sdfahjk";
	char *token = strtok(buf2,"+,|");
	while(token != NULL){
		printf("%s\n",token);
		token = strtok(NULL,",+|");
	}*/

	//string s; 
	//const char *s2;
	//cin >> s;
	//s2 = s.c_str();
	return 0; 
}
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main(){
//	//freopen("in.txt","r",stdin);
//	string str;
//	string str2 = "iios,12DDWD|FF@122";
//	while(true){
//		int i = str2.find_first_of(",|");
//		str = str2.substr(0,i);
//		str2 = str2.substr(i + 1);
//		cout << str << endl;
//		if(i == -1) break;
//	}
//	return 0;
//}