#pragma once
#include "Admin.h"
#include <msclr\marshal_cppstd.h>
#include "RegController.h"

namespace TicketHelper {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RegForm
	/// </summary>
	public ref class RegForm : public System::Windows::Forms::Form
	{
	public:
		RegForm(void)
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
		~RegForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::ComboBox^ cbUserType;
	private: System::Windows::Forms::Label^ lbRegistration;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ tbName;
	private: System::Windows::Forms::TextBox^ tbLogin;

	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ tbPassword;
	private: System::Windows::Forms::Button^ btRegister;
	private: System::Windows::Forms::Button^ btAuthorize;
	private: System::Windows::Forms::Label^ label5;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;



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
			this->cbUserType = (gcnew System::Windows::Forms::ComboBox());
			this->lbRegistration = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tbName = (gcnew System::Windows::Forms::TextBox());
			this->tbLogin = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tbPassword = (gcnew System::Windows::Forms::TextBox());
			this->btRegister = (gcnew System::Windows::Forms::Button());
			this->btAuthorize = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// cbUserType
			// 
			this->cbUserType->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Адміністратор", L"Відвідувач" });
			this->cbUserType->Location = System::Drawing::Point(192, 114);
			this->cbUserType->Name = L"cbUserType";
			this->cbUserType->Size = System::Drawing::Size(204, 24);
			this->cbUserType->TabIndex = 1;
			this->cbUserType->Text = L"Тип";
			// 
			// lbRegistration
			// 
			this->lbRegistration->AutoSize = true;
			this->lbRegistration->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbRegistration->Location = System::Drawing::Point(206, 34);
			this->lbRegistration->Name = L"lbRegistration";
			this->lbRegistration->Size = System::Drawing::Size(160, 32);
			this->lbRegistration->TabIndex = 2;
			this->lbRegistration->Text = L"Реєстрація";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(187, 75);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(209, 25);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Виберіть тип акаунту";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(232, 151);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(124, 25);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Введіть ім\'я";
			// 
			// tbName
			// 
			this->tbName->Location = System::Drawing::Point(192, 179);
			this->tbName->Name = L"tbName";
			this->tbName->Size = System::Drawing::Size(204, 22);
			this->tbName->TabIndex = 5;
			// 
			// tbLogin
			// 
			this->tbLogin->Location = System::Drawing::Point(192, 232);
			this->tbLogin->Name = L"tbLogin";
			this->tbLogin->Size = System::Drawing::Size(204, 22);
			this->tbLogin->TabIndex = 7;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(232, 204);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(134, 25);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Введіть логін";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(222, 257);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(153, 25);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Введіть пароль";
			// 
			// tbPassword
			// 
			this->tbPassword->Location = System::Drawing::Point(192, 285);
			this->tbPassword->Name = L"tbPassword";
			this->tbPassword->Size = System::Drawing::Size(204, 22);
			this->tbPassword->TabIndex = 9;
			// 
			// btRegister
			// 
			this->btRegister->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btRegister->Location = System::Drawing::Point(201, 328);
			this->btRegister->Name = L"btRegister";
			this->btRegister->Size = System::Drawing::Size(184, 41);
			this->btRegister->TabIndex = 10;
			this->btRegister->Text = L"Зареєструватися";
			this->btRegister->UseVisualStyleBackColor = true;
			this->btRegister->Click += gcnew System::EventHandler(this, &RegForm::btRegister_Click);
			// 
			// btAuthorize
			// 
			this->btAuthorize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btAuthorize->Location = System::Drawing::Point(201, 433);
			this->btAuthorize->Name = L"btAuthorize";
			this->btAuthorize->Size = System::Drawing::Size(184, 41);
			this->btAuthorize->TabIndex = 11;
			this->btAuthorize->Text = L"Авторизуватися";
			this->btAuthorize->UseVisualStyleBackColor = true;
			this->btAuthorize->Click += gcnew System::EventHandler(this, &RegForm::btAuthorize_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(188, 410);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(224, 20);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Якщо у вас вже є аккаунт";
			// 
			// RegForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(566, 499);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->btAuthorize);
			this->Controls->Add(this->btRegister);
			this->Controls->Add(this->tbPassword);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->tbLogin);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->tbName);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->lbRegistration);
			this->Controls->Add(this->cbUserType);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(584, 546);
			this->MinimumSize = System::Drawing::Size(584, 546);
			this->Name = L"RegForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RegForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	

private: System::Void btRegister_Click(System::Object^ sender, System::EventArgs^ e) {
	msclr::interop::marshal_context context;

	std::string name = context.marshal_as<std::string>(this->tbName->Text);
	std::string login = context.marshal_as<std::string>(this->tbLogin->Text);
	std::string password = context.marshal_as<std::string>(this->tbPassword->Text);

	if (cbUserType->SelectedIndex == 0)
	{
		Admin admin(name, login, password);
		RegController regController;
		regController.json_write(admin);
	}
	else if (cbUserType->SelectedIndex == 1)
	{
		
		Visitor visitor(name, login, password);
		RegController regController;
		regController.json_write(visitor);
	}
	else
	{
		this->cbUserType->BackColor = System::Drawing::Color::Red;
	}
}

private: System::Void btAuthorize_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
};

}
