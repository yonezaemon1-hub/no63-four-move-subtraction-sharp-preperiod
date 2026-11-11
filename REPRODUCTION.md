# No.63 finite reproducibility kit, v1.0

Copyright (c) 2026 Ryutaro Yonezu. All rights reserved.
AI-assisted research; not human peer-reviewed.
REFERENCES PARTIAL. NOVELTY INCONCLUSIVE.

The three source files are byte-identical to the v0.4 mathematical original.
The six small-case certificates are the exact words and finite mex checks in
these sources and in the paper. No separate certificate data file is needed.
PROOF_CANDIDATE.md is preserved byte-for-byte as a historical proof note;
its old HOLD and audit-pending statements describe its original date/state.
The v1.0 paper and PUBLICATION_STATUS.md give the current publication scope.

For the complete kit, extract the reproducibility ZIP and enter its `repro`
directory. The repository-root verification sources are identical copies.
Using Python 3.10+ and a C++17 compiler:

```sh
python -B -I verify_four_move.py --max-c 1001
g++ -O2 -std=c++17 verify_four_move_independent.cpp -o check_large
./check_large 1501
g++ -O2 -std=c++17 verify_small_independent.cpp -o check_small
./check_small
```

Windows PowerShell 5.1 (from this same directory; compiler on PATH):

```powershell
python -B -I .\verify_four_move.py --max-c 1001
g++ -O2 -std=c++17 .\verify_four_move_independent.cpp -o check_large.exe
if ($LASTEXITCODE -ne 0) { throw 'Large verifier compilation failed' }
.\check_large.exe 1501
if ($LASTEXITCODE -ne 0) { throw 'Large verifier failed' }
g++ -O2 -std=c++17 .\verify_small_independent.cpp -o check_small.exe
if ($LASTEXITCODE -ne 0) { throw 'Small verifier compilation failed' }
.\check_small.exe
if ($LASTEXITCODE -ne 0) { throw 'Small verifier failed' }
```

Success markers:
- FINITE_PASS c=23..1001 odd_cases=490 positions=1286250
- INDEPENDENT_CPP_FINITE_PASS max_c=1501 checked_positions=3406220
- SMALL_INDEPENDENT_CERTIFICATES_PASS checks=230

expected_output/ contains only clean stdout from the v1.0 Linux preparation
run. No Windows raw log, workstation path, credentials, or binaries are
redistributed. WINDOWS_REPRO_SANITIZED.md is the inherited author-supplied
Windows evidence summary, not an independent v1.0 Windows rerun.

All executable checks are finite. The paper supplies the infinite argument.
The three programs compare with the stated formulas; their separate coding
does not by itself make them a formula-independent discovery of the theorem.
The separately reported 996-parameter AI recurrence enumeration was not
rerun during publication preparation.
