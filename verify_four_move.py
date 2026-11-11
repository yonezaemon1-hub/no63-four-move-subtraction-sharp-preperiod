#!/usr/bin/env python3
"""Finite check only. The accompanying proof note supplies the all-c argument."""
import argparse

W = '000111022133020'
EXCEPTION_TP = {11:(16,2),13:(0,16),15:(20,2),17:(22,2),19:(24,2),21:(26,2)}
EXCEPTION_BLOCKS = {11:'32203',15:'13102',17:'12103',19:'14102',21:'13102'}
PERIOD_13 = '0001110221330241'

def exceptional_value(c,n):
    if c==13:return int(PERIOD_13[n%16])
    T=c+5
    if n>=T:return n%2
    pref=W[:c] if c<15 else W + '10'*((c-15)//2)
    word=pref+EXCEPTION_BLOCKS[c]
    assert len(word)==T
    return int(word[n])


def nim(c, limit):
    S = (3,7,9,c)
    out=[]
    for n in range(limit+1):
        ss={out[n-s] for s in S if n>=s}
        x=0
        while x in ss: x+=1
        out.append(x)
    return out

def formula(c,n):
    if c<23 or c%2==0: raise ValueError('c must be odd >=23')
    if n<15:return int(W[n])
    if n<c:return 1 if n%2 else 0
    if n<c+5:return int('12103'[n-c])
    return n%2

def verify():
    parser=argparse.ArgumentParser()
    parser.add_argument('--max-c',type=int,default=1201)
    args=parser.parse_args()
    assert args.max_c>=23 and args.max_c%2==1
    cases=0; positions=0
    for c in range(23,args.max_c+1,2):
        limit=5*c+64
        g=nim(c,limit)
        for n,v in enumerate(g):
            assert v==formula(c,n),(c,n,v,formula(c,n))
        T=c+5
        assert g[T-1]!=g[T+1], ('least preperiod',c)
        assert g[T]!=g[T+1], ('least period',c)
        cases+=1;positions+=len(g)
    for c,(T,p) in EXCEPTION_TP.items():
        g=nim(c,T+c+2*p+40)
        assert all(g[n]==g[n+p] for n in range(T,T+c)), (c,'period certificate')
        bound=T+p+c-1
        for n in range(bound+1):
            want=exceptional_value(c,n)
            seen={exceptional_value(c,n-s) for s in (3,7,9,c) if n>=s}
            mex=next(v for v in range(5) if v not in seen)
            assert want==mex==g[n],(c,n,want,mex,g[n])
        if T>0:assert g[T-1]!=g[T-1+p],(c,'preperiod minimality')
        for d in range(1,p):
            if p%d==0:assert any(g[n]!=g[n+d] for n in range(T,T+p)), (c,'least period',d)
        assert (T,p)==({11:(16,2),13:(0,16),15:(20,2),17:(22,2),19:(24,2),21:(26,2)}[c])
        print(f'SMALL_CERTIFICATE c={c} T={T} p={p} checked_recurrence n=0..{bound}')
    print(f'FINITE_PASS c=23..{args.max_c} odd_cases={cases} positions={positions}')
    print('GENERAL_PROOF: separate in PROOF_CANDIDATE.md; this executable is finite only')

if __name__=='__main__':verify()
