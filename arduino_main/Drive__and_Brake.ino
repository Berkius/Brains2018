/*
 * All the functions that tells the motor how to run
 * 
 * Date: 2018-06-16
 */

// ROLL
// Create a positive roll motion (lower motor)
void Roll_Positive(int Speed) {
  int safe_marg = 5;
<<<<<<< HEAD
  if (rolldeg < azimuth_max - safe_marg){
=======
  if (rolldeg < 540 - safe_marg){
>>>>>>> 634baedf7ae2872d2d2e81165a4a4986bd97237b
     //Serial.println("Entering Roll_Positive");
     motor_direction=3;  //drive forward roll
     digitalWrite(roll_IN1,HIGH); 
     digitalWrite(roll_IN2,LOW);  
     analogWrite(roll_PWM,Speed);
     //Serial.println("Ending Roll_Positive");
<<<<<<< HEAD
     //ROLL_T++;
  }
  else{
    Serial.println("Roll reached maximum value");
=======
  }
  else{
    //Serial.println(F("Roll reached maximum value"));
>>>>>>> 634baedf7ae2872d2d2e81165a4a4986bd97237b
    }
  }

// Create a negative roll motion (lower motor)
void Roll_Negative(int Speed) {    
  int safe_marg = 5;
<<<<<<< HEAD
  if (rolldeg >= azimuth_min + safe_marg){
=======
  if (rolldeg >= -540 + safe_marg){
>>>>>>> 634baedf7ae2872d2d2e81165a4a4986bd97237b
     //Serial.println("Entering Roll_Negative");
     motor_direction=4;  //drive backwards roll
     digitalWrite(roll_IN1,LOW); 
     digitalWrite(roll_IN2,HIGH);  
     analogWrite(roll_PWM,Speed);
     //Serial.println("Ending Roll_Negative");
<<<<<<< HEAD
     //ROLL_T--;
  }
  else{
    Serial.println("Roll reached minimum value");
=======
  }
  else{
    //Serial.println(F("Roll reached minimum value"));
>>>>>>> 634baedf7ae2872d2d2e81165a4a4986bd97237b
  }
 }

// Breake the roll motion (lower motor)
void Roll_Brake(){
     //Serial.println("Entering Roll_Brake");
     digitalWrite(roll_IN1,LOW); 
     digitalWrite(roll_IN2,HIGH); 
     //Serial.println("Ending Roll_Brake");
}

// PITCH
// Create a positive pitch motion (upper motor)
void Pitch_Positive(int Speed) {
  int safe_marg = 5;
  if (pitchdeg < elevation_max - safe_marg){
     //Serial.println("Entering Pitch_Positive");
     motor_direction=1;  //drive forward pitch
     digitalWrite(pitch_IN1,HIGH); 
     digitalWrite(pitch_IN2,LOW);  
     analogWrite(pitch_PWM,Speed);
     //Serial.println("Ending Pitch_Positive");
  }
  else{
<<<<<<< HEAD
    Serial.println("Pitch reached maximum value");
=======
    //Serial.println(F("Pitch reached maximum value"));
>>>>>>> 634baedf7ae2872d2d2e81165a4a4986bd97237b
    }
}

// Create a negative pitch motion (upper motor)
void Pitch_Negative(int Speed) {  
  int safe_marg = 5;
  if (pitchdeg >= elevation_min + safe_marg){
     //Serial.println("Entering Pitch_Negative");
     motor_direction=2; //drive backwards pitch
     digitalWrite(pitch_IN1,LOW); 
     digitalWrite(pitch_IN2,HIGH);  
     analogWrite(pitch_PWM,Speed);
     //Serial.println("Ending Pitch_Negative");
  }
  else{
<<<<<<< HEAD
  Serial.println("Pitch reached minimum value");
=======
  //Serial.println(F("Pitch reached minimum value"));
>>>>>>> 634baedf7ae2872d2d2e81165a4a4986bd97237b
  }
 }


// Breake the pitch motion (upper motor)
void Pitch_Brake(){
     //Serial.println("Entering Pitch_Brake");
     digitalWrite(pitch_IN1,LOW); 
     digitalWrite(pitch_IN2,LOW); 
     //Serial.println("Ending Pitch_Brake");
}

