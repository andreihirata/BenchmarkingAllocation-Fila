#!/bin/bash

BASE_VALUES=(50000000 250000000 500000000 750000000 1000000000)

for value in ${BASE_VALUES[@]}; do
    /usr/bin/time -v ./contigua_inserir $value > contigua_inserir_$value.txt 2>&1
    /usr/bin/time -v ./contigua_remover $value > contigua_remover_$value.txt 2>&1
    /usr/bin/time -v ./encadeada_inserir $value > encadeada_inserir_$value.txt 2>&1
    /usr/bin/time -v ./encadeada_remover $value > encadeada_remover_$value.txt 2>&1
done
