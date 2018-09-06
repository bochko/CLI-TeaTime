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
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::LinkLabel^  linkLabel1;
			 System::Windows::Forms::ContextMenu ^mWinContextMenu;


#pragma endregion

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(13, 13);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(185, 223);
			this->panel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(4, 4);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(178, 80);
			this->label1->TabIndex = 0;
			this->label1->Text = L"00:00";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(334, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(24, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"X";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 252);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"TeaTime! v0.1.0 ";
			this->label2->Click += gcnew System::EventHandler(this, &TeaTime::label2_Click);
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->linkLabel1->Location = System::Drawing::Point(290, 252);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(68, 13);
			this->linkLabel1->TabIndex = 3;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"GitHub Page";
			// 
			// TeaTime
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(370, 277);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->Name = L"TeaTime";
			this->Text = L"TeaTime";
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
