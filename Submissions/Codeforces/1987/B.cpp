#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for(int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<int> v;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] < mx) {
      v.push_back(mx - a[i]);
    }
    else {
      mx = a[i];
    }
  }

  sort(v.begin(), v.end());
  int done = 0, ans = 0, sz = v.size();
  for (int i = 0; i < sz; i++) {
    int now = v[i] - done;
    if (now == 0) continue;
    ans += (now * ((sz - i) + 1));
    done += now;
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