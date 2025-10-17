#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }
void CLR(int &N, int pos) { (N &= ~(1ll << pos)); }

void solve() {
  int a, b; cin >> a >> b;

  if (a == b) {
    cout << 0 << '\n';
    return;
  }

  int msb1 = __lg(a);
  int msb2 = __lg(b);

  if (msb2 > msb1) {
    cout << -1 << '\n';
    return;
  }
  int c = a ^ b;
  int msb = __lg(c);
  CLR(c, msb);
  cout << 2 << '\n';
  cout << c << ' ' << (1 << msb) << '\n';

  assert((c <= a) and (1 << msb) <= (a ^ c) and ((a ^ c) ^ (1 << msb)) == b);
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