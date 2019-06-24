// WordPattern.cpp : �������̨Ӧ�ó������ڵ㡣
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
    //�ж��ַ���src�а����ĵ���ģʽ���Ƿ��pattern��ģʽһ��
    bool wordPattern(string pattern, string src)
    {
        map<string, char> myMap;
        vector<string> myVec; //���src�ж�Ӧ����
#if 0
        int i = 0;

        //����scr�е����ɿո��������������ȡ������vec��
        for (i = 0; i < src.length(); i++)
        {
            //Ѱ�ҿո��λ�ã������ظ�j
            int j = src.find(' ', i);

            //���ʣ���ַ�����δ�ҵ��ո�����ַ���Ϊһ������,������forѭ��
            if (j==-1)
            {
                break;
            }

            myVec.push_back(src.substr(i, j - i));

            i = j;
        }

        myVec.push_back(src.substr(i, src.length() - i));
#endif
        /* ��ʹ���Ӵ��⺯�����Լ�ʵ�� */
        string tmpWord=" "; //��ʱ�����ѡ�����ĵ���
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



        //���pattern��Ԫ�ظ����Ͳ�ֺ�word������ͬ���򷵻�false
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

