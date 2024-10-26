#include <bits/stdc++.h>
using namespace std;

const int N = 26;
const char base_char = 'a';
struct TrieNode {
  int cnt;
  TrieNode * nxt[N];
  TrieNode() {
    cnt = 0;
    for (int i = 0; i < N; i++) nxt[i] = NULL;
  }
};

struct Trie {
  TrieNode *root;
  Trie() {
    root = new TrieNode();
  }
  ~Trie() {
    del(root);
  }
  void insert(const string &s) {
    TrieNode *cur = root;
    int n = (int)s.size();
    for (int i = 0; i < n; i++) {
      int idx = s[i] - base_char;
      if (cur -> nxt[idx] == NULL) cur -> nxt[idx] = new TrieNode();
      cur = cur -> nxt[idx];
      cur -> cnt++;
    }
  }
  int query(TrieNode *cur, const string &s, int pos) { // complexity not sure (maybe exponential but get accepted)
    if (!cur) return 0;
    if (pos == s.size()) return cur -> cnt;
    int ans = 0;
    if (s[pos] == '?') {
      for (int i = 0; i < 26; i++) {
        if (cur -> nxt[i]) {
          ans += query(cur -> nxt[i], s, pos + 1);
        }
      }
    }
    else {
      ans += query(cur -> nxt[s[pos] - base_char], s, pos + 1);
    }
    return ans;
  }
  void del(TrieNode *cur) {
    for (int i = 0; i < N; i++) if (cur -> nxt[i]) del(cur -> nxt[i]);
    delete(cur);
  }
};

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  Trie pref_trie, suff_trie, both_trie;
  for (int i = 1; i <= n; i++) {
    string s; cin >> s;
    pref_trie.insert(s);
    string t = s;
    reverse(t.begin(), t.end());
    suff_trie.insert(t);
    string tmp = "";
    for (int j = 0; j < s.size(); j++) {
      tmp += s[j];
      tmp += t[j];
    }
    both_trie.insert(tmp);
  }

  int q; cin >> q;
  while (q--) {
    string s, t; cin >> s >> t;
    reverse(t.begin(), t.end());
    string tmp = "";
    int mx = max(s.size(), t.size());
    for (int j = 0; j < mx; j++) {
      if (j < s.size()) tmp += s[j];
      else tmp += '?';
      if (j < t.size()) tmp += t[j];
      else tmp += '?';
    }
    int ans = pref_trie.query(pref_trie.root, s, 0) + suff_trie.query(suff_trie.root, t, 0) - both_trie.query(both_trie.root, tmp, 0);
    cout << ans << '\n';
  }

  return 0;
}