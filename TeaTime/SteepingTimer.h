#ifndef STEEPING_TIMER_H_
#define STEEPING_TIMER_H_

namespace TeaTime {

	static unsigned int TIM_DEFAULT_FREQ_MS = 1000;
	static unsigned int TIM_DEFAULT_ELAPSE_INTERVAL = 120;

	typedef struct {
		bool valid;
		bool active;
		unsigned int freq;
		unsigned int interval;
		unsigned int remaining;
	} TimerDataBundle_t;

	public ref class SteepingTimer {
		// internal type definitions
	public:
		typedef void(*callback_func)(void);
		
	private:
		// primitives
		bool isActive;
		unsigned int currentFreq;
		unsigned int currentInterval;

		callback_func externalTick_cb__;
		callback_func externalExpired_cb__;

		// managed
		System::Timers::Timer^ tim;
		System::Threading::Mutex^ idataMutex;

		// functions
		///
		/// internal tick function (triggers every frequency period set); 
		/// also triggers external callbacks on certain events if set
		void internal_tick(void);

	public:
		// functions
		/// ctor
		SteepingTimer();
		/// dtor
		~SteepingTimer();

		///
		/// set the external tick callback function (triggers every frequency period set)
		void setExternalTickCallback(callback_func cb);

		///
		/// set the external expired callback function (triggers when all intervals have elapsed)
		void setExternalExpiredCallback(callback_func cb);

		///
		/// stops and reinitializes the timer with a new interval
		bool reset(unsigned int newInterval);

		///
		/// stops and reinitializes the timer with same internal interval
		bool reset(void);

		TimerDataBundle_t getData(void);
	};

}

#endif // STEEPING_TIMER_H_
