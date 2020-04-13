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

//��Ŀ����ܼ򵥣����Ǹ����ֵ�Ķ�Ӧ��Ϣ��Ȼ������ѯ����Ҫ��������ֵ��ѯ���������ַ���û�����ֵ��������"eh"���ȶ��ֵ�ʹ��qsort����Ȼ����ʹ��bsearch()�����ַ������ɡ���һ����ϵͳ��bsearch,ע��cmp��д���� 
//���õ���һ�����뺯��sscanf()�����Դ�һ���ַ����ж�ȡ���ݣ���ʽ����
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
//		 sscanf(str,"%s%s",a[i].en,a[i].fn);//ʹ��sscanf��str�ж�ȡ��ѯҪ��
//		i++;
//	}
//	qsort(a,i,sizeof(a[0]),qcmp);
//	while(scanf("%s",s)!=EOF)
//	{
//		p=(dict*)bsearch(s,a,i,sizeof(a[0]),bcmp);//���ֲ���ָ���ַ���
//		if(p)//����ָ��
//		printf("%s\n",p->en);
//		else
//		printf("eh\n");
//	}
//	return 0;
//}
// 
//�ܽ᡿ 
//��һ��Ҫע�ⲻͬ�ĺ����Ƿ���ܿո�����Ƿ��������Ļس���������!
//��ȡ�ַ�ʱ��
//scanf()��Space��Enter��Tab����һ�����룬�����������Ļس��������س���������ڻ������У���
//getchar()��Enter�������룬Ҳ�����������Ļس�����
//��ȡ�ַ���ʱ��
//scanf()��Space��Enter��Tab����һ�����룬�������Ļس�����
//gets()��Enter�������루�ո񲻽����������ܿո񣬻��������Ļس�����
//
//�ڶ���Ϊ�˱�������������⣬����Ҫ��ջ������Ĳ������ݣ����������µķ��������
//����1��C�������ṩ�˺�����ջ�������ֻҪ�ڶ�����֮ǰ����ջ�������û�����ˣ�
//       ���������fflush(stdin)��
//����2���Լ�ȡ����������Ĳ������ݡ�
//       scanf("%[^\n]",string);
//
//Ӧ�þ�����fgets����gets�ɣ�gets�в���bug��������


//qsort ��bsearch��cmp������ͬ��
//qsort �Ƚϵ�ʱdict �����������Ա
//bsearch�Ƚϵ�ʱkey ��dict�г�Ա
