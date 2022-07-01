#pragma once
#include "stdafx.h"
#include <msclr\marshal_cppstd.h>
#include "AuthController.h"
#include "AdminAccountForm.h"
namespace TicketHelper {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			tbPassword->PasswordChar = '*';
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lbLogin;
	private: System::Windows::Forms::Label^ lbPassword;
	private: System::Windows::Forms::TextBox^ tbLogin;
	private: System::Windows::Forms::TextBox^ tbPassword;
	private: System::Windows::Forms::Button^ btEnter;

	private: System::Windows::Forms::Button^ btRegister;
	private: System::Windows::Forms::Label^ lbWrongInfo;




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
			this->lbLogin = (gcnew System::Windows::Forms::Label());
			this->lbPassword = (gcnew System::Windows::Forms::Label());
			this->tbLogin = (gcnew System::Windows::Forms::TextBox());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->btEnter = (gcnew System::Windows::Forms::Button());
			this->btRegister = (gcnew System::Windows::Forms::Button());
			this->lbWrongInfo = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// lbLogin
			// 
			this->lbLogin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbLogin->AutoSize = true;
			this->lbLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbLogin->Location = System::Drawing::Point(268, 77);
			this->lbLogin->Name = L"lbLogin";
			this->lbLogin->Size = System::Drawing::Size(84, 32);
			this->lbLogin->TabIndex = 0;
			this->lbLogin->Text = L"Логін";
			// 
			// lbPassword
			// 
			this->lbPassword->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbPassword->AutoSize = true;
			this->lbPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbPassword->Location = System::Drawing::Point(253, 198);
			this->lbPassword->Name = L"lbPassword";
			this->lbPassword->Size = System::Drawing::Size(113, 32);
			this->lbPassword->TabIndex = 1;
			this->lbPassword->Text = L"Пароль";
			// 
			// tbLogin
			// 
			this->tbLogin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbLogin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbLogin->Location = System::Drawing::Point(204, 135);
			this->tbLogin->Name = L"tbLogin";
			this->tbLogin->Size = System::Drawing::Size(213, 38);
			this->tbLogin->TabIndex = 2;
			// 
			// tbPassword
			// 
			this->tbPassword->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbPassword->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbPassword->Location = System::Drawing::Point(204, 258);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->Size = System::Drawing::Size(213, 38);
			this->tbPassword->TabIndex = 3;
			// 
			// btEnter
			// 
			this->btEnter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btEnter->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btEnter->Location = System::Drawing::Point(259, 342);
			this->btEnter->Name = L"btEnter";
			this->btEnter->Size = System::Drawing::Size(107, 38);
			this->btEnter->TabIndex = 4;
			this->btEnter->Text = L"Ввійти";
			this->btEnter->UseVisualStyleBackColor = true;
			this->btEnter->Click += gcnew System::EventHandler(this, &MainForm::btEnter_Click);
			// 
			// btRegister
			// 
			this->btRegister->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btRegister->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btRegister->Location = System::Drawing::Point(204, 424);
			this->btRegister->Name = L"btRegister";
			this->btRegister->Size = System::Drawing::Size(213, 38);
			this->btRegister->TabIndex = 6;
			this->btRegister->Text = L"Зареєструватися";
			this->btRegister->UseVisualStyleBackColor = true;
			this->btRegister->Click += gcnew System::EventHandler(this, &MainForm::btRegister_Click);
			// 
			// lbWrongInfo
			// 
			this->lbWrongInfo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbWrongInfo->AutoSize = true;
			this->lbWrongInfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbWrongInfo->ForeColor = System::Drawing::Color::Red;
			this->lbWrongInfo->Location = System::Drawing::Point(170, 30);
			this->lbWrongInfo->Name = L"lbWrongInfo";
			this->lbWrongInfo->Size = System::Drawing::Size(282, 22);
			this->lbWrongInfo->TabIndex = 7;
			this->lbWrongInfo->Text = L"Неправильний логін або пароль!";
			this->lbWrongInfo->Visible = false;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(627, 486);
			this->Controls->Add(this->lbWrongInfo);
			this->Controls->Add(this->btRegister);
			this->Controls->Add(this->btEnter);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->tbLogin);
			this->Controls->Add(this->lbPassword);
			this->Controls->Add(this->lbLogin);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(645, 533);
			this->MinimumSize = System::Drawing::Size(645, 533);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Авторизація";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	
private: System::Void btRegister_Click(System::Object^ sender, System::EventArgs^ e) {
	TicketHelper::RegForm regForm;
	regForm.ShowDialog();
	this->Show();
}
private: System::Void btEnter_Click(System::Object^ sender, System::EventArgs^ e) {
	msclr::interop::marshal_context context;

	std::string login = context.marshal_as<std::string>(this->tbLogin->Text);
	std::string password = context.marshal_as<std::string>(this->tbPassword->Text);
	
	AuthController authController;
	if (authController.Authorization(login, password))
	{
		this->Hide();
		TicketHelper::AdminAccountForm adminForm(authController.admin);
		adminForm.Welcome();
		adminForm.ShowDialog();
		this->Close();
	}
	else
	{
		this->lbWrongInfo->Visible = true;
	}
}
};
}
