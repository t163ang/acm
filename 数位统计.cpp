#include<iostream>
using namespace std;
int f[50][50];
int X,Y,K,B;
void init(){
	//ͳ��һ�ø߶�Ϊi����ȫ�������ڶ����Ʊ�ʾ��ǡ�ú���j��1�����ĸ���
	//+++++++ע�⵱j = 0ʱ f[i][0] = 1û��1�ĸ�����1
	int i,j;
	f[0][0] = 1;
	for(i = 1; i <= 31; i++){
		f[i][0] = 1;
		for(j = 1; j <= i; j++) f[i][j] = f[i - 1][j] + f[i -1][j - 1];
	}
}


int solve(int x, int b){
	//��b���Ƶ���Ϊ�����ƣ���Ϊ��������>>��1ʱ����b^i ����<<��###��λͳ�ƣ�ͳ�Ƶľ���ÿһ��λ�Ƿ���ڰɣ�������#####
	int s[40], i = 0;
	int ans = 0;
	while(x > 0) s[i++] = x % b, x /= b;
	for(i--;i >= 0;i-- ){ 
		if(s[i] > 1){
			ans--;
			ans += 1 << (i + 1);
			break;
		}
		ans+=s[i]*(1<<i);
	} 
	return ans;
} 

//int change(int x, int b){
//	int s[40], i = 0;
//	while(x > 0) s[i++] =  x % b, x /= b;
//	int ans = 0;
//	for(--i; i > -1; i--){
//		if(s[i] > 1){
//			ans--;
//			ans |= 1 << (i + 1);
//			break;
//		}
//		ans |= (1 & s[i])<< i;
//	}
//	return ans;
//}

//int change(int x,int b)
//{
//	string s;
//	do {
//		s=char('0'+x%b)+s;
//		x/=b;
//	} while (x>0);
//	for (int i=0;i<s.size();++i)
//		if (s[i]>'1') {
//			for (int j=i;j<s.size();++j) s[j]='1';
//			break;
//		}
//	x=0;
//	for (int i=0;i<s.size();++i)
//		x=x|((s[s.size()-i-1]-'0')<<i);
//	return x;
//}

int calc(int x, int k){
	int tot = 0, ans = 0;//tot��ǰ
	x = solve(x,B);
	for(int i = 31; i >= 0; i--){
		if(x & (1 << i)){
			////����Ҷ��һ���У���Ϊtot�����˵ľ���x��λ������x�����ֵ�Ҷ��Ϊf[0][j > 0]��Ϊ0
			ans += f[i][k - tot];
			tot++;
			//����Ҷ��һ��һ�У���Ϊtot�����˵ľ���x��λ������ansҲҪ��1 
			if(tot == k) { ans++; break;}
		}
	}
	return ans;
} 
int main(){
	//freopen("in.txt","r",stdin);
	init();
	while(EOF!=scanf("%d %d %d %d",&X,&Y,&K,&B)){
		printf("%d\n",calc(Y,K)-calc(X-1,K));
	}
	return 0;
}

//���ԵĲ���������15�����ȼ������£�
//() [] -> .                                                                                         left to right
//! ~ ++ -- +�����ţ� -�����ţ� *��ָ��ȡֵ���� (type) sizeof      right to left
//* / %                                                                                         left to right
//+ -                                                                                            left to right
//<<   >>                                                                                     left to right
//< <= >   >=                                                                              left to right
//== !=                                                                                        left to right
//&                                                                                              left to right
//^                                                                                                left to right
//|                                                                                                left to right
//&&                                                                                           left to right
//||                                                                                               left to right
//?:                                                                                             right to left
//= += -=   *= /=   %=   &=   ^=   |=   <<=   >>=                             right to left
//,                                                                                                left to right
//
//����ھ�
//
//���ų�Ա��һ;                                     //���������[]() ��Ա�����. ->
//ȫ�嵥Ŀ�ڶ�;                                   //���еĵ�Ŀ���������++ -- +(��) -(��) ָ������*&
//�˳�����,�Ӽ���;                             //���"��"��ָȡ�����㼴%
//��λ�壬��ϵ��;                           //��λ�������<< >> ����ϵ��> < >= <= ��
//����(��)�����ŵ���;                   //��== !=
//λ������λ��;                        //�⼸������λ����: λ��(&)���(^)λ��(|) 
//"��������"�˾�ʮ; 
//�߼������;                             //�߼������:|| �� &&
//ʮ����ʮһ;                           //ע��˳��:���ȼ�(||) ���� ���ȼ�(&&) 
//�������ڸ�ֵ,                       //��Ŀ��������ȼ��ŵ� 13 λֻ�ȸ�ֵ�������","��
//�������㼶���!                 //������������ȼ����          