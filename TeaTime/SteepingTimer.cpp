#include "SteepingTimer.h"

TeaTime::SteepingTimer::SteepingTimer() {

	this->isActive = false;

	this->currentInterval = TeaTime::TIM_DEFAULT_ELAPSE_INTERVAL;

	this->currentFreq = TeaTime::TIM_DEFAULT_FREQ_MS;
	this->tim =
		gcnew System::Timers::Timer(TeaTime::TIM_DEFAULT_FREQ_MS);

	this->idataMutex = gcnew System::Threading::Mutex();

}

TeaTime::SteepingTimer::~SteepingTimer() {
	if (this->tim) {
		delete this->tim;
	}
	if (this->idataMutex) {
		delete this->idataMutex;
	}
}

void TeaTime::SteepingTimer::setExternalTickCallback(callback_func cb) {
	if (cb) {
		this->externalTick_cb__ = cb;
	}
}

void TeaTime::SteepingTimer::setExternalExpiredCallback(callback_func cb) {
	if (cb) {
		this->externalExpired_cb__ = cb;
	}
}

bool TeaTime::SteepingTimer::reset(unsigned int newFrequency) {
	if (this->idataMutex->WaitOne(TeaTime::TIM_DEFAULT_FREQ_MS)) {
		this->tim->Stop();
		this->isActive = false;
		this->tim->BeginInit();
		this->tim->Interval = newFrequency;
		this->tim->EndInit();
		return true;
	}
	else {
		return false;
	}
	
}

bool TeaTime::SteepingTimer::reset(void) {
	return this->reset(TeaTime::TIM_DEFAULT_ELAPSE_INTERVAL);
}

void TeaTime::SteepingTimer::internal_tick(void)
{
	tim->BeginInit();
	tim->AutoReset = false;
}

TeaTime::TimerDataBundle_t TeaTime::SteepingTimer::getData(void) {
	TeaTime::TimerDataBundle_t bundle;
	if (this->idataMutex->WaitOne(TeaTime::TIM_DEFAULT_FREQ_MS)) {
		bundle.valid = true;
		bundle.active = this->isActive;
		bundle.freq = this->currentFreq;
		bundle.interval = this->currentInterval;
		bundle.remaining = 0; // TODO
	}
	else {
		bundle.valid = false;
	}
	this->idataMutex->ReleaseMutex();
	return bundle;
}