# Testes para o circuito VCF

O circuito VCF é um filtro que tem sua frequência de corte controlada por tensão, e junto com o envelope produz as modulações 
na frequência central que estiver ajustada. O VCF possui a entrada do sinal do áudio e a entrada para a tensão de controle, 
que virá do envelope e também do LFO. A frequência central é controlada por um potenciômetro.

Os parâmetros do envelope são:

  - Atack: tempo para a frequência de corte (cutoff) atingir o ponto que está ajustada.
  - Decay: tempo para o cuttof chegar até o sustain.
  - Sustain: frequência de corte estática.

## Circuito de simulação

![vcf]()

![envelope]()

### Resultado da simulação:

Em amarelo: sinal do envelope.

Em azul: sinal de áudio modulado.

Em rosa: sinal de áudio original.

![]()



## Resultados práticos
