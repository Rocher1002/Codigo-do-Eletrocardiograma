void setup() {
  // Inicializa a comunicação serial com uma taxa de transmissão de 9600 bauds.
  Serial.begin(9600);

  // Configura o pino 10 como uma entrada para detectar a condição de "leads off" positivo (LO +).
  pinMode(10, INPUT);

  // Configura o pino 11 como uma entrada para detectar a condição de "leads off" negativo (LO -).
  pinMode(11, INPUT);
}

void loop() {
  // Verifica se o pino 10 ou o pino 11 estão em nível alto (1).
  // Se algum deles estiver em nível alto, envia um caractere '!' para a comunicação serial.
  if ((digitalRead(10) == 1) || (digitalRead(11) == 1)) {
    Serial.println('!');
  } else {
    // Se ambos os pinos 10 e 11 estiverem em nível baixo (0), lê o valor do pino analógico A0.
    // Envia esse valor para a comunicação serial.
    Serial.println(analogRead(A0));
  }

  // Aguarda 1 milissegundo para evitar a saturação dos dados seriais e garantir uma transmissão mais estável.
  delay(1);
}

