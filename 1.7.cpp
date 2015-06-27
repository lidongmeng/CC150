/*************************************************************************
    > File Name: 1.7.cpp
	> Author: lidongmeng
	> Mail: lidongmeng@ict.ac.cn
	> Created Time: 2015年06月27日 星期六 10时15分38秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

void transferMatrix(int matrix[4][4])
{
    vector<int> row(4, 0);
    vector<int> col(4, 0);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if (row[i] || col[j])
                matrix[i][j] = 0;
       }
    }
}

int main()
{ 
    int matrix[4][4] = {
        {1,2,3,4},
        {0,1,2,4},
        {2,0,1,4},
        {5,6,7,8}
    };
    transferMatrix(matrix);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    return 0;
}
