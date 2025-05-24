#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
  string s; cin >> s;
  int n = s.size();
  s = '.' + s;
  int last = -1;
  for (int i = n; i >= 1; i--) {
    if (s[i] == ')') {
      last = i;
      break;
    }
  }

  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '(') cnt++;
    else {
      if (cnt == 1 and last > i) {
        cout << "Yes\n";
        return;
      }
      cnt--;
    }
  }
  cout << "No\n";
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