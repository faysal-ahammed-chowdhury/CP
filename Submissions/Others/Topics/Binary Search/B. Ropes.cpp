#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 9;
const double MAX = 1e7 + 9;
int n, k, arr[N];

bool ok(double len) {
    int possible = 0;
    for(int i = 1; i <= n; i++) {
        possible += floor(arr[i] / len);
        if(possible >= k) {
            return true;
        }
    }
    return false;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    double ans = 0;
    double l = 0, r = MAX;
    while(r - l > 1e-7) {
        double mid = (l + r) / 2;
        if(ok(mid)) {
            ans = mid;
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}