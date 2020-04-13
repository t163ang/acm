#include<iostream>
#include<cstdio>
using namespace std;
const int MN = 10240;
const int rwCnt = 32;//关键字个数
FILE *fin,*fout;
char cur; //读前读入字符
char *rwtab[128] = {"","auto","double","int","struct","break","else",
"long","switch","case","enum","register","typedef","char","extern",
"return","union","const","float","short","unsigned","continue","for",
"signed","void","default","goto","sizeof","volatile","do","while","static",
"if","include"};
struct Word{
	int syn,len;//len记录单词长度
	char token[MN];
	void init(){
		syn = -1;
		len = 0;
	}
	void push(char c){
		if(len < MN){
			token[len++] = c; 
		}
	}
	void pop(){
		if(len > 0){
			len--;
		}
	}
	char top(){
		return token[len - 1];
	}
	bool isEmpty(){
		return len == 0;
	}
	void end(int s){
		syn = s;
		token[len++] = '\0';
	}
}word;

void output(){
	fprintf(fout,"( %d , %s )\n",word.syn,word.token);
}
/*
读取一个词，错误则syn = -1
*/
void scanner(){
	word.init();
	int i,syn;
	cur = fgetc(fin);
	if(cur == -1){
		word.end(-1);
		return;
	}
	while(cur == ' ' || cur == '\r' || cur == '\n' || cur == '\t'){
		cur = fgetc(fin);
	}
	if(isalpha(cur)){//isalpha(cur)字母a - z,A-Z返回非零值
		do{
			word.push(cur);
			cur = fgetc(fin);
		}while(isdigit(cur) || isalpha(cur));
		for(i = 1; i <= rwCnt; i++){
			if(!strcmp(word.token,rwtab[i])){
				syn = i;
				break;
			}
		}
		if(i > rwCnt){ // 不是关键字，是标识符
			syn = 75;
		}
		word.end(syn);
		fseek(fin,-1L,SEEK_CUR); //文件指针回退一个字符
	}else if(isdigit(cur)){
		do{
			word.push(cur);
			cur = fgetc(fin);
		}while(isdigit(cur));
		word.end(76);
		fseek(fin,-1L,SEEK_CUR);
	}else{
		switch(cur){
			case '(':word.push(cur); word.end(48); break;
			case ')':word.push(cur); word.end(34); break;
			case '[':word.push(cur); word.end(35); break;
			case ']':word.push(cur); word.end(36); break;
			case '-':
				word.push('-');
				cur = fgetc(fin);
				if(cur == '>'){
					word.push(cur);
					word.end(37);
				}else if(cur == '='){
					word.push(cur);
					word.end(61);
				}else if(cur == '-'){
					word.push(cur);
					word.end(42);
				}else{
					word.end(44);
					fseek(fin,-1L,SEEK_CUR);
				}
				break;
			case '.':word.push(cur);word.end(38);break;
			case '!':
				word.push(cur);
				cur = fgetc(fin);
				if(cur == '='){
					word.push(cur);
					word.end(59);
				}else{
					word.end(39);
					fseek(fin,-1,SEEK_CUR);
				}
				break;

			case '~':word.push(cur);word.end(40);break;
			case '+':
				word.push(cur);
				cur = fgetc(fin);
				if(cur == '+'){
					word.push(cur);
					word.end(41);
				}else if(cur == '='){
					word.push(cur);
					word.end(60);
				}else{
					word.end(43);
					fseek(fin,-1L,SEEK_CUR);
				}
				break;
			case '*':
				word.push(cur);
				cur = fgetc(fin);
				if(cur == '='){
					word.push(cur);
					word.end(62);
				}else if(cur == '/'){
					word.push(cur);
					word.end(80);
				}
				else{
					word.end(45);
					fseek(fin,-1L,SEEK_CUR);
				}
				break;
			case '/':
				word.push(cur);
				cur = fgetc(fin);
				if(cur == '/'){
					word.push(cur);
					word.end(81);
				}else if(cur == '='){
					word.push(cur);
					word.end(63);
				}else if(cur == '*'){
					word.push(cur);
					word.end(79);
				}else{
					word.end(46);
					fseek(fin,-1L,SEEK_CUR);
				}
				break;
			case '&':
				word.push(cur);
				cur = fgetc(fin);
				if(cur == '&'){
					word.push(cur);
					word.end(68);
				}else if(cur == '='){
					word.push(cur);
					word.end(73);
				}else{
					word.end(47);
					fseek(fin,-1L,SEEK_CUR);
				}
				break;
			case '%':
				word.push(cur);
				cur = fgetc(fin);
				if(cur == '='){
					word.push(cur);
					word.end(82);
				}else{
					word.end(49);
					fseek(fin,-1L,SEEK_CUR);
				}
				break;
			case '<':
				word.push(cur);
				cur = fgetc(fin);
				if(cur == '<'){
					word.push(cur);
					cur = fgetc(fin);
					if(cur == '='){
						word.push(cur);
						word.end(52);
					}else{
						word.end(50);
						fseek(fin,-1L,SEEK_CUR);
					}
				}else if(cur == '='){
					word.push(cur);
					word.end(57);
				}else{
					word.end(55);
					fseek(fin,-1L,SEEK_CUR);
				}
				break;
			case '>':
				word.push(cur);
				cur = fgetc(fin);
				if(cur == '>'){
					word.push(cur);
					cur = fgetc(fin);
					if(cur == '='){
						word.push(cur);
						word.end(53);
					}else{
						word.end(51);
						fseek(fin,-1L,SEEK_CUR);
					}
				}else if(cur == '='){
					word.push(cur);
					word.end(56);
				}else{
					word.end(54);
					fseek(fin,-1L,SEEK_CUR);
				}
				break;
			case '=':
				word.push(cur);
				cur = fgetc(fin);
				if(cur == '='){
					word.push(cur);
					word.end(58);
				}else{
					word.end(72);
					fseek(fin,-1L,SEEK_CUR);
				}
				break;
			case '^':
				word.push(cur);
				cur = fgetc(fin);
				if(cur == '='){
					word.push(cur);
					word.end(66);
				}else{
					word.end(64);
					fseek(fin,-1L,SEEK_CUR);
				}
				break;
			case '|':
				word.push(cur);
				cur = fgetc(fin);
				if(cur == '='){
					word.push(cur);
					word.end(67);
				}if(cur == '|'){
					word.push(cur);
					word.end(69);
				}else{
					word.end(65);
					fseek(fin,-1L,SEEK_CUR);
				}
				break;
			case '?' : word.push(cur); word.end(70); break;
			case ':' : word.push(cur); word.end(71); break;
			case ',' : word.push(cur); word.end(74); break;
			case '{' : word.push(cur); word.end(77); break;
			case '}' : word.push(cur); word.end(78); break;
			case ';' : word.push(cur); word.end(83); break;
			case '#' : word.push(cur); word.end(84); break;
			case '\'' : word.push(cur); word.end(85); break;
			case '"' : word.push(cur); word.end(86); break;
			default : word.end(-1);
		}
	}
}

int main(){
	fin = fopen("source.txt","r");
	fout = fopen("prom.txt","w");
	if(fin == NULL || fout == NULL){
		printf("open file error\n");
		return 1;
	}
	do{
		scanner();
		if(word.syn != -1){//正常
			output();
		}else{
			 //错误则判断是否因到达文件尾结束
			if(fgetc(fin) != EOF){
				printf("error!! unknown char: %c\n",cur);
			}
			break;
		}
	}while(true);
	return 0;
}