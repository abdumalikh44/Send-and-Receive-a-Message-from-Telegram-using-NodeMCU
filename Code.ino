
//include library CBot
#include "CTBot.h"
#include "DHT.h"

#define DHTTYPE DHT11
const int DHTPin = 5; 

DHT dht(DHTPin,DHTTYPE);
CTBot myBot;

//konfigurasi koneksi ke wifi
String ssid = "無結LAN";
String pass = "BC123456";
//variable token dan id telegram
String token = "5383028731:AAGAGaTrdFIhc3ABOjZmeWmrJuO8TZPfoRA";
uint32_t id = 1738236894;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Memulai telegram bot. koneksi ke Wifi");
  //koneksi
  myBot.wifiConnect(ssid, pass);
  //set token telegram
  myBot.setTelegramToken(token);

  //cek koneksi wifi
  if(myBot.testConnection())
    Serial.println("Koneksi Berhasil");
  else
    Serial.println("Koneksi Gagal");
    
  dht.begin();

}

/*class Sample {
  public:
    float temperature;
    float humidity1;
    Sample(float temp, float hum){
      temperature = temp;
      humidity1 = hum; 
    }
    void display(){
      printf("Temperature %f", temperature);
      printf("Humidity %f", humidity1);
    }
};
*/

void loop() {
  int temp = dht.readTemperature();
  int hum = dht.readHumidity();
 
  // put your main code here, to run repeatedly:
  //baca pesan masuk dari telegram
  TBMessage msg;
  if(myBot.getNewMessage(msg)){
     //Tampilkan di serial monitor
     Serial.println("Pesan Masuk : " + msg.text);
  }
  //variabel penampung isi pesan
  String pesan = msg.text;
  if(pesan == "Cek Suhu"){
    //kirim pesan balasan
    myBot.sendMessage(1738236894, "Temperature: ", temp);
  }

  if(temp >  && temp < 30){
      return true;
  }
  else if(temp 
  
  
 
 
  

}
