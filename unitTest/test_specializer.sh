#!/bin/bash

set -x

fstcompile --isymbols=syms --osymbols=syms --keep_isymbols --keep_osymbols one.txt | fstarcsort > one.fst
fstcompile --isymbols=syms --osymbols=syms --keep_isymbols --keep_osymbols sigma.txt | fstarcsort > sigma.fst
fstcompile --isymbols=syms --osymbols=syms --keep_isymbols --keep_osymbols sigout.txt | fstarcsort > sigout.fst
fstcompile --isymbols=syms --osymbols=syms --keep_isymbols --keep_osymbols rho.txt | fstarcsort > rho.fst
fstcompile --isymbols=syms --osymbols=syms --keep_isymbols --keep_osymbols rhoout.txt | fstarcsort > rhoout.fst
fstcompile --isymbols=syms --osymbols=syms --keep_isymbols --keep_osymbols phi.txt | fstarcsort > phi.fst
fstcompile --isymbols=syms --osymbols=syms --keep_isymbols --keep_osymbols phiout.txt | fstarcsort > phiout.fst
python specializer.py
