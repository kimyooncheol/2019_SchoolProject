/*
 * dht핀: 13
 * 스위치 핀:6
 * 리얼타임클럭 핀:2 4 5 
 * 심박수 센서 핀: A0
 * 적외선 온도 센서 핀: 
 * wifi모듈 핀:rx:9 tx:10
 */
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include "DHT.h"
#include <ThreeWire.h>  
#include <RtcDS1302.h>
#include <SoftwareSerial.h>

 
#define PROCESSING_VISUALIZER 1
#define SERIAL_PLOTTER  2
#define DHTPIN 13
#define DEBUG true
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27,16,4);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
DHT dht(DHTPIN, DHTTYPE);
ThreeWire myWire(4,5,2); // IO, SCLK, CE
RtcDS1302<ThreeWire> Rtc(myWire);
SoftwareSerial ESP8266(7,8); //rx tx

int nTemp; //온도 저장
int nDHT_temp; //dht센서 온도 저장
int nDHT_humi; //dht습도 저장
int nHeartBeat; //심박수
int nHeartBeat_array[100]; //심박수 평균 구하기 위한 배열
int i; //반복문 사용
int nPerce; //심박수 평균
int percent; //%표시
const int swpin=6;
const int pulsePin = 0;                              
volatile int BPM;                  
volatile int Signal;               
volatile int IBI = 600;             
volatile boolean Pulse = false;     
volatile boolean QS = false;  
static int outputType =PROCESSING_VISUALIZER;


void setup() {  
  lcd_setup();
  sensor_begin();
  wifi_setUp();
  interruptSetup(); //동일 폴더에 참조 
}

void loop() {
  if(digitalRead(swpin)==HIGH) {
    lcd_output();
  }
  else {
    beatsensor_main();
  }
}
/*
 * -----------------초기 설정--------------------
 */
void sensor_begin() {
  Serial.begin(9600);
  ESP8266.begin(9600);
  mlx.begin();
  dht.begin();
  Rtc.Begin();
  pinMode(swpin,INPUT);
}
//wifi 모듈 시작

void wifi_setUp() {
  delay(2000);
  ESP8266.println("AT+RST\r\n"); //리셋
  delay(1000);
  ESP8266.println("AT+CWMODE=3\r\n"); //모드3
  delay(1000);
  ESP8266.println("AT+CWJAP=\"iptype\",\"root123\"\r\n"); //wifi연결
  delay(3000);
}
//lcd 설정
void lcd_setup() {
  lcd.init();                     
  lcd.backlight();
  lcd.clear();
}
/*
 * -----------------LCD출력 함수-------------------- 
 */ 
void lcd_output() {
  lcd.clear();
  dhtsensor();
  timesensor();
  delay(500);  
}

//dht 센서
void dhtsensor() {
  nDHT_temp=dht.readTemperature();
  nDHT_humi=dht.readHumidity();
  lcd.setCursor(0,0);
  lcd.print("C:");  
  lcd.print(nDHT_temp);
  lcd.print(" H:");
  lcd.print(nDHT_humi);
}
//리얼 타임
void timesensor() {
  RtcDateTime now = Rtc.GetDateTime();
  lcd.setCursor(0,1);
  printDateTime(now);
}
#define countof(a) (sizeof(a) / sizeof(a[0]))

void printDateTime(const RtcDateTime& dt) {
    char datestring[20];

    snprintf_P(datestring, 
            countof(datestring),
            PSTR("%02u/%02u/%04u %02u:%02u:%02u"),
            dt.Month(),
            dt.Day(),
            dt.Year(),
            dt.Hour(),
            dt.Minute(),
            dt.Second() );
    lcd.print(datestring);
}

/*
 *-----------------심박 센서-------------------- 
 */
//심박센서 메인
void beatsensor_main() {
   lcd.clear();
   Beat_start();
   for(i=0;i<3000;i++) {
     serialOutput();
     if (QS == true){          
       serialOutputWhenBeatHappens();  
       QS = false;                     
     }               
     Beat_do();
    }
    Beat_Finish();  
  while(digitalRead(swpin)==LOW);
}
//심박센서 사용 전 5초 기다리기
void Beat_start() { 
  for(i=5;i>0;i--) {
    lcd.setCursor(0,0);
    lcd.print("Wait");
    lcd.print(i);
    lcd.print("sec");
    delay(1000);
  }
  lcd.clear();
}
//bpm 출력하기
void Beat_do() {
   lcd.setCursor(0,0);
   percent=int(i*100/3000); 
   lcd.print(percent); 
   nHeartBeat_array[percent]=BPM;
   lcd.setCursor(3,0);
   lcd.print("%");
   delay(1);
}
//측정 끝났을 시 
void Beat_Finish() {
  for(i=0;i<100;i++) { //평균 내기
    nHeartBeat+=nHeartBeat_array[i];
  }
  nHeartBeat=nHeartBeat/100;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Finish ");
  lcd.print(int(mlx.readObjectTempC()));
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("BPM:");
  lcd.print(nHeartBeat); 
  Beat_Upload(); 
}
//업로드 하는 부분
void Beat_Upload() {
  ESP8266.println("AT+CIPMUX=1");
  delay(1000);
  printResponse();
  ESP8266.println("AT+CIPSTART=4,\"TCP\",\"superthinks.dothome.co.kr\",80");
  delay(1000);
  printResponse();
  String StsensorValue = String(nHeartBeat);
  String cmd = "GET http://localhost/scripts/Upload.php?num="+StsensorValue+" HTTP/1.0"; 
  ESP8266.println("AT+CIPSEND=4," + String(cmd.length() + 4));
  delay(1000);
  ESP8266.println(cmd);
  delay(200);
  ESP8266.println();
  delay(200);
  printResponse();
}
void printResponse() {
  while (ESP8266.available()) {
    Serial.println(ESP8266.readStringUntil('\n')); 
  }
}
