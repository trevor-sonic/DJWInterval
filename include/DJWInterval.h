//
//  DJWInterval
//  Created by DejaWorks on 22/07/2020.
//  Copyright © 2020 dejaWorks. All rights reserved.
//
#ifndef DJWINTERVAL_H
#define DJWINTERVAL_H

#include <Arduino.h>

// ----- Callback function types -----
extern "C"
{
	typedef void (*callbackFunction)(void);
}

class DJWInterval
{
private:
	bool _running = false;
	bool _currStatus = false;
	bool _enable = true;

	unsigned int _currTime = millis();
	unsigned int _times = 0;
	unsigned long _lastMillis = 0;
	unsigned long _delay = 500;

	callbackFunction _functionHandler = NULL;

public:
	DJWInterval();
	virtual ~DJWInterval();

	void setFunction(callbackFunction theFunction);
	void setDelay(unsigned long delay, unsigned int times);
	void stop();
	void start();
	void restart();
	void loop();

	DJWInterval &mSeconds(unsigned long delay);
	DJWInterval &repeat(unsigned int times);
	DJWInterval &call(callbackFunction theFunction);
};

#endif