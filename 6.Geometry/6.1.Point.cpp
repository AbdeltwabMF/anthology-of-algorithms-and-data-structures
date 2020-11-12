#include <bits/stdc++.h>
using namespace std;
typedef int64_t     ll;
typedef long double ld;

const int N = 5e5 + 9, M = 1e5 + 9, oo = 0x3f3f3f3f, Mod = 1e9 + 7;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ld EPS = 1e-9, PI  = acos(-1.0);

/**
    notes:
    EPS = 1e-9
    ------------------------------------
    Integers   |       Doubles         |
    ------------------------------------
     a == b    | fabs(a - b) < EPS     |
     a <= b    | a < b + EPS           |
     a >= b    | a + EPS > b           |
     a < b     | a + EPS < b           |
     a > b     | a > b + EPS           |
     x ≥ 0.0   | x > -EPS              |
     x ≤ 0.0   | x < EPS               |
     -----------------------------------
**/

class point
{
    public :
    ld x, y;

    point() = default;
    point(ld _x, ld _y) : x(_x), y(_y) {}

    bool operator < (point other) const {
        if(fabs(x - other.x) > EPS) // if(x != other.x)
            return x < other.x;
        return y < other.y;
    }

    bool operator == (point other) const {
        return ((fabs(x - other.x) < EPS) && (fabs(y - other.y) < EPS)); // " < EPS " equal to " == zero "
    }

    bool operator > (point other) const {
        if(fabs(x - other.x) > EPS)
            return x > other.x;
        return y > other.y;
    }

    ld dist(point other) { // Euclidean distance
		ld dx = this->x - other.x;
		ld dy = this->y - other.y;
        return sqrtl(dx * dx + dy * dy);
    }

    ld DEG_to_RAD(ld theta) {
        return theta * PI / 180.0;
    }

    ld RAD_to_DEG(ld theta) {
        return theta * 180.0 / PI;
    }

    point rotate(ld theta) {
        ld rad = DEG_to_RAD(theta);
        return point(cos(theta) * x - sin(theta) * y,
                     sin(theta) * x + cos(theta) * y);
    }
};

istream & operator >> (istream & in, point & p) noexcept
{ ld a, b; cin >> a >> b; p.x = a; p.y = b; return in; }

ostream & operator << (ostream & out, const point p) noexcept
{ out << "(" << p.x << " " << p.y << ")"; return out; }


void Solve()
{
    point vas;
    cin >> vas;
    cout << vas << endl;
}

int main()
{
    Fast();
    cout << fixed << setprecision(20);

    int tc = 1;
    for(int i = 1; i <= tc; ++i)
        Solve();
}

