# SesnsoresUwU

Aqui esta el codigo para que funcione el arduino, con comentarios y detalles. En caso de que no entiendan asi. Aqui el algoritmo:

### Algoritmo:

1. **Inicialización del sistema**:
   - Iniciar la comunicación serial a 9600 baudios para enviar mensajes a la consola.
   - Configurar los pines del Arduino: 
     - Pines del motor (izquierda y derecha) como **salida**.
     - Pines de los sensores (agua, luz) como **entrada**.
   - Inicializar el reloj en tiempo real (RTC) para obtener la hora en formato de 24 horas.
   - Si el RTC no se encuentra, mostrar un mensaje de error.

2. **Bucle principal (`loop()`)**:
   - Obtener el tiempo actual en milisegundos con `millis()`.
   - Si ha transcurrido una hora (60 minutos = 3600000 ms) desde el último ciclo, proceder a ejecutar el siguiente flujo. Si no, el programa sigue esperando.

3. **Giro del motor hacia la izquierda**:
   - Activar el motor para que gire hacia la izquierda (usando el pin correspondiente).
   - Registrar el tiempo de inicio del giro hacia la izquierda (almacenar `millis()`).

4. **Esperar a la detección de agua**:
   - Mientras el sensor de agua no detecte agua (es decir, mientras el valor analógico del sensor de agua sea menor a un umbral), el motor sigue girando hacia la izquierda.
   - Cuando el sensor de agua detecta la presencia de agua (valor superior al umbral), el motor se detiene y se calcula el tiempo que tomó en llegar abajo (diferencia entre el tiempo actual y el tiempo de inicio del giro hacia la izquierda).

5. **Pausa de 8 minutos**:
   - Esperar durante 8 minutos (480000 ms) sin hacer nada mientras el motor está detenido.

6. **Giro del motor hacia la derecha**:
   - Después de la pausa, activar el motor para que gire hacia la derecha.
   - El motor debe girar hacia la derecha por el mismo tiempo que tardó en girar hacia la izquierda (el tiempo registrado antes de detectar el agua).
   - Cuando el motor haya girado ese tiempo, se detiene.

7. **Medir la intensidad de luz**:
   - Una vez que el motor ha llegado a la posición "arriba", leer la intensidad de luz a través del sensor de luz.
   - Leer la hora actual usando el RTC.
   - Enviar a la consola el valor de la luz y la hora actual en formato de 24 horas (hora:minutos:segundos).

8. **Esperar 60 minutos**:
   - Actualizar el tiempo del último ciclo para comenzar la espera de una nueva hora (60 minutos).
   - Mientras no se haya cumplido una nueva hora, el programa sigue esperando en el bucle principal.

9. **Repetir el ciclo**:
   - Una vez que ha transcurrido una hora, el ciclo se repite desde el giro hacia la izquierda del motor.

### Variables clave:
- `tiempoInicioMotor`: Guarda el momento en el que el motor comenzó a girar hacia la izquierda.
- `tiempoMotorAbajo`: Tiempo que el motor tardó en bajar hasta que el sensor de agua detectó agua.
- `duracionGiroDerecha`: Duración del tiempo que el motor girará hacia la derecha (igual a `tiempoMotorAbajo`).
- `ultimoCiclo`: Guarda el momento en que el último ciclo completo terminó para calcular el tiempo de espera hasta el próximo ciclo.

### Flujo lógico:

1. Esperar 60 minutos ➡️ Iniciar el motor (izquierda) ➡️ Detectar agua ➡️ Pausa 8 minutos ➡️ Iniciar el motor (derecha) ➡️ Medir luz y registrar hora ➡️ Esperar nuevamente 60 minutos ➡️ Repetir.


# Notas;
- Iba a conectar una pantalla lcd para que ahi mostrara los resultados antes de hacer una BD para mostrarlos remotamente
¿Por que no esta? Por que no pude hacerlo


- Tengo 19, voy en primer semestre de Ing. Sistemas Computacionales, tal vez para ustedes parezca sencillo. Y en teoria lo es. Pero
al final de cuentas sigo aprendiendo a programar y hacer otras cosas. Atte Tellez (https://www.instgram.com/rat4life.rar)


## Dev by V.Tellez (RataLife)