#include<bits/stdc++.h>
using namespace std;

const int N = 3e5 + 9, MAXV = 1e9 + 9; // change here
int a[N];

struct wavelet_tree {
  int low, high;
  wavelet_tree *lft = NULL, *rgt = NULL;
  int *pref = NULL;
  long long *sum = NULL;

  wavelet_tree(int *l, int *r, int low, int high): low(low), high(high) {
    if (l >= r || low >= high) return;
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
  // swaps the elements at index 'idx' and 'idx+1'
  void swap_adjacent(int idx) {
    if (low == high)return;
    int firstBit = pref[idx] - pref[idx - 1];
    sum[idx] = sum[idx - 1] + sum[idx + 1] - sum[idx];
    if (firstBit == (pref[idx + 1] - pref[idx])) {
      if (firstBit) lft->swap_adjacent(pref[idx]);
      else rgt->swap_adjacent(idx - pref[idx]);
    }
    else {
      if (firstBit) pref[idx]--;
      else pref[idx]++;
    }
  }
  // count occurences of 'k' in range [l,r]
  int count(int l, int r, int k) {
    if (l > r || high < k || low > k) return 0;
    if (low == high) return r - l + 1;
    int mid = (low + high) >> 1;
    if (k <= mid) return lft->count(pref[l - 1] + 1, pref[r], k);
    return rgt->count(l - pref[l - 1], r - pref[r], k);
  }
  // returns the k'th smallest element in range [l,r]  //act like multiset
  int kth(int l, int r, int k) {
    if (l > r) return 0;
    if (low == high) return low;
    int lftCount = pref[r] - pref[l - 1];
    if (lftCount >= k) return lft->kth(pref[l - 1] + 1, pref[r], k);
    return rgt->kth(l - pref[l - 1], r - pref[r], k - lftCount);
  }
  // returns the count of elements that are less than or equal to 'k' in range [l,r]
  int LTE(int l, int r, int k) {
    if (l > r || low > k) return 0;
    if (high <= k) return r - l + 1;
    return lft->LTE(pref[l - 1] + 1, pref[r], k) + rgt->LTE(l - pref[l - 1], r - pref[r], k);
  }
  // returns the sum of elements less than 'k' in range [l,r]
  long long sum_query(int l, int r, int k) {
    if (l > r || low >= k) return 0;
    if (low == high) return 1LL * (r - l + 1) * low;
    if (high < k) return sum[r] - sum[l - 1];
    return lft->sum_query(pref[l - 1] + 1, pref[r], k) + rgt->sum_query(l - pref[l - 1], r - pref[r], k);
  }
  ~wavelet_tree() {
    if (pref != NULL) delete []pref;
    if (sum != NULL) delete []sum;
    if (lft != NULL) delete lft;
    if (rgt != NULL) delete rgt;
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  wavelet_tree t = wavelet_tree(a + 1, a + n + 1, -MAXV, MAXV);

  return 0;
}