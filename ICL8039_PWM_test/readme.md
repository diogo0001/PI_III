## Simulação no proteus

Simulação para validar a utilização do PWM como VCO para o circuito oscilador. É feita a leitura de um valor analógico de um potenciômetro (pino 23) e o reproduz por PWM (pino 15). São utilizados 2 filtros de primeira ordem, com um aplificador de G=3 que atua entre eles, e que atua também como desacoplador. O resultado é um sinal contínuo que pode ter sua amplitude controlada pelo PWM, logo, temos um VCO controlado por PWM.

 A simulação foi feita utilizando o Atmega328, que é o uC que havia disponível no simulador, apenas para testar a técnica.
 
 No proteus, abra o projeto e carregue o arquivo AnalogInOutSerial.ino.hex no Atmega328, configure como mostra a figura a seguir:
  
  ![foto](https://github.com/diogo0001/PI_III/blob/master/ICL8039_PWM_test/atmegaProteusConfig.PNG)
  
  
  ### Circuito de teste
  
  ![foto](https://github.com/diogo0001/PI_III/blob/master/ICL8039_PWM_test/pwm_test_circuit.PNG)
  
  #### Resultados com filtro no pwm
  
  PWM e saída do filtro:
  
  ![foto](https://github.com/diogo0001/PI_III/blob/master/ICL8039_PWM_test/cd_pwm.PNG)
  
  ![foto](https://github.com/diogo0001/PI_III/blob/master/ICL8039_PWM_test/cd_pwm2.PNG)
  
  Variações com o potenciômetro lido pelo ADC do  arduino, o sinal mostrado é o da saída do filtro, que corresponde à variação do potenciômetro amplificada:
  
  ![foto](https://github.com/diogo0001/PI_III/blob/master/ICL8039_PWM_test/variacao_pot.PNG)
  
  ![foto](https://github.com/diogo0001/PI_III/blob/master/ICL8039_PWM_test/variacao_pot2.PNG)


## Resultados de bancada

Filtro 1:

 - R: 2,3 kohms
 - C: 4,7 uF
 
 
 - Vm: 3,17 V
 - PWM: 66%
 - T subida:aprox 30 ms
 - Ripple: 260 mV


 - Vm: 870 mV
 - PWM: 16 %
 - T subida: 19 ms
 - Ripple: 200 mV
