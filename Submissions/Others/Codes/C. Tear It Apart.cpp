#include <bits/stdc++.h>
using namespace std;

// @author: faysalahammedchowdhury

void solve() {
  string s; cin >> s;
  int n = s.size();
  int ans = INT_MAX;
  for(char c = 'a'; c <= 'z'; c++) {
    int a[n];
    for(int i = 0; i < n; i++) {
      if(s[i] == c) a[i] = 1;
      else a[i] = 0;
    }

    int cnt = 0, last = -1, mx = 0;
    for(int i = 0; i < n; i++) {
      if(a[i] == 0) {
        if(cnt == 0) cnt = 1;
        if(last == 0) cnt++;
      }
      else {
        int x = log2(cnt) + 1;
        mx = max(mx, x);
        cnt = 0;
      }
      last = a[i];
    }
    int x = log2(cnt) + 1;
    mx = max(mx, x);
    ans = min(ans, mx);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}