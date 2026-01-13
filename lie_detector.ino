/*
  Master Mini Lie Detector Simulator
  Автор: [Вашето име]
  Дата: 02.10.2024
  Платформа: Arduino Uno
  Цел: Симулиране на работата на детектор на стрес/лъжата с LED и Serial Monitor.
  
  Описание:
  - Кодът симулира биометрични показатели (пулс, GSR, температура) без реални сензори.
  - Вграден LED на пин 13 се използва за визуална индикация:
      HIGH = ALERT (червен LED)
      LOW  = NORMAL (зелено)
  - Serial Monitor показва текущите симулирани стойности и състоянието.
*/

const int ledPin = 13;          // Вграден LED на платката
const int baseScore = 100;      // Базово „спокойно“ състояние
const int alertThreshold = 110; // Праг за ALERT
const int updateInterval = 1000; // Време за ново измерване (ms)

int simulatedPulse = 0;
int simulatedGSR = 0;
int simulatedTemp = 0;
int combinedScore = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("=== Mini Lie Detector Simulator ===");
  Serial.println("Симулация без реални сензори");
  Serial.println("---------------------------------");
}

void loop() {
  // 1. Генерираме случайни стойности за симулираните сензори
  simulatedPulse = random(70, 120);  // Симулирана сърдечна честота (BPM)
  simulatedGSR = random(300, 700);   // Симулирана кожна проводимост (условни единици)
  simulatedTemp = random(36, 38);    // Симулирана температура (°C)
  
  // 2. Изчисляваме комбиниран скор (примерно средно претеглено)
  combinedScore = (simulatedPulse * 0.5) + (simulatedGSR * 0.3 / 10) + ((simulatedTemp - 36) * 0.2 * 100);
  
  // 3. Печат на симулираните стойности
  Serial.print("Pulse (BPM): "); Serial.print(simulatedPulse);
  Serial.print(" | GSR: "); Serial.print(simulatedGSR);
  Serial.print(" | Temp (°C): "); Serial.print(simulatedTemp);
  Serial.print(" | Combined Score: "); Serial.println(combinedScore);

  // 4. Логика за ALERT / NORMAL
  if(combinedScore > alertThreshold){
    digitalWrite(ledPin, HIGH);  // ALERT
    Serial.println("ALERT! Possible stress detected");
  } else {
    digitalWrite(ledPin, LOW);   // NORMAL
    Serial.println("Normal state");
  }

  Serial.println("---------------------------------");
  
  // 5. Изчакване преди следваща симулация
  delay(updateInterval);
}
