/*
 �뿼��һ�����ո�ָ��ģ���1��N��������ɵĵ������У�1 2 3 ...N���������������в����ʾ�ӵġ�+�������߱�ʾ����-��������߱�ʾ�հ׵ġ� ��
 (����1-2 3�͵���1-23)������ÿһ��������ϳ�һ�����ʽ����һ������ǰ�޿ո񣩡�����ñ��ʽ�Ľ�����ж���ֵ�Ƿ�Ϊ0��
 ����дһ�������ҳ����в�����Ϊ��ĳ���ΪN�����С�
����
����Ϊһ�У�����һ������N��3��N��9��
���
���Ϊ������ÿ�����ּ���롰+��, ��-��, �� �� �����ܵõ���Ϊ������У��������ֵ䣨ASCII�룩�����С�  �ֵ����ȿո��ټӺ��ټ���
��������
7

�������
1+2-3+4-5-6+7
1+2-3-4+5+6-7
1-2 3+4+5+6+7
1-2 3-4 5+6 7
1-2+3+4-5+6-7
1-2-3-4-5+6+7
*/
#include<iostream>
using namespace std;
char s[20];
int n;

void dfs(int curPos, int preSum, int curValue) {  //��������Ϊ ��ǰλ�ã�������ǰλ�õĺ�  ��ǰλ�õ�ֵ
    //�ݹ����
    if (curPos == n) {
        if (preSum + curValue == 0) {
            cout << s << endl;
        }
        return;
    }
    //�� �������� " "
    s[curPos * 2 - 1] = ' ';
    if (curValue > 0) {
        dfs(curPos + 1, preSum, curValue * 10 + curPos + 1);  //��һ��������ֵ  λ����չ�ˣ�cuurPos + 1
    } else {
        dfs(curPos + 1, preSum, curValue * 10 - (curPos + 1)); //�����ǰλ��ֵΪ�������磺1-2 3-4 5+6 7  -2��3 ��Ϊ -23
    }
    s[curPos * 2 - 1] = '+';  //�������� +
    dfs(curPos + 1, preSum + curValue, curPos + 1);   // +����ͣ���һ������ֵ Ϊ curPos + 1
    s[curPos * 2 - 1] = '-';
    dfs(curPos + 1, preSum + curValue, -(curPos + 1)); //��������һ��ֵΪ -(curPos + 1)
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        s[i * 2] = i + '1';
    }
    dfs(1, 0, 1);
    return 0;
}

