#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
#include <fstream>
#include <string>
#define random()(rand()%1000)
using namespace std;


//����ת��Ϊ�ַ���
string int_string(int number)
{
    int value = abs(number);//ȡ����ֵ
    char str[100];
    //itoa_s(value, str, 10); //����itoa()������int������ת��Ϊ�ַ��� 
    string str_= str;
    return str_;
}
//��ʽת��Ϊ�ַ���
string group(string str1, string str2, char m)  // group:��ʽ���
{
    string Equation;       // equation:��ʽ
    Equation = str1 + m + str2;
    return Equation;
}
//���������
char mark(int opt)
{
    int opt1, a;
    char symbol[1]; // ��������
    if (opt == 0)
    {
        opt1 = 2;
    }
    if (opt == 1)
    {
        opt1 = 4;
    }
    a = random() % opt1+1; //�������1-2��1-4��������opt��ֵ������opt��Ϊ�Ƿ��г˳���
    if (a == 1) symbol[0] = '+';
    if (a == 2) symbol[0] = '-';
    if (a == 3) symbol[0] = '*';
    if (a == 4) symbol[0] = '/';
    return symbol[0];
}
//������
void main()
{
    srand((int)time(NULL));     //����ʱ�����ӣ�ÿ��ִ�����Ӳ�ͬ�����ɲ�ͬ�������
    int num1, num2,minus;
    int    opt, bracket, output, max, min, amount, control, b, c,d;
    string str_num1, str_num2, value; //����-�ַ���
    cout << "�Ƿ���Ҫ�����˳�����1(��)��0(û��)��" << endl;
    cin >> opt;    //opt:ѡ���Ƿ��г˳���
    /*cout << "�Ƿ���Ҫ��������1���У���0��û�У���" << endl;
    cin >> minus; */
    cout << "�Ƿ������ţ�1���У���0��û�У���" << endl;
    cin >> bracket;
    cout << "��Ŀ�Ƿ�Ҫ���ļ��������1���ǣ���0�����ǣ���" << endl;
    cin >> output;
    cout << "���������ַ�Χ��(��ʽΪ����С�� �ո� �����)" << endl;
    cin >> max>>min;
    cout << "���������������" << endl;
    cin >> amount;
    string equation[1000]; //��������
    char symbol;
    ofstream fout;
    /*if (opt == 1)
    {
        cout << "��������������1���У���0���ޣ�" << endl;
            cin >> remainder;
    }*/
    if ( output == 1 )
    {
        fout.open("output.txt");
        fout << amount << "���������������£�" << endl;
    }
    else
    {
        cout << amount << "���������������£�" << endl;
    }
    for (int i = 0; i<amount; i++)  //Ϊ����涨����
    {
        num1 = random() % (max - min + 1) + min;// �������min-max������
        num2 = random() % (max - min + 1) + min;// �������min-max������
        control = random() % 9 + 2;  //�����Ǽ�����������ʽ�����֧��10����������ʽ
        symbol = mark(opt);
        /*if (minus == 0)      //����Ҫ�Ӹ����ģ�˼·�е㲻�������Ժ�Ľ�
        {
            str_num1 = int_string(num1);
            str_num2 = int_string(num2);
        }
        if (minus == 1)
        {
            d = random() % 2; //�������0-1����
            if (d == 0)
            {
                str_num1 = int_string(num1);
                str_num2 = '-' + str_num2;
            }
        }*/
        str_num1 = int_string(num1);
        str_num2 = int_string(num2);
        equation[i] = group(str_num1, str_num2, symbol);
        if (control >= 2)
        {
            for (; control >= 2; control--)
            {
                symbol = mark(opt);
                str_num1 = equation[i];
                if (bracket == 1)
                {
                    b = random() % 2; //�������0-2����
                    if (b == 0)  //���b=0�������ַ���str_num1�����Ҽ�������
                    {
                        str_num1 = '(' + str_num1 + ')';
                    }
                }
                symbol = mark(opt);
                num2 = random() % (max - min + 1) + min;// �������min-max������
                str_num2 = int_string(num2);
                b = random() % 2;
                if (b == 0)
                {
                    value = str_num1;
                    str_num1 = str_num2;
                    str_num2 = value;
                }
                equation[i] = group(str_num1, str_num2, symbol);
            }
        }
        //�ж��Ƿ��ظ�
        int repeat = 0; //repeat:�ظ� 
        for (c = 0; c<i; c++)
        {
            if (equation[c] == equation[i])
            {
                i = i - 1;
                repeat = 1;
                break;
            }
        }
        if (repeat != 1)//�����ظ�������� 
        {
            if (output == 1)
            {
                fout << equation[i] << "=" << endl;
            }
            else
            {
                cout << equation[i] << "=" << endl;
            }
        }

    }
    if (output == 1) //������ļ�
    {
        fout.close();
    }
}