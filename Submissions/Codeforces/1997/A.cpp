#include <bits/stdc++.h>
using namespace std;

char get(char c) {
  if (c == 'z') c--;
  else c++;
  return c;
}

void solve() {
  string s; cin >> s;
  int n = s.size();
  int idx = -1;
  char c;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
      idx = i;
      c = get(s[i]);
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i == idx) cout << c;
    cout << s[i];
  }
  if (idx == -1) cout << get(s[n - 1]);
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}