
#define flamepin 2
#define gaspin 3
#define ldrpin A5
#define temppin A0
#define humiditypin A1
#define buzzer 5


int flame,gas;
float ldr,humidityread,tempread,rh,humiditydata;
String flame_str,gas_str,motion;

#define pirPin 4
int calibrationTime = 30;
long unsigned int lowIn;
long unsigned int pause = 5000;
boolean lockLow = true;
boolean takeLowTime;
int PIRValue = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(flamepin, INPUT);
  pinMode(gaspin, INPUT);
  pinMode(ldrpin,INPUT);
  pinMode(pirPin, INPUT);
  pinMode(temppin, INPUT);
  pinMode(humiditypin, INPUT);
  pinMode(buzzer, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  delay(200);
  flame = digitalRead(flamepin);
  gas = digitalRead(gaspin);
  ldr = analogRead(ldrpin);
  if(flame==1){
    flame_str="FIRE!!";
    tone(buzzer,1000);
    delay(20);
    noTone(buzzer);
  }else{
    flame_str="No FIRE";

  }
  if(gas==1){
    gas_str="Gas Leak";
    tone(buzzer,1000);
    delay(20);
    noTone(buzzer);;
  }else{
    gas_str="No Gas leak";

  }
////  PIRSensor();
  if((digitalRead(pirPin) == HIGH)&&(ldr<50)){
    motion="Motion detected but low light so light turned on";
    
  }
  if((digitalRead(pirPin) == HIGH)&&(ldr>50)){
    motion="Motion detected and enough light so light not turned on";
  }
  if(digitalRead(pirPin) == LOW){
    motion="no motion";
  }




  tempread = analogRead(temppin);
  float val = (tempread/1024.0)*5000;
  float tempdata=val/10;
//
//  
  humidityread = analogRead(humiditypin);
  rh=((humidityread/1024.0)-0.1515)/0.00636;
  float true_rh=(rh)/(1.0546-0.00216*tempdata);

  Serial.println(tempdata);
  Serial.println(true_rh);
  
 
  Serial.println(ldr);
  Serial.println(motion);
  Serial.println(flame_str);
  Serial.println(gas_str);





}
