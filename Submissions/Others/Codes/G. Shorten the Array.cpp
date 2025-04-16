#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Trie {
  static const int K = 31; // bit size
  struct TrieNode {
    TrieNode *nxt[2]; // 0, 1
    int cnt, idx[2];
    TrieNode() {
      nxt[0] = NULL, nxt[1] = NULL;
      cnt = 0;
    }
  } *root;
  Trie() {
    root = new TrieNode();
  }
  void insert(int x, int idx) {
    TrieNode *cur = root;
    for (int i = K - 1; i >= 0; i--) {
      int k = (x >> i) & 1; // ith bit
      if (cur -> nxt[k] == NULL) cur -> nxt[k] = new TrieNode();
      cur = cur -> nxt[k];
      cur -> cnt++;
      cur -> idx[k] = idx;
    }
  }
  void rem(TrieNode *cur, int x, int pos) { // free :: De Alloactes Memory
    if (pos < 0) return;
    int k = (x >> pos) & 1; // pos'th bit
    rem(cur -> nxt[k], x, pos - 1);
    cur -> nxt[k] -> cnt--;
    if (cur -> nxt[k] -> cnt == 0) {
      free(cur -> nxt[k]);
      cur -> nxt[k] = NULL;
    }
  }
  int get(int x, int y) { // returns maximum idx where val ^ x >= y
    TrieNode *cur = root;
    int idx = -1, idx2 = -1;
    bool flag = false;
    for (int i = K - 1; i >= 0; i--) {
      int k = (x >> i) & 1; // ith bit
      int kk = (y >> i) & 1; // ith bit
      if (kk == 0) {
        if (cur -> nxt[!k] != NULL) {
          TrieNode *tmp = cur -> nxt[!k];
          idx2 = max(idx2, tmp -> idx[!k]);
        }
        if (cur -> nxt[k] != NULL) {
          cur = cur -> nxt[k];
          idx = cur -> idx[k];
        }
      }
      else {
        if (cur -> nxt[!k] != NULL) {
          cur = cur -> nxt[!k];
          idx = cur -> idx[!k];
        }
        else {
          flag = true;
          break;
        }
      }
    }
    if (flag) idx = -1;
    return max(idx, idx2);
  }
  void del(TrieNode* cur) {
    for (int i = 0; i < 2; i++) if (cur -> nxt[i]) del(cur -> nxt[i]);
    delete(cur);
  }
};

void solve() {
  int n, k; cin >> n >> k;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  Trie trie;

  int ans = 1e9;
  for (int i = 1; i <= n; i++) {
    trie.insert(a[i], i);
    int j = trie.get(a[i], k);
    // cout << j << ' ' << i << '\n';
    if (j != -1) ans = min(ans, i - j + 1);
  }

  if (ans >= 1e9) ans = -1;
  cout << ans << '\n';

  trie.del(trie.root); // clear try
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