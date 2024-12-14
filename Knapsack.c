#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>

int main()
{
    int money, num;
    cin >> money >> num;
    int cost[num][4];
    int weight[num][4];
    int v, p, q;
    int dp[num][money+1];

    memset(cost,0,sizeof(cost));
    memset(weight,0,sizeof(weight));
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<num; i++)
    {
        cin >> v >> p >> q;
        if(q == 0)
        {
            cost[i][0] = v;
            weight[i][0] = v*p;
        }
        else if(cost[q-1][1]==0)
        {
            cost[q-1][1] = v;
            weight[q-1][1] = v*p;
        }
        else
        {
            cost[q-1][2] = v;
            weight[q-1][2] = v*p;
            cost[q-1][3] = cost[q-1][1]+v;
            weight[q-1][3] = weight[q-1][1]+v*p;
        }
    }

    for(int i=0; i<num; i++)
    {
        for(int k=1; k<4; k++)
        {
            if(cost[i][k]!=0)
            {
                cost[i][k] = cost[i][k] + cost[i][0];
                weight[i][k] = weight[i][k] + weight[i][0];
            }
        }
    }



    for (int i = 0; i < num; i++) {
        if (cost[i][0] == 0) continue;
        for (int j = 0; j <= money; j += 10) { // 确保money是10的倍数
            int dp_tmp = (i == 0) ? 0 : dp[i - 1][j]; // 初始化dp_tmp
            for (int k = 0; k < 4; k++) {
                if (j >= cost[i][k]) {
                    dp_tmp = max(dp_tmp, (i == 0 ? 0 : dp[i - 1][j - cost[i][k]]) + weight[i][k]);
                }
            }
            dp[i][j] = dp_tmp;
        }
    }
    cout << dp[num-1][money] << endl;
        
        
    return 0;

}
