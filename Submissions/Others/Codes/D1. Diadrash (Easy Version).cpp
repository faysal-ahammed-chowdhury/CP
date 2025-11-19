#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int query(int l, int r) {
  cout << "? " << l << ' ' << r << endl;
  int mex; cin >> mex;
  return mex;
}

void solve() {
  int n, q; cin >> n >> q;
  vector<pair<int, int>> v(q);
  for (int i = 0; i < q; i++) {
    cin >> v[i].first >> v[i].second;
  }

  sort(v.begin(), v.end());
  deque<pair<int, int>> dq;
  for (auto [l, r] : v) {
    if (dq.empty()) {
      dq.push_back({l, r});
      continue;
    }

    if (dq.back().second >= r) continue;
    while (!dq.empty() and dq.back().first == l) {
      dq.pop_back();
    }
    dq.push_back({l, r});
  }

  assert(dq.size() <= n);

  int mid = (1 + n) / 2;
  int mex1 = query(1, mid);
  bool first_half = (mex1 > 0);

  int ans = 0, cnt = 0;
  for (auto [l, r] : dq) {
    if (first_half) {
      if (l > mid) continue;
    }
    else {
      if (r <= mid) continue;
    }
    cnt++;
    ans = max(ans, query(l, r));
  }

  int mx = max(300, ((n + 1) / 2) + 2);
  assert(cnt <= mx);

  cout << "! " << ans << endl; 
}

int32_t main() {

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}