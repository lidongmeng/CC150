/*************************************************************************
	> File Name: 1.5.cpp
	> Author: lidongmeng
	> Mail: lidongmeng@ict.ac.cn 
	> Created Time: 2015年06月26日 星期五 20时30分27秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

char * replaceSpace(char * s)
{ 
    if (s == NULL)
        return s;
    int len = strlen(s);
    int cnt = 0;
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == ' ')
            ++cnt;
    }
    int length = len + 2*cnt;
    char * str = new char[length+1];
    int index = 0;
    for (int i = 0; i < len; ++i)
    {
        if (s[i] == ' ')
        {
            str[index++] = '%';
            str[index++] = '2';
            str[index++] = '0';
        }
        else
        {
            str[index++] =  s[i];
        }
    }
    str[index] = '\0';
    return str;
}

int main()
{
    char s[] = "Hello world I am Li dong meng!";
    cout << replaceSpace(s) << endl;
    return 0;
}
