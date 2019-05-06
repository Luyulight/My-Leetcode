#include <iostream>
#include <algorithm>
using namespace std;
void QuickSort1(int s[], int l, int r) //���ص�����Ҫ���п�������������±귶Χ 
{
	if(l>=r)//��Ҫ���������鳤��С�ڵ���1��ʱ�򷵻� 
		return;
    int i = l, j = r;
    int x = s[l]; //s[l]��s[i]���ǵ�һ����
    while (i < j)
    {
        // ����������С��x��������s[i]
       while(i < j && s[j] >= x)
            j--;
        if(i < j)
        {
            s[i] = s[j]; //��s[j]�s[i]�У�s[j]���γ���һ���µĿ�
            i++;
        }
        // ���������Ҵ��ڻ����x��������s[j]
        while(i < j && s[i] < x)
            i++;
        if(i < j)
        {
            s[j] = s[i]; //��s[i]�s[j]�У�s[i]���γ���һ���µĿ�
            j--;
        }
    }
    //�˳�ʱ��i����j����x�������С�
    s[i] = x;
    QuickSort1(s, l, i - 1); // �ݹ���ã����ð���pivot
	QuickSort1(s, i + 1, r);	
}

void QuickSort2(int s[],int l,int r)//�α��ϵĿ�������
{
	if(l>=r)
		return;
	swap(s[l],s[(l+r)/2]);//�������м䲿�ֵ�Ԫ�ػ�����ͷ����Ϊpivot,�����������ֳɴ�С�ӽ������� 
	int pivot=s[l]; //ѡȡ��һ��Ԫ��Ϊ֧�� 
	int first_less=l;
	for(int i=l+1;i<=r;i++)
	{
		if(s[i]<pivot)
		{
			swap(s[i],s[++first_less]);
		}
	}
	swap(s[first_less],s[l]);//��pivot�����һ���ϸ�С������ֵ��λ���������С�������ұߴ��ڵ�����
	QuickSort2(s,l,first_less-1);
	QuickSort2(s,first_less+1,r);
}

int main()
{
	int s[]= {43,16,27,59,50,26,31,48,62,36,13,50,15,27,15,37,37,16,37,21,22,19,41,27,8,25,65,59,60,1,51,18,52,57,65,3,39,51,44,49,59,34,8,64,38,60,45,48,42};
	QuickSort2(s,0,sizeof(s)/sizeof(int)-1);
	for(int i=0;i<sizeof(s)/sizeof(int);i++)
	{
		cout<<s[i]<<" ";
	}
 } 
