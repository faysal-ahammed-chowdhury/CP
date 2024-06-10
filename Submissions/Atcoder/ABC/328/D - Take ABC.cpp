#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int n = s.size();
  stack<char> st;
  for (int i = 0; i < n; i++) {
    st.push(s[i]);
    if (st.size() >= 3) {
      char last = st.top();
      st.pop();
      char middle = st.top();
      st.pop();
      char first = st.top();
      st.pop();
      if (!(first == 'A' and middle == 'B' and last == 'C')) {
        st.push(first);
        st.push(middle);
        st.push(last);
      }
    }
  }

  string ans = "";
  while (!st.empty()) {
    ans += st.top();
    st.pop();
  }
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';

  return 0;
}