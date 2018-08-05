#pragma once

#define TEXT_TEATIME_EXIT "Exit"
#define TEXT_TEATIME_SETTINGS "Settings"

namespace TeaTime {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for TeaTime
	/// </summary>
	public ref class TeaTime : public System::Windows::Forms::Form
	{
	public:
		TeaTime(void)
		{
			InitializeComponent();

#pragma region Custom ctor code
			// ctor after component initialization
			
			// system tray component init
			this->mWinTrayObject = 
				gcnew System::Windows::Forms::NotifyIcon(
					gcnew System::ComponentModel::Container()
				);

			// context menu soon-to-be tray component child init
			this->mWinContextMenu = 
				gcnew System::Windows::Forms::ContextMenu();

			// suspend this form's layout
			this->SuspendLayout();

			// associate tray component context menu with this private context menu
			this->mWinTrayObject->ContextMenu = this->mWinContextMenu;
			// icon is WINAPI default application icon
			this->mWinTrayObject->Icon = System::Drawing::SystemIcons::WinLogo;
			// some VERY informative description
			this->mWinTrayObject->Text = "Steep your tea right!";

			System::Windows::Forms::MenuItem ^settingsMenuItem = 
				gcnew System::Windows::Forms::MenuItem();
			settingsMenuItem->Text = TEXT_TEATIME_SETTINGS;
			settingsMenuItem->Index = 4;
			//settingsMenuItem->Click +=

			mWinContextMenu->MenuItems->Add(settingsMenuItem);

			System::Windows::Forms::MenuItem ^exitMenuItem =
				gcnew System::Windows::Forms::MenuItem();
			exitMenuItem->Text = TEXT_TEATIME_EXIT;
			exitMenuItem->Index = 5;
			exitMenuItem->Click += gcnew System::EventHandler(&TeaTime::exit);

			mWinContextMenu->MenuItems->Add(exitMenuItem);
			
			// make it visible
			this->mWinTrayObject->Visible = true;

			// last step resume layout
			this->ResumeLayout(false);
			

#pragma endregion
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~TeaTime()
		{
			if (components)
			{
				delete components;
			}
			if (this->mWinTrayObject) {
				delete this->mWinTrayObject;
			}
			if (this->mWinContextMenu) {
				delete this->mWinContextMenu;
			}
		}

		static void exit(System::Object^ sender, System::EventArgs^ args) {
			System::Windows::Forms::Application::Exit();
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Custom components
		// custom component declaration
		System::Windows::Forms::NotifyIcon ^mWinTrayObject;
		System::Windows::Forms::ContextMenu ^mWinContextMenu;


#pragma endregion

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->Size = System::Drawing::Size(300,300);
			this->Text = L"TeaTime";
			this->Padding = System::Windows::Forms::Padding(0);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		}
#pragma endregion
	};
}
