#!/bin/bash
ittrs=500       # Quantidade de Iterações
rd_size=100     # Tamanho da Estrada
max_cars=0      # Quantidade Maxima de Carros
max_speed=0     # Velocidade Maxima dos Carros
min_spwn=2      # Numero minima de iterações para gerar novo Carro
max_spwn=4      # Numero máximo de iterações para gerar novo Carro
brk_prb=0.25    # Probabilidade de redução de velocidade

./exec $ittrs $rd_size $max_cars $max_speed $min_spwn $max_spwn $brk_prb