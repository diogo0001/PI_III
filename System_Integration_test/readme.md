# Resultados dos testes da integração do sistema

Aqui serão apresentados os resultados dos testes para a integração de todos os blocos do sistema.

## Integração MIDI(STM32) -> AD9833 

O primeiro estágio consiste em adquirir a nota a ser tocada via MIDI e gerá-la no CI.

A seguir são mostrados o que foi obtido:

![Foto protocolo]()

![Foto frequência gerada]()

...

## Integração de 2 AD9833 -> Somador

Como serão geradas 2 ondas distintas, será utilizado um circuito somador para mixar as nodas antes do VCF

...

## Integração STM32 -> Envelope(VCF) e Somador -> VCF

Para realizar o controle do VCF pelo envelope, é preciso enviar o sinal de gate para o envelope enquanto a nota
é tocada, e este sinal virá do STM32, o VCF receberá então o sinal de controle do envelope e o sinal das ondas vindo
do somador

...

## Integração STM32 - Envelope(VCA) e VCF -> VCA

Será então senviado o sinal do VCF para o VCA, e este, por sua vez, também terá seu envelope, que terá o mesmo sinal de 
controle do envelope VCF, vindo do STM32.

...

## Integração Controles -> STM32 ->AD9833

Para que os parâmetros da escolha da forma de onda, frequência e LFO, existem os controles enviados para a
respectiva parte do sistema.

### Controle Forma de onda  Chave -> STM32

Uma chave de múltiplos estágios enviará a opção para a forma de onda ao STM32, que enviará para o respectivo
AD9833. Cada CI possuirá uma chave seletora de forma de onda, bem como uma para a oitava. Logo, haverão 2 controles
de formas de onda e 2 controles de oitavas, via potenciômetro seletor.

...

### Controle do LFO Pot -> STM32

O LFO será gerado por PWM e será filtrado, o tempo de variação do duty cycle será de acordo com o valor ADC lido do 
potenciômetro de frequência. O amount do LFO (intensidade) será coltrolado pelo potenciômetro do filtro passa baixa.

...

