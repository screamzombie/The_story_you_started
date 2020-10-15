#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    stack<char> s;
    string words = "";
    cin >> words;
    for (auto &&i : words)
    {
        if (i == ')' or i == ']' or i == '}')
        {
            s.push(i);
        }
    }
    for (auto &&i : words)
    {
        if (i == '(' or i == '[' or i == '{')
        {
            char temp;
            temp = s.top();
            s.pop();
            if ((i == '(' and temp == ')') or (i == '[' and temp == ']') or (i == '{' and temp == '}'))
            {
                continue;
            }
            else
            {
                cout << "no!" << endl;
                return 0;
            }
        }
    }
    if (!s.empty())
    {
        cout << "no!" << endl;
        return 0;
    }
    else
    {
        cout << "yes" << endl;
        return 0;
    }
}