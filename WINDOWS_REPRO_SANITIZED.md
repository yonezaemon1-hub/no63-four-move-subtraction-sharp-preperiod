# Windows finite reproduction — privacy-safe summary

**Observation date:** 2026-11-11 (JST)
**Source:** User-provided Windows execution log, reviewed for this package.
**Scope:** finite-only reproducibility; not a proof, novelty check, or peer review.
**Status:** `ALL_WINDOWS_FINITE_REPRO_PASS` reported by the runner.

## Verified markers in the supplied log

| Check | Outcome |
| --- | --- |
| Original source ZIP SHA256 pin | PASS |
| Original archive payload inventory (9 files) and checksums | PASS |
| Python recurrence, odd c=23..1001 | 490 cases; 1,286,250 checked positions |
| Separately coded C++17 recurrence, odd c up to 1501 | 3,406,220 checked positions |
| Six small exceptional cases c=11,13,15,17,19,21 | PASS in Python and separately coded C++17 |
| Small-case C++17 checked positions | 230 |
| Final runner status | `ALL_WINDOWS_FINITE_REPRO_PASS` |

The supplied log reports no failed check in this completed execution.
The original ZIP SHA256 checked by the runner was:

`19567791f2e640b13a8c4a382066e9a16f7e68abf3502581ba467fec48657227`

**Limits:** The runner's final lines explicitly state that the general
proof was not verified by the runner and novelty remains INCONCLUSIVE.
The log was provided by the author; independent recreation of the Windows
execution by the external reviewer has not yet occurred. No personal
identifiers, workstation paths, timestamps precise to the millisecond,
compiler binaries, or transcript lines are copied into this file.

**Privacy:** The full original Windows log and all stdout/stderr captures
remain outside this audit archive. This is a curated status report only.
