#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();
  s = '.' + s;
  char suff_min[n + 1];
  suff_min[n] = s[n];
  for (int i = n  - 1; i >= 1 ; i--) {
    suff_min[i] = min(suff_min[i + 1], s[i]);
  }
  string ans;
  stack<char> st;
  for (int i = 1; i <= n ; i++) {
    while (!st.empty() and st.top() <= suff_min[i]) {
      ans += st.top();
      st.pop();
    }
    if (s[i] == suff_min[i]) ans += s[i];
    else st.push(s[i]);
  }
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }
  cout << ans << '\n';

  return 0;
}