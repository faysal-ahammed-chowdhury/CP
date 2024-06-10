#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
vector<int> v(N);
bool find(int l, int r, int x) {
    if (l > r) return false;
    int mid = (l + r) / 2;
    if (v[mid] == x) return true;
    else if (v[mid] < x) return find(mid + 1, r, x);
    else return find(l, mid - 1, x);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= k;i++) {
        int x; cin >> x;
        bool found = find(1, n, x);
        cout << (found ? "YES\n" : "NO\n");
    }

    return 0;
}