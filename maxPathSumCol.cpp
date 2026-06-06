#include <iostream>
using namespace std;

long* getMax(long dp[][5], int col)
{
    static long result[2];

    long max1 = -1;
    long max2 = -1;

    for(int i = 0; i < 4; i++)
    {
        if(dp[i][col] > max1)
        {
            max2 = max1;
            max1 = dp[i][col];
        }
        else if(dp[i][col] > max2)
        {
            max2 = dp[i][col];
        }
    }

    result[0] = max1;
    result[1] = max2;

    return result;
}

int main()
{
    long matrix[4][5];
    long dp[4][5];

    cout << "Enter the 4x5 matrix:\n";

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // First column remains unchanged
    for(int i = 0; i < 4; i++)
    {
        dp[i][0] = matrix[i][0];
    }

    // Fill DP column-wise
    for(int j = 1; j < 5; j++)
    {
        long* values = getMax(dp, j - 1);

        long max1 = values[0];
        long max2 = values[1];

        for(int i = 0; i < 4; i++)
        {
            if(dp[i][j - 1] == max1)
                dp[i][j] = matrix[i][j] + max2;
            else
                dp[i][j] = matrix[i][j] + max1;
        }
    }

    cout << "\nDP Table:\n";

    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << dp[i][j] << "\t";
        }
        cout << endl;
    }

    long* answer = getMax(dp, 4);

    cout << "\nMaximum Sum = " << answer[0];

    return 0;
}
