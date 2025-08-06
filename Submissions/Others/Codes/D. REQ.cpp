#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int mod = 1e9 + 7;
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

const int N = 2e5 + 9, MAXV = 1e6 + 9;
int a[N];
vector<pair<int, int>> Q[N];
mint ans[N], pref[N];
int spf[MAXV];

void spf_sieve() {
  for (int i = 2; i < MAXV; i++) {
    spf[i] = i;
  }
  for (int i = 2; i < MAXV; i++) {
    if (spf[i] == i) {
      for (int j = i; j < MAXV; j += i) {
        spf[j] = min(spf[j], i);
      }
    }
  }
}

struct ST {
  mint tree[4 * N];
  void build(int n, int b, int e) {
    if (b == e) {
      tree[n] = 1;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    tree[n] = tree[l] * tree[r];
  }
  void upd(int n, int b, int e, int i, mint x) {
    if (b > i || e < i) return;
    if (b == e && b == i) {
      tree[n] *= x;
      return;
    }
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    upd(l, b, mid, i, x);
    upd(r, mid + 1, e, i, x);
    tree[n] = tree[l] * tree[r];
  }
  mint query(int n, int b, int e, int i, int j) {
    if (b > j || e < i) return 1;
    if (b >= i && e <= j) return tree[n];
    int mid = (b + e) >> 1, l = n << 1, r = l + 1;
    mint L = query(l, b, mid, i, j);
    mint R = query(r, mid + 1, e, i, j);
    return (L * R);
  }
} st;

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  spf_sieve();

  int n; cin >> n;
  pref[0] = 1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref[i] = pref[i - 1] * a[i];
  }

  int q; cin >> q;
  for (int i = 1; i <= q; i++) {
    int l, r; cin >> l >> r;
    Q[r].push_back({l, i});
  }

  st.build(1, 1, n);

  map<int, int> last_idx;
  for (int r = 1; r <= n; r++) {
    int x = a[r];
    while (x > 1) {
      mint p = spf[x];
      while (x % p.value == 0) {
        x /= p.value;
      }

      mint val = (p - 1) / p;
      if (last_idx.find(p.value) != last_idx.end()) {
        mint tmp = 1; tmp /= val;
        st.upd(1, 1, n, last_idx[p.value], tmp);
      }

      last_idx[p.value] = r;
      st.upd(1, 1, n, r, val);
    }

    for (auto i : Q[r]) {
      int l = i.first, id = i.second;
      ans[id] = st.query(1, 1, n, l, r) * (pref[r] / pref[l - 1]);
    }
  }

  for (int i = 1; i <= q; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}