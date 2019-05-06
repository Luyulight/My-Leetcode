#include <iostream>
#include <cmath>
using namespace std;
#define left(x) 2*x+1
#define right(x) 2*x+2//��Ϊ�����±��Ǵ�0��ʼ�ģ����Զ�Ӧÿ������Ҷ�ڵ�x,�������ҽڵ�ֱ�Ϊ2x+1 2x+2
void MaxHeap(int *a,int i,int high)//����ĳ���ڵ��������� 
//aΪҪ�������飬iΪҪ����Ľڵ㣬highΪ����Ҫ��ά��������±� 
{
	int l=left(i);
	int r= right(i);
	int largest;//���߽ϴ�ڵ��±� 
	int temp;
	//�ҳ�r l �� iλ�õĽڵ�ֵ�����ֵ ����iλ�ý��� 
	if(l<=high && a[l]>a[i])
		largest=l; 
	else  
		largest = i;
	if(r<=high&&a[r]>a[largest])
		largest=r;
	if(largest!=i)//�� ����ֵ����λ�� i ���� l��r��������ʱ largest=i,��ʱ���������������ء� 
	{
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		MaxHeap(a,largest,high);
	}
	
 } 
void buildMaxHeap(int *a,int length)//�����齨����һ������ 
{
 	for(int i=length/2-1;i>=0;i--)
	{
		MaxHeap(a,i,length-1);
	} 
}
void HeapSort(int *a,int length)
{
	int temp;
	buildMaxHeap(a,length);
	for(int i=length-1;i>=1;i--)
	{
		// for(int i=0;i<5;i++)
		// {
		// 	cout<<a[i]<<" ";
		// }
		// cout<<endl;
		temp=a[i];//���������һ��Ԫ�ؽ���λ��	 
		a[i]=a[0];
		a[0]=temp;
		MaxHeap(a,0,i-1);
	}
}
int main()
{
	int a[]={4,6,8,5,9}; 
	HeapSort(a,5);
	for(int i=0;i<5;i++)
	{
		cout<<a[i]<<endl;
	}
 } 
