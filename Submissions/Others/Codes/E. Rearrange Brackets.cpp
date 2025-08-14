#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  int k; cin >> k;
  string s; cin >> s;
  int n = s.size();
  s = '.' + s;
  stack<pair<char, int>> st;
  vector<array<int, 3>> v;
  int en[n + 1];
  for (int i = 1; i <= n; i++) {
    if (s[i] == '(') st.push({'(', i});
    else {
      auto [_, idx] = st.top(); 
      st.pop();
      v.push_back({i - idx + 1, idx, i});
      en[idx] = i;
    }
  }
  sort(v.rbegin(), v.rend());

  string t = "";

  set<int> se, se2;

  for (int i = 0; i < min(k, (int)v.size()); i++) {
    se2.insert(v[i][1]);
  }

  for (int i = 1; i <= n; i++) {
    if (se.find(i) != se.end()) continue;
    if (se2.find(i) != se2.end()) {
      // cout << "jere\n";
      t += "()";
      se.insert(en[i]);
    }
    else {
      t += s[i];
    }
  }

  reverse(t.begin(), t.end());
  t = '.' + t;

  // cout << t << '\n';
  // return;

  ll ans = 0;
  stack<char> st2;
  for (int i = 1; i <= n; i++) {
    if (t[i] == ')') st2.push(')');
    else {
      ans += (int)st2.size() - 1;
      st2.pop();
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