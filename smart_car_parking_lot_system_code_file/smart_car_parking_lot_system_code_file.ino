#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

Servo myservo;

#define ir_enter 2
#define ir_back 4

#define ir_car1 5
#define ir_car2 6
#define ir_car3 7
#define ir_car4 8

#define l1 9
#define l2 10
#define l3 11
#define l4 12
#define r 13

int S1 = 0, S2 = 0, S3 = 0, S4 = 0;
int flag1 = 0, flag2 = 0;
int slot = 4;
int full = 0;
void setup() {
  Serial.begin(9600);

  pinMode(ir_car1, INPUT);
  pinMode(ir_car2, INPUT);
  pinMode(ir_car3, INPUT);
  pinMode(ir_car4, INPUT);

  pinMode(ir_enter, INPUT);
  pinMode(ir_back, INPUT);

  pinMode(l1, OUTPUT);
  pinMode(l2, OUTPUT);
  pinMode(l3, OUTPUT);
  pinMode(l4, OUTPUT);
  pinMode(r, OUTPUT);

  myservo.attach(3);
  myservo.write(90);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" Hi Welcome To ");
  lcd.setCursor(0, 1);
  lcd.print("smart car parking lot project");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" Today's Project ");
  lcd.setCursor(0, 1);
  lcd.print("smart Parking  ");
  delay(4000);
  lcd.clear();

  Read_Sensor();

  int total = S1 + S2 + S3 + S4;
  slot = 4 - total; // Initialize slots based on occupied spaces
}

void loop() {
  Read_Sensor();

  // Display the number of available slots or Parking Full
  if (slot > 0) {
    lcd.setCursor(0, 0);
    lcd.print("Slots: ");
    lcd.print(slot);
    lcd.print("     "); // Clear any previous characters
    digitalWrite(r, LOW);
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Parking Full    ");
    digitalWrite(r, HIGH);
  }

  // Display the status of each slot
  lcd.setCursor(0, 1);
  lcd.print("1:");
  lcd.print(S1 == 1 ? "F" : "E");
  lcd.print(" 2:");
  lcd.print(S2 == 1 ? "F" : "E");
  lcd.print(" 3:");
  lcd.print(S3 == 1 ? "F" : "E");
  lcd.print(" 4:");
  lcd.print(S4 == 1 ? "F" : "E");

  // Handle car entry
  if (digitalRead(ir_enter) == 0 && flag1 == 0) {
    if (slot > 0) {  // Only open gate if there is a free slot
      flag1 = 1;
      if (flag2 == 0) {
        myservo.write(180);
        digitalWrite(r, LOW);
        slot--;
      }
    } else {
      lcd.setCursor(0, 0);
      lcd.print("Parking Full    "); 
      digitalWrite(r, HIGH);
    }
  }

  // Handle car exit
  if (digitalRead(ir_back) == 0 && flag2 == 0) {
    flag2 = 1;
    if (flag1 == 0) {
      myservo.write(180);
      slot++;
    }
  }

  // Close the servo after both entry and exit have been processed
  if (flag1 == 1 && flag2 == 1) {
    delay(1000);
    myservo.write(90);
    flag1 = 0;
    flag2 = 0;
  }

  delay(1);
}

void Read_Sensor() {
  S1 = 0; S2 = 0; S3 = 0; S4 = 0;

  if (digitalRead(ir_car1) == 0) {
    S1 = 1;
    digitalWrite(l1, LOW);
  } else {
    digitalWrite(l1, HIGH);
  }
  if (digitalRead(ir_car2) == 0) {
    S2 = 1;
    digitalWrite(l2, LOW);
  } else {
    digitalWrite(l2, HIGH);
  }
  if (digitalRead(ir_car3) == 0) {
    S3 = 1;
    digitalWrite(l3, LOW);
  } else {
    digitalWrite(l3, HIGH);
  }
  if (digitalRead(ir_car4) == 0) {
    S4 = 1;
    digitalWrite(l4, LOW);
  } else {
    digitalWrite(l4, HIGH);
  }

  int total = S1 + S2 + S3 + S4;
  slot = 4 - total; 
  
}
