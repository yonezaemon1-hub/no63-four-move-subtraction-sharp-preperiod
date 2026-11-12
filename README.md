# Research No.63 - v1.0 Preprint

**A Sharp Preperiod and Explicit Nim-Words for the Four-Move Subtraction Sets {3,7,9,c}**

Ryutaro Yonezu - Independent Researcher  
Publication date: 2026-11-11  
Version: v1.0; type: Preprint  
AI-assisted research; human peer review: NOT PERFORMED  
**NOVELTY INCONCLUSIVE. REFERENCES PARTIAL.**  
Copyright (c) 2026 Ryutaro Yonezu. **All rights reserved.**

For the usual normal-play Sprague-Grundy mex recurrence and odd c>9,
the least (preperiod, period) is (0,16) for c=13 and (c+5,2) otherwise.
The paper gives complete nim-words, an infinite-family proof, and finite
proof certificates for the six small parameters. No assertion is made
for even c, general a>3, or arbitrary subtraction sets.

The eventual period-two observation already appears in Zhang's Remark 7.
The prospective contribution here is the proof of this restricted infinite
family, the exact least preperiod, and explicit Grundy words. Bounded
comparison of other sources does not certify historical novelty. The
enlarged Flammenkamp book remains unverified. See PRIOR_ART_STATUS.md.

## Files

- No63_v1.0_PREPRINT_20261111.pdf: typeset manuscript.
- No63_v1.0_SOURCE_20261111.tex: matching source.
- No63_v1.0_REPRODUCIBILITY_20261111.zip: exact frozen verifiers, proof note,
  clean expected output, instructions, inherited review/Windows scope, hashes.
- Three verify_*.py / verify_*.cpp files: the same frozen sources, directly readable.
- REPRODUCTION.md and the status/provenance notes: reproducibility and evidence scope.
- SHA256SUMS.txt: relative-path checksums, excluding itself.
- PUBLICATION_STATUS.md: evidence boundaries and prepublication validation.
- LICENSE: All rights reserved; no open-source license is granted.

See REPRODUCTION.md (complete clean expected output is inside the ZIP) for Python 3.10+ / C++17 commands and portable
PowerShell 5.1 instructions. The v1.0 preparation reran all three frozen
verifiers under Linux: Python 490 large cases / 1,286,250 positions;
large C++ 3,406,220 positions; small C++ 230 certificate positions.
These checks are finite; the paper supplies the all-c proof.

AI-audit PASS is inherited within the author-supplied reports' stated scope.
Windows PowerShell 5.1 finite PASS is inherited from the author-provided
sanitized record for unchanged code. A v1.0 Windows rerun was not performed.
No raw Windows logs, personal workstation paths, or credentials are included.

The frozen mathematical TeX segment is 6,656 bytes, SHA256
`3314bc24a76be60369880f1ce03bd69cb3c5845e59406b23b17cad656aa05431`.
All three verifier sources are byte-identical to the mathematical original.
The full source ZIP and earlier audit history remain preserved separately;
FREEZE_PROVENANCE.md connects this version to those exact records.

## Author correspondence (metadata update, 2026-11-12)

**Ryutaro Yonezu — Independent Researcher**  
Research correspondence: **yonezaemon1+research@gmail.com**

This contact-information addition does not revise any mathematical claims, frozen verification files, published preprint PDF, release assets, DOI, or existing SHA256 checksums.
