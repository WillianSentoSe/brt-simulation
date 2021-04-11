#!/bin/bash
ittrs=100               # Quantidade de Iterações
rd_size=50              # Tamanho da Estrada
max_cars=25             # Quantidade Maxima de Carros
max_speed=2             # Velocidade Maxima dos Carros
min_spwn=1              # Numero minima de iterações para gerar novo Carro
max_spwn=1              # Numero máximo de iterações para gerar novo Carro
brk_prb=0.25            # Probabilidade de redução de velocidade

./exec $ittrs $rd_size $max_cars $max_speed $min_spwn $max_spwn $brk_prb