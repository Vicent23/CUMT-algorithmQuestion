/*
Vigen��re �����ڲ���ʱ��Ҫע�⣺
������Բ����������ĸ�Ĵ�Сд����������ĸ������ MM �еĴ�Сд��ʽ��
������ M�ĳ��ȴ�����Կ k�ĳ���ʱ������Կ k�ظ�ʹ�á� ���磬���� M=Helloworld����Կ k=abcʱ������ C=Hfnlpyosnd��
����
��һ��Ϊһ���ַ�������ʾ��Կ k�����Ȳ����� 100100�����н�������Сд��ĸ��
�ڶ���Ϊһ���ַ�������ʾ�����ܺ�����ģ����Ȳ����� 10001000�����н�������Сд��ĸ��
���
����� 11 �У�һ���ַ�������ʾ������Կ����������Ӧ�����ġ�
��������
CompleteVictory
Yvqgpxaimmklongnzfwpvxmniytm

�������
Wherethereisawillthereisaway            ���ִ�Сд

N=(M+K)mod(26)        NΪ���ģ�MΪ���ģ�KΪ��Կ
M=(N-K)mod(26)
*/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	string h;
	cin >> h;
	for (int i = 0; i < h.length(); i++)
	{
		if (h[i] >= 'a' && h[i] <= 'z')
			h[i] = h[i] - 32;   //ת��Ϊ��д   ��ΪVigenere��������Ӧ�Ķ��Ǵ�д   CompleteVictory  ����Ϊ 15
	}
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			int x = s[i] - 'a';  //���Բ����������ĸ�Ĵ�Сд ��Ҫ������ĸ�����ĵĴ�д��ʽ  Yvqgpxaimmklongnzfwpvxmniytm  ����28
			int y = h[i % h.length()] - 'A';
			s[i] = 'a' + (x - y + 26) % 26;
		}
		else if (s[i] >= 'A' && s[i] <= 'Z')
		{
			int x = s[i] - 'A';   //x=Y - A = 25  ��Ӧ����
			int y = h[i % h.length()] - 'A';  // 0%15 = 0  h[0]=C  y=C-A=2
			s[i] = 'A' + (x-y+26) % 26;   // (25-2+26)%26=23    23 + A = W
		}
	}
	for (int i = 0; i < s.length(); i++)
		cout << s[i];
	cout << endl;
}

