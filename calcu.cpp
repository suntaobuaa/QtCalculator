#include "calcu.h"
#include<vector>
#include<stack>
#include<QDebug>
#include<string>
using namespace std;
string q;

Calcu::Calcu()
{
}

double Calcu::ducalcu(string s)
{
    stack<char>houzhui;   //转换后缀表达式用
    vector<double>strmmm;    //后缀表达式存储
    stack<double>stc_int;
    string jiangzemin;   //分解表达式中的数字
    auto its = s.begin();
    while (its !=s.end())
    {
        if (*its == ' ')
            its = s.erase(its);
        else
            its++;
    }

    for (auto it = s.begin(); it != s.end(); it++)
    {

        if (isdigit(*it)||*it == '.')
            jiangzemin.push_back(*it);
        else if (houzhui.empty())
        {
            if (*it!='('&&*(it-1)!=')')
            {
                strmmm.push_back(stod(jiangzemin));
                jiangzemin.clear();
            }

            houzhui.push(*it);
        }
        else if (*it == '(')
        {
            houzhui.push(*it);
        }
        else if (*it == ')')
        {
            if (isdigit(*(it - 1)))
            {
                strmmm.push_back(stod(jiangzemin));
                jiangzemin.clear();
            }

            while (houzhui.top() != '(')
            {
                strmmm.push_back(-1 * houzhui.top());
                houzhui.pop();
            }
            houzhui.pop();
        }
        else if (*it == '*' || *it == '/')
        {
            if (isdigit(*(it - 1)))
            {
                strmmm.push_back(stoi(jiangzemin));
                jiangzemin.clear();
            }


            while ( houzhui.top() == '*' ||houzhui.top() == '/')
            {
                strmmm.push_back(-1*houzhui.top());
                houzhui.pop();
                if (houzhui.empty()||houzhui.top()=='(')
                    break;
            }
            houzhui.push(*it);
        }
        else
        {
            if (isdigit(*(it - 1)))
            {
                strmmm.push_back(stoi(jiangzemin));
                jiangzemin.clear();
            }

            while (!houzhui.empty()&&houzhui.top()!='(')
            {
                strmmm.push_back(-1*houzhui.top());
                houzhui.pop();
            }
            houzhui.push(*it);
        }

    }
    if (isdigit(*(s.end()-1)))
    {
        strmmm.push_back(stod(jiangzemin));
        jiangzemin.clear();
    }

    while (!houzhui.empty())
    {

        strmmm.push_back(-1*houzhui.top());
        houzhui.pop();
    }

    for (auto it2 = strmmm.begin(); it2 != strmmm.end(); it2++)
    {

        if (*it2 == -'+' || *it2 ==- '-' || *it2 ==- '*' || *it2 ==- '/')
        {
            double a = 0, b = 0;
            a = stc_int.top();
            stc_int.pop();
            b = stc_int.top();
            stc_int.pop();
            switch(static_cast<int>(-*it2))
            {
            case '+': b = b + a;
                break;
            case '-': b = b - a;
                break;
            case '*': b = b * a;
                break;
            case '/': b = b / a;
                break;
            }
            stc_int.push(b);
        }
        else
        {
            stc_int.push(*it2);
        }

    }
    double result = stc_int.top();
    return result;
}
