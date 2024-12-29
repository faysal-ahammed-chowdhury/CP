#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, MAXV = 1e9;
pair<int, int> a[N];
int n, b[N];

struct wavelet_tree { // rawaha bhai
  int low, high;
  wavelet_tree *lft = NULL, *rgt = NULL;
  int *pref = NULL;

  wavelet_tree(int *l, int *r, int low, int high): low(low), high(high) {
    if (l >= r || low >= high) return;
    pref = new int[r - l + 2];
    pref[0] = 0;
    int mid = (low + high) >> 1, cnt = 1;
    for (int *i = l; i != r; i++, cnt++) {
      pref[cnt] = pref[cnt - 1] + ((*i) <= mid);
    }
    int *pivot = stable_partition(l, r, [&](int x) {return x <= mid;});
    lft = new wavelet_tree(l, pivot, low, mid);
    rgt = new wavelet_tree(pivot, r, mid + 1, high);
  }
  // returns the k'th smallest element in range [l,r]  //act like multiset
  int kth(int l, int r, int k) {
    if (l > r) return 0;
    if (low == high) return low;
    int lftCount = pref[r] - pref[l - 1];
    if (lftCount >= k) return lft->kth(pref[l - 1] + 1, pref[r], k);
    return rgt->kth(l - pref[l - 1], r - pref[r], k - lftCount);
  }
  // returns the count of elements that are greater than 'k' in range [l,r]
  int GT(int l, int r, int k) {
    if (l > r || high <= k) return 0;
    if (low > k) return r - l + 1;
    return lft->GT(pref[l - 1] + 1, pref[r], k) + rgt->GT(l - pref[l - 1], r - pref[r], k);
  }
  ~wavelet_tree() {
    if (pref != NULL) delete []pref;
    if (lft != NULL) delete lft;
    if (rgt != NULL) delete rgt;
  }
};

int xx, yy;

bool ok(int k, wavelet_tree &t) {
  int x, y;
  for (int i = k + k + 1; i + k + k - 1 <= n; i++) {
    x = a[i].first;
    y = t.kth(1, i - 1, k);
    y = max(y, t.kth(i, n, k));

    int cnt1 = t.GT(1, i - 1, y);
    int cnt2 = t.GT(i, n, y);

    if (cnt1 >= k and cnt2 >= k and a[i].first > a[i - 1].first) {
      xx = x;
      yy = max(t.kth(1, i - 1, k) + 1, t.kth(i, n, k) + 1);
      return true;
    }
  }
  return false;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    // cout << "(" << a[i].first << ',' << a[i].second << ")" << '\n';
    b[i] = a[i].second;
  }
  wavelet_tree t = wavelet_tree(b + 1, b + n + 1, -MAXV, MAXV);

  int l = 0, r = n / 4, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid, t)) {
      ans = mid;
      l = mid + 1;
    }
    else r = mid - 1;
  }
  cout << ans << '\n';
  cout << xx << ' ' << yy << '\n';
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