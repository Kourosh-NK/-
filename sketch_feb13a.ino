#include <Servo.h>

Servo myServo;  // تعریف سروو موتور
int trigPin = 9;
int echoPin = 10;
int servoPin = 8;  // پین PWM موتور

void setup() {
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    myServo.attach(servoPin); // اتصال سروو به پین 8
}

float getDistance() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    long duration = pulseIn(echoPin, HIGH);
    float distance = duration * 0.034 / 2; // تبدیل مدت زمان به فاصله
    return distance;
}

void loop() {
    for (int angle = 0; angle <= 180; angle += 5) {
        myServo.write(angle);
        delay(100);
        float distance = getDistance();
        Serial.print(angle);
        Serial.print(",");
        Serial.println(distance);
    }
}
