#!/bin/bash

# == PARAMETROS DA SIMULACAO =================================================================================== #
ittrs=5000								# Quantidade de iterações
rd_size=10000							# Tamanho da estrada
max_speed=2								# Velocidade maxima dos carros
min_spwn=1								# Numero minima de iterações para gerar novo Carro
max_spwn=1								# Numero máximo de iterações para gerar novo Carro
brk_prb=0.25							# Probabilidade de redução de velocidade
min_stop=3								# Tempo mínimo de parada dos carros
max_stop=5								# Tempo máximo de parada dos carros
num_threads=8							# Numero de threads utilizadas para execucao paralela da simulacao

# == PARAMETROS DE EXECUCAO ==================================================================================== #
N=(1 10 100)								# Lista de quantidades máxima de carros na via
I={1..5}								# Número de execuções por quantidade máxima de carros na via

# == FORMACATAO DE RESULTADO =================================================================================== #
out_seq=tmp/seq-result.txt				# Arquivo de saída para a execução sequencial
out_par=tmp/par-result.txt				# Arquivo de saída para a execução paralela
TIMEFORMAT="%E"							# Formatação do tempo

rm $out_seq
rm $out_par

for i in $I; do
	for n in $N; do
		echo "${n}" >> $out_seq
		{ time ./main $ittrs $rd_size $n $max_speed $min_spwn $max_spwn $brk_prb $min_stop $max_stop 0 ; } 2>>$out_seq
	done
done

for i in $I; do
	for n in $N; do
		echo "${n}" >> $out_par
		{ time ./main $ittrs $rd_size $n $max_speed $min_spwn $max_spwn $brk_prb $min_stop $max_stop $num_threads ; } 2>>$out_par
	done
done