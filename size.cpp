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


//数字转换为字符串
string int_string(int number)
{
    int value = abs(number);//取绝对值
    char str[100];
    //itoa_s(value, str, 10); //运用itoa()函数将int型整数转换为字符串 
    string str_= str;
    return str_;
}
//算式转换为字符串
string group(string str1, string str2, char m)  // group:算式组合
{
    string Equation;       // equation:算式
    Equation = str1 + m + str2;
    return Equation;
}
//生成运算符
char mark(int opt)
{
    int opt1, a;
    char symbol[1]; // 符号数组
    if (opt == 0)
    {
        opt1 = 2;
    }
    if (opt == 1)
    {
        opt1 = 4;
    }
    a = random() % opt1+1; //随机生成1-2或1-4的数，随opt的值而定，opt意为是否含有乘除法
    if (a == 1) symbol[0] = '+';
    if (a == 2) symbol[0] = '-';
    if (a == 3) symbol[0] = '*';
    if (a == 4) symbol[0] = '/';
    return symbol[0];
}
//主函数
void main()
{
    srand((int)time(NULL));     //设置时间种子，每次执行种子不同，生成不同的随机数
    int num1, num2,minus;
    int    opt, bracket, output, max, min, amount, control, b, c,d;
    string str_num1, str_num2, value; //数字-字符串
    cout << "是否需要包含乘除法？1(有)，0(没有)：" << endl;
    cin >> opt;    //opt:选择是否含有乘除法
    /*cout << "是否需要包含负数1（有），0（没有）：" << endl;
    cin >> minus; */
    cout << "是否含有括号？1（有），0（没有）：" << endl;
    cin >> bracket;
    cout << "题目是否要在文件中输出？1（是），0（不是）：" << endl;
    cin >> output;
    cout << "请输入数字范围：(格式为：最小数 空格 最大数)" << endl;
    cin >> max>>min;
    cout << "请输入出题数量：" << endl;
    cin >> amount;
    string equation[1000]; //定义数组
    char symbol;
    ofstream fout;
    /*if (opt == 1)
    {
        cout << "除法有无余数，1（有），0（无）" << endl;
            cin >> remainder;
    }*/
    if ( output == 1 )
    {
        fout.open("output.txt");
        fout << amount << "道四则运算题如下：" << endl;
    }
    else
    {
        cout << amount << "道四则运算题如下：" << endl;
    }
    for (int i = 0; i<amount; i++)  //为输出规定题数
    {
        num1 = random() % (max - min + 1) + min;// 随机生成min-max的整数
        num2 = random() % (max - min + 1) + min;// 随机生成min-max的整数
        control = random() % 9 + 2;  //控制是几个数的运算式，最多支持10个数的运算式
        symbol = mark(opt);
        /*if (minus == 0)      //本来要加负数的，思路有点不清晰，以后改进
        {
            str_num1 = int_string(num1);
            str_num2 = int_string(num2);
        }
        if (minus == 1)
        {
            d = random() % 2; //随机生成0-1的数
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
                    b = random() % 2; //随机生成0-2的数
                    if (b == 0)  //如果b=0，就在字符串str_num1的左右加上括号
                    {
                        str_num1 = '(' + str_num1 + ')';
                    }
                }
                symbol = mark(opt);
                num2 = random() % (max - min + 1) + min;// 随机生成min-max的整数
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
        //判断是否重复
        int repeat = 0; //repeat:重复 
        for (c = 0; c<i; c++)
        {
            if (equation[c] == equation[i])
            {
                i = i - 1;
                repeat = 1;
                break;
            }
        }
        if (repeat != 1)//若不重复，则输出 
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
    if (output == 1) //输出到文件
    {
        fout.close();
    }
}