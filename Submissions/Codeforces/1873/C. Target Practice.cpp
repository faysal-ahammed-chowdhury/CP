#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

void solve() {
  int n = 11;
  int a[n][n];
  string s[n];
  for(int i = 1; i < n; i++) {
    cin >> s[i];
  }

  int start = 1, end = 10;
  int point = 1;
  while(start <= end) {
    for(int i = start; i <= end; i++) {
      a[start][i] = point;
      a[end][i] = point;
      a[i][start] = point;
      a[i][end] = point;
    }
    start++, end--, point++;
  }

  int ans = 0;
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(s[i][j] == 'X') {
        ans += a[i][j + 1];
      }
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}