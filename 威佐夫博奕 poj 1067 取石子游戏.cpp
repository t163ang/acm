//��������(Wythoff Game):
//�����Ѹ����ɸ���Ʒ,������������ĳһ�ѻ�ͬʱ��������ȡͬ�������Ʒ,�涨ÿ������ȡһ��,���߲���,���ȡ���ߵ�ʤ.
#include<iostream>
#include<cmath>
int a,b;
int main(){
	freopen("in.txt","r",stdin);
	double g =  (sqrt(5.0) + 1 ) / 2.0;
	while(~scanf("%d%d",&a,&b)){
		if(a > b) std::swap(a,b);
		int k = b - a;
		if(a == (int)(k * g)) printf("0\n");
		else printf("1\n");
	}
	return 0;
}
//
//#include<iostream>
//#include<cmath>
//#define g ((sqrt(5.0) + 1 ) / 2.0)
//#define ng ((sqrt(5.0) - 1) / 2.0)
//int main(){
//	freopen("in.txt","r",stdin);
//	int a,b;
//	while(~scanf("%d%d",&a,&b)){
//		if(a > b) std::swap(a,b);
//		int k = (int)(a * ng);
//		if(a == (int)(k * g) && b == a + k || a == (int)((k + 1) * g) && b == k + 1 + a) printf("0\n");
//		else printf("1\n");
//	}
//	return 0;
//}



//#include <iostream>
//#include <math.h>
//
//using namespace std;
//
//bool solve(const int &a, const int &b, const int &j)
//{
//    if (a == floor((double)(j * (sqrt(5.0)+1))/2.0) && a + j == b)
//        return true;
//    else
//        return false;
//}
//
//int main()
//{
//    int a, b;
//
//    while (cin >> a >> b){
//        if (a > b)
//            swap(a, b);
//        int j = floor((double)(a * (sqrt(5.0)-1))/2.0);
//    
//        if (solve(a, b, j) || solve(a, b, j+1))
//            cout << "0\n";
//        else
//            cout << "1\n";
//    }
//    return 0;
//}

//ȡʯ����Ϸ
//Time Limit: 1000MS		Memory Limit: 10000K
//Total Submissions: 19649		Accepted: 5988
//Description
//
//������ʯ�ӣ��������⣬���Բ�ͬ����Ϸ��ʼ������������ȡʯ�ӡ���Ϸ�涨��ÿ�������ֲ�ͬ��ȡ����һ�ǿ����������һ����ȡ��������ʯ�ӣ����ǿ�����������ͬʱȡ����ͬ������ʯ�ӡ�����ʯ��ȫ��ȡ����Ϊʤ�ߡ����ڸ�����ʼ������ʯ�ӵ���Ŀ������ֵ�����ȡ������˫������ȡ��õĲ��ԣ����������ʤ�߻��ǰ��ߡ�
//Input
//
//������������У���ʾ������ʯ�ӵĳ�ʼ���������ÿһ�а��������Ǹ�����a��b����ʾ����ʯ�ӵ���Ŀ��a��b��������1,000,000,000��
//Output
//
//�����ӦҲ�������У�ÿ�а���һ������1��0������������ʤ�ߣ���Ϊ1����֮����Ϊ0��
//Sample Input
//
//2 1
//8 4
//4 7
//Sample Output
//
//0
//1
//0