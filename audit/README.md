# Independent finite checks of Fibonacci suffix profiles

Compile and run:

~~~sh
g++ -std=c++17 -O2 -Wall -Wextra -pedantic audit/verify_suffix_profiles.cpp -o /tmp/verify_suffix_profiles
/tmp/verify_suffix_profiles
~~~

The audit independently reconstructs the three singular-word factor families \(W^{21}\), \(W^{22}\), and \(W^{23}\) from the defining Fibonacci recursion. It computes

\[
\rho(w)=|\operatorname{LRS}(w)|-
|\operatorname{LRS}(\operatorname{LRS}(w))|
\]

without using the manuscript's piecewise formula: it calculates longest repeated suffixes via the Z-algorithm on reversed words. It then checks all three formulas and exact absence of duplicate family factors for every \(k=5,\ldots,14\) and \(0\le a\le F_{k-1}-1\), a total of **1,275,912 individual profiles** with factor lengths from 13 to 1596 inclusive.

Passing the checks confirms only these finite instances, **not** the theorem for arbitrary lengths. The published mathematical argument remains the source of the infinite generality claim. No external packages or floating-point calculations are required.
