#include "TeaTime.h"
#include "TrayNotifyIcon.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main (array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	TeaTime::Tray^ trayObject = gcnew TeaTime::Tray();
	trayObject->enable();
	Application::Run();
}