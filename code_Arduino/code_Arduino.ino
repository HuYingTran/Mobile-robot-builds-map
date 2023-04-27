template <int order> // order is 1 or 2
class LowPass
{
  private:
    float a[order];
    float b[order+1];
    float omega0;
    float dt;
    bool adapt;
    float tn1 = 0;
    float x[order+1]; // Raw values
    float y[order+1]; // Filtered values

  public:  
    LowPass(float f0, float fs, bool adaptive){
      // f0: cutoff frequency (Hz)
      // fs: sample frequency (Hz)
      // adaptive: boolean flag, if set to 1, the code will automatically set
      // the sample frequency based on the time history.
      
      omega0 = 6.28318530718*f0;
      dt = 1.0/fs;
      adapt = adaptive;
      tn1 = -dt;
      for(int k = 0; k < order+1; k++){
        x[k] = 0;
        y[k] = 0;        
      }
      setCoef();
    }

    void setCoef(){
      if(adapt){
        float t = micros()/1.0e6;
        dt = t - tn1;
        tn1 = t;
      }
      
      float alpha = omega0*dt;
      if(order==1){
        a[0] = -(alpha - 2.0)/(alpha+2.0);
        b[0] = alpha/(alpha+2.0);
        b[1] = alpha/(alpha+2.0);        
      }
      if(order==2){
        float c1 = 2*sqrt(2)/alpha;
        float c2 = 4/(alpha*alpha);
        float denom = 1.0+c1+c2;
        b[0] = 1.0/denom;
        b[1] = 2.0/denom;
        b[2] = b[0];
        a[0] = -(2.0-2.0*c2)/denom;
        a[1] = -(1.0-c1+c2)/(1.0+c1+c2);      
      }
    }

    float filt(float xn){
      // Provide me with the current raw value: x
      // I will give you the current filtered value: y
      if(adapt){
        setCoef(); // Update coefficients if necessary      
      }
      y[0] = 0;
      x[0] = xn;
      // Compute the filtered values
      for(int k = 0; k < order; k++){
        y[0] += a[k]*y[k+1] + b[k]*x[k];
      }
      y[0] += b[order]*x[order];

      // Save the historical values
      for(int k = order; k > 0; k--){
        y[k] = y[k-1];
        x[k] = x[k-1];
      }
  
      // Return the filtered value    
      return y[0];
    }
};

// Filter instance
LowPass<2> lp(3,1e3,true);
//======================================================================================
#include <SimpleKalmanFilter.h> // THU VIEN LOC KALMAN
SimpleKalmanFilter bo_loc(2, 2, 0.001);

#include "Adafruit_VL53L0X.h" // thu vien cam bien lazer
Adafruit_VL53L0X lox = Adafruit_VL53L0X();

#include<Servo.h>
Servo myServo;

const int trig = 10; //------------BIEN
const int echo = 11;
const int tcan = 12;
int distance;
int i=0;
int j=0;
int pos;
int pot;
String inStr;

#define IN1 7 //------BIEN DIEU KIEN DC
#define IN2 6
#define IN3 5
#define IN4 4
#define MAX_SPEED 255 //từ 0-255
#define MIN_SPEED 0 

int encoder_pin1 = 2; //---BIEN ENCODER
int encoder_pin2 = 3;          
unsigned int rpm1;   
unsigned int rpm2;
volatile byte pulses1 = 0;  
volatile byte pulses2 = 0;
unsigned long timeold = 0;
unsigned int pulsesperturn = 20;

void counter1(){  pulses1++;  }
void counter2(){  pulses2++;  } 

void setup(){
  Serial.begin(115200);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(tcan, INPUT);

  pinMode(trig,OUTPUT);   // chân trig sẽ phát tín hiệu
  pinMode(echo,INPUT);

  pinMode(encoder_pin1, INPUT);
  pinMode(encoder_pin2, INPUT);
  attachInterrupt(0, counter1, FALLING);
  attachInterrupt(1, counter2, FALLING);



  //Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
    myServo.attach(9);
  delay(1000);
  myServo.write(0);
}

void loop(){
  if(Serial.available()){
    inStr = Serial.readString();
    if(inStr=="quet"){
      while(true){
        //tien();
        delay(100);
        quet_t();
        //tien();
        delay(100);
        quet_n();
      }
    }
  }
}
void tien(){
  motor_1_Tien(80); // motor 1 tiến
  motor_2_Tien(80);
  for(j=0;j<5;j++){
    attachInterrupt(0, counter1, FALLING);
    attachInterrupt(1, counter2, FALLING);
    tinh_rpm();
    Serial.println(String(rpm1)+'-'+String(rpm2)+'-'+String(i)+'-'+String(1000));
    delay(100);
  }
  motor_1_Dung();
  motor_2_Dung();
}
void quet_t(){
  for(i=0;i<180;i+=2){
    myServo.write(i);
    tinh_rpm();
    int val = lp.filt(do_kc());
    Serial.println(String(rpm1)+'-'+String(rpm2)+'-'+String(i)+'-'+String(val));
    delay(200);
  }
}
void quet_n(){
  for(i=180;i>00;i-=2){
    myServo.write(i);
    tinh_rpm();
    Serial.println(String(rpm1)+'-'+String(rpm2)+'-'+String(i)+'-'+String(do_kc()));
    delay(200);
  }
}

void tinh_rpm(){
  if (millis() - timeold >= 1000){
    detachInterrupt(0);
    rpm1 = (60 * 1000 / pulsesperturn )/ (millis() - timeold)* pulses1;
    rpm2 = (60 * 1000 / pulsesperturn )/ (millis() - timeold)* pulses2;
    rpm1 = bo_loc.updateEstimate(rpm1);
    rpm2 = bo_loc.updateEstimate(rpm2);
    timeold = millis();
   
    pulses1 = 0;
    pulses2 = 0;
    attachInterrupt(0, counter1, FALLING);
    attachInterrupt(1, counter2, FALLING);
  }
}

int do_kc(){
  VL53L0X_RangingMeasurementData_t measure;
  lox.rangingTest(&measure, false); // pass in 'true' to get debug data printout!
  if (measure.RangeMilliMeter < 800) {  // phase failures have incorrect data
    return measure.RangeMilliMeter;
  } else {
    return 1000;
  }
}

int tinh_kc(){ // ---------------------------- khoang cach
  digitalWrite(trig, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trig, HIGH); 
  delayMicroseconds(5);
  digitalWrite(trig, LOW);
  distance= int(pulseIn(echo, HIGH))*0.034/2;
  return distance;
}

//========================================================= code dieu khien dong cow
void motor_1_Dung() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}
 
void motor_2_Dung() {
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
 
void motor_1_Tien(int speed) { //speed: từ 0 - MAX_SPEED
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1, HIGH);// chân này không có PWM
  analogWrite(IN2, 255 - speed);
}
 
void motor_1_Lui(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  digitalWrite(IN1, LOW);// chân này không có PWM
  analogWrite(IN2, speed);
}
 
void motor_2_Tien(int speed) { //speed: từ 0 - MAX_SPEED
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  analogWrite(IN3, speed);
  digitalWrite(IN4, LOW);// chân này không có PWM
}
 
void motor_2_Lui(int speed) {
  speed = constrain(speed, MIN_SPEED, MAX_SPEED);
  analogWrite(IN4, 255 - speed);
  digitalWrite(IN3, HIGH);// chân này không có PWM
} 
