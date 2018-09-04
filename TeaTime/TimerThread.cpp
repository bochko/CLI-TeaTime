namespace TeaTime {

	using namespace System;

	public ref class SteepingThread {

	private:
		static bool timerRunning;

		void internal_proc__
		(
			unsigned int args, 
			System::Windows::Forms::Label^ lctl, 
			System::Windows::Forms::Form^ fctor
		) {
			// total time must not be negative, as this is
			// going to be condition checked, so safeguard via
			// force unsigned
			unsigned int tt_must_elapse = args;

			// step is a second whole
			unsigned int ms_step = 1000; // milliseconds
			System::Timers::Timer^ tim = gcnew System::Timers::Timer(ms_step);

			tim->BeginInit();
			tim->AutoReset = false;
		}

	public:
		SteepingThread();
		~SteepingThread();

		

	};
}