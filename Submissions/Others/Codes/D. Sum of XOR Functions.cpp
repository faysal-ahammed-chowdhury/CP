#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool CHECK(int N, int pos) { return (bool)(N & (1ll << pos)); }
void SET(int &N, int pos) { (N |= (1ll << pos)); }
void CLR(int &N, int pos) { (N &= ~(1ll << pos)); }

const int N = 3e5 + 9, mod = 998244353;
int n, a[N], b[N];

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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  mint ans = 0;
  for (int k = 0; k <= 30; k++) {
    for (int i = 1; i <= n; i++) {
      b[i] = CHECK(a[i], k);
    }

    int cur = 0;
    mint tmp = 0;
    mint even = 0, odd = 0;
    mint even_cnt = 0, odd_cnt = 0;
    mint even_for_1 = 0, odd_for_1 = 0;
    mint even_cnt_for_1 = 0, odd_cnt_for_1 = 0;
    for (int i = 1; i <= n; i++) {
      if (b[i] == 1) cur++;

      if (cur % 2 == 0) {
        even_cnt += 1;
        even += i;
        tmp += (odd_cnt * i) - odd + odd_cnt;

        if (b[i]) {
          even_cnt_for_1 += 1;
          even_for_1 += i;
        }

        tmp -= (odd_cnt_for_1 * i) - odd_for_1 + odd_cnt_for_1;
        tmp += (even_cnt_for_1 * i) - even_for_1 + even_cnt_for_1;
      }
      else {
        odd_cnt += 1;
        odd += i;
        tmp += (even_cnt * i) - even + even_cnt;

        if (b[i]) {
          odd_cnt_for_1 += 1;
          odd_for_1 += i;
        }

        tmp -= (even_cnt_for_1 * i) - even_for_1 + even_cnt_for_1;
        tmp += (odd_cnt_for_1 * i) - odd_for_1 + odd_cnt_for_1;
      }

    }

    ans += tmp * power(2, k, mod);
  }

  cout << ans << '\n';

  return 0;
}