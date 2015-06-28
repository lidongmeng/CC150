/*************************************************************************
	> File Name: 1.8.cpp
	> Author: lidongmeng
	> Mail: lidongmeng@ict.ac.cn 
	> Created Time: 2015年06月28日 星期日 08时52分27秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

bool isSubString (string s1, string s2)
{
    if (s1.find(s2) != string::npos)
        return true;
    else
        return false;
}

// determine if we can get s2 by rotating s1 
bool isRotation(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    else
        return isSubString(s1+s1, s2);
}

int main()
{
    string s1 = "ABCD";
    string s2 = "BCDA";
    cout << isRotation(s1, s2) << endl;
    return 0;
}
