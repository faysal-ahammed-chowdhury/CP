#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  s = '.' + s;
  stack<char> st;
  for (int i = 1; i <= n; i++) {
    if (!st.empty() and st.top() == s[i]) st.pop();
    else st.push(s[i]);
  }

  if (st.empty()) cout << "YES\n";
  else cout << "NO\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}