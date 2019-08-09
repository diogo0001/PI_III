# PI III
Repositório para o projeto integrador III do curso de engenharia eletrônica do IFSC Florianópolis.

## Sintetizador de áudio

É um instrumento musical que gera seus sons eletronicamente. Pode-se controlar diversos parâmetros para modelar o timbre
e caracterizar vários aspectos do som. Existem diversos tipos e modelos de sintetizadores, que podem ser modulares ou 
possuir uma interface para ser tocado (teclado por exemplo).

A seguir é mostrado um sintetizador com teclado:

![Foto](https://upload.wikimedia.org/wikipedia/commons/3/3e/R.A.Moog_minimoog_2.jpg)

Um modular que pode ser utilizado com teclado também:

![Foto](https://upload.wikimedia.org/wikipedia/commons/e/e6/Moog_Modular_55_img2.jpg)

Uma demostração de como funciona um sintetizador pode ser vista [aqui](https://youtu.be/V_kiqQpiVjE?t=380).

### Mercado

Atualmente, estes instrumentos existem tanto puramente analógicos, como eram antigamente, e que possuem as melhores
características em termos de qualidade e "pressão" no som. Existem os digitais, híbridos (analógico-digital), e VST
 (Virtual Studio Tecnology), que são instrumentos virtuais utilizados no computador.

Geralmente possuem um preço elevado, dependendo muito da sua arquitetura e fabricante. 
... continua

## O Projeto - Sintetizador Híbrido

O intuito deste projeto é desenvolver um sintetizador com seus blocos básicos (Vco, Vcf, Vca, LFO e envelopes), sem efeitos.

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
  
  https://hackaday.io/project/161618-cello-like-mostly-analog-synth/log/153824-vco-vca-vcf
  
  https://sound-au.com/articles/vca-techniques.html
  
  http://www.yusynth.net/Modular/EN/MOOGVCF/index.html
 
