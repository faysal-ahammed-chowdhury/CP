#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9;
int pi1[N], pi2[N], pi1_left[N], pi1_right[N], pi2_left[N], pi2_right[N];

int power(long long n, long long k, const int mod) {
  int ans = 1 % mod;
  n %= mod;
  if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

const int MOD1 = 127657753, MOD2 = 987654319;
const int p1 = 137, p2 = 277;
int ip1, ip2;
pair<int, int> pw[N], ipw[N];
void prec() {
  pw[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    pw[i].first = 1ll * pw[i - 1].first * p1 % MOD1;
    pw[i].second = 1ll * pw[i - 1].second * p2 % MOD2;
  }
  ip1 = power(p1, MOD1 - 2, MOD1);
  ip2 = power(p2, MOD2 - 2, MOD2);
  ipw[0] = {1, 1};
  for (int i = 1; i < N; i++) {
    ipw[i].first = 1ll * ipw[i - 1].first * ip1 % MOD1;
    ipw[i].second = 1ll * ipw[i - 1].second * ip2 % MOD2;
  }
}

struct Hashing {
  int n;
  string s;
  vector<pair<int, int>> hash_val;
  vector<pair<int, int>> rev_hash_val;
  Hashing() {}
  Hashing(string _s) {
    s = _s;
    n = s.size();
    hash_val.emplace_back(0, 0);
    for (int i = 0; i < n; i++) {
      pair<int, int> p;
      p.first = (hash_val[i].first + 1ll * s[i] * pw[i].first % MOD1) % MOD1;
      p.second = (hash_val[i].second + 1ll * s[i] * pw[i].second % MOD2) % MOD2;
      hash_val.push_back(p);
    }
    rev_hash_val.emplace_back(0, 0);
    for (int i = 0, j = n - 1; i < n; i++, j--) {
      pair<int, int> p;
      p.first = (rev_hash_val[i].first + 1ll * s[i] * pw[j].first % MOD1) % MOD1;
      p.second = (rev_hash_val[i].second + 1ll * s[i] * pw[j].second % MOD2) % MOD2;
      rev_hash_val.push_back(p);
    }
  }

  pair<int, int> get_hash(int l, int r) { // 1 indexed
    pair<int, int> ans;
    ans.first = (hash_val[r].first - hash_val[l - 1].first + MOD1) * 1ll * ipw[l - 1].first % MOD1;
    ans.second = (hash_val[r].second - hash_val[l - 1].second + MOD2) * 1ll * ipw[l - 1].second % MOD2;
    return ans;
  }
  pair<int, int> rev_hash(int l, int r) { // 1 indexed
    pair<int, int> ans;
    ans.first = (rev_hash_val[r].first - rev_hash_val[l - 1].first + MOD1) * 1ll * ipw[n - r].first % MOD1;
    ans.second = (rev_hash_val[r].second - rev_hash_val[l - 1].second + MOD2) * 1ll * ipw[n - r].second % MOD2;
    return ans;
  }
  pair<int, int> get_hash() { // 1 indexed
    return get_hash(1, n);
  }
  bool is_palindrome(int l, int r) {
    return get_hash(l, r) == rev_hash(l, r);
  }
};

//array values can be negative too, use appropriate minimum and maximum value
struct wavelet_tree {
  int lo, hi;
  wavelet_tree *l, *r;
  int *b, bsz, csz; 
  ll *c; 

  wavelet_tree() {
    lo = 1;
    hi = 0;
    bsz = 0;
    csz = 0, l = NULL;
    r = NULL;
  }

  void init(int *from, int *to, int x, int y) {
    lo = x, hi = y;
    if (from >= to) return;
    int mid = (lo + hi) >> 1;
    auto f = [mid](int x) {
      return x <= mid;
    };
    b = (int*)malloc((to - from + 2) * sizeof(int));
    bsz = 0;
    b[bsz++] = 0;
    c = (ll*)malloc((to - from + 2) * sizeof(ll));
    csz = 0;
    c[csz++] = 0;
    for (auto it = from; it != to; it++) {
      b[bsz] = (b[bsz - 1] + f(*it));
      c[csz] = (c[csz - 1] + (*it));
      bsz++;
      csz++;
    }
    if (hi == lo) return;
    auto pivot = stable_partition(from, to, f);
    l = new wavelet_tree();
    l->init(from, pivot, lo, mid);
    r = new wavelet_tree();
    r->init(pivot, to, mid + 1, hi);
  }
  //kth smallest element in [l, r]
  //for array [1,2,1,3,5] 2nd smallest is 1 and 3rd smallest is 2
  int kth(int l, int r, int k) {
    if (l > r) return 0;
    if (lo == hi) return lo;
    int inLeft = b[r] - b[l - 1], lb = b[l - 1], rb = b[r];
    if (k <= inLeft) return this->l->kth(lb + 1, rb, k);
    return this->r->kth(l - lb, r - rb, k - inLeft);
  }
  //count of numbers in [l, r] Less than or equal to k
  int LTE(int l, int r, int k) {
    if (l > r || k < lo) return 0;
    if (hi <= k) return r - l + 1;
    int lb = b[l - 1], rb = b[r];
    return this->l->LTE(lb + 1, rb, k) + this->r->LTE(l - lb, r - rb, k);
  }
  //count of numbers in [l, r] Greater than k
  int GT(int l, int r, int k) {
    if (l > r || k >= hi) return 0;
    if (lo > k) return r - l + 1;
    int lb = b[l - 1], rb = b[r];
    return this->l->GT(lb + 1, rb, k) + this->r->GT(l - lb, r - rb, k);
  }
  //count of numbers in [l, r] equal to k
  int count(int l, int r, int k) {
    if (l > r || k < lo || k > hi) return 0;
    if (lo == hi) return r - l + 1;
    int lb = b[l - 1], rb = b[r];
    int mid = (lo + hi) >> 1;
    if (k <= mid) return this->l->count(lb + 1, rb, k);
    return this->r->count(l - lb, r - rb, k);
  }
  //sum of numbers in [l ,r] less than or equal to k
  ll sum(int l, int r, int k) {
    if (l > r or k < lo) return 0;
    if (hi <= k) return c[r] - c[l - 1];
    int lb = b[l - 1], rb = b[r];
    return this->l->sum(lb + 1, rb, k) + this->r->sum(l - lb, r - rb, k);
  }
  ~wavelet_tree() {
    delete l;
    delete r;
  }
} t1, t2, t3, t4;

ll f(int x) {
  return (1ll * x * (x + 1)) / 2;
}

ll f(int l, int r) {
  if (l > r) return 0;
  return f(r) - f(l - 1);
}

string s;
Hashing hash_s;
int n;

bool ok(int l, int r) {
  return hash_s.is_palindrome(l, r);
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  prec(); // must include

  cin >> s;
  n = s.size();
  hash_s = Hashing(s);

  for (int i = 1; i <= n; i++) {
    int l = 0, r = min(n - i, i - 1), cnt = 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ok(i - mid, i + mid)) {
        cnt = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }
    pi1[i] = cnt + 1;
    pi1_left[i] = pi1[i] - i;
    pi1_right[i] = i + pi1[i];
  }
  for (int i = 2; i <= n; i++) {
    if (s[i - 1] == s[i - 2]) {
      int l = 0, r = min(n - i, i - 1), cnt = 2;
      while (l <= r) {
        int mid = (l + r) >> 1;
        if (ok(i - 1 - mid, i + mid)) {
          cnt = mid;
          l = mid + 1;
        }
        else {
          r = mid - 1;
        }
      }
      pi2[i] = cnt + 1;
    }
    else pi2[i] = 0;

    pi2_left[i] = pi2[i] - i;
    pi2_right[i] = i + pi2[i];
  }

  // for (int i = 1; i <= n; i++) {
  //   cout << pi1[i] << ' ';
  // }
  // cout << '\n';
  // for (int i = 1; i <= n; i++) {
  //   cout << pi2[i] << ' ';
  // }
  // cout << '\n';
  // return 0;

  t1.init(pi1_left + 1, pi1_left + n + 1, -N, N);
  t2.init(pi1_right + 1, pi1_right + n + 1, -N, N);
  t3.init(pi2_left + 1, pi2_left + n + 1, -N, N);
  t4.init(pi2_right + 1, pi2_right + n + 1, -N, N);

  int q; cin >> q;
  while (q--) {
    int l, r; cin >> l >> r;
    // define k, find cnt > k and summation whose are <= k; this can be done by wavelet tree
    int m = (l + r) / 2;
    int k = 1 - l;
    ll ans = f(l, m);
    ans += t1.sum(l, m, k);
    int cnt = t1.GT(l, m, k);
    ans += 1ll * k * cnt;

    k = 1 + r;
    ans += -f(m + 1, r);
    ans += t2.sum(m + 1, r, k);
    cnt = t2.GT(m + 1, r, k);
    ans += 1ll * k * cnt;

    if (l + 1 <= m) { // a bit different than others
      k = -l;
      ans += f(l + 1, m);
      ans += t3.sum(l + 1, m, k);
      cnt = t3.GT(l + 1, m, k);
      ans += 1ll * k * cnt;
    }

    k = 1 + r;
    ans += -f(m + 1, r);
    ans += t4.sum(m + 1, r, k);
    cnt = t4.GT(m + 1, r, k);
    ans += 1ll * k * cnt;

    cout << ans << '\n';
  }

  return 0;
}