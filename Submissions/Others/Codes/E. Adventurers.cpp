#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9, MAXV = 1e9;
pair<int, int> a[N];
int n, b[N];

//array values can be negative too, use appropriate minimum and maximum value
struct wavelet_tree { 
  int lo, hi;
  wavelet_tree *l, *r;
  int *b, bsz;

  wavelet_tree() {
    lo = 1;
    hi = 0;
    bsz = 0;
    l = NULL;
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
    for (auto it = from; it != to; it++) {
      b[bsz] = (b[bsz - 1] + f(*it));
      bsz++;
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
  //count of numbers in [l, r] Greater than k
  int GT(int l, int r, int k) {
    if (l > r || k >= hi) return 0;
    if (lo > k) return r - l + 1;
    int lb = b[l - 1], rb = b[r];
    return this->l->GT(lb + 1, rb, k) + this->r->GT(l - lb, r - rb, k);
  }
  ~wavelet_tree() {
    delete l;
    delete r;
  }
} t;

int xx, yy;

bool ok(int k) {
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
  t.init(b + 1, b + n + 1, -MAXV, MAXV);

  int l = 0, r = n / 4, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) {
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