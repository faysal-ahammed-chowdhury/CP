#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int now_turn = 0;
  stack<char> st;
  for (auto c : s) {
    if (st.empty()) {
      st.push(c);
    }
    else {
      int last = st.top();
      if (last == c) {
        now_turn = !now_turn;
        st.pop();
      }
      else {
        st.push(c);
      }
    }
  }

  if (now_turn == 0) {
    cout << "No\n";
  }
  else {
    cout << "Yes\n";
  }

  return 0;
}