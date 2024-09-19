#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 9;
int a[N], psum[N], n;

bool ok(int i, int val) {
  return psum[i] >= val;
}

int cs;
void solve() {
  cin >> n;
  vector<int> goods;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    psum[i] = psum[i - 1] + a[i];
    if (a[i] > 0) goods.push_back(i);
  }
  int sz = goods.size();
  if (sz == 0) {
    cout << "Case " << ++cs << ": " << -1 << '\n';
    return;
  }
  int last = 0;
  if (sz) last = goods[0] - 1;
  int ans1 = 0;
  for (int i = 0; i < sz; i++) {
    int extra = psum[goods[i]] - psum[last];
    if (extra <= 0) {
      extra = a[goods[i]];
      ans1--;
    }
    int val = psum[goods[i]] - extra + 1; 
    int l = goods[i], r = n, go = goods[i];
    if (i + 1 < sz) {
      r = goods[i + 1] - 1;
    }
    while(l <= r) {
      int mid = (l + r) >> 1;
      if (ok(mid, val)) {
        go = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    last = go;
    ans1++;
  }
  if (a[1] < 0) ans1--;
  if (last != n) ans1--;

  last = 0;
  int ans2 = 0;
  for (int i = 0; i < sz; i++) {
    int extra = psum[goods[i]] - psum[last];
    if (extra <= 0) {
      extra = a[goods[i]];
      ans2--;
    }
    int val = psum[goods[i]] - extra + 1; 
    int l = goods[i], r = n, go = goods[i];
    if (i + 1 < sz) {
      r = goods[i + 1] - 1;
    }
    while(l <= r) {
      int mid = (l + r) >> 1;
      if (ok(mid, val)) {
        go = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    last = go;
    ans2++;
  }
  if (last != n) ans2--;
  cout << "Case " << ++cs << ": " << max(ans1, ans2) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t; cin >> t;
  while (t--) {
      solve();
  }

  return 0;
}