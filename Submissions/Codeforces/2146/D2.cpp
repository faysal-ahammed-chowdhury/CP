#include <bits/stdc++.h>
using namespace std;
#define int long long

using ll = long long;
bool CHECK(ll N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(ll &N, int pos) { (N |= (1ll << pos)); }
void CLR(ll &N, int pos) { (N &= ~(1ll << pos)); }

const int N = 2e5 + 9;
int a[N];
int l, r; 

int org(int i) {
  return i - l;
}

void solve(int l, int r, int add) {
  if (l > r) return;
  if (l == r) {
    a[org(l + add)] = r + add;
    return;
  }

  if (__lg(l) == __lg(r)) {
    int msb = __lg(l);
    CLR(l, msb);
    CLR(r, msb);
    solve(l, r, add | (1ll << msb));
    return;
  }

  int msb = __lg(r);
  int x = (1ll << msb);

  int cur = x - 1, cur2 = x;
  for (int i = x; cur >= l and i <= r; i++, cur2++) {
    a[org(i + add)] = cur + add;
    a[org(cur + add)] = i + add;
    cur--;
  }

  if (cur2 <= r) {
    solve(cur2, r, add);
  }
  if (cur >= l) {
    solve(l, cur, add);
  }
}

void solve() {
  cin >> l >> r;
  int n = r - l + 1;

  for (int i = 0; i < n; i++) {
    a[i] = 0;
  }

  solve(l, r, 0);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i] | (i + l);
  }

  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}