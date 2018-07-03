  void move_motor_protocol(){
/* Runs the motor(s) a few time units, then check the delta angle (between satetlite position and our position), 
 *  repeat until the delta angle is less than the tolerance
 * 
 * It's possible to drive both motor at the same time to most efficieltly get to the right position
 * Date: 2018-06-15
 */

 
  Serial.println("Entering move_motor_protocol");

  // Time keeping track on how often we should update satalite angles
  unsigned long startMillis;                                              // Starting time
  unsigned long currentMillis;                                            // Current time
  const unsigned long period = 1000;                                      // How often we should update [ms]
  startMillis = millis();                                                 // Initial start time
  
  int tol = 2;                                                          // Tolerance: How big is delta_roll/delta_pitch allowed to be [degree]
  int time_drive = 20;                                                    // How long to run the motors before updating angles      
  getCurrentPitch();
  getCurrentRoll(time_drive);
  
  Serial.print("Degree roll: ");  
  Serial.println(rolldeg); 
  Serial.print("Degree pitch: ");  
  Serial.println(pitchdeg);     

  // Calculate new delta pitch angle
      delta_pitch = EL_degree-pitchdeg;
  Serial.print("delta_pitch: ");
  Serial.println(delta_pitch);
  // Calculate new delta roll angle
  delta_roll = AZ_degree-rolldeg;
  Serial.print("delta_roll: ");
  Serial.println(delta_roll); 
  
  // Drive as long as any of the delta angles are outside the tolerance
  while((abs(delta_pitch) > tol) || (abs(delta_roll) > tol)){
    
    // If both delta angles are outside tolerance, run both
    while((abs(delta_pitch)) > tol && (abs(delta_roll) > tol)){
  
      // If we want positive or negative pitch
      if (delta_pitch > 0){
        Pitch_Positive(fastSpeed);}
      else{
        Pitch_Negative(fastSpeed);}
  
      // If we want positive or negative roll
      if (delta_roll > 0){
        Roll_Positive(fastSpeed);}
      else{
        Roll_Negative(fastSpeed);}
  
      // Drive the motors "time_drive" ms  before updating angles
      delay_s(time_drive);
  
      // Update pitch angle [degree]
      //getCurrentPitch(); // MAYBE ADD IF IMU AVALIABLE THING
  
      // Update angles motor, roll [degree]
      //getCurrentRoll(time_drive);
  
      // Calculate new delta pitch angle
      delta_pitch = EL_degree-pitchdeg;
  
      // Calculate new delta roll angle
      delta_roll = AZ_degree-rolldeg;

      // See if the satalite angles should be updated
      currentMillis = millis();                                   // Get the current "time"
      if (currentMillis - startMillis >= period){                 // Test whether the period has elapsed, if true update satelite angles 
        UpdateSateliteAngles();                                   // Update satelite angles
        startMillis = millis();                                   // Reset start time
      }
    }
    
    // If only the delta angle for pitch is outside tolerance, run pitch motor
    while((abs(delta_pitch) > tol) && (abs(delta_roll) <= tol)){
      // Brake the roll motor
      Roll_Brake();
      Serial.println("second if");
  
      // If we want positive or negative pitch
      if (delta_pitch > 0){
        Pitch_Positive(fastSpeed);}
      else{
        Pitch_Negative(fastSpeed);}
  
      // Drive the motor "time_drive" ms  before updating angles
      delay_s(time_drive);
  
      // Update pitch angle [degree]
      getCurrentPitch();
  
      // Calculate new delta pitch angle
      delta_pitch = EL_degree-pitchdeg;  

      // See if the satalite angles should be updated
      currentMillis = millis();                                   // Get the current "time"
      if (currentMillis - startMillis >= period){                 // Test whether the period has elapsed, if true update satelite angles 
        UpdateSateliteAngles();                                   // Update satelite angles
        startMillis = millis();                                   // Reset start time
      }
    }

    // If only the delta angle for roll is outside tolerance, run roll motor
    while((abs(delta_roll) > tol) && (abs(delta_pitch) <= tol)){
      // Brake the pitch motor
      Pitch_Brake();
      Serial.println("3:rd if");
  
      // If we want positive or negative roll
      if (delta_roll > 0){
        Roll_Positive(fastSpeed);}
      else{
        Roll_Negative(fastSpeed);}
  
      // Drive the motor "time_drive" ms  before updating angles
      delay_s(time_drive);
  
      // Update roll angle [degree]
      getCurrentRoll(time_drive);
  
      // Calculate new delta roll angle
      delta_roll = AZ_degree-rolldeg;       
    }

      // See if the satalite angles should be updated
      currentMillis = millis();                                   // Get the current "time"
      if (currentMillis - startMillis >= period){                 // Test whether the period has elapsed, if true update satelite angles 
        UpdateSateliteAngles();                                   // Update satelite angles
        startMillis = millis();                                   // Reset start time
      }
  }

  Serial.println("Ending move_motor_protocol");
}

