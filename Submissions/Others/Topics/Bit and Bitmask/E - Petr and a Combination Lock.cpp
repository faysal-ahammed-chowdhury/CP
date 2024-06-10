#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int mask = 0; mask < (1 << n); mask++) {
        int current = 0;
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i)) {
                current = current - a[i];
                if(current < 0) {
                    current = 360 + current;
                }
            }
            else {
                current = current + a[i];
                if(current > 360) {
                    current -= 360;
                }
            }
        }
        if(current == 0) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
}