#include <bits/stdc++.h>
using namespace std;

const long long MAX = 25 * 1e9;
const int N = 100;
int k, n, a[N];

bool ok(long long team_count) {
    int per_team_member = 0;
    long long member = 0;
    for(int i = 1; i <= n; i++) {
        if(team_count <= a[i]) {
            per_team_member++;
            continue;
        }
        member += a[i];
        if(member >= team_count) {
            per_team_member++;
            member -= team_count;
        }
    }
    return per_team_member >= k;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    long long l = 1, r = MAX, ans = 0;
    while(l <= r) {
        long long mid = l + (r - l) / 2;
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