#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int n = (int)s.size();
  sort(s.begin(), s.end());
  set<char> se;
  char last = 'A';
  bool ok = true;
  for(auto c: s) {
    se.insert(c);
    if(last == 'A') {
      last = c;
      continue;
    }
    if(c - 1 != last) {
      cout << "No\n";
      return;
    }
    last = c;
  }
  

  if(se.size() == n) {
    cout << "Yes\n";
  }
  else {
    cout << "No\n";
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}