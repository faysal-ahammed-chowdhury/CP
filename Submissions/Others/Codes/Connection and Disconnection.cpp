#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s; cin >> s;
  int k; cin >> k;
  int n = s.size();
  vector<int> v;
  int cnt = -1; char last = '0';
  for (int i = 0; i < n; i++) {
    if (s[i] == last) {
      cnt++;
    }
    else {
      if (cnt != -1) v.push_back(cnt);
      cnt = 1;
      last = s[i];
    }
  }
  v.push_back(cnt);
  int sz = v.size();
  int ans = 0;
  if (sz == 1) {
    ans += (k * v[0]) / 2;
  }
  else {
    for (int i = 1; i + 1 < sz; i++) {
      ans += k * (v[i] / 2);
    }
    if (s[0] == s[n - 1]) {
      int tot = v[0] + v.back();
      ans += (k - 1) * (tot / 2);
      ans += v[0] / 2;
      ans += v.back() / 2;
    }
    else {
      ans += k * (v[0] / 2);
      ans += k * (v.back() / 2);
    }
  }
  cout << ans << '\n';

  return 0;
}