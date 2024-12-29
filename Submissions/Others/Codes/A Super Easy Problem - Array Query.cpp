#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9, MAXV = 1e9 + 9; // change here
int n, a[N];

struct wavelet_tree { ///1 indexed
  int low, high;
  wavelet_tree *lft = NULL, *rgt = NULL;
  int *pref = NULL;
  long long *sum = NULL;

  wavelet_tree(int *l, int *r, int low, int high): low(low), high(high) {
    if (l >= r || low >= high)return;
    pref = new int[r - l + 2];
    sum = new long long[r - l + 2];
    pref[0] = 0;
    sum[0] = 0;
    int mid = (low + high) >> 1, cnt = 1;
    for (int *i = l; i != r; i++, cnt++) {
      pref[cnt] = pref[cnt - 1] + ((*i) <= mid);
      sum[cnt] = sum[cnt - 1] + (*i);
    }
    int *pivot = stable_partition(l, r, [&](int x) {return x <= mid;});
    lft = new wavelet_tree(l, pivot, low, mid);
    rgt = new wavelet_tree(pivot, r, mid + 1, high);
  }
  int LT(int l, int r, ll k) { ///Returns the count of elements that are less than 'k' in range [l,r]
    if (l > r || low >= k)return 0;
    if (high < k)return r - l + 1;
    return lft->LT(pref[l - 1] + 1, pref[r], k) + rgt->LT(l - pref[l - 1], r - pref[r], k);
  }
  int GT(int l, int r, ll k) {///Returns the count of elements that are greater than 'k' in range [l,r]
    if (l > r || high <= k)return 0;
    if (low > k)return r - l + 1;
    return lft->GT(pref[l - 1] + 1, pref[r], k) + rgt->GT(l - pref[l - 1], r - pref[r], k);
  }

  long long sum1(int l, int r, ll k) { //Returns the sum of elements less than 'k' in range [l,r]
    if (l > r || low >= k)return 0;
    if (low == high)return 1LL * (r - l + 1) * low;
    if (high < k)return sum[r] - sum[l - 1];
    return lft->sum1(pref[l - 1] + 1, pref[r], k) + rgt->sum1(l - pref[l - 1], r - pref[r], k);
  }
  long long sum2(int l, int r, ll k) { //Returns the sum of elements greater than 'k' in range [l,r]
    if (l > r || high <= k)return 0;
    if (low == high)return 1LL * (r - l + 1) * low;
    if (low > k)return sum[r] - sum[l - 1];
    return lft->sum2(pref[l - 1] + 1, pref[r], k) + rgt->sum2(l - pref[l - 1], r - pref[r], k);
  }

  ~wavelet_tree() {
    if (pref != NULL)delete []pref;
    if (sum != NULL)delete []sum;
    if (lft != NULL)delete lft;
    if (rgt != NULL)delete rgt;
  }
};

int cs;
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  wavelet_tree t = wavelet_tree(a + 1, a + n + 1, -MAXV, MAXV);
  int q; cin >> q;
  cout << "Case " << ++cs << ":\n";
  while (q--) {
    int l, r; ll x; cin >> l >> r >> x;
    ll sum1 = t.sum1(l, r, x);
    ll sum2 = t.sum2(l, r, x);
    int cnt1 = t.LT(l, r, x);
    int cnt2 = t.GT(l, r, x);
    ll ans1 = (1ll * cnt1 * x) - sum1;
    ll ans2 = sum2 - (1ll * cnt2 * x);
    cout << ans1 + ans2  << '\n';
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