#include <bits/stdc++.h>
using namespace std;

const int B = 800;

int get_msb(bitset<B> bs) {
  for (int i = B - 1; i >= 0; i--) {
    if (bs[i] == 1) {
      return i;
    }
  }
  return 0;
}

bool ok(bitset<B> a, bitset<B> b) {
  int msba = get_msb(a);
  int msbb = get_msb(b);
  for (int i = msbb; i >= 0; i--) {
    if (a[i] == 1 and b[i] == 0) return false;
    if (b[i] == 1 and a[i] == 0) return true;
  }
  return true;
}

pair<int, bitset<B>> fun(bitset<B> a, bitset<B> b) {
  int msba = get_msb(a);
  int msbb = get_msb(b);
  if (msbb > msba) {
    return {0, b};
  }
  int cnt = 0;
  while (msbb < msba) {
    cnt++;
    b = b << 1;
    msbb++;
  }
  if (!ok(a, b)) {
    cnt++;
    b = b << 1;
  }

  return {cnt, b};
}

void solve() {
  int n; cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int cnt = 0;
  bitset<B> last(a[1]);
  for (int i = 2; i <= n; i++) {
    bitset<B> bs(a[i]);
    pair<int, bitset<B>> p = fun(last, bs);
    last = p.second;
    cnt +=  p.first;
  }
  cout << cnt << '\n';
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