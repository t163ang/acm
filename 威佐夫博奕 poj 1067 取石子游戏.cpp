//威佐夫博奕(Wythoff Game):
//有两堆各若干个物品,两个人轮流从某一堆或同时从两堆中取同样多的物品,规定每次至少取一个,多者不限,最后取光者得胜.
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

//取石子游戏
//Time Limit: 1000MS		Memory Limit: 10000K
//Total Submissions: 19649		Accepted: 5988
//Description
//
//有两堆石子，数量任意，可以不同。游戏开始由两个人轮流取石子。游戏规定，每次有两种不同的取法，一是可以在任意的一堆中取走任意多的石子；二是可以在两堆中同时取走相同数量的石子。最后把石子全部取完者为胜者。现在给出初始的两堆石子的数目，如果轮到你先取，假设双方都采取最好的策略，问最后你是胜者还是败者。
//Input
//
//输入包含若干行，表示若干种石子的初始情况，其中每一行包含两个非负整数a和b，表示两堆石子的数目，a和b都不大于1,000,000,000。
//Output
//
//输出对应也有若干行，每行包含一个数字1或0，如果最后你是胜者，则为1，反之，则为0。
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