#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 + 9, K = 20;
int a[N], b[N], n;
pair<int, int> tree1[N][K], tree2[N][K];

int log2_floor(unsigned long long i) {
  return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

void build_a(int n) {
  for (int i = 1; i <= n; i++) {
    tree1[i][0].first = a[i];
    tree1[i][0].second = a[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      tree1[i][k].first = min(tree1[i][k - 1].first, tree1[i + (1 << (k - 1))][k - 1].first);
      tree1[i][k].second = max(tree1[i][k - 1].second, tree1[i + (1 << (k - 1))][k - 1].second);
    }
  }
}

pair<int, int> query_a(int l, int r) {
  int k = log2_floor(r - l + 1);
  return {min(tree1[l][k].first, tree1[r - (1 << k) + 1][k].first), max(tree1[l][k].second, tree1[r - (1 << k) + 1][k].second)};
}

void build_b(int n) {
  for (int i = 1; i <= n; i++) {
    tree2[i][0].first = b[i];
    tree2[i][0].second = b[i];
  }
  for (int k = 1; k < K; k++) {
    for (int i = 1; i + (1 << k) - 1 <= n; i++) {
      tree2[i][k].first = min(tree2[i][k - 1].first, tree2[i + (1 << (k - 1))][k - 1].first);
      tree2[i][k].second = max(tree2[i][k - 1].second, tree2[i + (1 << (k - 1))][k - 1].second);
    }
  }
}

pair<int, int> query_b(int l, int r) {
  int k = log2_floor(r - l + 1);
  return {min(tree2[l][k].first, tree2[r - (1 << k) + 1][k].first), max(tree2[l][k].second, tree2[r - (1 << k) + 1][k].second)};
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  build_a(n);
  build_b(n);

  vector<pair<int, int>> v;
  for (int i = 1; i <= n; i++) {
    int mn = min(query_a(1, i).first, query_b(i, n).first);
    int mx = max(query_a(1, i).second, query_b(i, n).second);
    v.push_back({mn, mx});
  }

  sort(v.begin(), v.end());

  stack<int> st;
  int id = 0;
  for (auto [l, r] : v) {
    while (!st.empty()) {
      auto top = st.top();
      if (v[top].second >= r) {
        st.pop();
      }
      else break;
    }
    st.push(id);
    id++;
  }

  vector<pair<int, int>> tmp;
  while (!st.empty()) {
    int id = st.top();
    st.pop();
    tmp.push_back(v[id]);
  }
  reverse(tmp.begin(), tmp.end());
  
  int last = 0;
  ll ans = 0;
  for (auto [l, r] : tmp) {
    int left = l - last;
    int right = (n + n) - r + 1;
    ans += 1ll * left * right;
    last = l;
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t = 1; cin >> t;
  while(t--) {
    solve();
  }

  return 0;
}