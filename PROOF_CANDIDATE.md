# Candidate mathematical result — proof for author/independent audit

Date 2026-11-11 (JST). **Independent AI proof audit reported PASS with one minor Step 4 repair, applied in this REV2; publication HOLD.**

## Model

For a finite move set S, the normal-play Sprague–Grundy sequence g_S(n), n>=0,
is determined by g(n)=mex{g(n-s):s in S, 0<=s<=n}. Here mex(empty)=0.
The *least preperiod* T is the smallest starting index of an eventually
periodic suffix, and p is the least eventual period.

## Theorem candidate: the entire a=3 case of Zhang's Remark 7

Let c be any odd integer c>9 and S_c={3,7,9,c}. The least preperiod
and least period are

- if c=13: T=0 and p=16;
- otherwise: T=c+5 and p=2.

In fact, the **entire nim-word** is explicit. Write
W=000111022133020 (15 symbols); concatenation is juxtaposition,
and X^r is r repetitions.

For each odd c>=23,

    g_{S_c} = W (10)^((c-15)/2) 12103 (01)^infinity.

For the remaining odd c>9, the complete descriptions are:

    c=11:  W[:11] 32203 (01)^infinity
    c=13:  (0001110221330241)^infinity
    c=15:  W 13102 (01)^infinity
    c=17:  W (10) 12103 (01)^infinity
    c=19:  W (10)^2 14102 (01)^infinity
    c=21:  W (10)^3 13102 (01)^infinity.

Here W[:11] means the first eleven symbols of W. This is a proposed
**proved-within-this-note** proposition, subject to independent mathematical
and historical-priority audits; do not call it a peer-reviewed theorem.

## Proof, all odd c>=23

**Step 1: the three-move base.** For S_0={3,7,9}, direct mex evaluation
for indices 0..23 yields

    g_{S_0} = W (10)^infinity.

To extend beyond index 23, note that for n>=24, each n-s for
s=3,7,9 is >=15. All s are odd, so all three predecessor symbols
are 1 if n is even and 0 if n is odd. Their mex is 0 if n is
even and 1 if n is odd. Thus the displayed base word holds for all n.

**Step 2: define candidate f.** Fix odd c>=23. Define f(n) by the
proposed word. All indices n<c reproduce the three-move base, because
move c is not then legal. Its symbols at n=c,...,c+4 are 1,2,1,0,3.
The mex computations are:

    n=c:   predecessors 0,0,0 and f(0)=0 -> mex 1;
    n=c+1: predecessors 1,1,1 and f(1)=0 -> mex 2;
    n=c+2: predecessors 0,0,0 and f(2)=0 -> mex 1;
    n=c+3: predecessors 1,1,1 and f(3)=1 -> mex 0;
    n=c+4: predecessors 2,0,0 and f(4)=1 -> mex 3.

The predecessor order is moves 3,7,9, followed by c.
For c>=23, all referenced indices in the first three positions
lie in the stable parity phase of the base sequence (starting at 14).

**Step 3: all later positions by strong induction.** The candidate
f has these easily verified global properties:

(A) f(j)!=0 for every odd j>=5;
(B) f(j)!=1 for every even j>=6;
(C) f(j)=0 for every even j>=c-3, apart from f(c+1)=2.

For even n>=c+5, all n-3,n-7,n-9,n-c are odd and >=5.
By (A), all corresponding f-values are nonzero, so their mex is 0=f(n).

For odd n>=c+5, all these predecessors are even, and n-c>=6.
By (B), none of their f-values is 1. Moreover n-3,n-7,n-9 are
three *distinct* even indices >=c-3. By (C), at least two of them
have value zero. Thus mex is 1=f(n).

By strong induction the candidate f satisfies the full recurrence,
and uniqueness of mex recursion gives f=g_{S_c} for every n>=0.

**Step 4: sharpness.** The tail begins at T=c+5 (which is even),
so its period divides 2; it contains both 0 and 1, hence least period
is exactly 2. The last symbol before T is f(T-1)=f(c+4)=3, whereas every
symbol at index n>=T belongs to {0,1}. Suppose any eventual
period q>=1 could start at some index T'<T. Then, because
T-1>=T', periodicity would imply f(T-1)=f(T-1+m*q)
for every positive integer m. Already for m=1 we have T-1+q>=T, forcing the value 3
inside the {0,1}-valued tail, a contradiction.
Thus **no period of any length** can begin before T, and the
least preperiod is exactly T=c+5.

## Proof, six fixed small values of c

For c in {11,13,15,17,19,21}, use the explicit finite/infinite
words in the theorem statement. For any fixed maximal move c,
preperiod T and eventual period p, the recurrence needs to be
checked only through n=T+p+c-1:

- Check the recurrence for every 0<=n<=T+p+c-1.
- For n>=T+p+c, periodicity of the proposed word allows an
  induction comparing mex at n and at n-p (all predecessors of n
  and n-p have indices >=T, and the prior candidate values match).

The `verify_four_move.py` program checks the proposed word itself
against the mex equation on the following complete finite ranges:

| c | T | p | last n checked |
|---|---|---|---|
| 11 | 16 | 2 | 28 |
| 13 | 0 | 16 | 28 |
| 15 | 20 | 2 | 36 |
| 17 | 22 | 2 | 40 |
| 19 | 24 | 2 | 44 |
| 21 | 26 | 2 | 48 |

For c=13, the 16-letter periodic word has no period 1,2,4,8,
and hence least period 16 and least preperiod 0. For each of the other five cases, the last symbol before the
claimed start T=c+5 is not in {0,1}, whereas every symbol at or
after T belongs to {0,1}. The same arbitrary-period obstruction
as in Step 4 therefore proves **minimality against every period**,
not merely against period 2. (The finite certificates check the full proposed words against the mex
recurrence; the stated boundary symbols and the {0,1}-valued tails
follow from those verified words.)

The finite certificate and above induction together prove these
six cases mathematically, and a separately written C++ verifier (`verify_small_independent.cpp`)
independently checks all six finite certificates. The larger-c C++
checker covers c>=23. Neither is a substitute for an external audit.

## Boundaries

- The case for arbitrary odd a>=5 in Zhang's Remark 7 is **not** proved.
- No theorem for even c is asserted.
- No new theorem about {3,5,8k+1} is asserted. It is a specialization
  of Zhang's Theorem 6.3(1) and is a rejected duplicate.
- The historical novelty of this exact four-move classification is **not** certified.
- A reviewer report supplied by the author records MODEL/PROOF/COMPUTATION/SCOPE PASS on REV1 and targeted Step 4 differential PASS on REV2; the two edits in REV3 are editorial and have not separately been audited. The frozen verifier sources are unchanged. Windows finite reproduction was author-reported PASS. Human peer review has not occurred.
