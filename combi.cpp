#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();

    for (int mask = 1; mask < (1 << n); mask++) {

        for (int i = 0; i < n; i++) {

            if (mask & (1 << i)) {
                cout << s[i];
            }
        }

        cout << endl;
    }

    return 0;
}
