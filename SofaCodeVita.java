
#include <bits/stdc++.h>
using namespace std;

class Sofa {
public:
    int fsr, fsc, ssr, ssc;
    char dir;
    int moves;

    Sofa(int fsr, int fsc, int ssr, int ssc, char dir, int moves) {
        this->fsr = fsr;
        this->fsc = fsc;
        this->ssr = ssr;
        this->ssc = ssc;
        this->dir = dir;
        this->moves = moves;
    }
};

bool canAdd(int fsr, int fsc, int ssr, int ssc,
            vector<string>& visit) {
    string s = to_string(fsr) + "_" + to_string(fsc) + "_" +
               to_string(ssr) + "_" + to_string(ssc);

    if (find(visit.begin(), visit.end(), s) != visit.end())
        return false;

    visit.push_back(s);
    return true;
}

int main() {
    int row, col;
    cin >> row >> col;

    vector<vector<char>> grid(row, vector<char>(col));

    int fsr = -1, fsc = -1, ssr = -1, ssc = -1;
    int scount = 0;

    for (int r = 0; r < row; r++) {
        for (int c = 0; c < col; c++) {
            char ch;
            cin >> ch;
            grid[r][c] = ch;

            if (ch == 's') {
                scount++;

                if (scount == 1) {
                    fsr = r;
                    fsc = c;
                } else if (scount == 2) {
                    ssr = r;
                    ssc = c;
                }
            }
        }
    }

    vector<string> vis;
    canAdd(fsr, fsc, ssr, ssc, vis);

    queue<Sofa> q;
    q.emplace(fsr, fsc, ssr, ssc, 'H', 0);

    while (!q.empty()) {
        Sofa cur = q.front();
        q.pop();

        if (grid[cur.fsr][cur.fsc] == 'S' && grid[cur.ssr][cur.ssc] == 'S') {
            cout << cur.moves;
            return 0;
        }

        if (cur.dir == 'H') {

            // 1. Drag right
            if (cur.ssc < col - 1 &&
                grid[cur.ssr][cur.ssc + 1] != 'H') {
                if (canAdd(cur.ssr, cur.ssc,cur.ssr, cur.ssc + 1, vis)) {
                    q.emplace(cur.ssr, cur.ssc,cur.ssr, cur.ssc + 1,'H', cur.moves + 1);
                }
            }

            // 2. Drag left
            if (cur.fsc > 0 && grid[cur.fsr][cur.fsc - 1] != 'H') {
                if (canAdd(cur.fsr, cur.fsc - 1,cur.fsr, cur.fsc, vis)) {
                    q.emplace(cur.fsr, cur.fsc - 1,cur.fsr, cur.fsc,'H', cur.moves + 1);
                }
            }

            // 3. Drag up
            if (cur.fsr > 0 && grid[cur.fsr - 1][cur.fsc] != 'H' && grid[cur.ssr - 1][cur.ssc] != 'H') {
                if (canAdd(cur.fsr - 1, cur.fsc,cur.ssr - 1, cur.ssc, vis)) {
                    q.emplace(cur.fsr - 1, cur.fsc,cur.ssr - 1, cur.ssc,'H', cur.moves + 1);
                }
            }

            // 4. Drag down
            if (cur.fsr < row - 1 && grid[cur.fsr + 1][cur.fsc] != 'H' && grid[cur.ssr + 1][cur.ssc] != 'H') {
                if (canAdd(cur.fsr + 1, cur.fsc,cur.ssr + 1, cur.ssc, vis)) {
                    q.emplace(cur.fsr + 1, cur.fsc,cur.ssr + 1, cur.ssc,'H', cur.moves + 1);
                }
            }

            // 5. Rotate upward around the second seat
            if (cur.fsr > 0 && grid[cur.fsr - 1][cur.fsc] != 'H' && grid[cur.ssr - 1][cur.ssc] != 'H') {

                if (canAdd(cur.ssr - 1, cur.ssc,cur.ssr, cur.ssc, vis)) {
                    q.emplace(cur.ssr - 1, cur.ssc,cur.ssr, cur.ssc,'V', cur.moves + 1);
                }

                // 6. Rotate upward around the first seat
                if (canAdd(cur.fsr, cur.fsc,cur.fsr - 1, cur.fsc, vis)) {
                    q.emplace(cur.fsr, cur.fsc,cur.fsr - 1, cur.fsc,'V', cur.moves + 1);
                }
            }

            // 7. Rotate downward around the second seat
            if (cur.fsr < row - 1 && grid[cur.fsr + 1][cur.fsc] != 'H' && grid[cur.ssr + 1][cur.ssc] != 'H') {

                if (canAdd(cur.ssr + 1, cur.ssc,cur.ssr, cur.ssc, vis)) {
                    q.emplace(cur.ssr + 1, cur.ssc,cur.ssr, cur.ssc,'V', cur.moves + 1);
                }

                // 8. Rotate downward around the first seat
                if (canAdd(cur.fsr, cur.fsc,cur.fsr + 1, cur.fsc, vis)) {
                    q.emplace(cur.fsr, cur.fsc,cur.fsr + 1, cur.fsc,'V', cur.moves + 1);
                }
            }
        }

        if (cur.dir == 'V') {

            // 1. Drag down
            if (cur.ssr < row - 1 && grid[cur.ssr + 1][cur.ssc] != 'H') {
                if (canAdd(cur.fsr+1, cur.fsc,cur.ssr + 1, cur.ssc, vis)) {
                    q.emplace(cur.fsr+1, cur.fsc,cur.ssr + 1, cur.ssc,'V', cur.moves + 1);
                }
            }

            // 2. Drag up
            if (cur.fsr > 0 && grid[cur.fsr - 1][cur.fsc] != 'H') {
                if (canAdd(cur.fsr - 1, cur.fsc,cur.ssr - 1, cur.ssc, vis)) {
                    q.emplace(cur.fsr - 1, cur.fsc,cur.ssr - 1, cur.ssc,'V', cur.moves + 1);
                }
            }

            // 3. Drag right
            if (cur.fsc < col - 1 && grid[cur.fsr][cur.fsc + 1] != 'H' && grid[cur.ssr][cur.ssc + 1] != 'H') {
                if (canAdd(cur.fsr, cur.fsc + 1,cur.ssr, cur.ssc + 1, vis)) {
                    q.emplace(cur.fsr, cur.fsc + 1,cur.ssr, cur.ssc + 1,'V', cur.moves + 1);
                }
            }

            // 4. Drag left
            if (cur.fsc > 0 && grid[cur.fsr][cur.fsc - 1] != 'H' && grid[cur.ssr][cur.ssc - 1] != 'H') {
                if (canAdd(cur.fsr, cur.fsc - 1,cur.ssr, cur.ssc - 1, vis)) {
                    q.emplace(cur.fsr, cur.fsc - 1,cur.ssr, cur.ssc - 1,'V', cur.moves + 1);
                }
            }

            // 5. Rotate right around the second seat
            if (cur.fsc < col - 1 && grid[cur.fsr][cur.fsc + 1] != 'H' && grid[cur.ssr][cur.ssc + 1] != 'H') {

                if (canAdd(cur.ssr, cur.ssc + 1,cur.ssr, cur.ssc, vis)) {
                    q.emplace(cur.ssr, cur.ssc + 1,cur.ssr, cur.ssc,'H', cur.moves + 1);
                }

                // 6. Rotate right around the first seat
                if (canAdd(cur.fsr, cur.fsc,cur.fsr, cur.fsc + 1, vis)) {
                    q.emplace(cur.fsr, cur.fsc,cur.fsr, cur.fsc + 1,'H', cur.moves + 1);
                }
            }

            // 7. Rotate left around the second seat
            if (cur.fsc > 0 && grid[cur.fsr][cur.fsc - 1] != 'H' && grid[cur.ssr][cur.ssc - 1] != 'H') {

                if (canAdd(cur.ssr, cur.ssc - 1,cur.ssr, cur.ssc, vis)) {
                    q.emplace(cur.ssr, cur.ssc - 1,cur.ssr, cur.ssc,'H', cur.moves + 1);
                }

                // 8. Rotate left around the first seat
                if (canAdd(cur.fsr, cur.fsc,cur.fsr, cur.fsc - 1, vis)) {
                    q.emplace(cur.fsr, cur.fsc,cur.fsr, cur.fsc - 1,'H', cur.moves + 1);
                }
            }
        }
    }

    cout << "Impossible";
    return 0;
}
