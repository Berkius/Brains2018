void getCurrentRoll(int time_roll){

  int change_in_roll;

  // Check rotation speed
  int angular_velocity_roll = Check_angular_velocity_roll();
  
  change_in_roll = time_roll * angular_velocity_roll;
  
  rolldeg = rolldeg + change_in_roll;

  Serial.print("roll angle: ");
  Serial.println(rolldeg);
  
<<<<<<< HEAD
}
=======
}
>>>>>>> 634baedf7ae2872d2d2e81165a4a4986bd97237b
