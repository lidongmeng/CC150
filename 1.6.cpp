/*************************************************************************
	> File Name: 1.6.cpp
	> Author: lidongmeng
	> Mail: lidongmeng@ict.ac.cn 
	> Created Time: 2015年06月27日 星期六 11时05分16秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

void output(int (*matrix)[4])
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

void roatedImage(int (*matrix)[4])
{
    int n = 4;
    // roated by second diagonal
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n-i-1; ++j)
        {
            swap(matrix[i][j], matrix[n-j-1][n-i-1]);
        }
    }
    output(matrix);
    // roated by the mid of the vetical
    for (int i = 0; i < n/2; ++i)
    {
        for (int j = 0; j < n; ++j)
            swap(matrix[i][j], matrix[n-i-1][j]);
    }
    output(matrix);
}


int main()
{
    int matrix[4][4] = 
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    roatedImage(matrix);
}
