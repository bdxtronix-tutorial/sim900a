
// sebelum memulakan projek pastikan baki kredit kad sim anda mencukupi
// sambungkan  Pin GSM TX ke pin 9 Arduino  
// dan pin GSM RX disambungkan ke pin 10 Arduino.
// untuk menghidupkan GSM pula sambungkan pin 5V dan GND  dari Arduino ke Vcc dan GND GSM.
 

#include <SoftwareSerial.h>
SoftwareSerial mySerial(9,10);
void setup()
{
  mySerial.begin(9600);                    // Set baud rate of GSM Module  
  Serial.begin(9600);                      // Set baud rate Serial Monitor (Arduino)
  Serial.println("GSM SIM900A");             
  Serial.println("Masukkan pilihan anda.."); 
  Serial.println("s : untuk menghantar SMS");
  delay(100);
}
void loop()
{
  if (Serial.available()>0)
   switch(Serial.read())
  {
    case 's':
      HantarSMS();
      break;  
  }
 if (mySerial.available()>0)
   Serial.write(mySerial.read());
}
 void HantarSMS()
{
  mySerial.println("AT+CMGF=1");                                // Untuk setkan GSM Modul dalam Mod teks
  delay(1000);                                                                // Delay 1000 millisaat atau 1 saat
  mySerial.println("AT+CMGS=\"+60xxxxxxx\"\r");  // Gantikan X's dengan nombor telefon penerima
  delay(1000);
  Serial.println("Menghantar SMS..");
  mySerial.println("SMS from GSM SIM900A");     // pesanan SMS yang ingin dihantar ke penerima
  delay(100);
   mySerial.println((char)26);// ASCII code  CTRL+Z
  delay(1000);
}
 void TerimaSMS()
{
  mySerial.println("AT+CNMI=2,2,0,0,0");                // AT Command untuk menerima live SMS
  delay(1000);
 }
