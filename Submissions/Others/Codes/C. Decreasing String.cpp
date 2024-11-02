#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
  string s; cin >> s;
  int pos; cin >> pos;
  int n = s.size();
  s = '.' + s + '#';
  n++;
  stack<pair<char, int>> st;
  vector<int> v;
  for (int i = 1; i <= n; i++) {
    while (!st.empty() and st.top().first > s[i]) {
      v.push_back(st.top().second);
      st.pop();
    }
    st.push({s[i], i});
  }
  n--;

  int len = 0, x = n, cnt = 1;
  while (len + x < pos) {
    len += x;
    x--;
    cnt++;
  }

  vector<int> vec;
  for (int i = 0; i < (cnt - 1); i++) {
    vec.push_back(v[i]);
  }
  sort(vec.begin(), vec.end());

  int need = pos - len, i = 1, j = 1, now = 0;
  while (true) {
    if (i > n or j > n) break;
    if (now < vec.size() and vec[now] == j) {
      now++;
      j++;
      continue;
    }
    if (i == need) {
      cout << s[j];
      return;
    }
    i++, j++;
  }
  assert(false);
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