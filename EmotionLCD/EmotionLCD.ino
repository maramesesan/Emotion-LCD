#include <SPI.h>
#include <RFID.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
Servo servoRight;
Servo servoLeft;

#define SDA_DIO 9
#define RESET_DIO 8
RFID RC522(SDA_DIO, RESET_DIO);
String CARD_1 = "179426214169";
String CARD_2 = "1954212616649";
String CARD_3 = "6875220186105";
String CARD_4 = "68232172186186";
String CARD_5 = "1161131911860";
String cardID;

void setup()
{
  Serial.begin(9600);
  SPI.begin();
  RC522.init();
  lcd.init();
  lcd.begin(20, 4);
  lcd.backlight();
  servoRight.attach(2);
  servoLeft.attach(4);

       servoLeft.write(0);
    servoRight.write(180);
}

void loop()
{
  if (RC522.isCard())
  {
    RC522.readCardSerial();
    Serial.println("Card detected:");

    for (int i = 0; i < 5; i++)
    {
      cardID += RC522.serNum[i];
    }
    Serial.print(cardID);

    if (cardID == CARD_1)
    {
      lcd.clear();
      hearts();
    }
    else if (cardID == CARD_2)
    {
      lcd.clear();
      openEyes();
    }
    else if (cardID == CARD_3)
    {
      lcd.clear();
      sad();
    }
    else if (cardID == CARD_4)
    {
      lcd.clear();
      lines();
    }
    else if (cardID == CARD_5)
    {
      lcd.clear();
      triangle();
    }

    cardID = "";
    Serial.println();
    Serial.println();
  }
  delay(1000);
}

void hearts()
{
  lcd.setCursor(1, 0);
  lcd.print("*** ***    *** ***");
  lcd.setCursor(0, 1);
  lcd.print("*********  *********");
  lcd.setCursor(1, 2);
  lcd.print("*******    *******");
  lcd.setCursor(3, 3);
  lcd.print("***        ***");

     servoLeft.write(0);
    servoRight.write(180);

        delay(100);
          servoLeft.write(45);
    servoRight.write(45);

      delay(1000);
     servoLeft.write(0);
    servoRight.write(180);
}

void openEyes()
{
  lcd.setCursor(4, 0);
  lcd.print("**        **");
  lcd.setCursor(3, 1);
  lcd.print("*  *      *  *");
  lcd.setCursor(2, 2);
  lcd.print("*    *    *    *");
  lcd.setCursor(2, 3);
  lcd.print("* ** *    * ** *");

     servoLeft.write(0);
    servoRight.write(180);

        delay(100);
    servoLeft.write(180);
    servoRight.write(0);

      delay(1000);
     servoLeft.write(0);
    servoRight.write(180);
}

void sad()
{
  lcd.setCursor(2, 0);
  lcd.print("****        ****");
  lcd.setCursor(1, 1);
  lcd.print("*                *");
  lcd.setCursor(0, 2);
  lcd.print("*                  *");
  lcd.setCursor(2, 3);
  lcd.print("******    ******");

      servoLeft.write(0);
    servoRight.write(180);

        delay(100);
          servoLeft.write(90);
    servoRight.write(90);

      delay(1000);
     servoLeft.write(0);
    servoRight.write(180);
}

void lines()
{
  lcd.setCursor(2, 2);
  lcd.print("******    ******");

     servoLeft.write(180);
    servoRight.write(0);

        delay(100);
          servoLeft.write(45);
    servoRight.write(45);

      delay(1000);
     servoLeft.write(0);
    servoRight.write(180);

}

void triangle()
{
  lcd.setCursor(5, 0);
  lcd.print("*         *");
  lcd.setCursor(4, 1);
  lcd.print("* *       * *");
  lcd.setCursor(3, 2);
  lcd.print("*   *     *   *");
  lcd.setCursor(2, 3);
  lcd.print("*     *   *     *");

      servoLeft.write(0);
    servoRight.write(180);

        delay(100);

    servoRight.write(45);

      delay(1000);

    servoRight.write(180);
}
