#include <bits/stdc++.h>
using namespace std;

long long const MAX = (long long)1e14;
long long w, h, n;

bool ok(long long mid) {
    if((mid / h) == 0) return false;
    if((mid / w) >= ((double)n / (mid / h))) return true;
    return false;
}

long long search(long long l, long long r) {
    long long ans = -1;
    while(l <= r) {
        long long mid = (l + r) / 2;
        if(ok(mid)) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> w >> h >> n;
    long long ans = search(1, MAX);
    cout << ans << '\n';
    return 0;
}