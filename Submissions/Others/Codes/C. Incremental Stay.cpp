#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

void solve() {
  int n; cin >> n;
  n += n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int l = 1, r = n;
  int x = 0;
  while (l <= r) {
    x += abs(a[l] - a[r]);
    l++, r--;
  }

  n /= 2;

  int ans[n + 1];
  ans[n] = x;
  l = n, r = n + 1;
  int add = a[r] - a[l], rem = 0;
  for (int i = n - 1; i >= 1; i--) {
    swap(add, rem);
    add += a[l] - a[l - 1];
    add += a[r + 1] - a[r];
    x += add;
    x -= rem;
    x -= a[r + 1] - a[l - 1];
    ans[i] = x;
    l--, r++;
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
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