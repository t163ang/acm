#include<iostream>
#include<cstring>
using namespace std;

const int MW = 100024;
struct Word{
	char eng[11];
	char fgn[11];
}word[MW];

int qcmp(const void *a, const void *b){
	return strcmp(((Word *)a)->fgn,((Word *)b) -> fgn);
}

int bcmp(const void *a, const void *b){
	return strcmp((char *)a,((Word *)b) -> fgn);

}


int main(){
	//freopen("in.txt","r",stdin);
	char s[23] = {0};
	int n = 0;
	while(gets(s)){		
		if(!s[0]) break;
		sscanf(s,"%s%s",word[n].eng,word[n].fgn);
		n++;
	}
	qsort(word,n,sizeof(word[0]),qcmp);
	
	Word *bs;
	while(scanf("%s",s) != EOF){
		bs = (Word *)bsearch(s,word,n,sizeof(word[0]),bcmp);
		if(!bs) printf("eh\n");
		else printf("%s\n",bs->eng);
	}
	
	return 0;
}

/*
Input

Input consists of up to 100,000 dictionary entries, followed by a blank line, followed by a message of up to 100,000 words. Each dictionary entry is a line containing an English word, followed by a space and a foreign language word. No foreign word appears more than once in the dictionary. The message is a sequence of words in the foreign language, one word on each line. Each word in the input is a sequence of at most 10 lowercase letters.
Output

Output is the message translated to English, one word per line. Foreign words not in the dictionary should be translated as "eh". 
Sample Input

dog ogday
cat atcay
pig igpay
froot ootfray
loops oopslay

atcay
ittenkay
oopslay

Sample Output
cat
eh
loops
*/

//题目大意很简单，就是给你字典的对应信息，然后给你查询条件要求你输出字典查询结果，如果字符串没有在字典中则输出"eh"。先对字典使用qsort排序然后再使用bsearch()查找字符串即可。第一次用系统的bsearch,注意cmp的写法。 
//还用到了一个输入函数sscanf()，可以从一个字符串中读取内容，格式如下
//
//sscanf (string str, string format [, string var1...])
//
//
////poj_2503 Babelfish
////LiQi 2010-7-19 16:35
//#include<istream>
//#include<cstdlib>
//#include<cstring>
//typedef struct
//{
//	char en[11];
//	char fn[11];
//}dict;
//dict a[100001];
//int qcmp(const void *a,const void *b)
//{
//	// return strcmp(((dict*)a)->fn,((dict*)b)->fn);
//	dict *c=(dict*)a;
//	dict *d=(dict*)b;
//	return strcmp(c->fn,d->fn);
//}
//int bcmp(const void *a,const void *b)
//{
//	return strcmp((char*)a,((dict*)b)->fn);
//}
//int main()
//{
//   freopen("in.txt","r",stdin);
//	int i=0;
//	dict *p;
//	char s[30],str[11];
//	while(gets(str))
//	{
//		if(str[0]=='\0') break;
//		 sscanf(str,"%s%s",a[i].en,a[i].fn);//使用sscanf从str中读取查询要求
//		i++;
//	}
//	qsort(a,i,sizeof(a[0]),qcmp);
//	while(scanf("%s",s)!=EOF)
//	{
//		p=(dict*)bsearch(s,a,i,sizeof(a[0]),bcmp);//二分查找指定字符串
//		if(p)//返回指针
//		printf("%s\n",p->en);
//		else
//		printf("eh\n");
//	}
//	return 0;
//}
// 
//总结】 
//第一：要注意不同的函数是否接受空格符、是否舍弃最后的回车符的问题!
//读取字符时：
//scanf()以Space、Enter、Tab结束一次输入，不会舍弃最后的回车符（即回车符会残留在缓冲区中）；
//getchar()以Enter结束输入，也不会舍弃最后的回车符；
//读取字符串时：
//scanf()以Space、Enter、Tab结束一次输入，舍弃最后的回车符。
//gets()以Enter结束输入（空格不结束），接受空格，会舍弃最后的回车符！
//
//第二：为了避免出现上述问题，必须要清空缓冲区的残留数据，可以用以下的方法解决：
//方法1：C语言里提供了函数清空缓冲区，只要在读数据之前先清空缓冲区就没问题了！
//       这个函数是fflush(stdin)。
//方法2：自己取出缓冲区里的残留数据。
//       scanf("%[^\n]",string);
//
//应该尽量用fgets代替gets吧，gets有产生bug的隐患。


//qsort 和bsearch的cmp函数不同的
//qsort 比较的时dict 数组的两个成员
//bsearch比较的时key 和dict中成员
