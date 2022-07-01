#pragma once
#include "Admin.h"
#include "Theatre.h"
#include <msclr\marshal_cppstd.h>
#include "Event.h"

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
	
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ tbMinutes;
	public:

	private: System::Windows::Forms::TextBox^ tbHours;
	private: System::Windows::Forms::Button^ btCreateEvent;

		   
		

	private: System::Windows::Forms::Panel^ panelCreateEvent;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ tbTitle;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;

	private: System::Windows::Forms::ComboBox^ cbYear;
	private: System::Windows::Forms::ComboBox^ cbMonth;
	private: System::Windows::Forms::Button^ btCreate;

	private: System::Windows::Forms::ComboBox^ cbDay;



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
			this->btCreateEvent = (gcnew System::Windows::Forms::Button());
			this->panelCreateEvent = (gcnew System::Windows::Forms::Panel());
			this->btCreate = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tbMinutes = (gcnew System::Windows::Forms::TextBox());
			this->tbHours = (gcnew System::Windows::Forms::TextBox());
			this->cbYear = (gcnew System::Windows::Forms::ComboBox());
			this->cbMonth = (gcnew System::Windows::Forms::ComboBox());
			this->cbDay = (gcnew System::Windows::Forms::ComboBox());
			this->tbTitle = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panelCreateEvent->SuspendLayout();
			this->SuspendLayout();
			// 
			// lbWelcome
			// 
			this->lbWelcome->AutoSize = true;
			this->lbWelcome->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbWelcome->Location = System::Drawing::Point(12, 29);
			this->lbWelcome->Name = L"lbWelcome";
			this->lbWelcome->Size = System::Drawing::Size(118, 29);
			this->lbWelcome->TabIndex = 0;
			this->lbWelcome->Text = L"Вітаємо, ";
			// 
			// btCreateEvent
			// 
			this->btCreateEvent->Location = System::Drawing::Point(12, 70);
			this->btCreateEvent->Name = L"btCreateEvent";
			this->btCreateEvent->Size = System::Drawing::Size(139, 32);
			this->btCreateEvent->TabIndex = 1;
			this->btCreateEvent->Text = L"Створити Подію";
			this->btCreateEvent->UseVisualStyleBackColor = true;
			this->btCreateEvent->Click += gcnew System::EventHandler(this, &AdminAccountForm::btCreateEvent_Click);
			// 
			// panelCreateEvent
			// 
			this->panelCreateEvent->Controls->Add(this->btCreate);
			this->panelCreateEvent->Controls->Add(this->label5);
			this->panelCreateEvent->Controls->Add(this->tbMinutes);
			this->panelCreateEvent->Controls->Add(this->tbHours);
			this->panelCreateEvent->Controls->Add(this->cbYear);
			this->panelCreateEvent->Controls->Add(this->cbMonth);
			this->panelCreateEvent->Controls->Add(this->cbDay);
			this->panelCreateEvent->Controls->Add(this->tbTitle);
			this->panelCreateEvent->Controls->Add(this->label4);
			this->panelCreateEvent->Controls->Add(this->label3);
			this->panelCreateEvent->Controls->Add(this->label2);
			this->panelCreateEvent->Controls->Add(this->label1);
			this->panelCreateEvent->Location = System::Drawing::Point(17, 137);
			this->panelCreateEvent->Name = L"panelCreateEvent";
			this->panelCreateEvent->Size = System::Drawing::Size(637, 295);
			this->panelCreateEvent->TabIndex = 2;
			this->panelCreateEvent->Visible = false;
			// 
			// btCreate
			// 
			this->btCreate->Location = System::Drawing::Point(7, 172);
			this->btCreate->Name = L"btCreate";
			this->btCreate->Size = System::Drawing::Size(106, 32);
			this->btCreate->TabIndex = 10;
			this->btCreate->Text = L"Створити";
			this->btCreate->UseVisualStyleBackColor = true;
			this->btCreate->Click += gcnew System::EventHandler(this, &AdminAccountForm::btCreate_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(146, 127);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(15, 22);
			this->label5->TabIndex = 10;
			this->label5->Text = L":";
			// 
			// tbMinutes
			// 
			this->tbMinutes->Location = System::Drawing::Point(167, 126);
			this->tbMinutes->Name = L"tbMinutes";
			this->tbMinutes->Size = System::Drawing::Size(68, 22);
			this->tbMinutes->TabIndex = 9;
			this->tbMinutes->Text = L"Хвилини";
			// 
			// tbHours
			// 
			this->tbHours->Location = System::Drawing::Point(72, 126);
			this->tbHours->Name = L"tbHours";
			this->tbHours->Size = System::Drawing::Size(68, 22);
			this->tbHours->TabIndex = 8;
			this->tbHours->Text = L"Години";
			// 
			// cbYear
			// 
			this->cbYear->FormattingEnabled = true;
			this->cbYear->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"2022", L"2023", L"2024", L"2025", L"2026", L"2027",
					L"2028", L"2029", L"2030"
			});
			this->cbYear->Location = System::Drawing::Point(248, 88);
			this->cbYear->Name = L"cbYear";
			this->cbYear->Size = System::Drawing::Size(64, 24);
			this->cbYear->TabIndex = 7;
			this->cbYear->Text = L"Рік";
			// 
			// cbMonth
			// 
			this->cbMonth->FormattingEnabled = true;
			this->cbMonth->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"Січень", L"Лютий", L"Березень", L"Квітень", L"Травень",
					L"Червень", L"Липень", L"Серпень", L"Вересень", L"Жовтень", L"Листопад", L"Грудень"
			});
			this->cbMonth->Location = System::Drawing::Point(140, 88);
			this->cbMonth->Name = L"cbMonth";
			this->cbMonth->Size = System::Drawing::Size(102, 24);
			this->cbMonth->TabIndex = 6;
			this->cbMonth->Text = L"Місяць";
			// 
			// cbDay
			// 
			this->cbDay->FormattingEnabled = true;
			this->cbDay->Items->AddRange(gcnew cli::array< System::Object^  >(31) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7", L"8", L"9",
					L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25", L"26", L"27",
					L"28", L"29", L"30", L"31"
			});
			this->cbDay->Location = System::Drawing::Point(72, 88);
			this->cbDay->Name = L"cbDay";
			this->cbDay->Size = System::Drawing::Size(62, 24);
			this->cbDay->TabIndex = 5;
			this->cbDay->Text = L"День";
			// 
			// tbTitle
			// 
			this->tbTitle->Location = System::Drawing::Point(72, 47);
			this->tbTitle->Name = L"tbTitle";
			this->tbTitle->Size = System::Drawing::Size(203, 22);
			this->tbTitle->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(5, 14);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(60, 22);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Театр";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(3, 127);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(41, 22);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Час";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(3, 86);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(52, 22);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Дата";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(3, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Назва";
			// 
			// AdminAccountForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(688, 500);
			this->Controls->Add(this->panelCreateEvent);
			this->Controls->Add(this->btCreateEvent);
			this->Controls->Add(this->lbWelcome);
			this->Name = L"AdminAccountForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AdminAccountForm";
			this->panelCreateEvent->ResumeLayout(false);
			this->panelCreateEvent->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
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
	public:Void Welcome()
		{
			this->lbWelcome->Text += name;
		}

	public:String^ Title;
		  int day, month, year, hours, minutes, theatreIndex;

	private: System::Void btCreateEvent_Click(System::Object^ sender, System::EventArgs^ e) {
		
		this->panelCreateEvent->Visible = true;
	}
private: System::Void btCreate_Click(System::Object^ sender, System::EventArgs^ e) {
	msclr::interop::marshal_context context;

	Title = this->tbTitle->Text;
	day = this->cbDay->SelectedIndex + 1;
	month = this->cbMonth->SelectedIndex + 1;
	year = this->cbYear->SelectedIndex + 1;

	std::string hoursString = context.marshal_as<std::string>(this->tbHours->Text);
	std::string minutesString = context.marshal_as<std::string>(this->tbMinutes->Text);

	hours = stoi(hoursString);
	minutes = stoi(minutesString);

	std::string title = context.marshal_as<std::string>(Title);
	Date date(day, month, year);
	Time time(hours, minutes);


	Event _event(title, date, time);


}
};
}
