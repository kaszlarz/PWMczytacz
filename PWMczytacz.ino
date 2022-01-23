//Funkcja pulsu
// pulseIn mikrosekundy

byte PWM_PIN = 3;
 
int PWM_CZAS_HIGH;
int PWM_CZAS_LOW;
int PWM_CZAS_LOWDIV;
 
void setup() {
  pinMode(PWM_PIN, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
}
 
void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  PWM_CZAS_HIGH = pulseIn(PWM_PIN, HIGH);
  if (PWM_CZAS_HIGH>0) PWM_CZAS_LOW = pulseIn(PWM_PIN, LOW); 
  if (PWM_CZAS_LOW>0) 
    {
    PWM_CZAS_LOWDIV = PWM_CZAS_LOW/2;
    
    }    
  if (PWM_CZAS_HIGH>0 & PWM_CZAS_LOWDIV>0)
  {
    delayMicroseconds(PWM_CZAS_LOWDIV);
    digitalWrite(LED_BUILTIN, HIGH);
    delayMicroseconds(PWM_CZAS_HIGH);
    digitalWrite(LED_BUILTIN, LOW);
    delayMicroseconds(PWM_CZAS_LOWDIV-PWM_CZAS_HIGH);
    
    
  }
  
  
 //Serial.println(PWM_CZAS_LOWDIV);
 }
