#include <bits/stdc++.h>
using namespace std;

const int N = 10; // change here
const char base_char = '0';  // change here
struct TrieNode {
  int cnt;
  TrieNode * nxt[N];
  TrieNode() {
    cnt = 0;
    for (int i = 0; i < N; i++) nxt[i] = NULL;
  }
} *root;

void insert(const string &s) {
  TrieNode *cur = root;
  int n = (int)s.size();
  for (int i = 0; i < n; i++) {
    int idx = s[i] - base_char;
    if (cur -> nxt[idx] == NULL ) cur -> nxt[idx] = new TrieNode();
    cur = cur -> nxt[idx];
    cur -> cnt++;
  }
}
void rem(TrieNode *cur, string &s, int pos) { // free :: De Alloactes Memory
  if (pos == s.size()) return;
  int d = s[pos] - base_char;
  rem(cur -> nxt[d], s, pos + 1);
  cur -> nxt[d] -> cnt--;
  if (cur -> nxt[d] -> cnt == 0) {
    free(cur -> nxt[d]);
    cur -> nxt[d] = NULL;
  }
}
int query(const string &s) { // "s" is a prefix of some element or not
  int n = (int)s.size();
  TrieNode *cur = root;
  for (int i = 0; i < n; i++) {
    int idx = s[i] - base_char;
    if (cur -> nxt[idx] == NULL) return 0;
    cur = cur -> nxt[idx];
  }
  return cur -> cnt;
}
void del(TrieNode *cur) {
  for (int i = 0; i < N; i++) if (cur -> nxt[i]) del(cur -> nxt[i]);
  delete(cur);
}

int cs;
void solve() {
  int n; cin >> n;
  string s[n + 1];
  root = new TrieNode(); // init new trie
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    insert(s[i]);
  }
  bool ok = true;
  for (int i = 1; i <= n; i++) {
    rem(root, s[i], 0);
    if (query(s[i])) {
      ok = false;
      break;
    }
    insert(s[i]);
  }
  cout << "Case " << ++cs << ": ";
  if (ok) cout << "YES\n";
  else cout << "NO\n";
  del(root); // clear trie
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