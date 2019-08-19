## Simulação no proteus

Simulação para validar a utilização do PWM como VCO para o circuito oscilador. É feita a leitura de um valor analógico de um potenciômetro e o reproduz por PWM. São utilizados 2 filtros de primeira ordem, com um aplificador de G=3 que atua entre eles, e que atua também como desacoplador. O resultado é um sinal contínuo que pode ter sua amplitude controlada pelo PWM, logo, temos um VCO controlado por PWM.

 No proteus, abra o projeto e carregue o arquivo AnalogInOutSerial.ino.hex, configure como mostra na figura a seguir:
  
  ![foto](https://github.com/diogo0001/PI_III/blob/master/Arduino/atmegaProteusConfig.PNG)
  
  
  ### Circuito de teste
  
  ![foto](https://github.com/diogo0001/PI_III/blob/master/Arduino/pwm_test_circuit.PNG)
  
  #### Resultados com filtro no pwm
  
  PWM e saída do filtro:
  
  ![foto](https://github.com/diogo0001/PI_III/blob/master/Arduino/cd_pwm.PNG)
  
  ![foto](https://github.com/diogo0001/PI_III/blob/master/Arduino/cd_pwm2.PNG)
  
  Variações com o potenciômetro lido pelo ADC do  arduino, o sinal mostrado é o da saída do filtro, que corresponde à variação do potenciômetro amplificada:
  
  ![foto](https://github.com/diogo0001/PI_III/blob/master/Arduino/variacao_pot.PNG)
  
  ![foto](https://github.com/diogo0001/PI_III/blob/master/Arduino/variacao_pot2.PNG)
