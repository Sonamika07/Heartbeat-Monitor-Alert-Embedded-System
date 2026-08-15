#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// ================= PIN DEFINITIONS =================

#define OLED_SDA 21
#define OLED_SCL 22

#define BUZZER_PIN 25
#define GREEN_LED 26
#define RED_LED 27

// ================= OLED SETTINGS =================

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  OLED_RESET
);

// ================= THRESHOLDS =================

// Educational demonstration thresholds
const int LOW_THRESHOLD = 60;
const int HIGH_THRESHOLD = 100;

// ================= SIMULATION VARIABLES =================

int simulatedBPM = 75;

unsigned long lastBPMChange = 0;
unsigned long lastBuzzerChange = 0;

bool buzzerState = false;

// Simulation states
int simulationState = 0;


// ======================================================
// SETUP
// ======================================================

void setup() {

  Serial.begin(115200);

  // Output pins
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  // Turn everything OFF initially
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);

  // Start I2C
  Wire.begin(OLED_SDA, OLED_SCL);

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {

    Serial.println("OLED initialization failed!");

    while (true) {
      delay(1000);
    }
  }

  display.clearDisplay();

  display.setTextColor(SSD1306_WHITE);

  display.setTextSize(2);
  display.setCursor(10, 5);
  display.println("HEART");

  display.setCursor(10, 30);
  display.println("MONITOR");

  display.display();

  delay(2000);

  Serial.println("--------------------------------");
  Serial.println("Heartbeat Monitor Started");
  Serial.println("--------------------------------");
}


// ======================================================
// LOOP
// ======================================================

void loop() {

  unsigned long currentTime = millis();

  // Change simulated BPM every 8 seconds
  if (currentTime - lastBPMChange >= 8000) {

    lastBPMChange = currentTime;

    simulationState++;

    if (simulationState > 2) {
      simulationState = 0;
    }

    // -------------------------------
    // NORMAL
    // -------------------------------

    if (simulationState == 0) {

      simulatedBPM = 75;
    }

    // -------------------------------
    // LOW
    // -------------------------------

    else if (simulationState == 1) {

      simulatedBPM = 50;
    }

    // -------------------------------
    // HIGH
    // -------------------------------

    else if (simulationState == 2) {

      simulatedBPM = 110;
    }
  }

  // Process BPM
  processHeartbeat(simulatedBPM);

  delay(100);
}


// ======================================================
// HEARTBEAT PROCESSING
// ======================================================

void processHeartbeat(int bpm) {

  String status;

  // -------------------------------
  // LOW BPM
  // -------------------------------

  if (bpm < LOW_THRESHOLD) {

    status = "LOW";

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);

    alertBuzzer();

  }

  // -------------------------------
  // HIGH BPM
  // -------------------------------

  else if (bpm > HIGH_THRESHOLD) {

    status = "HIGH";

    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);

    alertBuzzer();

  }

  // -------------------------------
  // NORMAL BPM
  // -------------------------------

  else {

    status = "NORMAL";

    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);

    digitalWrite(BUZZER_PIN, LOW);
    buzzerState = false;
  }

  // Display on OLED
  displayBPM(bpm, status);

  // Serial Monitor
  static unsigned long lastSerial = 0;

  if (millis() - lastSerial >= 1000) {

    lastSerial = millis();

    Serial.print("Heart Rate: ");
    Serial.print(bpm);
    Serial.print(" BPM");

    Serial.print(" | Status: ");
    Serial.println(status);
  }
}


// ======================================================
// BUZZER ALERT
// ======================================================

void alertBuzzer() {

  unsigned long currentTime = millis();

  // Buzzer ON/OFF every 300 ms
  if (currentTime - lastBuzzerChange >= 300) {

    lastBuzzerChange = currentTime;

    buzzerState = !buzzerState;

    digitalWrite(BUZZER_PIN, buzzerState);
  }
}


// ======================================================
// OLED DISPLAY
// ======================================================

void displayBPM(int bpm, String status) {

  display.clearDisplay();

  // Title
  display.setTextSize(1);
  display.setCursor(20, 0);
  display.println("HEART MONITOR");

  // BPM
  display.setTextSize(2);
  display.setCursor(10, 18);
  display.print("BPM:");

  display.setCursor(70, 18);
  display.println(bpm);

  // Status
  display.setTextSize(1);
  display.setCursor(25, 48);
  display.print("STATUS: ");
  display.println(status);

  display.display();
}
