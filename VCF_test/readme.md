# Testes para o circuito VCF

O circuito VCF é um filtro que tem sua frequência de corte controlada por tensão, e junto com o envelope produz as modulações 
na frequência central que estiver ajustada. O VCF possui a entrada do sinal do áudio e a entrada para a tensão de controle, 
que virá do envelope e também do LFO. A frequência central é controlada por um potenciômetro. Há também um potenciômetro para 
o controle da ressonância na frequência de corte. O envelope é um circuito igual para o VCA.

## Circuito de simulação

![vcf](https://github.com/diogo0001/PI_III/blob/master/VCF_test/vcf_schematic.PNG)

### Resultado da simulação:

A simulação não presentou resultados satisfatórios, gerando distorção do sinal.

![](https://github.com/diogo0001/PI_III/blob/master/VCF_test/vcf_sim.PNG)


### Implementação alternativa

Foi implementada uma alternativa utilizando um filtro passa paixa com LDR controlado poe LED. Este circuito 
foi incorporado junto ao mixer: 

![](https://github.com/diogo0001/PI_III/blob/master/VCF_test/Capturar.PNG)

A seguir, o circuito de amplificação para o LFO que seria implementado:

![](https://github.com/diogo0001/PI_III/blob/master/VCF_test/LFO_amp.PNG)

Esta implementação foi feita diretamente em protoboard, testando diretamente com gerador de sinais.


## Resultados práticos do VCF

 Como na simulação não houve um resultado satisfatório, tentou-se implementar o circuito para 
 verificar o que poderia ocorrer na prática. O circuito gera muita distorção do sinal. A seguir são mostradas
 as formas de onda variando os potenciômetros de Cuttof e ressonância: (azul- entrada, amarelo-saída)
 
 
 Cuttof no mínimo e sem ressonância:
 
 ![](https://github.com/diogo0001/PI_III/blob/master/VCF_test/cuttof_min_no_res.png)
 
 Cuttof no mínimo e com ressonância
 
 ![](https://github.com/diogo0001/PI_III/blob/master/VCF_test/cuttof_min_and_res.png)
 
 Cuttof no máximo e sem ressonância
 
 ![](https://github.com/diogo0001/PI_III/blob/master/VCF_test/cuttof_max_no_res.png)
 
 Cuttof no máximo e com ressonância
 
 ![](https://github.com/diogo0001/PI_III/blob/master/VCF_test/cuttof_max_and_res.png)
 
 
