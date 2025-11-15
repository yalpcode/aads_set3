#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int MAXITER = 1e7;

struct pt {
    ld x, y;

    pt() = default;
    explicit pt(ld x, ld y) : x(x), y(y) {
    }
};

struct circle {
    ld x, y, r;

    bool contains(const pt& p) const {
        return (p.x - x) * (p.x - x) + (p.y - y) * (p.y - y) <= r * r;
    }
};

istream& operator>>(istream& is, circle& c) {
    is >> c.x >> c.y >> c.r;

    return is;
}

bool f(const vector<circle>& a, const pt& p) {
    for (auto c : a) {
        if (!c.contains(p)) {
            return false;
        }
    }

    return true;
}

int32_t main(int argc, char const* argv[]) {
    cin.tie(0)->sync_with_stdio(0);

    MAXITER = atoi(argv[1]);

    int flag = atoi(argv[2]);

    int n = 3;

    vector<circle> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int countIn = 0, countOut = 0;
    ld x1, y1, x2, y2;

    if (flag) {
        x1 = 10, y1 = 10, x2 = 10, y2 = 10;
        for (auto c : a) {
            x1 = min(x1, c.x - c.r);
            y1 = min(y1, c.y - c.r);
            x2 = min(x2, c.x + c.r);
            y2 = min(y2, c.y + c.r);
        }
    } else {
        x1 = -10, y1 = -10, x2 = -10, y2 = -10;
        for (auto c : a) {
            x1 = max(x1, c.x - c.r);
            y1 = max(y1, c.y - c.r);
            x2 = max(x2, c.x + c.r);
            y2 = max(y2, c.y + c.r);
        }
    }

    uniform_real_distribution<ld> x_dist(x1, x2);
    uniform_real_distribution<ld> y_dist(y1, y2);

    for (int i = 0; i < MAXITER; ++i) {
        pt p(x_dist(rng), y_dist(rng));

        if (f(a, p)) {
            ++countIn;
        } else {
            ++countOut;
        }
    }

    cout << fixed << setprecision(15)
         << (ld(countIn) / (countIn + countOut)) * (x2 - x1) * (y2 - y1);

    return 0;
}
