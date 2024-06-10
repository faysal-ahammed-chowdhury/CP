#include <bits/stdc++.h>
using namespace std;

const int MAX = 2e9;
int  n, x, y;

bool ok(int sec) {
    int x_done = sec / x;
    int y_done = (sec - x) / y;
    long long total_possible = x_done + y_done;
    return total_possible >= n;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x >> y;
    if(x > y) swap(x, y);
    int l = 0, r = MAX, ans = 0;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(ok(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}