# PI III
Repositório para o Projeto Integrador III do curso de Engenharia Eletrônica - IFSC Florianópolis.

Alunos: Diogo Tavares e José Nicolau Varela.

O cronograma previsto para as atividades pode ser visto [aqui](https://github.com/diogo0001/PI_III/blob/master/cronograma.md).

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

Sintetizadores podem ter um preço elevado, dependendo muito da sua arquitetura e fabricante. O modelo que norteará este projeto
é o [MiniMoog](https://en.wikipedia.org/wiki/Minimoog), que é um sintetizador monofônico extremamente popular desde os anos 70.
Foi encontrado um modelo usado por R$23.000,00, como pode ser visto [aqui](https://produto.mercadolivre.com.br/MLB-1237333066-minimoog-model-d-vintage-original-ano1974-sn438x-_JM?quantity=1&variation=37701313709).

[Este](https://produto.mercadolivre.com.br/MLB-1245546290-sintetizador-analogico-model-d-behringer-_JM?quantity=1#reco_item_pos=1&reco_backend=machinalis-v2p&reco_backend_type=low_level&reco_client=vip-v2p&reco_id=53b2ba6c-0ad8-430d-add6-b6dd5013def7) 
é um "simulador" de MiniMoog da marca Behringer, o qual demonstra o a proposta de produto o qual se deseja desenvolver. 


## O Projeto - Sintetizador Híbrido

Como mostrado anteriormente, este mercado pode ter um bom potencial a ser explorado. E para nós, apreciadores do áudio, é uma grande oportunidade para aplicar os conhecimentos adquiridos até então.
Busca-se com este projeto, compreender as etapas e desafios no desenvolvimento destes instrumentos, para que, futuramente,
seja possível ter uma bagagem para o aperfeiçoamento e produção destes para o mercado.

Este projeto consiste em desenvolver um sintetizador híbrido(digital/analógico) com seus blocos básicos (Vco, Vcf, Vca, LFO e envelopes), monofônico e sem efeitos, como é um minimoog.

A seguir é mostrado um diagrama de blocos padrão de um sintetizador:

![Foto](https://upload.wikimedia.org/wikipedia/commons/8/86/Synthesizer.components.01.png)

Na implementação que será desenvolvida, o sinal MIDI é recebido de um teclado controlador com as informações das notas, e aí será gerada a forma de onda desejada com a respectiva frequência (será estudada a melhor forma para a geração das ondas). Após esta etapa, o sinal passa pelos blocos analógicos de VCF(Voltage Controled Filter) e pelo VCA(Voltage Controled Amplifier). Para as modulações serão feitos os envelopes e o LFO.

A seguir está o diagrama de blocos do projeto:

![foto](https://github.com/diogo0001/PI_III/blob/master/images/Synth%20Diagram.png)

Este é um esboço 3D de como será o projeto:

![foto](https://github.com/diogo0001/PI_III/blob/master/images/Synth%203d.png)

### Requisitos de projeto

Serão utilizados neste projeto:

  - uC [stm32f103C8T6](https://www.curtocircuito.com.br/placa-arm-stm32-stm32f103c8t6.html) (Blue Pill): microcontrolador de 32 bits. 
  Possui resolução de PWM de 16 bits e 2 portas SPI. Aqui está seu [datasheet](https://github.com/diogo0001/PI_III/blob/master/STM32_docs_codes/docs/stm32%20series%20datasheet.pdf).
  ![](https://github.com/diogo0001/PI_III/blob/master/STM32_docs_codes/docs/stm32-Bluepill_pinout.png)
  - CI ICL8038: gera onda senoide, quadrada e triangular, com ajuste de pwm, pode gerar dente de serra. Aqui está seu [datasheet](http://www.mit.edu/~6.331/icl8038data.pdf). (Foram feitos testes , e este acabou sendo descartado do projeto)
  - CI AD9833: gera formas de onda com comunicação SPI, e controle digital. Aqui está seu [datasheet](https://www.analog.com/media/en/technical-documentation/data-sheets/AD9833.pdf).
  ![](https://github.com/diogo0001/PI_III/blob/master/Images/ad9833.PNG)
  - Instrumentação: gerador de sinal e osciloscópio para os testes.
  - Componentes eletrônicos: para a parte analógica.
  - Confecção PCI: para implementar o circuito.
  - Gabinete para a montagem final.
  
  
  #### Parâmetros do VCO
  
  Haverão 2 VCOs que serão mixados, de acordo com o que for desejado. Cada canal terá os seguintes controles:
  
   - Seletor do tipo de onda. Senóide, quadrada e triangular. 
   - Controle do ganho.
   - Seletor de oitava. Seleciona se será exatamente a frequência da nota, metade, ou o dobro. Opção para aumetar as possibilidades 
   para a mixagem das ondas. Este controle é enviado para pinos digitais do uC, que enviará a respectiva oitava. 
  
  #### Parâmetros do VCF
  
  O filtro poderá ser selecionado como Passa Baixa ou Passa Alta, onde será controlada sua frequência de cutoff e a amplitude da 
  frequência de resonância (cutoff). O envelope fará a modulação da dinâmica do filtro. Os parâmetros controlados são:
  
   - Controle da frequência de corte (cutoff).
   - Controle da frequência de resonância.
   - Atack, que é o tempo que o filtro leva para atingir o ponto da frequência de corte.
   - Decay, que é o tempo que o filtro leva para  atingir o nível de sustain.
   - Sustain, amplitude que ficará sustentada.
   
   Basicamente, o envelope realizará as modulações acima descritas como se fosse um controle manual no pot de frequência.
   
O envelope recebe o trigger do sinal MIDI enviado enquanto a nota está em ON, e o circuito envelope modula um sinal de tensão de controle, que irá modular a dinâmica do filtro conforme sua envoltória.
  
  #### Parâmetros do VCA
  
  O bloco do controle de amplitude tem os seguintes parâmetros a serem controlados:
  
   - Controle do ganho total.
   - Atack, tempo para atingir a amplitude máxima.
   - Decay, tempo para decair até a amplitude de sustain.
   - Sustain, amplitude que ficará sustentada.
   - Release, tempo que amplitude levará para chegar a zero, após ser encerrada o sinal MIDI, prolongamento.
   
   O envelope age da mesma forma que no VCF, onde fará aqui, a modulação do sinal na sua amplitude.
  
  #### Parâmetros do LFO
  
  O LFO será gerado por PWM diretamente do uC, e passará por um filtro PB. Os seguintes parâmetros podem ser controlados:
  
   - Frequência da oscilação, que será um sinal analógico enviado ao uC para o ajuste da modulação do PWM. Será uma onda 
   triangular, que é mais simples de ser gerada e o seu efeito é praticamente igual à uma senoide. O controle do amount 
   no filtro PB também atenua as pontas da onda.
   - Amount, que é a intensidade ou profundidade da atuação do LFO sobre seu target. Em outras palavras, a amplitude do LFO.
   É controlado no filtro PB, e modifica um pouco a forma da onda, deixando a triangular com aspecto de senónide conforme
   maior for sua atenuação.
   - Target, é o bloco que se deseja aplicar. Pode ser o cutoff do VCF, o ganho do VCA, ou desligado.
 
 ## Desenvolvimento
  
  A metodologia adotada foi a implementação e testes de cada bloco do sistema de forma independente, uma vez que os requisitos foram estabelecidos, a implementação de cada bloco pode ser feita em paralelo com outro bloco.
  
  A primeira etapa, durante o levantamento dos parâmetros desejados para o projeto, foi definir como seriam gerados os sinais. 
  Iniciamlente pensou-se em criar as formas de onda em um uC, porém, além de exigir um dispositivo com capacidade para tal, 
  a interface com o mundo analógico também deve ser considerada. Pensou-se em utilizar um Arduino DUE de 32 bits, que possui 2 saídas DAC de 12 bits, porém, não pareceu ter muita qualidade para o propósito, segundo relatos em fóruns. Além disso, o uC é muito grande, e não poderia ser incorporado à placa, sendo necessário o uso de jumpers. Logo, procuramos por outras alternativas.
  
  Outra opção seria utilizar o stm32f103C8T8 (Blue Pill), que também é de 32 bits, com preço bem acessível, mais barato até que um Arduino Uno de 8 bits. No entanto, ele não possui saída DAC. Cogitou-se utilizar um DAC externo que já possuíamos (no caso 2, pois faremos para 2 formas de onda), o problema é a quantidade de pinos necessários para isso.
 
 Durante algumas pesquisas, foi encontrado o CI ICL8038, que é um gerador de formas de onda, muito utilizado para geradores de função
  DIY (Do It Yourself). Este pareceu ser uma boa solução , pois o que precisaríamos fazer seria gerar o VCO para controlá-lo. 
  
  Foi decidido utilizar, inicialmente, o CI ICL8038, e a técnica para o VCO consiste em gerá-lo por PWM. Conforme a nota é obtida pelo sinal MIDI, uma largura específica de PWM é gerada, isso deve ser feito nota a nota, para afiná-las. Logo, decidimos utilizar o uC stm32f103C8T8, pois ele possui PWM de 16 bits (65536 possibilidades de ajuste). o Problema é que PWM é um sinal pulsado, e o uC gera uma tensão de até 3,3 V na saída, sendo necessário também amplificá-la para alimentar o VCO do CI, que será até 12 V. Uma possível solução encontrada e os respectivos testes podem ser vistos [aqui](https://github.com/diogo0001/PI_III/blob/master/ICL8039_PWM_test/readme.md).  Apesar de ser possível, esta solução apresentou inconvenientes e limitações, como foi apresentado. Decidiu-se utilizar então o CI AD9833, gerador de funções digital, com comunicação via SPI. O uso do stm32 foi mantido devido ao fato de ele possiur duas portas SPI, pois deseja-se utilizar 2 geradores independentes. Os testes de comunicação e a geração das formas de onda pode ser visto [aqui](https://github.com/diogo0001/PI_III/blob/master/AD9833_test/readme.md).
  
  Para a obtenção do [protocolo MIDI](https://ccrma.stanford.edu/~craig/articles/linuxmidi/misc/essenmidi.html) vindo do controlador, foi utilizada a porta serial do stm32, que recebe os protocolos cada vez que uma nota é tocada. Os testes de aquisição destes valores pela serial podem ser vistos [aqui](https://github.com/diogo0001/PI_III/tree/master/MIDI_test). Foi então feita a lógica para obter a nota, e o tempo que esta permanece ligada. Foi criado um vetor com os parâmetros a serem enviados para o AD9833, onde o índice do vetor
é o parâmetro retirado diretamente do protocolo MIDI. 
  
  Paralelamente ao desenvolvimento do sistema para o MIDI, foi feita a pesquisa e testes para os circuitos de envelope, VCA e VCF.
  Os resultados dos testes isolados para o VCA com envelope podem ser vistos [aqui](https://github.com/diogo0001/PI_III/blob/master/VCA_test/readme.md), e para o VCF com envelope pode ser visto [aqui](https://github.com/diogo0001/PI_III/tree/master/VCF_test).
  
  Foi feita a implementação do LFO por software, onde a variação da amplitude será gerada por PWM, e a frequência será a taxa que o
  duty cycle varia. A regulagem para a frequência do LFO é feita por um potenciômetro lido pelo ADC do STM32. Um filtro passa baixa
  é utilizado na saída no uC, e um potenciômetro na parte R do filtro RC será responsável intensidade da amplitude do LFO. Os resultados
  dos testes do LFO podem ser vistos [aqui](https://github.com/diogo0001/PI_III/blob/master/LFO_test/readme.md).
  
  Após todas as partes do sistema serem implementadas e testadas, iniciou-se a integração de todo o sistema, as etapas adotadas
  e os resultados podem ser vistos [aqui](https://github.com/diogo0001/PI_III/tree/master/System_Integration_test).
  
  Para a montagem final do sistema, foram criadas placas de circuito impresso (PCIs) em módulos, de modo que ficasse mais prático
  o desenvolvimento e correção de erros, os layouts das placas e as mesmas montadas podem ser vistas [aqui](https://github.com/diogo0001/PI_III/blob/master/Board_layout/readme.md).
  Os resultados finais, com o sistema todo montado, integrado e e em funcionamento, bem como os vídeos, podem ser vistos [aqui](https://github.com/diogo0001/PI_III/tree/master/Final_results). 
  
  ### Conclusão
  
  ### Referências
  
  
  https://medium.com/@dennisstoelwinder/understanding-every-synthesizer-in-a-5-minute-read-7af0a4a3a920
  
  https://hackaday.io/project/161618-cello-like-mostly-analog-synth/log/153824-vco-vca-vcf
  
  https://sound-au.com/articles/vca-techniques.html
  
  http://www.yusynth.net/Modular/EN/MOOGVCF/index.html
  
  https://www.soundonsound.com/techniques/synthesizing-strings-pwm-string-sounds
  
  https://www.soundonsound.com/techniques/modulation
  
  https://electricdruid.net/voltage-controlled-lfo-vclfo-9d/
  
  http://electro-music.com/forum/phpbb-files/simplevcf_252_119.gif
 
  https://www.arduino.cc/en/Tutorial/SecretsOfArduinoPWM
  
  https://www.filipeflop.com/blog/como-programar-stm32-em-c/
  
  https://www.schmitzbits.de/adsr.html
  
  http://www.circuitstoday.com/audio-oscillator-circuit-2
  
   - stm32 pwm
  
  https://simonmartin.ch/resources/stm32/dl/STM32%20Tutorial%2002%20-%20PWM%20Generation%20using%20HAL%20(and%20FreeRTOS).pdf
  
  https://www.waveshare.com/wiki/STM32CubeMX_Tutorial_Series:_PWM
  
  https://www.st.com/content/ccc/resource/training/technical/product_training/c4/1b/56/83/3a/a1/47/64/STM32L4_WDG_TIMERS_GPTIM.pdf/files/STM32L4_WDG_TIMERS_GPTIM.pdf/jcr:content/translations/en.STM32L4_WDG_TIMERS_GPTIM.pdf
  https://www.st.com/content/ccc/resource/technical/document/application_note/54/0f/67/eb/47/34/45/40/DM00042534.pdf/files/DM00042534.pdf/jcr:content/translations/en.DM00042534.pdf
  
  https://visualgdb.com/tutorials/arm/stm32/pwm/
  
  http://www.emcu.eu/stm32-basic-timer/
  
  [Video](https://www.youtube.com/watch?v=EaZuKRSvwdo) stm32 Arduino IDE
  
  Cálculo da frequência das notas:
  
  https://pages.mtu.edu/~suits/NoteFreqCalcs.html
  https://www.quora.com/Why-are-the-frequencies-of-musical-notes-in-geometric-progression
  
  Exemplo para ad9832:
  
  https://gist.github.com/2e1hnk/d102c36f259060f51d95aa5dbc4c2372
