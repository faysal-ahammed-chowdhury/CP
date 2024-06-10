#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int n, ans[N];
vector<array<int, 3>> a;

void fun(int l, int r) {
  if (l > r) return;
  int mid = (l + r) / 2;
  a.push_back({l, r, r - l + 1});
  fun(l, mid - 1);
  fun(mid + 1, r);
}

bool cmp(array<int, 3> a, array<int, 3> b) {
  if (a[2] == b[2]) {
    return a[0] < b[0];
  }
  else {
    return a[2] > b[2];
  }
}

void solve() {
  a.clear();
  
  cin >> n;
  fun(1, n);

  sort(a.begin(), a.end(), cmp);
  int i = 1;
  for (auto [x, y, z] : a) {
    // cout << x << ' ' << y << '\n';
    int mid = (x + y) / 2;
    ans[mid] = i++;
  }

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
  while (t--) {
    solve();
  }

  return 0;
}