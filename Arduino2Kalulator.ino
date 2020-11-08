int buff=0;
void setup()
{
  Serial.begin(57600);
}
void loop()
{
  
  if (buff==0){
  	Serial.println("Wpisz rownanie np 'a znak b'");
  	buff=1;
  }
  else if(Serial.available()>0){
  	long a = Serial.parseInt();
  	int znak = Serial.read();
  	long b = Serial.parseInt();
  	
  	switch(znak){
    	case '+':
    		Serial.println(a+b);
      		break;
      	case '-':
    		Serial.println(a-b);
      		break;
    	case '*':
    		Serial.println(a*b);
      		break;
     	case '/':
    		Serial.println((float)a/b);
      		break;
    }
    buff=0;
  }
}