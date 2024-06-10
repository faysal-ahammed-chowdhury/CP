#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> v(N);

int search(int l, int r, int x) {
    int idx = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (v[mid] == x) {
            idx = mid;
            l = mid + 1;
        }
        else if (v[mid] < x) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    return idx != -1 ? idx : r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < k;i++) {
        int x; cin >> x;
        int idx = search(0, n - 1, x);
        cout << idx + 1 << '\n';
    }

    return 0;
}