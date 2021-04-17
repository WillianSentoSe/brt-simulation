#!/bin/bash
ittrs=10000             # Quantidade de Iterações
rd_size=5000            # Tamanho da Estrada
max_cars=1000           # Quantidade Maxima de Carros
max_speed=2             # Velocidade Maxima dos Carros
min_spwn=1              # Numero minima de iterações para gerar novo Carro
max_spwn=1              # Numero máximo de iterações para gerar novo Carro
brk_prb=0.25            # Probabilidade de redução de velocidade
min_stop=3
max_stop=5
num_threads=8         # Numero de Threads Utilizadas para Execucao Paralela da Simulacao

echo 
echo "--SEQUENCIAL"
time ./main $ittrs $rd_size $max_cars $max_speed $min_spwn $max_spwn $brk_prb $min_stop $max_stop 0

echo 
echo 
echo "--PARALELO"
time ./main $ittrs $rd_size $max_cars $max_speed $min_spwn $max_spwn $brk_prb $min_stop $max_stop $num_threads