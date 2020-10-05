
#include <OneWire.h>
#include <DallasTemperature.h>
#include <ESP8266WiFi.h> 
#include <FirebaseArduino.h>

#define WIFI_SSID "TP-Link_82D2"  
#define WIFI_PASSWORD "03770559" 
#define FIREBASE_HOST "qwerty-23593.firebaseio.com"  
#define FIREBASE_AUTH "5DuDt4PXLjUN6U8MdqmNUPx5pa4JylljaClPUMvO" 


#define ONE_WIRE_BUS D2

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature ds(&oneWire);
int numberOfDevices;

DeviceAddress tempDeviceAddress; 

void setup(){
  Serial.begin(9600);

  // соединение к wifi 
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD); 
  Serial.print("connecting"); 
  while (WiFi.status() != WL_CONNECTED) { 
    Serial.print("."); 
    delay(500); 
  } 
  Serial.println(); 
  Serial.print("connected: "); 
  Serial.println(WiFi.localIP()); 
   
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH); 

 ds.setResolution(tempDeviceAddress, 9);
  
  ds.begin();
  
  numberOfDevices = ds.getDeviceCount(); 
  Serial.print("Found ");
  Serial.print(numberOfDevices);
  Serial.println(" devices.");
}


void loop(){ 
  ds.requestTemperatures(); // считываем температуру с датчиков

  int i;
  i=0;
  Firebase.setFloat("temperature/Temp1", ds.getTempCByIndex(i));
  i=1;
  Firebase.setFloat("temperature/Temp2", ds.getTempCByIndex(i));
  i=2;
  Firebase.setFloat("temperature/Temp3", ds.getTempCByIndex(i));
  i=3;
  Firebase.setFloat("temperature/Temp4", ds.getTempCByIndex(i));
  i=4;
  Firebase.setFloat("temperature/Temp5", ds.getTempCByIndex(i));
  i=5;
  Firebase.setFloat("temperature/Temp6", ds.getTempCByIndex(i));
  i=6;
  Firebase.setFloat("temperature/Temp7", ds.getTempCByIndex(i));
  i=7;
  Firebase.setFloat("temperature/Temp8", ds.getTempCByIndex(i));
  i=8;
  Firebase.setFloat("temperature/Temp9", ds.getTempCByIndex(i));
  i=9;
  Firebase.setFloat("temperature/Temp10", ds.getTempCByIndex(i));
  
 
 
   
  Serial.println();
}
