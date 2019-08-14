## Simulação no proteus

 No proteus, abra o projeto e carregue o arquivo AnalogInOutSerial.ino.hex, e configure como mostra na figura a seguir:
  
  ![foto](https://github.com/diogo0001/PI_III/blob/master/Arduino/atmegaProteusConfig.PNG)
  
 A simulação faz a leitura de um valor analógico e o reproduz por pwm, para verificar os problemas com a frequencia do pwm
 e o transitório do filtro RC. 
 A frequência baixa do pwm (400 Hz) para haver melhor resolução, implica na necessidade de um filtro que prejudica 
 transitórios de tensões rápidos na saída.
