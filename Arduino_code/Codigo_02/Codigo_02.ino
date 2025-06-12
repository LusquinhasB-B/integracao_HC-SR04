#include <WiFi.h>
#include <HTTPClient.h>

//--------------Configurando o WiFi------------------//
const char* ssid = "iot-senac";
const char* password = "senac2025";

const char* server = "http://192.168.1.100:5000/dados"; // IP do PC com Flask

//--------------Configurando os pinos do esp32------------------//
const int trigPin = 5;
const int echoPin = 4;

//--------------Configurando o setup do arduino------------------//
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  //Enquanto o WiFi não estiver conectado, ele conituará procurando
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //Quando conectar, ele mostrará a Mensagem
  Serial.println("\nConectado ao Wi-Fi");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

//--------------Configurando o loop de funcionamento do código------------------//
void loop() {
  // Medir distância
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2;

  Serial.print("Distância: ");
  Serial.println(distance);

  // Enviar para o Flask via GET
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String url = String(server) + "?distancia=" + String(distance, 2);
    http.begin(url);
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      Serial.print("Resposta HTTP: ");
      Serial.println(httpResponseCode);
    } else {
      Serial.print("Erro HTTP: ");
      Serial.println(http.errorToString(httpResponseCode));
    }

    http.end();
  }

  delay(10000); // Espera 10 segundos
}
