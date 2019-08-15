# PI III
Repositório para o projeto integrador III do curso de engenharia eletrônica do IFSC Florianópolis.

## Sintetizador de áudio


É um instrumento musical que gera seus sons eletronicamente. Pode-se controlar diversos parâmetros para modelar o timbre
e caracterizar vários aspectos do som. Existem diversos tipos e modelos de sintetizadores, que podem ser modulares ou 
possuir uma interface para ser tocado (teclado por exemplo). Podem ser mono ou polifônicos (uma ou mais notas simultaneamente).

A seguir é mostrado um sintetizador com teclado, o clássico MiniMoog:

![Foto](https://upload.wikimedia.org/wikipedia/commons/3/3e/R.A.Moog_minimoog_2.jpg)

Um modular que pode ser utilizado com teclado também:

![Foto](https://upload.wikimedia.org/wikipedia/commons/e/e6/Moog_Modular_55_img2.jpg)

Uma demostração de como funciona um sintetizador pode ser vista nos links a seguir:

https://www.youtube.com/watch?v=nOp25yIoPjo

https://youtu.be/V_kiqQpiVjE?t=380


### Mercado

Atualmente, estes instrumentos existem tanto puramente analógicos, como eram antigamente, e que possuem as melhores
características em termos de qualidade e "pressão" no som, segundo muitos. Existem os digitais, híbridos (analógico-digital), e VST
 (Virtual Studio Tecnology), que são instrumentos virtuais utilizados no computador.

Sintetizadores podem ter um preço elevado, dependendo muito da sua arquitetura e fabricante. O modelo que se norteará este projeto
é o [MiniMoog](https://en.wikipedia.org/wiki/Minimoog), que é um sintetizador monofônico extremamente popular desde os anos 70.
Foi encontrado um modelo usado por R$23.000,00, como pode ser visto [aqui](https://produto.mercadolivre.com.br/MLB-1237333066-minimoog-model-d-vintage-original-ano1974-sn438x-_JM?quantity=1&variation=37701313709).

[Este](https://produto.mercadolivre.com.br/MLB-1008756851-behringer-model-d-clone-mini-moog-entrega-a-partir-de-147-_JM) 
é um simulador de MiniMoog da marca Behringer, o qual demonstra o a proposta de produto o qual se deseja desenvolver. 


## O Projeto - Sintetizador Híbrido

O intuito deste projeto é desenvolver um sintetizador com seus blocos básicos (Vco, Vcf, Vca, LFO e envelopes), 
monofônico e sem efeitos, como é um minimoog.

A seguir é mostrado um diagrama de blocos padrão de um sintetizador:

![Foto](https://upload.wikimedia.org/wikipedia/commons/8/86/Synthesizer.components.01.png)

Para este projeto, sinal MIDI é recebido de um teclado controlador com as informações das notas, gera uma tensão respectiva por meio de pwm para emular uma tensão analógica que passará por um filtro passa baixa, para assim, alimentar o Vco do CI ICL8039, que gera as formas de onda. Após esta etapa, passa pelos blocos analógicos de VCF(Voltage Controled Filter) e pelo VCA(Voltage Controled Amplifier). Para as modulações serão feitos os envelopes e o LFO.

A seguir está o diagrama de blocos do projeto:

![foto](https://github.com/diogo0001/PI_III/blob/master/images/Synth%20Diagram.png)

Este é um esboço 3D de como será o projeto:

![foto](https://github.com/diogo0001/PI_III/blob/master/images/Synth%203d.png)

### Requisitos de projeto

Serão utilizados neste projeto:

  - uC [stm32f103C8T6](https://www.curtocircuito.com.br/placa-arm-stm32-stm32f103c8t6.html) (Blue Pill): microcontrolador de 32 bits que é até mais barato que um Arduino Uno e possui um PWM com resolução de 16 bits. É necessária uma boa resolução do PWM, bem como uma frequência alta, para precisão do VCO, e consequentemente das notas.
  - CI ICL8038: gera senoide, quadrada e triangular, con ajuste de pwm, pode gerar dente de serra. Aqui está seu [datasheet](https://github.com/diogo0001/PI_III/blob/master/doc/icl8038.pdf).
  - Instrumentação: gerador de sinal e osciloscópio para os testes.
  - Componentes eletrônicos: para a parte analógica.
  - Confecção PCI: para implementar o circuito.
  
  
  ### Referências
  
  
  https://medium.com/@dennisstoelwinder/understanding-every-synthesizer-in-a-5-minute-read-7af0a4a3a920
  
  https://hackaday.io/project/161618-cello-like-mostly-analog-synth/log/153824-vco-vca-vcf
  
  https://sound-au.com/articles/vca-techniques.html
  
  http://www.yusynth.net/Modular/EN/MOOGVCF/index.html
  
  https://www.soundonsound.com/techniques/synthesizing-strings-pwm-string-sounds
  
  https://www.soundonsound.com/techniques/modulation
  
  https://electricdruid.net/voltage-controlled-lfo-vclfo-9d/
 
  https://www.arduino.cc/en/Tutorial/SecretsOfArduinoPWM
