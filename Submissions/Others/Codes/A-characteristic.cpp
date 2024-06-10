#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int func(int neg, int pos) {
    return ((pos * (pos - 1)) / 2) + ((neg * (neg - 1)) / 2);
}

void solve() {
    int n, k; cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        int got = func(i, n - i);
        if (got == k) {
            cout << "YES\n";
            for (int j = 1; j <= i; j++) {
                cout << -1 << ' ';
            }
            for (int j = 1; j <= (n - i); j++) {
                cout << 1 << ' ';
            }
            cout << '\n';
            return;
        }
    }
    cout << "NO\n";
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

// brute force
/*
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n, k; cin >> n >> k;
    int arr[n + 1];
    fill(arr, arr + n + 1, 1);
    bool flag = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            arr[j] = -1;
        }

        int got = 0;
        for(int j = 0; j < n; j++) {
            for(int l = j + 1; l < n; l++) {
                if(arr[j] * arr[l] == 1) got++;
            }
        }
        if(got == k) {
            flag = 1;
            break;
        }
    }
    cout << (flag ? "YES\n" : "NO\n");
    if(flag) {
        for(int i = 0; i < n; i++) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
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
*/