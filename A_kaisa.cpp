/*
���磬��ƫ����������3��ʱ��
������ĸ��ABCDEFGHIJKLMNOPQRSTUVWXYZ
������ĸ��DEFGHIJKLMNOPQRSTUVWXYZABC
ʹ��ʱ�������߲���������ĸ������Ҫ���ܵ���Ϣ�е�ÿһ����ĸ����λ�ã�����д��������ĸ���ж�Ӧ����ĸ��
��Ҫ���ܵ��������������֪����Կ�������������õ�ԭ�������ġ����磺
���ģ�THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG
���ģ�WKH TXLFN EURZQ IRA MXPSV RYHU WKH ODCB GRJ
���ڸ�����һ���ַ���S�����Ȳ��ᳬ��1000000����һ������k��-1000000000<=k<=1000000000����
�ֱ����������յ������ĺ��ڼ��ܸ�����ʱ����ƫ��������������Ǽ����ԭ��������
ע�⣺ֻ����ĸ�ڼ���ʱ�Żᷢ��ƫ�ƣ������ַ����ֲ���
����
��������������ݣ����е�һ��Ϊ��������T��T<=10��
ÿ�����ݵ�һ��Ϊһ���ַ���S�������֡���ĸ�Լ������ַ���ɣ������ո񣩣�
�ڶ���Ϊһ������k�������ʱ����ƫ������|S|<=1000000,-1000000000<=k<=1000000000��
���
��ÿ�����ݣ����һ���ַ��������������е����Ķ�Ӧ�����ġ�
��������
1
DEFGHIJKLMNOPQRSTUVWXYZABC
3
�������
ABCDEFGHIJKLMNOPQRSTUVWXYZ
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string h;
        cin >> h;
        int k;
        cin >> k;
        int s = k % 26;
        for (int i = 0; i < h.length(); i++)
        {
            if (h[i] >= 'A' && h[i] <= 'Z')
            {
                int x = h[i] - 'A';
                h[i] = 'A' + (x - s + 26) % 26;
            }
            else if (h[i] >= 'a' && h[i] <= 'z')
            {
                int x = h[i] - 'a';
                h[i] = 'a' + (x - s + 26) % 26;
            }
        }
        for (int i = 0; i < h.length(); i++)
            cout << h[i];
        cout << endl;
    }
}
