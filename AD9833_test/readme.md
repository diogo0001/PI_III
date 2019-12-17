# Testes para o CI AD9833

No teclado musical controlador MIDI foram gerados os códigos das notas musicais utilizando o protocolo MIDI, tres bytes,
0x90, 0x2C, 0x5A  sendo o primeiro byte (0x90) o comando  on (nota acionada) ou off (desativada) , o byte seguinte representa  a nota musical  (0x2C) que neste caso é a nota lá (220 Hz);
e o terceiro byte (0x5A) representa o volume. Para este projeto , o terceiro byte só é cosiderado quando for igual a 0x00, significando que a nota musical foi desativada.
![foto](https://github.com/diogo0001/PI_III/blob/master/AD9833_test/esquema%20placa%20midi.PNG)
 ### PLACA CONTROLADORA MIDI

Através da placa controladora MIDI esses dados são tranferidos via serial para o microcontrolador e decodificados para a geração da onda na frequência da nota tocada.
Para a geração das ondas , utilizamos o CI AD9833 que utiliza o protocolo SPI para comunicação.

            ### FORMAS DE ONDAS GERADAS PELO CI AD9833 
 
![foto](https://github.com/diogo0001/PI_III/blob/master/AD9833_test/senoidal_220Hz.PNG)

![foto](https://github.com/diogo0001/PI_III/blob/master/AD9833_test/triangular_220Hz.PNG)

![foto](https://github.com/diogo0001/PI_III/blob/master/AD9833_test/quadrada_220Hz.PNG)

 
