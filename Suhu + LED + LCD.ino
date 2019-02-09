#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,9,10,11,12);

float C;
int hot = 39;
int cold = 21;
const int TemperaturePin = 0;
void setup() {
  pinMode(A0, INPUT);
  pinMode(3, OUTPUT); //Green Light
  pinMode(4, OUTPUT); //Blue Light
  pinMode(5, OUTPUT); //Red Light
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Haekal Ramadhan");
  lcd.setCursor(0,1);
  lcd.print("18116025");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Suhu C: ");
  lcd.setCursor(0,1);
  lcd.print("Terimakasih");
}

void loop() {
    float suhu = getVoltage (TemperaturePin);
    float C = (suhu - 0.5)*100.0;
  	lcd.setCursor(11, 0);
    lcd.print(C);
    if (C < cold) {
      digitalWrite(3, HIGH);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);   
    }
    else if (C > hot) {
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);   
    }
    else {
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);   
    }
    delay(100);
}

float getVoltage(int pin)
{
   return (analogRead(A0) * 0.004882814);
}