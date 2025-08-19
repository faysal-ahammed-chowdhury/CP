#include <bits/stdc++.h>
using namespace std;

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

const int N = 5e5 + 9;
int a[N];

struct ST {
  mint tree[4 * N], lazy1[4 * N], lazy2[4 * N];
  void push(int n, int b, int e) {
    if (lazy1[n] == 1 or lazy2[n] == 0) return;
    tree[n] = tree[n] * lazy1[n] + lazy2[n] * (e - b + 1);
    if (b != e) {
      int mid = (b + e) >> 1, l = n << 1, r = l + 1;
      lazy1[l] *= lazy1[n];
      lazy2[l] = lazy2[l] * lazy1[n] + lazy2[n];
      lazy1[r] *= lazy1[n];
      lazy2[r] = lazy2[r] * lazy1[n] + lazy2[n];
    }
    lazy1[n] = 1;
    lazy2[n] = 0;
  }

  void build(int n, int  b, int e) {
    lazy1[n] = 1;
    lazy2[n] = 0;
    if (b == e) {
      tree[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] + tree[r];
  }
  void upd(int n, int b, int e, int i, int j, int x, int y) {
    push(n, b, e);
    if (b > j || e < i) return;
    if (b >= i && e <= j) {
      lazy1[n] *= x;
      lazy2[n] += y;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, j, x, y);
    upd(r, mid + 1, e, i, j, x, y);
    tree[n] = tree[l] + tree[r];
  }
  mint query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    mint L = query(l, b, mid, i, j);
    mint R = query(r, mid + 1, e, i, j);
    return L + R;
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  st.build(1, 1, n);
  while (q--) {
    int type, l, r; cin >> type >> l >> r;
    l++;
    if (type == 0) {
      int x, y; cin >> x >> y;
      st.upd(1, 1, n, l, r, x, y);
    }
    else {
      cout << st.query(1, 1, n, l, r) << '\n';
    }
  }

  return 0;
}