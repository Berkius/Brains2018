void getCurrentPitch(){
/*
 * Calculate the pitch and roll angle with sensor data from the accelerometer
 * 
 * Date: 2018-06-16
 */
 //Serial.println("Entering getCurrentPitch");
 float X, Y, Z;
 int rawX, rawY, rawZ;

// code fragment for Accelerometer angles (roll and pitch)
  acc.readAccel(&ax, &ay, &az); //read the accelerometer values and store them in variables  x,y,z
  //rawX = ax - aoffsetX;
  //rawY = ay - aoffsetY;
  //rawZ = az  - (255 - aoffsetZ);
  
  X = ax/256.00; // used for angle calculations
  Y = ay/256.00; // used for angle calculations
  Z = az/256.00; // used for angle calculations
  
  // calculated angle in degrees (OBS in calibration offset will be zero) 
  pitchdeg = 180*(atan(X/sqrt(Y*Y+Z*Z)))/PI + offset_el; 

  //Serial.print("pitch angle: ");
  //Serial.println(pitchdeg);

  //Serial.println("Ending getCurrentPitch");
}
