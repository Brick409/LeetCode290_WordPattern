// WordPattern.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

class MySolution
{
public:
    //判断字符串src中包含的单词模式，是否和pattern的模式一样
    bool wordPattern(string pattern, string src)
    {
        map<string, char> myMap;
        vector<string> myVec; //存放src中对应单词
#if 0
        int i = 0;

        //由于scr中单词由空格隔开，所以依次取出，放vec中
        for (i = 0; i < src.length(); i++)
        {
            //寻找空格的位置，并返回给j
            int j = src.find(' ', i);

            //如果剩余字符串内未找到空格，则该字符串为一个单词,跳出该for循环
            if (j==-1)
            {
                break;
            }

            myVec.push_back(src.substr(i, j - i));

            i = j;
        }

        myVec.push_back(src.substr(i, src.length() - i));
#endif
        /* 不使用子串库函数，自己实现 */
        string tmpWord=" "; //临时存放挑选出来的单词
        for (int i = 0; i < src.size();i++)
        {
            if (src[i]!=' ')
            {
                tmpWord=tmpWord+src[i];
            }
            else
            {
                myVec.push_back(tmpWord);
                tmpWord = " ";
            }

            if (i==src.size()-1)
            {
                myVec.push_back(tmpWord);
            }

        }



        //如果pattern中元素个数和拆分后word个数不同，则返回false
        if (myVec.size()!=pattern.length())
        {
            return false;
        }

        for (int i = 0; i < myVec.size();i++)
        {
            for (auto x:myMap)
            {
                if (x.first==myVec[i]&&x.second!=pattern[i])
                {
                    return false;
                }
                else if (x.first != myVec[i] && x.second == pattern[i])
                {
                    return false;
                }
            }

            myMap[myVec[i]] = pattern[i];

        }

        return true;

    }

private:

};

/*
Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
*/


int _tmain(int argc, _TCHAR* argv[])
{
    string pattern = "abba";
    string str = "dog dog dog dog";


    if (MySolution().wordPattern(pattern, str))
    {
        cout <<str<<": is a pattern word!" << endl;
    }
    else
        cout << str << ": is not a pattern word!" << endl;
    
    system("pause");

	return 0;
}

