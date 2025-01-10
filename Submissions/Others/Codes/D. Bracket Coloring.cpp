#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int open = 0, close = 0;
  for (auto c : s) {
    open += c == '(';
    close += c == ')';
  }

  if ((n & 1) or open != close) {
    cout << "-1\n";
    return;
  }

  stack<char> st;
  bool notok = false;
  for (auto c : s) {
    if (c == '(') st.push(c);
    else if (c == ')') {
      if (!st.empty() and st.top() == '(') st.pop();
      else {
        notok = true;
        break;
      }
    }
  }

  notok |= st.empty() == false;

  if (!notok) {
    cout << 1 << '\n';
    for (int i = 1; i <= n; i++) {
      cout << 1 << ' ';
    }
    cout << '\n';
    return;
  }

  reverse(s.begin(), s.end());
  stack<char> st2;
  notok = false;
  for (auto c : s) {
    if (c == '(') st2.push(c);
    else if (c == ')') {
      if (!st2.empty() and st2.top() == '(') st2.pop();
      else {
        notok = true;
        break;
      }
    }
  }

  notok |= st2.empty() == false;

  if (!notok) {
    cout << 1 << '\n';
    for (int i = 1; i <= n; i++) {
      cout << 1 << ' ';
    }
    cout << '\n';
    return;
  }

  cout << 2 << '\n';

  reverse(s.begin(), s.end());
  int ans[n + 1];
  memset(ans, -1, sizeof ans);

  stack<pair<char, int>> st3;
  for (int i = 1; i <= n; i++) {
    char c = s[i - 1];
    if (c == '(') st3.push({c, i});
    else if (c == ')') {
      if (!st3.empty() and st3.top().first == '(') {
        ans[st3.top().second] = 1;
        ans[i] = 1;
        st3.pop();
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (ans[i] == -1) ans[i] = 2;
    cout << ans[i] << ' ';
  }
  cout << '\n';
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