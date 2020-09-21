#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9, M = 2e6 + 9;

void File() {
    freopen("input.in", "r", stdin);
}

class UnionFind
{
	public:
		UnionFind(size_t n) {
			
			assert(n > 0);
			disjoint_sets = sz = n;
			
			for(size_t i = 0; i <= n; ++i) {
				par[i] = i; 
				siz[i] = 1;
			}
		}
		
		int find_set(int u) {
			
			// find representative (leader) item
			int leader;
			for(leader = u; leader != par[leader]; leader = par[leader])
			
			// path compression
			for(int next = par[u]; u ^ leader; next = par[next]) {
				par[u] = leader;
				u = next;
			}
			
			return leader;
		}
		
		bool same_set(int u, int v) {
			return find_set(u) == find_set(v);
		}
		
		void union_set(int u, int v) {
			
			if(same_set(u, v)) return;
			
			int x = find_set(u);
			int y = find_set(v);
			
			if(siz[x] < siz[y]) swap(x, y);
				
			par[y] = x;
			siz[x] += siz[y];
			
			--disjoint_sets;	
		}

		int set_size(int u) {
			return siz[find_set(u)];
		}
	
		int components() {
			return disjoint_sets;
		}
		
		size_t size() {
			return sz;
		}
					
	private:
		int par[N];
		int siz[N];
		int disjoint_sets;
		size_t sz;
};

int u, v, n, m;

int main()
{
	File();
	
	cin >> n >> m;
	UnionFind uf = UnionFind(n);
	
	while(m--)
	{
		cin >> u >> v;
		uf.union_set(u, v);
	}
}

