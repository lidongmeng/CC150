/*************************************************************************
	> File Name: 1.1.cpp
	> Author: lidongmeng
	> Mail: lidongmeng@ict.ac.cn 
	> Created Time: 2015年06月25日 星期四 21时02分51秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

bool isUnique(string s)
{
    int hash_table[256]; // should ask the scope of the char
    memset(hash_table, 0, sizeof(hash_table));
    for (int i = 0; i < s.size(); ++i)
    {
        if (++hash_table[(int)s[i]] > 1)
            return false;
    }
    return true;
}

bool isUniqueII(string s)
{
    int hash_table[8];
    memset(hash_table, 0, sizeof(hash_table));
    for (int i = 0; i < s.size(); ++i)
    {
        int temp = (int)s[i];
        int index = temp/32, shift = temp%32;
        if (hash_table[index] & (1 << shift))
           return false;
        hash_table[index] |= (1 << shift);
        for (int i = 0; i < 8; ++i)
            cout << hash_table[i] << " " ;
        cout << endl;
    }
    return true;
}

int main()
{
    string s1 = "";
    string s2 = "abcde";
    string s3 = "abca";
    cout << isUnique(s1) << "  " << isUnique(s2) << " " << isUnique(s3) << endl;
    cout << isUniqueII(s3) << endl;
    return 0;
}
