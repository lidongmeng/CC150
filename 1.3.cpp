/*************************************************************************
	> File Name: 1.3.cpp
	> Author: lidongmeng
	> Mail: lidongmeng@ict.ac.cn 
	> Created Time: 2015年06月25日 星期四 22时25分46秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
// O(n2) O(1)
string removeDuplicate(string s)
{
   string result;
   int len = s.size();
   for (int i = 0; i < len; ++i)
    {
        if (s[i] != '\0')
        {
           result += s[i];
           for (int j = i + 1; j < len; ++j)
            {
                if (s[j] == s[i])
                    s[j] = '\0';
            }
        }
    }
    return result;
}
// O(n) O(n)
char * removeDuplicateII(char * s)
{
    if (s == NULL)
        return s;
    int len = strlen(s); 
    int index = 0;
    int hash_table[256];
    memset(hash_table, 0, sizeof(hash_table));
    for (int i = 0; i < len; ++i)
    {
        if (!hash_table[(int)s[i]])
        {
            s[index++] = s[i];
            hash_table[(int)s[i]] = 1;
        }
    }
    s[index] = '\0';
    return s;
}

int main()
{
    string s = "aabacddb"; 
    char str[] = "ababcdeg";
    cout << removeDuplicate(s) << endl;
    cout << removeDuplicateII(str) << endl;
    return 0;
}
