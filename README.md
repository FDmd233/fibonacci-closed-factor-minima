# Closed-Factor Minima in the Fibonacci Word

This repository contains **Closed-Factor Minima and the Closed-Rich Constant of the Fibonacci Word**, by **OpenAI**.

For each length, the manuscript determines the minimum number of distinct closed factors occurring in a factor of the infinite Fibonacci word, counting the empty word. It proves the first-difference formula in Maity--Puzynina, Conjecture 5.2, and the constant in Conjecture 5.3:

$$
C_f=\frac{\varphi^3}{(\varphi^3+2)^2},
\qquad
\varphi=\frac{1+\sqrt5}{2}.
$$

For every $k\ge 5$, it also proves uniqueness of the minimizing factor at length

$$
F_k+2F_{k-3}-2,
$$

with $F_{-1}=F_0=1$.

## Manuscript

- [PDF](paper/paper_en.pdf)
- [LaTeX source](paper/paper_en.tex)

The proof derives the repeated suffixes from singular-kernel intervals and uses reversal symmetry to minimize the closed-factor count. The return intervals, the required inequalities, and the finite initial counts are included in the manuscript. No computational certificate is required.

## Source problem

- [MathDB #374792](https://mathdb.com/p/374792/the-conjectured-first-difference-sequence-for-the-fibonacci)
- A. Maity and S. Puzynina, *Bounds on the closed-rich constant of infinite words*, arXiv:2605.19535v1 (2026), [arXiv](https://arxiv.org/abs/2605.19535v1)

## Build

With a standard TeX Live installation:

~~~sh
make
~~~

This compiles `paper/paper_en.tex` twice and writes `paper/paper_en.pdf`. File hashes are recorded in `SHA256SUMS`.

## Status

This manuscript is presented as a proposed solution for independent verification. It has not undergone journal peer review.

## AI assistance

OpenAI GPT-6 Astra and GPT-5.6 Sol were used during the investigation, proof checking, drafting, and revision. The manuscript is signed OpenAI; the repository owner maintains this public version.
