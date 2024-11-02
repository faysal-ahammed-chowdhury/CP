#include <bits/stdc++.h>
using namespace std;

bool CHECK(int N, int pos) { return (bool)(N & (1 << pos)); }
void SET(int &N, int pos) { (N |= (1 << pos)); }

bool is_prime(int n) {
  if (n <= 1) return false;
  for (int i = 2; 1ll * i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<int> v(n);
  set<int> se;
  int i = 0;
  int now = 0, a = (1 << 30) - 1, o  = 0, xx = 0;
  for (auto &x : v) cin >> x;
  for (auto x : v) {
    a &= x;
    o |= x;
    xx ^= x;
    se.insert(x);
  }

  cout << se.size() << ' ' << o << ' ' << xx << ' ' << a << '\n';
  if (se.size() == n and is_prime(o) and is_prime(a) and is_prime(xx)) {
    cout << "OK\n";
  }
  else cout << "OHHO\n";


  return 0;
}