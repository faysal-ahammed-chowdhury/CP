#include <bits/stdc++.h>
using namespace std;

const double MAX = 2e9;
const int N = 1e5 + 9;
int n;
vector<pair<int, int>> v(N);

bool ok(double time) {
    double lmax = -1e18, rmin = 1e18;
    for(int i = 1; i <= n; i++) {
        double left = v[i].first - (v[i].second * time);
        double right = v[i].first + (v[i].second * time);
        lmax = max(lmax, left);
        rmin = min(rmin, right);
    }
    return lmax <= rmin;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    double l = 0, r = MAX, ans = -1;
    int it = 100;
    while(it--) {
        double mid = l + (r - l) / 2.0;
        if(ok(mid)) {
            ans = mid;
            r = mid;
        }
        else {
            l = mid;
        }
    }
    cout << fixed << setprecision(10) << ans << '\n';

    return 0;
}