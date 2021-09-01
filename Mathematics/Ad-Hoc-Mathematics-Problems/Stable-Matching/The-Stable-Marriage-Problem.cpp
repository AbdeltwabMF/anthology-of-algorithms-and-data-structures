const int N = 1e3+ 9, M = 1e3 + 9, oo = 0x3f3f3f3f;
queue <int> Q;

int husband[N], wife[N], Next[N], order[N][N], pref[N][N], n, v;

void _clear() {
  memset(wife,    0, sizeof(wife[0])    * (n + 2));
  memset(husband, 0, sizeof(husband[0]) * (n + 2));
  memset(Next,    0, sizeof(Next[0])    * (n + 2));
}

void engage(int man, int woman) {
  int exWife = wife[man];
  wife[man] = woman;
  husband[woman] = man;

  if(exWife)
    Q.push(exWife);
}

void Solve() {
  _clear();
  cin >> n;

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j)
      cin >> pref[i][j];

  for(int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j) {
      cin >> v;
      order[i][v] = j;
    }

  for(int i = 1; i <= n; ++i)
    Q.push(i);

  int man, woman;
  while(Q.size()) {
    woman = Q.front(); Q.pop();
    man = pref[woman][++Next[woman]];

    if(!wife[man] || order[man][woman] < order[man][wife[man]])
      engage(man, woman);
    else
      Q.push(woman);
  }

  for(int i = 1; i <= n; ++i)
    cout << husband[i] << endl;
}
