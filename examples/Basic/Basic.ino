//
//  DJWInterval
//  Created by DejaWorks on 22/07/2020.
//  Copyright © 2020 dejaWorks. All rights reserved.
//

#include <Arduino.h>
#include <DJWInterval.h>

// init interval
DJWInterval interval;

void setup()
{
    Serial.begin(9600);
    Serial.println();
   
   someInterval
      .mSeconds(3000) // set delay time milliseconds
      .repeat(5)      // set repeat count 5 times (0 = infinite)
      .call(timeIsUp) // set call back function name
      .start();
}
void loop()
{
    // important, this makes the interval work.
    interval.loop();
}

// this function will be called by interval 
void timeIsUp()
{
  Serial.println("time is up.");
}
