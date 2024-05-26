
#include "Adafruit_VL53L0X.h"

// address we will assign if dual sensor is present
#define LOX1_ADDRESS 0x30
#define LOX2_ADDRESS 0x31
int sensor1,sensor2;


const int motorPin1 = 9; // Motor control pin 1
const int motorPin2 = 10; // Motor control pin 2


//// set the pins to shutdown
#define SHT_LOX1 7
#define SHT_LOX2 6
//
//// objects for the vl53l0x
Adafruit_VL53L0X lox1 = Adafruit_VL53L0X();
Adafruit_VL53L0X lox2 = Adafruit_VL53L0X();
//
//// this holds the measurement
VL53L0X_RangingMeasurementData_t measure1;
VL53L0X_RangingMeasurementData_t measure2;


void controlMotor1(int dutyCycle) {
  analogWrite(motorPin1, dutyCycle); // Set PWM duty cycle for motor 1
}

void controlMotor2(int dutyCycle) {
  analogWrite(motorPin2, dutyCycle); // Set PWM duty cycle for motor 2
}

void setID() {
  // all reset
  digitalWrite(SHT_LOX1, LOW);    
  digitalWrite(SHT_LOX2, LOW);
  delay(10);
  // all unreset
  digitalWrite(SHT_LOX1, HIGH);
  digitalWrite(SHT_LOX2, HIGH);
  delay(10);

  // activating LOX1 and reseting LOX2
  digitalWrite(SHT_LOX1, HIGH);
  digitalWrite(SHT_LOX2, LOW);

  // initing LOX1 Serial.print(sensor1);
    if(sensor1 >= 4000){
      Serial.print("175");    
      controlMotor1(175);  
    }else{
        controlMotor1(0);
    }
  if(!lox1.begin(LOX1_ADDRESS)) {
    Serial.println(F("Failed to boot first VL53L0X"));
    while(1);
  }
  delay(10);

  // activating LOX2
  digitalWrite(SHT_LOX2, HIGH);
  delay(10);

  //initing LOX2
  if(!lox2.begin(LOX2_ADDRESS)) {
    Serial.println(F("Failed to boot second VL53L0X"));
    while(1);
  }
}

void read_dual_sensors() {
  
  lox1.rangingTest(&measure1, false); // pass in 'true' to get debug data printout!
  lox2.rangingTest(&measure2, false); // pass in 'true' to get debug data printout!

  // print sensor one reading
  Serial.print("1: ");
    sensor1 = measure1.RangeMilliMeter;    
    Serial.print(sensor1);
   if(sensor1 >= 0 && sensor1 <= 2000){
      controlMotor1(240);
    }else if(sensor1 > 2000 && sensor1 <= 4000){
      controlMotor1(180);
    }else if(sensor1 > 4000 && sensor1 <= 6000){
      controlMotor1(120);
    }else if(sensor1 > 6000){
      controlMotor1(0);
    }
    Serial.print("mm");    
 
  
  Serial.print(" ");

  // print sensor two reading
  Serial.print("2: ");
    sensor2 = measure2.RangeMilliMeter;
    Serial.print(sensor2);
    if(sensor2 >= 0 && sensor2 <= 2000){
      controlMotor2(240);
    }else if(sensor2 > 2000 && sensor2 <= 4000){
      controlMotor2(180);
    }else if(sensor2 > 4000 && sensor2 <= 6000){
      controlMotor2(120);
    }else if(sensor2 > 6000){
      controlMotor2(0);
    }
    Serial.print("mm");
  
  
  Serial.println();
}

void setup() {
  pinMode(motorPin1, OUTPUT); // Set motor pin 1 as output
  pinMode(motorPin2, OUTPUT); // Set motor pin 2 as output
  Serial.begin(115200);

  // wait until serial port opens for native USB devices
  while (! Serial) { delay(1); }

  pinMode(SHT_LOX1, OUTPUT);
  pinMode(SHT_LOX2, OUTPUT);

  Serial.println("Shutdown pins inited...");

  digitalWrite(SHT_LOX1, LOW);
  digitalWrite(SHT_LOX2, LOW);

  Serial.println("Both in reset mode...(pins are low)");
  
  
  Serial.println("Starting...");
  setID();
 
}
void loop() {
  read_dual_sensors();
  delay(100);
}





