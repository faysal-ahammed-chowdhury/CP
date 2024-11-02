#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();
  stack<char> st;
  int cnt = 0;
  for (auto c : s) {
    if (c == '(') st.push(c);
    else if (!st.empty()) st.pop();
    else cnt++;
  }
  while (!st.empty()) {
    cnt++;
    st.pop();
  }
  cout << n - cnt << '\n';

  return 0;
}