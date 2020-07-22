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
    setupInterval();
}
void loop()
{
    // important, this makes the interval work.
    interval.loop();
}
void setupInterval(){
    // set the function name to call after a while
    interval.setFunction(timeIsUp);

    
    // set delay time and repeat count (0 = infinite)
    // below: after 2 seconds and do it 3 times
    interval.setDelay(2000, 3);

    // run interval
    interval.start();
}
// this function will be called by interval 
void timeIsUp()
{
  Serial.println("time is up.");
}
