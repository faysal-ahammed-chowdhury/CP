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
  if (n == 1) {
    cout << 2 << '\n';
    return 0;
  }
  if (n == 2) {
    cout << 2 << ' ' << 7 << '\n';
    return 0;
  }
  vector<int> v;
  for (int i = 0; i < n - 1; i++) {
    v.push_back(i + 1);
  }
  int a = (1 << 30) - 1, o  = 0, xx = 0;
  unordered_set<int> se;
  for (int i = 0; i < n - 1; i++) {
    int x = v[i];
    x <<= 1;
    if (CHECK(x, 1)) SET(x, 0);
    SET(x, 1);
    v[i] = x;
    a &= v[i];
    o |= v[i];
    xx ^= v[i];
    se.insert(v[i]);
  }

  for (int i = 0; i < (1 << 21); i++) {
    if (se.find(i) == se.end() and is_prime(o | i) and is_prime(a & i) and is_prime(xx ^ i)) {
      v.push_back(i);
      a &= i;
      o |= i;
      xx ^= i;
      break;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << v[i];
    if (i != n - 1) cout << ' ';
  }
  cout << '\n';

  return 0;
}