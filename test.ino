#include <Servo.h>
#include <IRremote.h>
int IRPIN = 2;
IRrecv irrecv(IRPIN);
decode_results result;

Servo myservo;  // 定义Servo对象来控制
int pos = 0;    // 角度存储变量

void setup() {
  myservo.attach(9);  // 控制线连接数字9
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn();
  Serial.println("Enabled IRin");
 // Initialize_streamer();
}

void loop() {
    if (irrecv.decode(&result))
  {
    Serial.print("Value: ");
    Serial.println(result.value, HEX);
    //Write_streamer();
    irrecv.resume();
    if(result.value == 0xFF30CF){
      myservo.write(60);
    }
    else if (result.value == 0xFF18E7){
      myservo.write(120);
    }
    else if (result.value == 0xFF7A85){
      myservo.write(180);
    }
    
  }
  
  delay(100);
  result.value = 0;
  myservo.write(150);
  
//  for (pos = 0; pos <= 180; pos ++) { // 0°到180°
//    // in steps of 1 degree
//    myservo.write(pos);              // 舵机角度写入
//    //delay(5);                       // 等待转动到指定角度
//  }
//  for (pos = 180; pos >= 0; pos --) { // 从180°到0°
//    myservo.write(pos);              // 舵机角度写入
//    //delay(5);                       // 等待转动到指定角度
  //}
}
