
#define flamepin 2
#define gaspin 3
int flame,gas;
String flame_str,gas_str;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(flamepin, INPUT);
  pinMode(gaspin, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  delay(200);
  flame = digitalRead(flamepin);
  gas = digitalRead(gaspin);
  if(flame==1){
    flame_str="agun dhorse";
  }else{
    flame_str="agun dhore nai";
  }
  if(gas==1){
    gas_str="gas leak korse";
    
  }else{
    gas_str="gas leak korenai chill";
  }
  Serial.println(flame_str);
  Serial.println(gas_str);

}
