void solve() {
    for (int d = 1; d <= 10; ++d) {
        set<pii> poss;
        for (int i = 0; i < (1 << (2*d)); ++i) {
            // This corresponds to something
            int x = 0, y = 0;
            for (int m = 0, j = i, cur = 1; m < d; ++m, cur *= k) {
                switch (j & 3) {
                    case 0: x += cur; break;
                    case 1: x -= cur; break;
                    case 2: y += cur; break;
                    case 3: y -= cur; break;
                }
                j >>= 2;
            }
            poss.insert(minmax(abs(x), abs(y)));
        }

        cerr << "d = " << d << ", pos.size() = " << poss.size() << ": ";
        // for (auto [x, y]: poss) {
        //     cerr << '(' << x << ", " << y << "), ";
        // }
        cerr << '\n';
    }
}