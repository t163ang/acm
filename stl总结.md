<HTML>
<HEAD>
<META NAME="GENERATOR" Content="Microsoft Visual Studio 8.0">
<TITLE>stl</TITLE>
</HEAD>
<BODY>
<textarea cols=120 rows=50>
1��stack

����stack�����ʾ���������£�
stack<int> s1;
stack<string> s2;

stack�Ļ��������У�
��ջ��s.push(x);
��ջ��s.pop();
����ջ����s.top();
�ж�ջ�գ�s.empty();
����ջ�е�Ԫ�ظ�����s.size();


2��queue

����queue�����ʾ���������£�
queue<int> q1;
queue<double> q2;

queue�Ļ��������У�
��ӣ�q.push(x);
���ӣ�q.pop(); 
���ʶ���Ԫ�أ�q.front();
���ʶ�βԪ�أ�q.back();
�ж϶��пգ�q.empty();
���ʶ����е�Ԫ�ظ�����q.size();


3�����ȶ���

��һ�ַ���:
priority_queue<int>
Ĭ�ϴӴ�С������: 9  5 1 

�ڶ��ַ�������С����:
priority_queue<int,vector<int>,greater<int>>

�����ַ������Զ������ȼ�:
struct node
{
    friend bool operator< (node n1, node n2)
    {
        return n1.priority < n2.priority;
    }
    int priority;
    int value;
};
���÷�����top() pop() push()


4��qsort

void qsort ( void * base, size_t num, size_t size, int ( * comparator ) ( const void *, const void * ) );

/* qsort example */
#include <stdio.h>
#include <stdlib.h>

int values[] = { 40, 10, 100, 90, 20, 25 };

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main ()
{
  int n;
  qsort (values, 6, sizeof(int), compare);
  for (n=0; n<6; n++)
     printf ("%d ",values[n]);
  return 0;
}

5��next_permutaition

bool next_permutation (BidirectionalIterator first,
                         BidirectionalIterator last );

// next_permutation
#include <iostream>
#include <algorithm>
using namespace std;

int main () {
  int myints[] = {1,2,3};

  cout << "The 3! possible permutations with 3 elements:\n";

  sort (myints,myints+3);

  do {
    cout << myints[0] << " " << myints[1] << " " << myints[2] << endl;
  } while ( next_permutation (myints,myints+3) );

  return 0;
}

6��nth_element
STL�е�nth_element()������ʹ�� ͨ������nth_element(start, start+n, end) ��������ʹ��n��Ԫ�ش��ڵ�nλ�ã���0��ʼ,��λ�����±�Ϊ n��Ԫ�أ���
���ұ����Ԫ��С��Ԫ�ض��������Ԫ��֮ǰ�������Ԫ�ش��Ԫ�ض��������Ԫ��֮�󣬵����ܱ�֤����������ģ���������������ľ���ʹ�÷���.

void nth_element ( RandomAccessIterator first, RandomAccessIterator nth,
                     RandomAccessIterator last );
// nth_element example
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool myfunction (int i,int j) { return (i<j); }

int main () {
  vector<int> myvector;
  vector<int>::iterator it;

  // set some values:
  for (int i=1; i<10; i++) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9

  random_shuffle (myvector.begin(), myvector.end());

  // using default comparison (operator <):
  nth_element (myvector.begin(), myvector.begin()+5, myvector.end());

  // using function as comp
  nth_element (myvector.begin(), myvector.begin()+5, myvector.end(),myfunction);

  // print out content:
  cout << "myvector contains:";
  for (it=myvector.begin(); it!=myvector.end(); ++it)
    cout << " " << *it;

  cout << endl;

  return 0;
}

5��fill
void fill ( ForwardIterator first, ForwardIterator last, const T& value );

vector<int> myvector (8);// myvector: 0 0 0 0 0 0 0 0
  fill (myvector.begin(),myvector.begin()+4,5);   
  // myvector: 5 5 5 5 0 0 0 0
  fill (myvector.begin()+3,myvector.end()-2,8);   
  // myvector: 5 5 5 8 8 8 0 0

</textarea>
</BODY>
</HTML>
