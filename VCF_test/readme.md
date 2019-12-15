# Testes para o circuito VCF

O circuito VCF é um filtro que tem sua frequência de corte controlada por tensão, e junto com o envelope produz as modulações 
na frequência central que estiver ajustada. O VCF possui a entrada do sinal do áudio e a entrada para a tensão de controle, 
que virá do envelope e também do LFO. A frequência central é controlada por um potenciômetro. Há também um potenciômetro para 
o controle da ressonância na frequência de corte.

Os parâmetros do envelope são:

  - Atack: tempo para a frequência de corte (cutoff) atingir o ponto que está ajustada.
  - Decay: tempo para o cuttof chegar até o sustain.
  - Sustain: frequência de corte estática.

## Circuito de simulação

![vcf]()

![envelope]()

### Resultado da simulação:

A simulação não presentou resultados satisfatórios, e alguns resultados são mostrados a seguir:


## Resultados práticos

 Como na simulação não houve um resultado satisfatório, tentou-se implementar o circuito para 
 verificar o que poderia ocorrer na prática. O circuito gera muita distorção do sinal como é mostrado a seguir:
 
 Cuttof no mínimo e sem ressonância:
 
 ![](https://github.com/diogo0001/PI_III/blob/master/VCF_test/cuttof_min_no_res.png)
 
 Cuttof no mínimo e com ressonância
 
 ![](https://github.com/diogo0001/PI_III/blob/master/VCF_test/cuttof_min_and_res.png)
 
 Cuttof no máximo e sem ressonância
 
 ![](https://github.com/diogo0001/PI_III/blob/master/VCF_test/cuttof_max_no_res.png)
 
 Cuttof no máximo e com ressonância
 
 ![](https://github.com/diogo0001/PI_III/blob/master/VCF_test/cuttof_max_and_res.png)
 
 
