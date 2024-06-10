#include <bits/stdc++.h>
using namespace std;

struct Trie {
  static const int K = 31; // bit size
  struct TrieNode {
    TrieNode *nxt[2]; // 0, 1
    int cnt;
    TrieNode() {
      nxt[0] = NULL, nxt[1] = NULL;
      cnt = 0;
    }
  } *root;
  Trie() {
    root = new TrieNode();
  }
  void insert(int x) {
    TrieNode *cur = root;
    for (int i = K - 1; i >= 0; i--) {
      int k = (x >> i) & 1; // ith bit
      if (cur -> nxt[k] == NULL) cur -> nxt[k] = new TrieNode();
      cur = cur -> nxt[k];
      cur -> cnt++;
    }
  }
  int query(int x, int k) { // number of values s.t. val ^ x < k
    TrieNode* cur = root;
    int ans = 0;
    for (int i = K - 1; i >= 0; i--) {
      if (cur == NULL) break;
      int b1 = x >> i & 1, b2 = k >> i & 1;
      if (b2 == 1) {
        if (cur -> nxt[b1]) ans += cur -> nxt[b1] -> cnt;
        cur = cur -> nxt[!b1];
      } else cur = cur -> nxt[b1];
    }
    return ans;
  }
  int get_max(int x) { // returns maximum of val ^ x
    TrieNode *cur = root;
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
    TrieNode *cur = root;
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
  void del(TrieNode* cur) {
    for (int i = 0; i < 2; i++) if (cur -> nxt[i]) del(cur -> nxt[i]);
    delete(cur);
  }
};

int cs;
void solve() {
  int n; cin >> n;
  int a[n + 1], pref_xor[n + 1];
  pref_xor[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pref_xor[i] = pref_xor[i - 1] ^ a[i];
  }
  Trie trie; // init new trie
  trie.insert(0);
  int ans1 = 0, ans2 = 2e9;
  for (int i = 1; i <= n; i++) {
    ans1 = max(ans1, trie.get_max(pref_xor[i]));
    ans2 = min(ans2, trie.get_min(pref_xor[i]));
    trie.insert(pref_xor[i]);
  }
  cout << "Case " << ++cs << ": " << ans1 << ' ' << ans2 << '\n';
  trie.del(trie.root); // clear trie
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