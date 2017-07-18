#!/bin/bash

set -x

fstcompile --isymbols=syms --osymbols=syms --keep_isymbols --keep_osymbols one.txt | fstarcsort > one.fst
fstcompile --isymbols=syms --osymbols=syms --keep_isymbols --keep_osymbols sigma.txt | fstarcsort > sigma.fst
fstcompile --isymbols=syms --osymbols=syms --keep_isymbols --keep_osymbols rho.txt | fstarcsort > rho.fst
fstcompile --isymbols=syms --osymbols=syms --keep_isymbols --keep_osymbols phi.txt | fstarcsort > phi.fst
python specializer.py
