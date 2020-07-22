//
//  DJWInterval
//  Created by DejaWorks on 22/07/2020.
//  Copyright © 2020 dejaWorks. All rights reserved.
//
#include "DJWInterval.h"

DJWInterval::DJWInterval()
{
	// _delay		=	500;
	// _lastMillis	=	millis();
	// _running	=	false;
	// _enable		=	true;

	// (void*)_functionHandler;
}
DJWInterval::~DJWInterval()
{
	// TODO Auto-generated destructor stub
}
void DJWInterval::start()
{
	_lastMillis = millis();
	_running = true;
	_currStatus = false;
	_currTime = _times;
}
void DJWInterval::stop()
{
	_running = false;
}
void DJWInterval::restart()
{
	stop();
	start();
}
void DJWInterval::loop()
{
	if (_running && _enable && _functionHandler && (_currTime > 0 || _times == 0) && (millis() >= _lastMillis + _delay))
	{
		_lastMillis = millis();
		if (_currTime > 0)
			_currTime--;

		_functionHandler();
	}
}
void DJWInterval::setDelay(unsigned long delay, unsigned int times)
{
	_delay = delay;
	_times = times;
	_currTime = _times;
}
void DJWInterval::setFunction(callbackFunction theFunction)
{
	_functionHandler = theFunction;
}

DJWInterval &DJWInterval::mSeconds(unsigned long delay)
{
	_delay = delay;
	return *this;
}
/// Howmany times should repeat (0 = infinite)
DJWInterval &DJWInterval::repeat(unsigned int times)
{
	_times = times;
	_currTime = _times;
	return *this;
}
DJWInterval &DJWInterval::call(callbackFunction theFunction)
{
	this->_functionHandler = theFunction;
	return *this;
}