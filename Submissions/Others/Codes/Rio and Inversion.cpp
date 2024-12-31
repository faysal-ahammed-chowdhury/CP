#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5 + 9, MAXV = 105;
int a[N], tmp[N];
ll pref[N], suff[N];

// verdict: wrong answer

struct wavelet_tree {
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
  // count occurences of 'k' in range [l,r]
  int count(int l, int r, int k) {
    if (l > r || high < k || low > k) return 0;
    if (low == high) return r - l + 1;
    int mid = (low + high) >> 1;
    if (k <= mid) return lft->count(pref[l - 1] + 1, pref[r], k);
    return rgt->count(l - pref[l - 1], r - pref[r], k);
  }
  // returns the count of elements that are less than 'k' in range [l,r]
  int LT(int l, int r, int k) {
    if (l > r || low >= k) return 0;
    if (high < k) return r - l + 1;
    return lft->LT(pref[l - 1] + 1, pref[r], k) + rgt->LT(l - pref[l - 1], r - pref[r], k);
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

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    tmp[i] = a[i];
    assert(a[i] <= 100 and a[i] >= 0);
  }
  wavelet_tree t = wavelet_tree(tmp + 1, tmp + n + 1, 0, MAXV);

  for (int i = 2; i <= n; i++) {
    pref[i] = t.GT(1, i - 1, a[i]);
    pref[i] += pref[i - 1];
  }
  suff[n] = 0;
  for (int i = n - 1; i >= 1; i--) {
    suff[i] = t.LT(i + 1, n, a[i]);
    suff[i] += suff[i + 1];
  }
  ll ans = pref[n];

  int q; cin >> q;
  while (q--) {
    int type, l, r; cin >> type >> l >> r;
    l++, r++;
    if (type == 0) {
      ll cur = ans - t.LT(l + 1, r, a[l]) + t.GT(l + 1, r, a[l]) - t.GT(l + 1, r - 1, a[r]) + t.LT(l + 1, r - 1, a[r]);
      // cout << t.LT(l + 1, r, a[l]) << '\n';
      // cout << t.GT(l + 1, r, a[l]) << '\n';
      // cout << t.GT(l + 1, r - 1, a[r]) << '\n';
      // cout << t.LT(l + 1, r - 1, a[r]) << '\n';
      cout << cur << '\n';
    }
    else {
      ll cur = pref[l - 1] + suff[r + 1];
      for (int val = 0; val <= MAXV; val++) {
        int cnt = t.count(r + 1, n, val);
        cur += 1ll * t.GT(1, l - 1, val) * cnt;
      }
      cout << cur << '\n';
    }
  }

  return 0;
}