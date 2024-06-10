#include <bits/stdc++.h>
using namespace std;

const int N = 25;
int n, a[N];
int ans;

void solve(int curr, int sum1, int sum2) {
    if(curr >= n) {
        ans = min(ans, abs(sum1 - sum2));
        return;
    }

    // first side
    solve(curr + 1, sum1 + a[curr], sum2);

    // second side
    solve(curr + 1, sum1, sum2 + a[curr]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ans = INT_MAX;
    solve(0, 0, 0);
    cout << ans << '\n';
    return 0;
}