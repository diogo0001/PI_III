# PI III
Repositório para o Projeto Integrador III do curso de Engenharia Eletrônica do IFSC Florianópolis.

Alunos: Diogo Tavares e José Nicolau Varela

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

[Este](https://produto.mercadolivre.com.br/MLB-1245546290-sintetizador-analogico-model-d-behringer-_JM?quantity=1#reco_item_pos=1&reco_backend=machinalis-v2p&reco_backend_type=low_level&reco_client=vip-v2p&reco_id=53b2ba6c-0ad8-430d-add6-b6dd5013def7) 
é um "simulador" de MiniMoog da marca Behringer, o qual demonstra o a proposta de produto o qual se deseja desenvolver. 


## O Projeto - Sintetizador Analógico

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

  - uC [stm32f103C8T6](https://www.curtocircuito.com.br/placa-arm-stm32-stm32f103c8t6.html) (Blue Pill): microcontrolador de 32 bits que é mais barato que um Arduino Uno e possui um PWM com resolução de 16 bits. É necessária uma boa resolução do PWM, para precisão do VCO, e consequentemente das notas. Na pasta [Arduino](https://github.com/diogo0001/PI_III/tree/master/Arduino) está a simulação do tratamento do sinal PWM->VCO, que foi feita para testar a técnica utilizando o uC que havia disponivel para simulação.
  - CI ICL8038: gera onda senoide, quadrada e triangular, com ajuste de pwm, pode gerar dente de serra. Aqui está seu [datasheet](https://github.com/diogo0001/PI_III/blob/master/doc/icl8038.pdf).
  - Instrumentação: gerador de sinal e osciloscópio para os testes.
  - Componentes eletrônicos: para a parte analógica.
  - Confecção PCI: para implementar o circuito.
  - Gabinete para a montagem final.
  
  
  #### Parâmetros do VCO
  
  Haverão 2 VCOs que serão mixados, de acordo com o que for desejado. Cada canal terá os seguintes controles:
  
   - Seletor do tipo de onda. Senóide, quadrada (com ajuste de pwm), triangular, dente de serra (obtida por ajuste de pwm).
   São as saídas diretamente do CI.
   - Controle do ganho, que será mo mixer (somador).
   - Seletor de oitava. Seleciona se será exatamente a frequência da nota, metade, ou o dobro. Opção para aumetar as possibilidades 
   para a mixagem das ondas. Este controle é enviado para pinos digitais do uC, que enviará a respectiva oitava. 
   - Controle do pwm da onda. Controle feito no circuito do próprio CI.
  
  #### Parâmetros do VCF
  
  O filtro poderá ser selecionado como Passa Baixa ou Passa Alta, onde será controlada sua frequência de cutoff e a amplitude da 
  frequência de resonância (cutoff). O envelope fará a modulação da dinâmica do filtro. Os parâmetros controlados são:
  
   - Seletor do tipo de filtro. PA ou PB.
   - Controle da frequência de corte (cutoff).
   - Controle da frequência de resonância.
   - Atack, que é o tempo que o filtro leva para atingir o máximo.
   - Decay, que é o tempo que o filtro leva para deixar de agir.
   - Sustain, amplitude mínima que ficará ao final do decay.
   
O envelope recebe o trigger do sinal MIDI enviado enquanto a nota está em ON, e o circuito envelope modula um sinal de tensão de controle, que irá modular a dinâmica do filtro conforme sua envoltória.
  
  #### Parâmetros do VCA
  
  O bloco do controle de amplitude tem os seguintes parâmetros a serem controlados:
  
   - Controle do ganho total.
   - Atack, tempo para atingir a amplitude máxima.
   - Decay, tempo para atingir a amplitude mímima.
   - Sustain, amplitude mínima que ficará ao final do decay.
   - Release, tempo que a nota continuará soando após ser encerrada o sinal MIDI, prolongamento.
   
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
  
  
  ### Referências
  
  
  https://medium.com/@dennisstoelwinder/understanding-every-synthesizer-in-a-5-minute-read-7af0a4a3a920
  
  https://hackaday.io/project/161618-cello-like-mostly-analog-synth/log/153824-vco-vca-vcf
  
  https://sound-au.com/articles/vca-techniques.html
  
  http://www.yusynth.net/Modular/EN/MOOGVCF/index.html
  
  https://www.soundonsound.com/techniques/synthesizing-strings-pwm-string-sounds
  
  https://www.soundonsound.com/techniques/modulation
  
  https://electricdruid.net/voltage-controlled-lfo-vclfo-9d/
 
  https://www.arduino.cc/en/Tutorial/SecretsOfArduinoPWM
  
  https://www.filipeflop.com/blog/como-programar-stm32-em-c/
  
  https://www.schmitzbits.de/adsr.html
  
   - stm32 pwm
  
  https://simonmartin.ch/resources/stm32/dl/STM32%20Tutorial%2002%20-%20PWM%20Generation%20using%20HAL%20(and%20FreeRTOS).pdf
  
  https://www.waveshare.com/wiki/STM32CubeMX_Tutorial_Series:_PWM
  
  https://www.st.com/content/ccc/resource/training/technical/product_training/c4/1b/56/83/3a/a1/47/64/STM32L4_WDG_TIMERS_GPTIM.pdf/files/STM32L4_WDG_TIMERS_GPTIM.pdf/jcr:content/translations/en.STM32L4_WDG_TIMERS_GPTIM.pdf
  https://www.st.com/content/ccc/resource/technical/document/application_note/54/0f/67/eb/47/34/45/40/DM00042534.pdf/files/DM00042534.pdf/jcr:content/translations/en.DM00042534.pdf
  
  https://visualgdb.com/tutorials/arm/stm32/pwm/
  
  http://www.emcu.eu/stm32-basic-timer/
