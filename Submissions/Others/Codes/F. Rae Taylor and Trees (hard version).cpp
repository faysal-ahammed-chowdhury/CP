#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, K = 20;
int n, a[N], tree[N][K];

int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void build(int n) {
  for (int i = 1; i <= n; i++) {
    tree[i][0] = a[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      tree[i][k] = min(tree[i][k - 1], tree[i + (1 << (k - 1))][k - 1]); 
    }
  }
}

int query(int l, int r) {
  int k = log2_floor(r - l + 1);
  return min(tree[l][k], tree[r - (1 << k) + 1][k]); 
}

bool ok(int idx, int val) {
  int x = query(1, idx);
  return x <= val;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  bool done[n + 1];
  memset(done, false, sizeof done);

  build(n);
  int ok_idx = n;
  vector<pair<int, int>> v;
  for (int i = n; i >= ok_idx; i--) {
    if (ok_idx - 1 < 1) continue;
    int l = 1, r = ok_idx - 1, idx = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (ok(mid, a[i])) {
        idx = mid;
        r = mid - 1;
      }
      else {
        l = mid + 1;
      }
    }

    if (idx == -1) continue;
    if (idx <= ok_idx) {
      done[a[idx]] = true;
      done[a[i]] = true;
      v.push_back({a[idx], a[i]});
    }
    ok_idx = idx;
  }

  if (ok_idx != 1) {
    cout << "NO\n";
    return;
  }

  vector<pair<int, int>> ans;
  for (int i = 0; i + 1 < v.size(); i++) {
    ans.push_back(v[i]);
    ans.push_back({v[i].first, v[i + 1].second});
    // cout << v[i].first << ' ' << v[i + 1].second << '\n';
  }
  ans.push_back(v.back());

  // for (int i = 1; i <= n; i++) {
  //   cout << done[i] << '\n';
  // }

  int mn = n + 1;
  for (int i = 1; i <= n; i++) {
    if (done[a[i]]) {
      mn = min(mn, a[i]);
    }
    else if (mn <= a[i]) {
      ans.push_back({mn, a[i]});
      done[a[i]] = true;
    }
  }

  int mx = 0;
  for (int i = n; i >= 1; i--) {
    if (done[a[i]]) {
      mx = max(mx, a[i]);
    }
    else if (mx >= a[i]) {
      ans.push_back({a[i], mx});
      done[a[i]] = true;
    }

    assert(done[a[i]]);
  }

  cout << "YES\n";
  assert(ans.size() == n - 1);
  for (auto [x, y] : ans) {
    cout << y << ' ' << x << '\n';
    assert(x < y);
  }
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