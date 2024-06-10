#include <bits/stdc++.h>
using namespace std;

const int N = 4; // change here
struct TrieNode {
  int cnt;
  TrieNode * nxt[N];
  TrieNode() {
    cnt = 0;
    for (int i = 0; i < N; i++) nxt[i] = NULL;
  }
} *root;

int get(char c) {
  if (c == 'A') return 0;
  if (c == 'C') return 1;
  if (c == 'G') return 2;
  return 3;
}

void insert(const string &s) {
  TrieNode *cur = root;
  int n = (int)s.size();
  for (int i = 0; i < n; i++) {
    int idx = get(s[i]);
    if (cur -> nxt[idx] == NULL ) cur -> nxt[idx] = new TrieNode();
    cur = cur -> nxt[idx];
    cur -> cnt++;
  }
}

void del(TrieNode *cur) {
  for (int i = 0; i < N; i++) if (cur -> nxt[i]) del(cur -> nxt[i]);
  delete(cur);
}

int f(TrieNode *cur, int pos) {
  int ans = cur -> cnt * pos;
  for (int i = 0; i < N; i++) {
    if (cur -> nxt[i]) ans = max(ans, f(cur -> nxt[i], pos + 1));
  }
  return ans;
}

int cs;
void solve() {
  root = new TrieNode(); // init new trie
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    string s; cin >> s;
    insert(s);
  }
  cout << "Case " << ++cs << ": " << f(root, 0) << '\n';
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