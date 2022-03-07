#define V_pin1     A3
#define V_pin2     A2
#define V_pin3     A1
#define temp_pin1  A4
#define temp_pin2  A5

float Input_volt;                                           // Auxilary Variables
float Input_temp;                                           // Auxilary Variables

/*Function for Voltage sensing
 * This function converts the voltage into a digital input 
 * and returns the converted value.
 */
float vlt_sns(const int pin){
  Input_volt = analogRead(pin);
  float V_out = float((Input_volt * 5.09 * 2)/1024.0);
  return(V_out); 
}


/*Function for Temperature sensing using the potentiometer
 * This function clones the working of an NTC thermistor
 * The value mapped here is 0-100C into 0-5V.
 */
float temp_sns(const int pin){
  Input_temp = analogRead(pin);
  float V_out = float((Input_temp*5.00)/1024.0);
  return(V_out);
}


/*Function for regulating the fan speed for cooling battery
 * Here, we use a mathematical expression to make the PWM signal as a variable
 * the expression is _integer_(n*125) if n > 2 then 255.
 */
void fanspeed_reg(float temp1, float temp2){
  float temp_multiple = 0.00;
  if(temp1 > temp2){
    temp_multiple = temp1;}  
  else{
    temp_multiple = temp2;}
    
  if(temp_multiple < 2.00){
    analogWrite(5, (temp_multiple*125));}
  else if(temp_multiple >= 2.00){
    analogWrite(5, 255);}
}



void setup() {
  pinMode(7, OUTPUT);                                     // Error Output for OR Gate w.r.t Voltage of cells
  pinMode(8, OUTPUT);                                     // Error Output for OR Gate w.r.t Temperature of the cells
  pinMode(0, OUTPUT);                                     // Error LED for Voltage Error
  pinMode(1, OUTPUT);                                     // Error LED for Temperature Error
}

void loop() {
  float conv_volt1 = vlt_sns(V_pin1);
  float conv_volt2 = vlt_sns(V_pin2);
  float conv_volt3 = vlt_sns(V_pin3);

  
  float conv_temp1 = temp_sns(temp_pin1);
  float conv_temp2 = temp_sns(temp_pin2);
  
  if((conv_volt1 >= 4.20) || (conv_volt2 >= 4.20) || (conv_volt3 >= 4.20)){
    digitalWrite(7, HIGH);
    digitalWrite(0, HIGH);}
  else if((conv_volt1 < 4.20) && (conv_volt2 < 4.20) && (conv_volt3 < 4.20)){
    digitalWrite(7, LOW);
    digitalWrite(0, LOW);}
  
  if((conv_temp1 >= 2.00) || (conv_temp2 >= 2.00)){
    digitalWrite(8, HIGH);
    digitalWrite(1, HIGH);}
  else if((conv_temp1 < 2.00) || (conv_temp2 < 2.00)){
    digitalWrite(8, LOW);
    digitalWrite(1, LOW);}

    fanspeed_reg(conv_temp1, conv_temp2);
  
}
