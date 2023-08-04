#pragma once
#include <iostream>
#include <sstream>
#include <regex>
#include <string>
#include <vector>
#include <curl/curl.h>
#include <stdio.h>
#include "curlWrapper.h"
#include <nlohmann/json.hpp>

using namespace nlohmann;
using namespace System::Collections::Generic;

namespace IpLookUp {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ asnNameL;

	private: System::Windows::Forms::Label^ countryL;
	private: System::Windows::Forms::Label^ asnL;


	private: System::Windows::Forms::Label^ statusL;
	private: System::Windows::Forms::Label^ timeZoneL;


	private: System::Windows::Forms::Label^ zip_codeL;
	private: System::Windows::Forms::Label^ LocationL;


	private: System::Windows::Forms::Label^ cityL;

	private: System::Windows::Forms::Label^ stateL;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ ipL;

	protected:

	protected:

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
		/// le contenu de cette méthode avec l'éditeur de code.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->asnNameL = (gcnew System::Windows::Forms::Label());
			this->countryL = (gcnew System::Windows::Forms::Label());
			this->asnL = (gcnew System::Windows::Forms::Label());
			this->statusL = (gcnew System::Windows::Forms::Label());
			this->timeZoneL = (gcnew System::Windows::Forms::Label());
			this->zip_codeL = (gcnew System::Windows::Forms::Label());
			this->LocationL = (gcnew System::Windows::Forms::Label());
			this->cityL = (gcnew System::Windows::Forms::Label());
			this->stateL = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->ipL = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(375, 39);
			this->panel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->label1->Location = System::Drawing::Point(74, 5);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(226, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ip-LookUp By deve.x_";
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->textBox1);
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Location = System::Drawing::Point(0, 45);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(375, 360);
			this->panel2->TabIndex = 1;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label11);
			this->panel3->Controls->Add(this->label10);
			this->panel3->Controls->Add(this->label9);
			this->panel3->Controls->Add(this->label8);
			this->panel3->Controls->Add(this->label7);
			this->panel3->Controls->Add(this->label6);
			this->panel3->Controls->Add(this->label5);
			this->panel3->Controls->Add(this->label4);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Controls->Add(this->label2);
			this->panel3->Location = System::Drawing::Point(12, 60);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(122, 283);
			this->panel3->TabIndex = 2;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.13F));
			this->label10->ForeColor = System::Drawing::Color::White;
			this->label10->Location = System::Drawing::Point(5, 207);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(119, 26);
			this->label10->TabIndex = 9;
			this->label10->Text = L"ASN name";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.13F));
			this->label9->ForeColor = System::Drawing::Color::White;
			this->label9->Location = System::Drawing::Point(5, 182);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(58, 26);
			this->label9->TabIndex = 8;
			this->label9->Text = L"ASN";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.13F));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(5, 156);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(109, 26);
			this->label8->TabIndex = 7;
			this->label8->Text = L"TimeZone";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.13F));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(5, 130);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(94, 26);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Location";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.13F));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(4, 52);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(59, 26);
			this->label6->TabIndex = 5;
			this->label6->Text = L"state";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.13F));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(4, 78);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(45, 26);
			this->label5->TabIndex = 4;
			this->label5->Text = L"city";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.13F));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(4, 104);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(94, 26);
			this->label4->TabIndex = 3;
			this->label4->Text = L"zip-code";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.13F));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(4, 26);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 26);
			this->label3->TabIndex = 2;
			this->label3->Text = L"country";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.13F));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 26);
			this->label2->TabIndex = 1;
			this->label2->Text = L"status";
			// 
			// panel4
			// 
			this->panel4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(75)), static_cast<System::Int32>(static_cast<System::Byte>(75)),
				static_cast<System::Int32>(static_cast<System::Byte>(75)));
			this->panel4->Controls->Add(this->ipL);
			this->panel4->Controls->Add(this->asnNameL);
			this->panel4->Controls->Add(this->countryL);
			this->panel4->Controls->Add(this->asnL);
			this->panel4->Controls->Add(this->statusL);
			this->panel4->Controls->Add(this->timeZoneL);
			this->panel4->Controls->Add(this->zip_codeL);
			this->panel4->Controls->Add(this->LocationL);
			this->panel4->Controls->Add(this->cityL);
			this->panel4->Controls->Add(this->stateL);
			this->panel4->Location = System::Drawing::Point(153, 57);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(209, 286);
			this->panel4->TabIndex = 0;
			// 
			// asnNameL
			// 
			this->asnNameL->AutoSize = true;
			this->asnNameL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->asnNameL->ForeColor = System::Drawing::Color::White;
			this->asnNameL->Location = System::Drawing::Point(20, 207);
			this->asnNameL->Name = L"asnNameL";
			this->asnNameL->Size = System::Drawing::Size(0, 22);
			this->asnNameL->TabIndex = 18;
			// 
			// countryL
			// 
			this->countryL->AutoSize = true;
			this->countryL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->countryL->ForeColor = System::Drawing::Color::White;
			this->countryL->Location = System::Drawing::Point(19, 26);
			this->countryL->Name = L"countryL";
			this->countryL->Size = System::Drawing::Size(0, 22);
			this->countryL->TabIndex = 11;
			// 
			// asnL
			// 
			this->asnL->AutoSize = true;
			this->asnL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->asnL->ForeColor = System::Drawing::Color::White;
			this->asnL->Location = System::Drawing::Point(20, 182);
			this->asnL->Name = L"asnL";
			this->asnL->Size = System::Drawing::Size(0, 22);
			this->asnL->TabIndex = 17;
			// 
			// statusL
			// 
			this->statusL->AutoSize = true;
			this->statusL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->statusL->ForeColor = System::Drawing::Color::White;
			this->statusL->Location = System::Drawing::Point(17, 0);
			this->statusL->Name = L"statusL";
			this->statusL->Size = System::Drawing::Size(0, 22);
			this->statusL->TabIndex = 10;
			// 
			// timeZoneL
			// 
			this->timeZoneL->AutoSize = true;
			this->timeZoneL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timeZoneL->ForeColor = System::Drawing::Color::White;
			this->timeZoneL->Location = System::Drawing::Point(20, 156);
			this->timeZoneL->Name = L"timeZoneL";
			this->timeZoneL->Size = System::Drawing::Size(0, 22);
			this->timeZoneL->TabIndex = 16;
			// 
			// zip_codeL
			// 
			this->zip_codeL->AutoSize = true;
			this->zip_codeL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->zip_codeL->ForeColor = System::Drawing::Color::White;
			this->zip_codeL->Location = System::Drawing::Point(19, 104);
			this->zip_codeL->Name = L"zip_codeL";
			this->zip_codeL->Size = System::Drawing::Size(0, 22);
			this->zip_codeL->TabIndex = 12;
			// 
			// LocationL
			// 
			this->LocationL->AutoSize = true;
			this->LocationL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LocationL->ForeColor = System::Drawing::Color::White;
			this->LocationL->Location = System::Drawing::Point(20, 130);
			this->LocationL->Name = L"LocationL";
			this->LocationL->Size = System::Drawing::Size(0, 22);
			this->LocationL->TabIndex = 15;
			// 
			// cityL
			// 
			this->cityL->AutoSize = true;
			this->cityL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cityL->ForeColor = System::Drawing::Color::White;
			this->cityL->Location = System::Drawing::Point(19, 78);
			this->cityL->Name = L"cityL";
			this->cityL->Size = System::Drawing::Size(0, 22);
			this->cityL->TabIndex = 13;
			// 
			// stateL
			// 
			this->stateL->AutoSize = true;
			this->stateL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->stateL->ForeColor = System::Drawing::Color::White;
			this->stateL->Location = System::Drawing::Point(19, 52);
			this->stateL->Name = L"stateL";
			this->stateL->Size = System::Drawing::Size(0, 22);
			this->stateL->TabIndex = 14;
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(251, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 38);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Look Up";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.18F));
			this->textBox1->ForeColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(41, 4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(203, 38);
			this->textBox1->TabIndex = 0;
			this->textBox1->Text = L"IP here";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.13F));
			this->label11->ForeColor = System::Drawing::Color::White;
			this->label11->Location = System::Drawing::Point(5, 233);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(33, 26);
			this->label11->TabIndex = 10;
			this->label11->Text = L"IP";
			// 
			// ipL
			// 
			this->ipL->AutoSize = true;
			this->ipL->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ipL->ForeColor = System::Drawing::Color::White;
			this->ipL->Location = System::Drawing::Point(20, 236);
			this->ipL->Name = L"ipL";
			this->ipL->Size = System::Drawing::Size(0, 22);
			this->ipL->TabIndex = 11;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(43)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(43)));
			this->ClientSize = System::Drawing::Size(374, 400);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->MinimumSize = System::Drawing::Size(392, 447);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
};

}
