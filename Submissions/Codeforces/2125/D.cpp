#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 998244353;
template <const int32_t MOD>
struct modint {
  int32_t value;
  modint() = default;
  modint(int32_t value_) : value(value_) {}
  inline modint<MOD> operator + (modint<MOD> other) const { int32_t c = this->value + other.value; return modint<MOD>(c >= MOD ? c - MOD : c); }
  inline modint<MOD> operator - (modint<MOD> other) const { int32_t c = this->value - other.value; return modint<MOD>(c <    0 ? c + MOD : c); }
  inline modint<MOD> operator * (modint<MOD> other) const { int32_t c = (int64_t)this->value * other.value % MOD; return modint<MOD>(c < 0 ? c + MOD : c); }
  inline modint<MOD> & operator += (modint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
  inline modint<MOD> & operator -= (modint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
  inline modint<MOD> & operator *= (modint<MOD> other) { this->value = (int64_t)this->value * other.value % MOD; if (this->value < 0) this->value += MOD; return *this; }
  inline modint<MOD> operator - () const { return modint<MOD>(this->value ? MOD - this->value : 0); }
  modint<MOD> pow(uint64_t k) const { modint<MOD> x = *this, y = 1; for (; k; k >>= 1) { if (k & 1) y *= x; x *= x; } return y; }
  modint<MOD> inv() const { return pow(MOD - 2); }  // MOD must be a prime
  inline modint<MOD> operator /  (modint<MOD> other) const { return *this *  other.inv(); }
  inline modint<MOD> operator /= (modint<MOD> other)       { return *this *= other.inv(); }
  inline bool operator == (modint<MOD> other) const { return value == other.value; }
  inline bool operator != (modint<MOD> other) const { return value != other.value; }
  inline bool operator < (modint<MOD> other) const { return value < other.value; }
  inline bool operator > (modint<MOD> other) const { return value > other.value; }
};
template <int32_t MOD> modint<MOD> operator * (int64_t value, modint<MOD> n) { return modint<MOD>(value) * n; }
template <int32_t MOD> modint<MOD> operator * (int32_t value, modint<MOD> n) { return modint<MOD>(value % MOD) * n; }
template <int32_t MOD> istream & operator >> (istream & in, modint<MOD> &n) { return in >> n.value; }
template <int32_t MOD> ostream & operator << (ostream & out, modint<MOD> n) { return out << n.value; }

using mint = modint<mod>;

const int N = 2e5 + 9, inf = 1e9;
array<mint, 4> a[N];
int nxt[N];
mint pref[N];
int dp[N];
int n, m;

int power(int x, long long n, int mod) {
  int ans = 1 % mod;
  while (n > 0) {
    if (n & 1) {
      ans = 1LL * ans * x % mod;
    }
    x = 1LL * x * x % mod;
    n >>= 1;
  }
  return ans;
}

int f(int i) {
  if (i > n) return 1;
  if (dp[i] != -1) return dp[i];
  mint ans = 0;
  if (i + 1 <= n and a[i][0] == a[i + 1][0]) {
    ans += ((a[i][3] - a[i][2]) / a[i][3]) * f(i + 1);
  }
  if (a[i][1] == m) {
    ans += (a[i][2] / a[i][3]) * (pref[n] / pref[i]);
    return dp[i] = (ans.value);
  }
  if (nxt[i] != -1) {
    int idx = nxt[i];
    ans += (a[i][2] / a[i][3]) * (pref[idx - 1] / pref[i]) * f(idx);
  }

  return dp[i] = ans.value;
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3];
  }
  sort(a + 1, a + n + 1);

  for (int i = n; i >= 1; i--) {
    nxt[i] = -1;
    array<mint, 4> x = {a[i][1] + 1, -inf, -inf, inf};
    auto it = upper_bound(a + 1, a + n + 1, x);
    if (it != (a + n + 1) and a[i][1] + 1 == (*it)[0]) {
      auto idx = it - a;
      nxt[i] = idx;
    }
  }

  pref[0] = 1;
  for (int i = 1; i <= n; i++) {
    pref[i] = pref[i - 1] * ((a[i][3] - a[i][2]) / a[i][3]);
  }

  if (a[1][0] > 1) {
    cout << 0 << '\n';
    return 0;
  }

  memset(dp, -1, sizeof dp);
  cout << f(1) << '\n';

  return 0;
}