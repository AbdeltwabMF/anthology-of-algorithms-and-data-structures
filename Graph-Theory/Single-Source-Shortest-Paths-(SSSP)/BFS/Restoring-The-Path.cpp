const int dr []     = {-1, 0, 1, 0};
const int dc []     = {0, 1, 0, -1};
const char dir [] = {'U', 'R', 'D', 'L'};
map <char, int> inv = { {'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}};

/** Implicit Graphs
    - char Par[N][N] initialize with -1
    - si start i
    - sj strat j
    - fi target i
    - fj target j
    - char dir and its map inv
    - dr, dc
    - in BFS, Dijkstra.. etc. ->  Par[nr][nc] = dir[i ^ 2]
**/

string restorePath(int si, int sj, int fi, int fj)
{
    string s;
    if(Par[ei][ej] == -1) return s;

    int ei = fi, ej = fj;
    for(char i = Par[fi][fj]; (si ^ fi) || (sj ^ fj); i = Par[fi][fj])
    {
        s  += dir[inv[i] ^ 2];
        fi += dr[inv[i]];
        fj += dc[inv[i]];
    }

    reverse(s.begin(), s.end());
    return s;
}

/** Explicit Graphs
    - int Par[N] initialize with  -1
    - ll dis[N]  initialize with  0x3f
    - ll INF = 0x3f3f3f3f3f3f3f3f
**/

vector <int> restorePath(int dest)
{
    vector <int> path;
    if(dis[dest] == INF) return path;

    for(int i = dest; ~i; i = Par[i])
        path.push_back(i);

    reverse(path.begin(), path.end());
    return path;
}

