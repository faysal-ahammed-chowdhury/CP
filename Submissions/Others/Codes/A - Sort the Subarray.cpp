#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

void solve() {
    int n; cin >> n;
    int a[n + 1], b[n + 1];
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int first_mismatch = -1, last_mismatch = -1;
    for(int i = 1; i <= n; i++) {
        if(a[i] != b[i]) {
            first_mismatch = i;
            break;
        }
    }
    for(int i = n; i > 0; i--) {
        if(a[i] != b[i]) {
            last_mismatch = i;
            break;
        }
    }
    if(first_mismatch == -1) {
        int start = -1, end = -1, last_start = 1, len = 1, mx_len = 0;
        for(int i = 2; i <= n; i++) {
            if(a[i] >= a[i - 1]) {
                len++;
            }
            else {
                if(len >= mx_len) {
                    mx_len = len;
                    len = 1;
                    start = last_start;
                    end = i - 1;
                    last_start = i;
                }
            }
        }
        if(len >= mx_len) {
            mx_len = len;
            start = last_start;
            end = n;
        }
        cout << start << ' ' << end << '\n';
        return;
    }
    int start = first_mismatch;
    while(start > 1 && b[start] >= b[start - 1]) {
        start--;
    }
    int end = last_mismatch;
    while(end < n && b[end] <= b[end + 1]) {
        end++;
    }
    cout << start << ' ' << end << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}