#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve() {
  int n; cin >> n;
  multiset<int> ms;
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    ms.insert(x);
  }

  vector<int> ans;
  ans.push_back(0);
  ans.push_back(*ms.begin());
  long long cur = *(ms.begin());
  ms.erase(ms.begin());
  int cnt = 0;
  for (int i = 2; i <= n; i++) {
    auto it = ms.upper_bound(cur);
    if (it == ms.end()) {
      cnt++;
      ans.push_back(*ms.begin());
      cur += *ms.begin();
      ms.erase(ms.begin());
    }
    else {
      ans.push_back(*it);
      cur += *it;
      ms.erase(it);
    }
  }
  cout << cnt << '\n';
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
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