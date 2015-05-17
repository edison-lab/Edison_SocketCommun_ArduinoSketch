#include <WiFi.h>

WiFiServer server(3000);
char c = '0';


void setup() {
  
  Serial.begin(9600);
  pinMode(13,OUTPUT);
    
  server.begin();
  Serial.print("Connected to TCP. My address:");
  IPAddress myAddress(127,0,0,1);
  Serial.println(myAddress);
  
}


void loop() {      
  
  WiFiClient client = server.available();
      
    if (client.available() > 0){
      
        c = client.read();
        if (c == '1') {
           digitalWrite(13, HIGH);
        } 
        if (c == '0') {
           digitalWrite(13, LOW);
        }
        
    }
    
  Serial.println(c);
  delay(10);
    
}

   

