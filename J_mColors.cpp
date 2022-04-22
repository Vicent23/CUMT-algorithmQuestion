/*
����������ͨͼG��m�ֲ�ͬ����ɫ������Щ��ɫ��ͼ�ĸ���������һ����ɫ����ĳ�ַ���ʹ��ͼ��ÿ���ߵ�2���������ɫ������ͬ������һ������ķ�����
�ҳ����еķ�����
����
��һ����3��������n��k��m���ֱ��ʾn�����㣬k���ߣ�m����ɫ
������k�У�ÿ��2������������ʾһ���ߵ���������
���
���в�ͬ����ɫ������
��������
5 8 4 
1 2
1 3 
1 4
2 3
2 4
2 5
3 4
4 5

�������
48
*/
#include<iostream>
using namespace std;
class Color
{
	friend void mcoloring(int n, int m, int** a);  //��Ԫ����
private:
	bool isUsed(int t);  //�жϸõ��ܷ��һ����ɫ
	void Backtrack(int i);
	int n; //������
	int m; //��ɫ��
	int** a; //�ڽӾ���
	int* x; //��ǰ��    x[i] ��ʾ �� i ����ɫ
	long sum; //������
};

//Լ���������ж϶��� t �����ڶ����Ƿ������ͬ����ɫ  ������ھͷ���false
bool Color::isUsed(int t)  
{
	for (int i = 1; i < t; i++)
		if (a[i][t] == 1 && x[i] == x[t])   //���������ֱ���������� ��ɫ��ͬ �򷵻�false
			return false;
	return true;
}

//�ؼ���������DFS�Ӽ�֦
void Color::Backtrack(int i)
{
	if (i > n)
	{
		sum++;  //��������  �ܷ�����++
	}
	else
	{
		for (int j = 1; j <= m; j++)
		{
			x[i] = j;  //���Ը��� i �� ������ɫ j
			if (isUsed(i))   // ���Ը���ɫ
				Backtrack(i + 1);
			x[i] = 0;  //���ݣ�������ɫ
		}
	}
}

//ͼ��m��ɫ��  �����ú���
void mcoloring(int n, int m, int **a)
{
	Color X;
	X.n = n;
	X.m = m;
	X.a = a;
	X.sum = 0;
	int* p = new int[n+1];
	for (int i = 1; i <= n; i++)
		p[i] = 0;  //��ʼ������
	X.x = p;  // X.x ��ŵ������ս�Ľṹ
	X.Backtrack(1);  //�ӵ�1��Ԫ�ؿ�ʼ���ݣ�  �����Ԫ��Ҳ�Ǵ�1��ʼ��
	delete[]p;
	cout << X.sum;
}

int main()
{
	int n, k, m;
	cin >> n >> k >> m;
	int k1, k2;
	int** a = new int* [n+1];
	for (int i = 1; i <= n; i++)
		a[i] = new int[n + 1];
	for (int i = 1; i <= k; i++)
	{
		cin >> k1 >> k2;
		a[k1][k2] = 1;
	}
	mcoloring(n, m, a);
	return 0;
}
