/*  Runs the motor until we are roughly at the correct position with help of
 *  the angular velocity and the delta angle (between satetlite position and our position)
 *  
 *  Run this program when starting to track a new satelite (or when the delta angles are vary large)
 *
 *  Date: 2018-06-15
 */
 
 void Coarse_adjust_orientation(){
  Serial.println("Entering Coarse_adjust_orientation");

   // Print initial delta_roll and delta_pitch for debugging
   Serial.println(delta_roll);
   Serial.println(delta_pitch);
  
  int angular_velocity = 14; // We probebly have to measure this by ourself
  int Speed = 200; // "CHANGE SPEED" //PWM setting 0-255
  
  // Calculate time 
  int time_roll = round(abs(delta_roll)/angular_velocity); // absoute value to get a positive time
  int time_pitch = round(abs(delta_pitch)/angular_velocity); // round to get int
  
  
  // Run both motors in 'time_pitch' seconds, then run roll motor 'time_roll'-'time_pitch' seconds
  if (time_roll > time_pitch){
  
    // If we want positive or negative roll
    if (delta_roll > 0){
      Roll_Positive(Speed);}
    else{
      Roll_Negative(Speed);}
    
    // If we want positive or negative pitch
    if (delta_pitch > 0){
      Pitch_Positive(Speed);}
    else {
      Pitch_Negative(Speed);}
    
    delay_s(time_pitch);
    Pitch_Brake();
    delay_s(time_roll-time_pitch);
    
    // Brake both motors
    Roll_Brake();
    Pitch_Brake();
    delay(100);
   }
  
  // Run both motors in 'time_roll' seconds, then run pitch motor 'time_pitch'-'time_roll' seconds
  else {
  
    // If we want positive or negative roll
    if (delta_roll > 0){
      Roll_Positive(Speed);}
    else{
      Roll_Negative(Speed);}
  
    // If we want positive or negative pitch
    if (delta_pitch > 0){
      Pitch_Positive(Speed);}
    else {
      Pitch_Negative(Speed);}
  
    delay_s(time_roll);
    Roll_Brake();
    delay_s(time_pitch-time_roll);
    
    // Brake both motors
    Roll_Brake();
    Pitch_Brake();
    delay(100);
  }
  // Print final delta_roll and delta_pitch for debugging
  Serial.println(delta_roll);
  Serial.println(delta_pitch);

  Serial.println("Ending Coarse_adjust_orientation");
  
}

