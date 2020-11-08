double kp = 15;  
int cm = 50;
double error; 
double output, setPoint; 

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  setPoint = 50;

}

void loop()
{
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  // convert to inches by dividing by 2.54
  
  Serial.print(cm);
  Serial.println("cm");
  delay(10); // Wait for 10 millisecond(s)
  output = computeP(cm);
  analogWrite(9, output);
}

double computeP(double cm){ 
        
        error = setPoint - cm;                                    //obliczenie błędu regulacji
                      
        double out = kp*error;                     
        
        return out;                                                //powrót z podprogramu
}