#include <bits/stdc++.h>
using namespace std;

const int N = 100 + 9;
int n, a[N * 2][N], dp[N * 2][N];

int solution(int i, int j) {
    if(i == ((n * 2) - 2)) {
        return a[i][j];
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    if(i >= (n - 1)) {
        int sum1 = 0, sum2 = 0;
        int last = (n - (i % n) - 2) != -1 ? (n - (i % n) - 2) : n - 1;
        if(j == 0) {
            sum1 = a[i][j] + solution(i + 1, j);
        }
        else if(j == last) {
            sum2 = a[i][j] + solution(i + 1, j - 1);
        }
        else {
            sum1 = a[i][j] + solution(i + 1, j);
            sum2 = a[i][j] + solution(i + 1, j - 1);
        }
        int ans = max(sum1, sum2);
        dp[i][j] = ans;
    }
    else {
        int sum1 = a[i][j] + solution(i + 1, j);
        int sum2 = a[i][j] + solution(i + 1, j + 1);
        int ans = max(sum1, sum2);
        dp[i][j] = ans;
    }
    return dp[i][j];
}
int cnt = 0;
void solve() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            dp[i][j] = -1;
            a[i][j] = 0;
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = n, k = 1; i < (2 * n - 1); i++, k++) {
        for(int j = 0; j < (n - k); j++) {
            cin >> a[i][j];
            dp[i][j] = -1;
        }
    }
    cout << "Case " << ++cnt << ": ";
    cout << solution(0, 0) << '\n';
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