#include <iostream>
using namespace std;

int main() {
    int mat[4][5] = {
        {10, 20, 30, 40, 50},
        {1,  2,  3,  4,  5},
        {6,  7,  8,  9, 25},
        {100, 50, 40, 50, 20}
    };

    int rows = 4, cols = 5;

    int r, c;
    cin >> r >> c;

    int dir[8][2] = {
        {-1,-1}, {-1,0}, {-1,1},
        {0,-1},          {0,1},
        {1,-1},  {1,0},  {1,1}
    };

    int sum = 0;

    for(int k = 0; k < 8; k++) {
        int nr = r + dir[k][0];
        int nc = c + dir[k][1];

        if(nr >= 0 && nr < rows &&
           nc >= 0 && nc < cols) {
            sum += mat[nr][nc];
        }
    }

    cout << sum;
}
