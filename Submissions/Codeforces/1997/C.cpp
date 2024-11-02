#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s[0] = '(';
  for (int i = 2; i < n; i++) {
    if (i & 1) continue;
    if (s[i - 1] == '(') s[i] = ')';
    else s[i] = '(';
  }
  stack<int> st;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '(') st.push(i);
    else {
      int top = st.top();
      st.pop();
      ans += i - top;
    }
  }
  cout << ans << '\n';
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