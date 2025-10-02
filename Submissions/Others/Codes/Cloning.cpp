#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 1e5 + 9, MAXV = 1e5 + 9, mod = 987654319;
int a[N], _hash[N];

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count()); // using current time as seed, so it will always generate different random values if you run this code multiple times
long long get_rand(long long l, long long r) { // random number from l to r
  assert(l <= r);
  return l + rnd() % (r - l + 1);
}

struct wavelet_tree {
  int low, high;
  wavelet_tree *lft = NULL, *rgt = NULL;
  int *pref = NULL;
  int *sum = NULL;

  wavelet_tree(int *l, int *r, int low, int high): low(low), high(high) {
    if (l >= r || low >= high) return;
    pref = new int[r - l + 2];
    sum = new int[r - l + 2];
    pref[0] = 0;
    sum[0] = 0;
    int mid = (low + high) >> 1, cnt = 1;
    for (int *i = l; i != r; i++, cnt++) {
      pref[cnt] = pref[cnt - 1] + ((*i) <= mid);
      sum[cnt] = (sum[cnt - 1] + _hash[(*i)]) % mod;
      // cout << (*i) << ' ' << _hash[(*i)] << '\n';
    }
    int *pivot = stable_partition(l, r, [&](int x) {return x <= mid;});
    lft = new wavelet_tree(l, pivot, low, mid);
    rgt = new wavelet_tree(pivot, r, mid + 1, high);
  }
  // returns the count of elements that are less than or equal to 'k' in range [l,r]
  int LTE(int l, int r, int k) {
    if (l > r || low > k) return 0;
    if (high <= k) return r - l + 1;
    return lft->LTE(pref[l - 1] + 1, pref[r], k) + rgt->LTE(l - pref[l - 1], r - pref[r], k);
  }
  // returns the count of elements that are greater than or equal to 'k' in range [l,r]
  int GTE(int l, int r, int k) {
    if (l > r || high < k) return 0;
    if (low >= k) return r - l + 1;
    return lft->GTE(pref[l - 1] + 1, pref[r], k) + rgt->GTE(l - pref[l - 1], r - pref[r], k);
  }
  // count occurences of 'k' in range [l,r]
  int count(int l, int r, int k) {
    if (l > r || high < k || low > k) return 0;
    if (low == high) return r - l + 1;
    int mid = (low + high) >> 1;
    if (k <= mid) return lft->count(pref[l - 1] + 1, pref[r], k);
    return rgt->count(l - pref[l - 1], r - pref[r], k);
  }
  long long hash_query(int l, int r, int k) {
    if (l > r || low >= k) return 0;
    // cout << "here: " << l << ' ' << r << ' ' << k << ' ' << low << ' ' << high << '\n';
    if (low == high) {
      // cout << low << ' ' << _hash[low] << '\n';
      return (1ll * (r - l + 1)) * _hash[low] % mod;
    }
    if (high < k) {
      int x = (sum[r] - sum[l - 1]) % mod;
      if (x < 0) x += mod;
      return x;
    }
    return (lft->hash_query(pref[l - 1] + 1, pref[r], k) + rgt->hash_query(l - pref[l - 1], r - pref[r], k)) % mod;
  }

  long long hash_query2(int l, int r, int k) {
    if (l > r || high <= k) return 0;
    // cout << "here: " << l << ' ' << r << ' ' << k << ' ' << low << ' ' << high << '\n';
    if (low == high) {
      // cout << low << ' ' << _hash[low] << '\n';
      return ((1ll * (r - l + 1)) * _hash[low]) % mod;
    }
    if (low > k) {
      int x = (sum[r] - sum[l - 1]) % mod;
      if (x < 0) x += mod;
      return x;
    }
    return (lft->hash_query2(pref[l - 1] + 1, pref[r], k) + rgt->hash_query2(l - pref[l - 1], r - pref[r], k)) % mod;
  }
  ~wavelet_tree() {
    if (pref != NULL) delete []pref;
    if (sum != NULL) delete []sum;
    if (lft != NULL) delete lft;
    if (rgt != NULL) delete rgt;
  }
};

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

void solve() {
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    int val = power(2, get_rand(2, mod - 1), mod);
    // int val = a[i];
    // cout << val << '\n';
    // cout << (val + val) % mod << '\n';
    // cout << (val + val + val + val) % mod << '\n';
    _hash[a[i]] = val;
  }

  wavelet_tree t = wavelet_tree(a + 1, a + n + 1, 0, MAXV + 10);
  // cout << "here: " << (t.hash_query2(1, 1, 10) ) << '\n';
  // cout << "here: " << (t.hash_query2(3, 3, 10) ) << '\n';
  // return;

  while (q--) {
    int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;

    // cout << t.hash_query(l1, r1, 14) << '\n';
    // cout << t.hash_query(l2, r2, 14) << '\n';
    // if (t.hash_query(l1, r1, 7) == t.hash_query(l2, r2, 7)) cout << "milse\n";
    // else cout << "No\n";


    int l = 0, r = 1e5 + 1, val = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      // cout << "here: " << mid << ' ' << t.hash_query(l1, r1, mid) << ' ' << t.hash_query(l2, r2, mid) << '\n';
      if (t.hash_query(l1, r1, mid) == t.hash_query(l2, r2, mid)) {
        val = mid;
        l = mid + 1;
      }
      else {
        r = mid - 1;
      }
    }

    if (val == 1e5 + 1) {
      cout << "YES\n";
    }
    else {
      // cout << "here: " << (t.hash_query2(l1, r1, 7) ) << '\n';
      // cout << "here: " << (t.hash_query2(l2, r2, 7) ) << '\n';
      int l = 0, r = 1e5 + 1, val2 = -1;
      while (l <= r) {
        int mid = (l + r) / 2;
        // cout << "here: " << ' ' << mid << ' ' << (t.hash_query2(l1, r1, mid) == t.hash_query2(l2, r2, mid)) << '\n';
        if (t.hash_query2(l1, r1, mid) == t.hash_query2(l2, r2, mid)) {
          val2 = mid;
          r = mid - 1;
        }
        else {
          l = mid + 1;
        }
      }

      // val--, val2++;
      // cout << val << ' ' << val2 << '\n';
      if (val > val2) swap(val, val2);
      int cnt1 = t.count(l1, r1, val);
      int cnt2 = t.count(l2, r2, val);
      int cnt3 = t.count(l1, r1, val2);
      int cnt4 = t.count(l2, r2, val2);

      int cnt5 = t.LTE(l1, r1, val2 - 1) - t.LTE(l1, r1, val);
      int cnt6 = t.LTE(l2, r2, val2 - 1) - t.LTE(l2, r2, val);

      // cout << cnt1 << '\n';
      // cout << cnt2 << '\n';
      // cout << cnt3 << '\n';
      // cout << cnt4 << '\n';
      // cout << cnt5 << '\n';
      // cout << cnt6 << '\n';

      bool ok = abs(cnt1 - cnt2) == 1 and abs(cnt3 - cnt4) == 1 and cnt5 == 0 and cnt6 == 0;
      if (ok) cout << "YES\n";
      else cout << "NO\n";
    }
  }
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