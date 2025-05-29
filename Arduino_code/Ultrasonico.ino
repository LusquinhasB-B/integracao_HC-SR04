#include <WiFi.h>


const char* ssid = "iot-senac";
const char* password = "senac2025";

// IP ou domínio da sua API PHP
const char* server = "http://localhost/Projeto27-05/Web/dados.php";

const int trigPin = 5;
const int echoPin = 6;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Conectado ao Wi-Fi");
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Medir distância
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2;

  //Aguarda 30 segundos para enviar o dado para o banco
  delay(30000);

  // Enviar para API
  conexaobanco();

  delay(5000); // Espera 5 segundos para nova leitura
}

void conexaoBanco(){
  WiFiClient client;
  if (client.connect("localhost", 80)) {
    String url = "Web/dados.php?distancia=" + String(distance);
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                  "Host: localhost" +
                  "Connection: close");
  }
}


