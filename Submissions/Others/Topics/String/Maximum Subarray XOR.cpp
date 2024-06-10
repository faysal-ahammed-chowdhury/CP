#include <bits/stdc++.h>
using namespace std;

struct Trie {
  static const int K = 31; // bit size
  struct node {
    node *nxt[2]; // 0, 1
    int sz;
    node() {
      nxt[0] = NULL, nxt[1] = NULL;
      sz = 0;
    }
  } *root;
  Trie() {
    root = new node();
  }
  void insert(int x) {
    node *cur = root;
    for (int i = K - 1; i >= 0; i--) {
      int k = (x >> i) & 1; // ith bit
      if (cur -> nxt[k] == NULL) cur -> nxt[k] = new node();
      cur = cur -> nxt[k];
      cur -> sz++;
    }
  }
  int query(int x, int k) { // number of values s.t. val ^ x < k
    node* cur = root;
    int ans = 0;
    for (int i = K - 1; i >= 0; i--) {
      if (cur == NULL) break;
      int b1 = x >> i & 1, b2 = k >> i & 1;
      if (b2 == 1) {
        if (cur -> nxt[b1]) ans += cur -> nxt[b1] -> sz;
        cur = cur -> nxt[!b1];
      } else cur = cur -> nxt[b1];
    }
    return ans;
  }
  int get_max(int x) { // returns maximum of val ^ x
    node *cur = root;
    int ans = 0;
    for (int i = K - 1; i >= 0; i--) {
      int k = (x >> i) & 1; // ith bit
      if (cur -> nxt[!k] != NULL) {
        ans += (1 << i);
        cur = cur -> nxt[!k];
      }
      else {
        cur = cur -> nxt[k];
      }
    }
    return ans;
  }
  int get_min(int x) { // returns minimum of val ^ x
    node *cur = root;
    int ans = 0;
    for (int i = K - 1; i >= 0; i--) {
      int k = (x >> i) & 1; // ith bit
      if (cur -> nxt[k] != NULL) {
        cur = cur -> nxt[k];
      }
      else {
        ans += (1 << i);
        cur = cur -> nxt[!k];
      }
    }
    return ans;
  }
};

void solve() {
  int n; cin >> n;
  int a[n + 1];
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  Trie trie;
  for (int i = 1; i <= n; i++) {
    a[i] = a[i - 1] ^ a[i];
    trie.insert(a[i]);
  }

  int ans = 0;
  for (int i = 0; i <= n; i++) {
    ans = max(ans, trie.get_max(a[i]));
    cout << i << ' ' << trie.get_max(a[i]) << '\n';
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}