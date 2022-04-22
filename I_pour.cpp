/*
 ���Բ�ʿ�����������ֱ��� A,B,C �����Թܣ�A,B,C�ֱ��������� 1�� 20�������������A �� B �Թܶ��ǿյģ��� C �Թ���װ������ͭ��Һ�ġ���
 ʱ�����Բ�ʿ������ͭ��Һ��һ���Թܵ�����һ���Թ��У�ֱ�������Թ�װ����ԭ�Թܿ��ˡ���Ȼÿһ�ι�ע������ȫ�ġ�
 �������Բ�ʿ������ô���ڣ�������������Һ�ڵ��Ĺ����в����ж�ʧ��
дһ������ȥ�������Բ�ʿ�ҳ��� A �Թ��ǿյ�ʱ��C �Թ�������ͭ��Һ��ʣ�������п����ԡ�
����
�����������������ÿ������������������һ�У�Ϊ�ո�ָ��������������ֱ�Ϊ���� A,B,C��
���
�������һ�У�������г��� A �Թ��ǿյ�ʱ��C �Թ���Һ��ʣ�������п����ԡ�
��������
2 5 10

�������
5 6 7 8 9 10
*/
/*#include <iostream>
#include <math.h>
#include <stdio.h>
#include <cstring>
using namespace std;

int A, B, C;
// res[a][b] �洢A B��Һ��Ϊa b������Ƿ������
int res[21][21];

//���� ����
//����ΪA B C �Թܵ�Һ������
void backtrace(int a, int b, int c)
{
    res[a][b] = 1;  //���Ϊ�ѱ�����
    int a0 = a, b0 = b, c0 = c;
    if (a < A)
    { // Aδ��
        if (b > 0)
        { // B -> A
            if (b >= A - a)
            { // A����
                b = b - A + a;
                a = A;
            }
            else
            { // B����
                a += b;
                b = 0;
            }
            if (res[a][b] == 0)  //�����ǰ����� û�б���������
                backtrace(a, b, c);
            // ����
            a = a0;
            b = b0;
        }
        if (c > 0)
        { // C -> A
            if (c >= A - a)
            { // A����
                c = c - A + a;
                a = A;
            }
            else
            { // C����
                a += c;
                c = 0;
            }
            if (res[a][b] == 0)
                backtrace(a, b, c);
            a = a0;
            c = c0;
        }
    }
    if (b < B)
    { // Bδ��
        if (a > 0)
        { // A -> B
            if (a >= B - b)
            { // B����
                a = a - B + b;
                b = B;
            }
            else
            { // A����
                b += a;
                a = 0;
            }
            if (res[a][b] == 0)
                backtrace(a, b, c);
            a = a0;
            b = b0;
        }
        if (c > 0)
        { // C -> B
            if (c >= B - b)
            { // B����
                c = c - B + b;
                b = B;
            }
            else
            { // C����
                b += c;
                c = 0;
            }
            if (res[a][b] == 0)
                backtrace(a, b, c);
            b = b0;
            c = c0;
        }
    }
    if (c < C)
    { // Cδ��
        if (a > 0)
        { // A -> C
            if (a >= C - c)
            { // C����
                a = a - C + c;
                c = C;
            }
            else
            { // A����
                c += a;
                a = 0;
            }
            if (res[a][b] == 0)
                backtrace(a, b, c);
            a = a0;
            c = c0;
        }
        if (b > 0)
        { // B -> C
            if (b >= C - c)
            { // C����
                b = b - C + c;
                c = C;
            }
            else
            { // B����
                c += b;
                b = 0;
            }
            if (res[a][b] == 0)
                backtrace(a, b, c);
            b = b0;
            c = c0;
        }
    }
}

int main()
{

    while (~scanf("%d %d %d", &A, &B, &C))
    {
        memset(res,0,sizeof(res));   //�����ԭ�����ڣ�ѭ������ʱû�н� �Ѿ���ֵ����res��������
        backtrace(0, 0, C);
        for (int i = B; i >= 0; i--)
        {
            // cout << res[0][i] << " ";
            if (res[0][i] == 1) //���ܵ����
            {
                cout << C - i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int A, B, C;
int dp[30][30][30];
vector<int> ans;

void solve(int a, int b, int c)
{
    if (dp[a][b][c])
        return; //������ʹ��ͷ���
    dp[a][b][c] = 1;
    if (a == 0)
        ans.push_back(c); //���A�Թ�Ϊ��

    if (a <= B - b)
        solve(0, a + b, c); // a����ȫ������B�� a����
    else
        solve(a + b - B, B, c); //  a �� b ����

    if (b <= A - a)
        solve(a + b, 0, c); // b�� a ����
    else
        solve(A, a + b - A, c); // b��a ����

    if (a <= C - c)
        solve(0, b, a + c); // a �� c ����
    else
        solve(a + c - C, b, C); // a �� c ����

    if (c <= A - a)
        solve(a + c, b, 0); // c �� a ����
    else
        solve(A, b, a + c - A); // c �� a����

    if (b <= C - c)
        solve(a, 0, b + c); // b �� c����
    else
        solve(a, b + c - C, C); // b �� c ����

    if (c <= B - b)
        solve(a, b + c, 0); // c �� b����
    else
        solve(a, B, b + c - B); // c �� b����
}

int main()
{
    while (scanf("%d%d%d", &A, &B, &C) == 3)
    {
        memset(dp, 0, sizeof(dp));
        ans.clear();
        solve(0, 0, C);
        sort(ans.begin(), ans.end());
        int len = ans.size();
        for (int i = 0; i < len; i++)
            //printf("%d%c", ans[i], i + 1 == len ? '\n' : ' '); //���һ��Ԫ�����뻻��
            printf("%d%c", ans[i],' ');
        printf("\n");
    }
    return 0;
}