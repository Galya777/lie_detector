/*
  Master Mini Lie Detector Simulator - DEMO VERSION
  Автор: [Вашето име]
  Дата: 02.10.2024
  Платформа: Arduino Uno (симулация без реални сензори)
  
  Цел:
  - Симулиране на работата на детектор на стрес/лъжата
  - Visual demo чрез Serial Monitor и “LED print”
  
  Бележка:
  - В този режим не се използва реален Arduino LED.
  - Симулираният LED се визуализира като текст в Serial Monitor.
*/

const int ledPin = 13;          // Вграден LED (симулиран)
const int alertThreshold = 110; // Праг за ALERT
const int updateInterval = 1000; // ms

int simulatedPulse = 0;
int simulatedGSR = 0;
int simulatedTemp = 0;
int combinedScore = 0;

// Симулиран digitalWrite за демонстрация без реална платка
void simulatedDigitalWrite(int pin, int state){
  if(pin == ledPin){
    if(state == HIGH) Serial.println("[LED 13] ALERT - RED");
    else Serial.println("[LED 13] NORMAL - GREEN");
  }
}

void setup() {
  Serial.begin(9600);
  Serial.println("=== Mini Lie Detector Simulator ===");
  Serial.println("Симулация без реални сензори");
  Serial.println("---------------------------------");
}

void loop() {
  // 1. Генерираме случайни стойности
  simulatedPulse = random(70, 120);
  simulatedGSR = random(300, 700);
  simulatedTemp = random(36, 38);

  // 2. Изчисляваме комбиниран скор (съчетание от трите сензора)
  combinedScore = (simulatedPulse * 0.5) + (simulatedGSR * 0.3 / 10) + ((simulatedTemp - 36) * 0.2 * 100);

  // 3. Печат на симулираните стойности
  Serial.print("Pulse (BPM): "); Serial.print(simulatedPulse);
  Serial.print(" | GSR: "); Serial.print(simulatedGSR);
  Serial.print(" | Temp (°C): "); Serial.print(simulatedTemp);
  Serial.print(" | Combined Score: "); Serial.println(combinedScore);

  // 4. ALERT / NORMAL логика
  if(combinedScore > alertThreshold){
    simulatedDigitalWrite(ledPin, HIGH); // ALERT
    Serial.println("ALERT! Possible stress detected");
  } else {
    simulatedDigitalWrite(ledPin, LOW);  // NORMAL
    Serial.println("Normal state");
  }

  Serial.println("---------------------------------");
  
  // 5. Изчакване преди следваща симулация
  delay(updateInterval);
}
