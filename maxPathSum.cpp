#include <iostream>
using namespace std;

long* getMax(long dp[][5], int row)
{
    static long result[2];

    long max1 = -1;
    long max2 = -1;

    for(int j = 0; j < 5; j++)
    {
        if(dp[row][j] > max1)
        {
            max2 = max1;
            max1 = dp[row][j];
        }
        else if(dp[row][j] > max2)
        {
            max2 = dp[row][j];
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

    // First row remains unchanged
    for(int j = 0; j < 5; j++)
    {
        dp[0][j] = matrix[0][j];
    }

    // Fill DP table
    for(int i = 1; i < 4; i++)
    {
        long* values = getMax(dp, i - 1);

        long max1 = values[0];
        long max2 = values[1];

        for(int j = 0; j < 5; j++)
        {
            if(dp[i - 1][j] == max1)
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

    long* answer = getMax(dp, 3);

    cout << "\nMaximum Sum = " << answer[0];

    return 0;
}
