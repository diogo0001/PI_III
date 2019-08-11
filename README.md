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
Foi encontrado um modelo usado por R$23.000,00, como pode ser visto [aqui](https://produto.mercadolivre.com.br/MLB-1237333066-minimoog-model-d-vintage-original-ano1974-sn438x-_JM?quantity=1&variation=37701313709)

[Este](https://produto.mercadolivre.com.br/MLB-1008756851-behringer-model-d-clone-mini-moog-entrega-a-partir-de-147-_JM) 
é um simulador de MiniMoog da marca Behringer, o qual demonstra o a proposta de produto o qual se deseja desenvolver. 


## O Projeto - Sintetizador Híbrido

O intuito deste projeto é desenvolver um sintetizador com seus blocos básicos (Vco, Vcf, Vca, LFO e envelopes), 
monofônico e sem efeitos, como é um minimoog.

A seguir é mostrado um diagrama de blocos padrão de um sintetizador:

![Foto](https://upload.wikimedia.org/wikipedia/commons/8/86/Synthesizer.components.01.png)

Para este projeto, sinal MIDI é recebido de um teclado controlador com as informações das notas, gera as ondas digitalmente, podendo mixar 2 formas de onda para gerar o timbre. Depois de passar por um DAC, passa pelos blocos analógicos de VCF(Voltage Controled Filter) e pelo VCA(Voltage Controled Amplifier). Para as modulações serão feitos os envelopes e o LFO.

### Requisitos de projeto

Serão utilizados neste projeto:

  - [Arduino DUE](https://store.arduino.cc/usa/due): microcontrolador de 32 bits, com DAC de 12 bits, que já é uma resolução satisfatória para a aplicação. 
  - [PlatformIO](https://platformio.org/): Ide para o desenvolvimento do código.
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
 
