#include <Wire.h>
#include <RTClib.h>  // Librería para manejar el reloj en tiempo real

RTC_DS1307 rtc;

// Pines
const int pinSensorAgua = A0;
const int pinSensorLuz = 3;
const int pinMotorIzquierda = 4;
const int pinMotorDerecha = 5;

// Variables de control de tiempo
unsigned long tiempoInicioMotor;
unsigned long tiempoMotorAbajo;
unsigned long duracionGiroDerecha;
unsigned long ultimoCiclo = 0;
const unsigned long intervaloCiclo = 3600000;  // 60 minutos en milisegundos

void setup() {
  Serial.begin(9600);

  // Inicializar los pines del motor
  pinMode(pinMotorIzquierda, OUTPUT);
  pinMode(pinMotorDerecha, OUTPUT);

  // Inicializar los sensores
  pinMode(pinSensorAgua, INPUT);
  pinMode(pinSensorLuz, INPUT);

  // Inicializar el RTC
  if (!rtc.begin()) {
    Serial.println("No se pudo encontrar el RTC");
    while (1);
  }
  if (!rtc.isrunning()) {
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));  // Ajustar a la hora de compilación
  }

  Serial.println("Sistema inicializado");
}

void loop() {
  unsigned long tiempoActual = millis();

  // Verificar si ha pasado una hora desde el último ciclo
  if (tiempoActual - ultimoCiclo >= intervaloCiclo) {
    // Girar el motor hacia la izquierda
    Serial.println("Motor girando hacia la izquierda...");
    digitalWrite(pinMotorIzquierda, HIGH);
    tiempoInicioMotor = millis();

    // Esperar hasta que se detecte agua
    while (analogRead(pinSensorAgua) < 500) {
      // Esperar a que el sensor de agua detecte agua
    }
    
    digitalWrite(pinMotorIzquierda, LOW);
    tiempoMotorAbajo = millis() - tiempoInicioMotor;  // Guardar cuánto tiempo tomó girar hacia abajo
    Serial.println("Agua detectada, motor detenido.");
    
    // Esperar 8 minutos
    delay(480000);

    // Girar el motor hacia la derecha por el mismo tiempo que tomó bajar
    Serial.println("Motor girando hacia la derecha...");
    digitalWrite(pinMotorDerecha, HIGH);
    delay(tiempoMotorAbajo);
    digitalWrite(pinMotorDerecha, LOW);
    Serial.println("Motor detenido en la posición 'arriba'.");

    // Leer el sensor de luz y enviar datos a la consola
    int intensidadLuz = analogRead(pinSensorLuz);
    DateTime now = rtc.now();
    Serial.print("Hora actual: ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.println(now.second(), DEC);
    Serial.print("Intensidad de luz: ");
    Serial.println(intensidadLuz);

    // Actualizar el último ciclo
    ultimoCiclo = millis();
  }
}
