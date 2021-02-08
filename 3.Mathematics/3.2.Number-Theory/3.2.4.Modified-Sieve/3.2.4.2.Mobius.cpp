/*
	Constraints:
	1 <= n <= 1e7
	
	Time Complexity:
	mobius_sieve takes O(n * ln(ln(n)))
	
	Space Complexity:
	MaxN
*/

char mob[N];

void mobius_sieve(int n) {
    memset(mob, 0x02, sizeof(mob)); // 00000010
    mob[1] = 1;
    for (int i = 2; i <= n; ++i) {
        if (mob[i] == 2) {
            mob[i] = -1;
            for (int j = i + i; j <= n; j += i) {
                mob[j] = (mob[j] == 2) ? 1 : mob[j];
                mob[j] = (j % (i * i) == 0) ? 0 : -mob[j];
            }
        }
    }
}
