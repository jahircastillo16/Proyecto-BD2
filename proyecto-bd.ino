int diferenciaMaxMin = 0; //salida sensor
int lecturaMaxima = 0; //valor maximo
int lecturaMinima = 1023; //valor mínimo
int lecturaSensor; // valor que lee a la salida del sensor
 float voltaje;
#define glucoseSensor A0 //A0 Salida Sensor glucómetro

void setup() {
  Serial.begin(9600); // Inicializar la comunicación serial a 9600 baudios
}

void loop() {
//Almacenar los valores de la salida del sensor
 lecturaSensor = analogRead(A3);
 //Si los valores de la salida son mayores que la lectura máxima, estos valores son ahora los máximos
 if (lecturaSensor>lecturaMaxima)
 {
 lecturaMaxima=lecturaSensor;
 }
 //Si los valores de la salida son menores que la lectura mínima, estos valores son ahora los mínimos

if (lecturaSensor<lecturaMinima)
 {
 lecturaMinima=lecturaSensor;
 }

 
if (lecturaSensor>lecturaMinima)
{
if (lecturaSensor<lecturaMaxima)
{
  // 125 veces*4ms=500ms encendido y 500 ms apagado
 diferenciaMaxMin = lecturaMaxima-lecturaMinima;
 lecturaMaxima=0;
 lecturaMinima=1023;
 voltaje = (diferenciaMaxMin*3.3)/1023;
 Serial.print("Nivel de glucosa: ");
 Serial.print(diferenciaMaxMin);
 Serial.print(" mg/dl");
 Serial.print(" Voltaje: ");
 Serial.println(voltaje);
 }
 else
 {
  diferenciaMaxMin=0;
  voltaje = 0;
 }
}
 delay(1000); // Esperar 1 segundo antes de volver a leer
}
