#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> v(N);

int my_lower_bound(int l, int r, int x) {
    while (l <= r) {
        int mid = (l + r) / 2;
        if (v[mid] >= x) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return l;
}

int my_upper_bound(int l, int r, int x) {
    while (l <= r) {
        int mid = (l + r) / 2;
        if (v[mid] <= x) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return l;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n;i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.begin() + n);
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int l, r; cin >> l >> r;
        int lower = my_lower_bound(0, n - 1, l);
        int upper = my_upper_bound(0, n - 1, r);
        cout << upper - lower << ' ';
    }
    cout << '\n';

    return 0;
}