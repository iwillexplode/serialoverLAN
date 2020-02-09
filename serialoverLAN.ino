#include <dht.h>
#include <SoftwareSerial.h>
#include <SPI.h>
#include <Ethernet.h>


dht DHT;
#define DHT11_PIN 3
byte mac[] = {  
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
EthernetClient client;

IPAddress ip(111,222,333,444);
IPAddress gateway(111,222,333,444);
IPAddress subnet(111, 111, 111, 1111);

EthernetServer Server(23);

void setup(){
Serial.begin(9600);
Server.begin();// start listening for clients
// start the serial library:
  Serial.begin(9600);
  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Server.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    for(;;)
      ;
  }

}

void loop()
{
    int chk = DHT.read11(DHT11_PIN);
    int temper = DHT.temperature;
    int humidity = DHT.humidity;

   if (humidity==-999 || temper==-999) {
      return;
    }

  Server.print("Temp= ");
  Server.println(temper);
  delay(10);
  Server.print("Humid= ");
  Server.println(humidity);
  delay(1000);
}
