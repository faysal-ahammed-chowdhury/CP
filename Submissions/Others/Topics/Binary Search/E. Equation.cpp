#include <bits/stdc++.h>
using namespace std;

const double MAX = (double)1e5;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    double c; cin >> c;
    double l = 0, r = MAX;
    int op = 100;
    while(op--) {
        double mid = l + (r - l) / 2.0;
        double x = (mid * mid) + sqrt(mid);
        if(abs(x - c) <= 1e-6) {
            cout << fixed << setprecision(10) << mid << '\n';
            return 0;
        }
        else if(x < c) {
            l = mid;
        }
        else {
            r = mid;
        }
    }

    return 0;
}