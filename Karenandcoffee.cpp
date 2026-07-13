#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, q;
    cin >> n >> k >> q;

    vector<int> diff(200002, 0);

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        diff[l]++;
        diff[r + 1]--;
    }

    vector<int> cnt(200002, 0);
    for (int i = 1; i <= 200000; i++) {
        cnt[i] = cnt[i - 1] + diff[i];
    }

    vector<int> pref(200002, 0);
    for (int i = 1; i <= 200000; i++) {
        pref[i] = pref[i - 1];
        if (cnt[i] >= k)
            pref[i]++;
    }

    while (q--) {
        int a, b;
        cin >> a >> b;

        cout << pref[b] - pref[a - 1] << '\n';
    }

    return 0;
}
