#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e9 + 9;
const int N = 1e4 + 9;
int n, k, a[N];

bool ok(int min_distance) {
    int put = 1;
    int last = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i] - a[last] >= min_distance) {
            put++;
            last = i;
        }
    }
    return put >= k;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    int l = 0, r = MAX, ans = -1;
    while(l <= r) {
        int mid = l + (r - l) / 2;
        if(ok(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans << '\n';

    return 0;
}