/*************************************************************************
	> File Name: 1.2.cpp
	> Author: lidongmeng
	> Mail: lidongmeng@ict.ac.cn
	> Created Time: 2015年06月25日 星期四 21时37分26秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

// first try use a temp to swap two char
void reverse(char * s)
{
    int len = strlen(s);
    for (int i = 0, j = len - 1; i <= j; ++i, --j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

// learn from github swap only use the two num 
void swap(char & a, char & b)
{
    a = a^b;
    b = a^b;
    a = a^b;
}

void reverseII(char * s)
{
    int len = strlen(s);
    for (int i = 0; i < len/2; ++i)
        swap(s[i], s[len-i-1]);
}

// use '\0' as the end of the string
// good one
void reverseIII(char * s)
{
    if (!s)
        return ;
     char * p = s;
     char * q = s;
    while (*q) ++q;
    --q;
    while (p < q)
    {
        swap(*p, *q);
        ++p, --q;
    }
}

int main()
{
    char s[] =  "abcde";
    reverse(s);
    cout << s << endl;
    reverseII(s);
    cout << s << endl;
    reverseIII(s);
    cout << s << endl;
    return 0;
}
