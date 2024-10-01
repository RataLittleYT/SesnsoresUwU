@echo off
cls
/*EsquemaParaEjceutarYApreciarComoVentanaEmergente*/
:loop
cls
echo +--------------------+                 +-------------------------+
echo |      Arduino       |                 |       Protoboard         |
echo |                    |                 |                         |
echo |   [5V] ---------+--|-----------------|-------------------------| 
echo |   [GND] --------|--|-----------------|-------------------------| 
echo |                 |  |                 |                         | 
echo |   [2]  ---------|--|-----------------|--> Sensor de Agua        |
echo |   [A0] ---------|--|-----------------|--> Sensor de Luz         |
echo |   [3]  ---------|--|-----------------|--> Motor (Izquierda)     |
echo |   [4]  ---------|--|-----------------|--> Motor (Derecha)       |
echo |   [7]  ---------|--|-----------------|--> Sensor de Temperatura |
echo |                    |                 |                         |
echo +--------------------+                 +-------------------------+

timeout /t 2 >nul
goto loop
