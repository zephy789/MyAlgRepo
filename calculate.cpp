/*
https://www.nowcoder.com/share/jump/9324748121734282097516
calculator
*/



#include <iostream>
using namespace std;
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
#include <stdexcept>

bool isPrior(stack<char>& st2, char op)
{
    if(st2.top() == '(')
    {
        return false;
    }
    else if((st2.top() == '+' || st2.top() == '-') && (op == '*' || op == '/'))
    {
        return false;
    }
    else
    {
        return true;
    }
}

void compute(stack<double>& st1, stack<char>& st2)
{
    double c;
    double a = st1.top();
    st1.pop();
    double b = st1.top();
    st1.pop();
    switch(st2.top())
    {
        case '+':
            c = b + a;
            break;
        case '-':
            c = b - a;
            break;
        case '*':
            c = b * a;
            break;
        case '/':
            if (a == 0) {
                throw runtime_error("除数不能为0");
            }
            c = b / a;
            break;
    }
    st1.push(c);
    st2.pop();
}

int main() {

    string s;
    bool flag =false;
    string mp = "+-*/";
        
    while(cin >> s)
    {
        s.push_back(')');
        stack<double> st1;
        stack<char> st2;
        st2.push('(');

        for(int i = 0; i < s.size(); i++) 
        {
            if(s[i] == '(')
            {
                st2.push(s[i]);
            }
            else if(s[i] == ')')
            {
                while(st2.top() != '(')
                {
                    compute(st1, st2);
                }
                st2.pop();
            }
            else if(mp.find(s[i]) != mp.npos && flag == true)
            {
                while(isPrior(st2, s[i]))
                {
                    compute(st1, st2);
                }
                st2.push(s[i]);
                flag = false;
            }
            else 
            {
                string dig_tmp;
                while(isdigit(s[i]) || (s[i]=='-' && !isdigit(s[i-1])))
                {
                    dig_tmp.push_back(s[i]);
                    i++;
                }
                st1.push(stod(dig_tmp));
                i--;
                flag = true;
            }
        }
        cout << st1.top() << endl;
    }
        

    return 0;
}

