#pragma once

#define TEXT_TEATIME_EXIT "Exit"
#define TEXT_TEATIME_SETTINGS "Settings"

namespace TeaTime {
	using namespace System::Windows::Forms;
	using namespace System;

	ref class Tray {
	private:
		NotifyIcon ^ mWinTrayObject;
		ContextMenu^ mWinContextMenu;
		bool isEnabled;

		void exit_cb__(System::Object ^, System::EventArgs ^);

	public:
		Tray();
		~Tray();

		void enable();
		void disable();
	};
}