# Teste do circuito VCA

O circuito VCA é responsável pela amplificação final, e junto com o envelope produz as modulações 
de amplitude que podem caracterizar o som desejado. O circuito do envelope produz a envoltória que irá controlar
a dinâmica da amplitude do VCA em função do tempo. O VCA possui a entrada do sinal do áudio e a entrada 
para a tensão de controle, que virá do envelope e também do LFO.

Os parâmetros do envelope são:

  - Atack: tempo para o sinal atingir o seu máximo
  - Decay: tempo para o sinal decair até zero
  - Sustain: amplitude de sustentação do sinal 
  - Release: tempo de decaimento do até zero depois que a nota para de ser tocada

## Circuito de simulação

![](https://github.com/diogo0001/PI_III/blob/master/VCA_test/VCA_circuit.PNG)

![](https://github.com/diogo0001/PI_III/blob/master/VCA_test/envelope_circuit.PNG)

Resultado da simulação:

![](https://github.com/diogo0001/PI_III/blob/master/VCA_test/vca_envelope.PNG)



## Resultados práticos
