/*************************************************************************
	> File Name: 1.4.cpp
	> Author: lidongmeng
	> Mail: lidongmeng@ict.ac.cn 
	> Created Time: 2015年06月26日 星期五 20时06分27秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
// 变位词(anagrams)指的是组成两个单词的字符相同，但位置不同的单词
bool isAnagrams(string s1, string s2)
{
    if (s1 == "" && s2 == "")
        return false;
    int s1_hash_table[256];
    int s2_hash_table[256];
    memset(s1_hash_table, 0, sizeof(s1_hash_table));
    memset(s2_hash_table, 0, sizeof(s2_hash_table));
    int len1 = s1.size();
    int len2 = s2.size();
    if (len1 != len2)
        return false;
    for (int i = 0; i < len1; ++i)
    {
        s1_hash_table[s1[i]]++;
        s2_hash_table[s2[i]]++;
    }
    for (int i = 0; i < 256; ++i)
    {
        if (s1_hash_table[i] != s2_hash_table[i])
            return false;
    }
    return true;
}

bool isAnagramsII(string s1, string s2)
{
    if (s1.size() != s2.size() || s1 == "" && s2 == "")
        return false;
    int len = s1.size();
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for (int i = 0; i < len; ++i)
    {
        if (s1[i] != s2[i])
            return false;
    }
    return true;
}

// improve using only one hash_table
bool isAnagramsIII(string s1, string s2)
{
    if (s1 == "" && s2 == "" || s1.size() != s2.size())
        return false;
    int len = s1.size();
    int hash_table[256];
    memset(hash_table, 0, sizeof(hash_table));
    for (int i = 0; i < len; ++i)
    {
        hash_table[s1[i]]++;
        hash_table[s2[i]]--;
    }
    for (int i = 0; i < 256; ++i)
    {
        if (hash_table[i])
            return false;
    }
    return true;
}

int main()
{
    string s1 = "abcdabcd";
    string s2 = "badcbadc";
    string s3 = "";
    string s4 = "";
    cout << s3.size() << endl;
    cout << isAnagrams(s1, s2) << endl;
    cout << isAnagramsII(s3, s4) << endl;
    cout << isAnagramsII(s1, s2) << endl;
    cout << isAnagramsIII(s1, s2) << " " << isAnagramsIII(s3, s4) << endl;
    return 0;
}
