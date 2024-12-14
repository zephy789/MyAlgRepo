/* 
https://www.nowcoder.com/share/jump/9324748121734196256498
坐标移动问题
*/

#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cctype>


int main()
{
    int x=0,y=0;
    string str;
    cin >> str;
    string str_cur;
    int cnt=0;


    for(int i=0; i<str.size(); i++)
    {
        if(str[i] != ';')
        {
            str_cur += str[i];
        }
        else if(!str_cur.empty())
        {

            string step;
            int step_num;
            
            for(int j=1; j<str_cur.size(); j++)
            {
                if(isdigit(str_cur[j]))
                    step += str_cur[j];
                else
                {
                    step.clear();
                    break;
                }
            }

            if(!step.empty())
                step_num = stoi(step);
            else
            {
                str_cur.clear();
                continue;
            }


            switch (str_cur[0])
            {
                case 'A':
                    x-=step_num;
                    break;
                case 'D':
                    x+=step_num;
                    break;
                case 'W':
                    y+=step_num;
                    break;
                case 'S':
                    y-=step_num;
                    break;
                default:
                    break;
            }
            str_cur.clear();
        }

    }
    cout << x << ',' << y << endl;


    return 0;
}
