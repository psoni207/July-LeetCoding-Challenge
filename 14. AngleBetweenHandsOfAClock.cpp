class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        if (hour == 12){
            hour = 0;
        }
        
        if (minutes == 60){ 
            minutes = 0; 
            hour += 1;
        }  
  
    // Calculate the angles moved by hour and minute hands with reference to 12:00  
        double hour_angle = 0.5 * (hour * 60 + minutes);  
        double minute_angle = 6 * minutes;  
  
    // Find the difference between two angles  
        double angle = abs(hour_angle - minute_angle);  
  
    // Return the smaller angle of two possible angles  
        angle = min(360 - angle, angle);  
  
        return angle;  
        
    }
};