#include <bits/stdc++.h>
using namespace std;

long long n, k;
int search(long long l, long long r, long long k) {
    if (l > r) return -1;
    long long mid = (l + r) / 2;
    int not_divisible = (mid - mid / n);
    if (not_divisible == k) {
        if (mid % n != 0) {
            return mid;
        }
        return search(l, mid - 1, k);
    }
    else if (not_divisible < k) {
        return search(mid + 1, r, k);
    }
    else {
        return search(l, mid - 1, k);
    }
}

void solve() {
    cin >> n >> k;
    cout << search(1, 2 * k, k) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}