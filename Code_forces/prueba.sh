#! /bin/bash

file=$(ls -c | sed -n 1p)
(g++ -std=c++11 -o ej $file) && echo "compilo esta wea :D" && echo "------------------------" && ./ej < ent.in
