#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int n = s.length();
  vector<int> v;
  bool last = false;
  int cnt = 0;
  int b_cnt = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == 'A') {
      if(last) {
        cnt++;
      }
      else {
        cnt = 1;
        last = true;
      }
    }
    else {
      b_cnt++;
      last = false;
      if(cnt > 0) v.push_back(cnt);
      cnt = 0;
    }
  }
  if(last) {
    v.push_back(cnt);
  }

  sort(v.rbegin(), v.rend());
  int x = min((int) v.size(), b_cnt);
  int ans = 0;
  for(int i = 0; i < x; i++) {
    ans += v[i];
  }
  cout << ans << '\n';
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