#pragma once
#include "Admin.h"
namespace TicketHelper {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AdminAccountForm
	/// </summary>
	public ref class AdminAccountForm : public System::Windows::Forms::Form
	{
	public:
		String^ name;
		String^ login;
		String^ password;
		AdminAccountForm(Admin _account)
		{
			InitializeComponent();
			name = gcnew String(_account.name.data());
			login = gcnew String(_account.login.data());
			password = gcnew String(_account.password.data());

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminAccountForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbWelcome;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lbWelcome = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lbWelcome
			// 
			this->lbWelcome->AutoSize = true;
			this->lbWelcome->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbWelcome->Location = System::Drawing::Point(12, 29);
			this->lbWelcome->Name = L"lbWelcome";
			this->lbWelcome->Size = System::Drawing::Size(115, 29);
			this->lbWelcome->TabIndex = 0;
			this->lbWelcome->Text = L"Welcome";
			// 
			// AdminAccountForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(688, 500);
			this->Controls->Add(this->lbWelcome);
			this->Name = L"AdminAccountForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AdminAccountForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:Void Welcome()
		{
			this->lbWelcome->Text = "Welcome, " + name;
		}

	
	};
}
