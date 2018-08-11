#include "TrayNotifyIcon.h"

		TeaTime::Tray::Tray() {
			// system tray component init
			this->mWinTrayObject =
				gcnew NotifyIcon(
					gcnew System::ComponentModel::Container()
				);

			// context menu soon-to-be tray component child init
			this->mWinContextMenu = 
				gcnew System::Windows::Forms::ContextMenu();

			// associate tray component context menu with this private context menu
			this->mWinTrayObject->ContextMenu = this->mWinContextMenu;
			// icon is WINAPI default application icon
			auto resourceAssembly = Reflection::Assembly::GetExecutingAssembly();
			auto resourceName = resourceAssembly->GetName()->Name + ".Resources";
			auto resourceManager = gcnew Resources::ResourceManager(resourceName, resourceAssembly);
			System::Drawing::Bitmap^ bmp =
				gcnew System::Drawing::Bitmap(
					dynamic_cast<System::Drawing::Image^>(resourceManager->GetObject("TeaTime_Icon"))
				);
			this->mWinTrayObject->Icon = System::Drawing::Icon::FromHandle(bmp->GetHicon());//System::Drawing::SystemIcons::WinLogo;
			// some VERY informative description
			this->mWinTrayObject->Text = "TeaTime!";

			System::Windows::Forms::MenuItem ^settingsMenuItem =
				gcnew System::Windows::Forms::MenuItem();
			settingsMenuItem->Text = TEXT_TEATIME_SETTINGS;
			//settingsMenuItem->Index = 4;
			//settingsMenuItem->Click +=

			mWinContextMenu->MenuItems->Add(settingsMenuItem);

			System::Windows::Forms::MenuItem ^exitMenuItem =
				gcnew System::Windows::Forms::MenuItem();
			exitMenuItem->Text = TEXT_TEATIME_EXIT;
			//exitMenuItem->Index = 5;
			exitMenuItem->Click += gcnew System::EventHandler(this, &Tray::exit_cb__);

			mWinContextMenu->MenuItems->Add(exitMenuItem);

			// set disabled
			this->disable();
		}

		TeaTime::Tray::~Tray() {
			if (this->mWinTrayObject) {
				delete this->mWinTrayObject;
			}
			if (this->mWinContextMenu) {
				delete this->mWinContextMenu;
			}
		}

		void TeaTime::Tray::exit_cb__(System::Object ^, System::EventArgs ^) {
			this->disable();
			Application::Exit();
		}

		void TeaTime::Tray::enable() {
			if (!isEnabled) {
				this->mWinTrayObject->Visible = true;
				this->isEnabled = true;
			}
		}

		void TeaTime::Tray::disable() {
			if (isEnabled) {
				this->mWinTrayObject->Visible = false;
				this->isEnabled = false;
			}
			
		}
