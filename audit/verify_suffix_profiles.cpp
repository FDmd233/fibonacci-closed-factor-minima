// Independent finite audit of the three suffix-profile formulas.
// This validates instances, not the infinite parameter theorem.
#include <algorithm>
#include <iostream>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

int longest_repeated_suffix(const string& word) {
    const int n = static_cast<int>(word.size());
    if (n < 2) return 0;
    const string rev(word.rbegin(), word.rend());
    vector<int> z(n);
    int left = 0, right = 0, best = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= right) z[i] = min(right - i + 1, z[i - left]);
        while (i + z[i] < n && rev[z[i]] == rev[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > right) {
            left = i;
            right = i + z[i] - 1;
        }
        best = max(best, z[i]);
    }
    return best;
}
int rho(const string& w) {
    const int l = longest_repeated_suffix(w);
    return l - longest_repeated_suffix(w.substr(w.size() - l));
}
string pre(const string& w, int n) {
    if (n < 0 || n > static_cast<int>(w.size())) throw runtime_error("prefix");
    return w.substr(0, n);
}
string suf(const string& w, int n) {
    if (n < 0 || n > static_cast<int>(w.size())) throw runtime_error("suffix");
    return w.substr(w.size() - n);
}
int expected21(int a, int i, int A, int B, int C, int D) {
    (void)A;
    return i <= a - B ? min(D, C + 1 + i) : max(B, i + 1);
}
int expected22(int a, int i, int A, int B, int C, int D) {
    (void)A; (void)D;
    const int L = max(0, a - B + 1);
    if (i < L) return C;
    if (i <= a) return B;
    if (i < B + a + 1) return min(C, B + i + 1);
    return min(C, i + 1);
}
int expected23(int a, int i, int A, int B, int C, int D) {
    (void)D;
    if (i < B) return max(B, min(C, a + i + 2));
    if (i < C) return max(A, a + i - B + 2);
    return B;
}
int main() {
    constexpr int max_k = 14;
    vector<string> fib(max_k + 1), singular(max_k + 1);
    fib[0] = "a"; fib[1] = "ab";
    for (int k = 2; k <= max_k; ++k) fib[k] = fib[k-1] + fib[k-2];
    singular[0] = "b";
    for (int k = 1; k <= max_k; ++k) {
        const char previous_last = (k == 1 ? 'a' : fib[k-1].back());
        singular[k] = string(1, previous_last)
                    + fib[k].substr(0, fib[k].size()-1);
    }
    long long total = 0;
    for (int k = 5; k <= max_k; ++k) {
        const int A = fib[k-4].size(), B = fib[k-3].size();
        const int C = A+B, D = A+2*B, K = fib[k].size();
        long long block = 0;
        for (int a = 0; a < D; ++a) {
            const int length = K+a;
            set<string> words;
            auto check = [&](int family, int i, const string& w, int expected) {
                const int actual = rho(w);
                if (static_cast<int>(w.size()) != length || actual != expected) {
                    cerr << "FAIL k=" << k << " a=" << a << " family="
                         << family << " i=" << i << " actual=" << actual
                         << " expected=" << expected << "\n";
                    exit(1);
                }
                words.insert(w);
                ++block;
            };
            for (int i=0; i<=a; ++i)
                check(21,i,suf(singular[k-1],i)+singular[k]+pre(singular[k-1],a-i),
                      expected21(a,i,A,B,C,D));
            for (int i=0; i<=C+a; ++i)
                check(22,i,suf(singular[k],i)+singular[k-1]+pre(singular[k],C+a-i),
                      expected22(a,i,A,B,C,D));
            for (int i=0; i<=D-a-2; ++i)
                check(23,i,suf(singular[k-1],a+i+1)+singular[k-2]
                      +pre(singular[k-1],D-i-1),expected23(a,i,A,B,C,D));
            if (static_cast<int>(words.size()) != length+1) {
                cerr << "FAIL factor classification k=" << k << " a=" << a
                     << " unique=" << words.size() << "\n";
                return 2;
            }
        }
        total += block;
        cout << "PASS k=" << k << " [" << K << "," << K+D-1
             << "] cases=" << block << "\n";
    }
    cout << "ALL_PASS tested=" << total << "\n";
    return total == 1275912 ? 0 : 3;
}
