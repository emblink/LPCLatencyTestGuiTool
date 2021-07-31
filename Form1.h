#pragma once
#include "protocol.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			findPorts();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::IO::Ports::SerialPort^ serialPort1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ Connect;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ ResetDevice;
	private: System::Windows::Forms::Button^ Trigger;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ Start;


	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ Disconnect;






	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->Connect = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->ResetDevice = (gcnew System::Windows::Forms::Button());
			this->Trigger = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Start = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Disconnect = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->SuspendLayout();
			// 
			// serialPort1
			// 
			this->serialPort1->ReadTimeout = 100;
			this->serialPort1->WriteTimeout = 100;
			this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &Form1::serialPort1_DataReceived);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(443, 43);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(151, 21);
			this->comboBox1->TabIndex = 0;
			// 
			// Connect
			// 
			this->Connect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Connect->ForeColor = System::Drawing::Color::ForestGreen;
			this->Connect->Location = System::Drawing::Point(392, 218);
			this->Connect->Name = L"Connect";
			this->Connect->Size = System::Drawing::Size(97, 48);
			this->Connect->TabIndex = 1;
			this->Connect->Text = L"Connect";
			this->Connect->UseVisualStyleBackColor = true;
			this->Connect->Click += gcnew System::EventHandler(this, &Form1::onConnectClick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(370, 46);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"COM_PORT";
			// 
			// ResetDevice
			// 
			this->ResetDevice->Enabled = false;
			this->ResetDevice->ForeColor = System::Drawing::Color::Red;
			this->ResetDevice->Location = System::Drawing::Point(495, 218);
			this->ResetDevice->Name = L"ResetDevice";
			this->ResetDevice->Size = System::Drawing::Size(97, 48);
			this->ResetDevice->TabIndex = 3;
			this->ResetDevice->Text = L"ResetDevice";
			this->ResetDevice->UseVisualStyleBackColor = true;
			this->ResetDevice->Click += gcnew System::EventHandler(this, &Form1::onResetDevice);
			// 
			// Trigger
			// 
			this->Trigger->BackColor = System::Drawing::Color::Transparent;
			this->Trigger->Enabled = false;
			this->Trigger->Location = System::Drawing::Point(392, 272);
			this->Trigger->Name = L"Trigger";
			this->Trigger->Size = System::Drawing::Size(97, 47);
			this->Trigger->TabIndex = 4;
			this->Trigger->Text = L"Trigger OFF";
			this->Trigger->UseVisualStyleBackColor = false;
			this->Trigger->Click += gcnew System::EventHandler(this, &Form1::onTriggerPress);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(366, 345);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(250, 23);
			this->progressBar1->TabIndex = 5;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->AutoSize = true;
			this->numericUpDown1->Location = System::Drawing::Point(495, 119);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(80, 20);
			this->numericUpDown1->TabIndex = 6;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65, 0, 0, 0 });
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(495, 157);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500000, 0, 0, 0 });
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(80, 20);
			this->numericUpDown2->TabIndex = 7;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(407, 121);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(82, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Press Period ms";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(382, 159);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Measurements Count";
			// 
			// Start
			// 
			this->Start->Enabled = false;
			this->Start->Location = System::Drawing::Point(495, 272);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(97, 47);
			this->Start->TabIndex = 10;
			this->Start->Text = L"Start";
			this->Start->UseVisualStyleBackColor = true;
			this->Start->Click += gcnew System::EventHandler(this, &Form1::onStartPress);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Purple;
			this->textBox1->ForeColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(-1, -1);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->textBox1->Size = System::Drawing::Size(365, 381);
			this->textBox1->TabIndex = 11;
			// 
			// Disconnect
			// 
			this->Disconnect->Enabled = false;
			this->Disconnect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Disconnect->ForeColor = System::Drawing::Color::Red;
			this->Disconnect->Location = System::Drawing::Point(392, 189);
			this->Disconnect->Name = L"Disconnect";
			this->Disconnect->Size = System::Drawing::Size(97, 23);
			this->Disconnect->TabIndex = 12;
			this->Disconnect->Text = L"Disconnect";
			this->Disconnect->UseVisualStyleBackColor = true;
			this->Disconnect->Click += gcnew System::EventHandler(this, &Form1::onDisconnectClick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(620, 380);
			this->Controls->Add(this->Disconnect);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->Start);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->Trigger);
			this->Controls->Add(this->ResetDevice);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Connect);
			this->Controls->Add(this->comboBox1);
			this->Name = L"Form1";
			this->Text = L"LPCLatencyTestTool";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// find serial ports
	private: void findPorts(void)
		{
			// get port names
			array<Object^>^ objectArray = SerialPort::GetPortNames();
			// add string array to combobox
			this->comboBox1->Items->AddRange(objectArray);
		}
	private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void onConnectClick(System::Object^ sender, System::EventArgs^ e) {
		if (this->comboBox1->Text != String::Empty) {
			try {
				if (!this->serialPort1->IsOpen) {
					this->serialPort1->PortName = this->comboBox1->Text;
					this->serialPort1->BaudRate = 115200;
					this->serialPort1->Open();
					if (this->serialPort1->IsOpen) {
						this->textBox1->AppendText("Connected\r\n");
						this->Connect->Enabled = false;
						this->Disconnect->Enabled = true;
						this->ResetDevice->Enabled = true;
						this->Start->Enabled = true; // start
						this->Disconnect->Enabled = true;
						this->Trigger->Enabled = true;
					}
					else {
						this->textBox1->AppendText("Connection failed\r\n");
					}
				}
				else {
					this->textBox1->AppendText("Already connected\r\n");
				}
			}
			catch(UnauthorizedAccessException^) {
				this->textBox1->AppendText("UnauthorizedAccess\r\n");
			}
		} else {
			this->textBox1->AppendText("Choose COM PORT\r\n");
		}
	}

	private: System::Void onDisconnectClick(System::Object^ sender, System::EventArgs^ e) {
		if (this->serialPort1->IsOpen) {
			this->serialPort1->Close();
			this->textBox1->AppendText("Disconnected\r\n");
			this->Connect->Enabled = true;
			this->Disconnect->Enabled = false;
			this->ResetDevice->Enabled = false;
			this->Start->Enabled = false; // start
			this->Disconnect->Enabled = false;
			this->Trigger->Enabled = false;
			this->progressBar1->Value = 0;
			this->Trigger->BackColor = System::Drawing::Color::Red;
			this->Trigger->Text = L"Trigger OFF";
			this->Trigger->BackColor = System::Drawing::SystemColors::Control;
		}
	}
	
	private: System::Void onResetDevice(System::Object^ sender, System::EventArgs^ e)
	{
		// TODO: add cmd
	}

	private: System::Void onStartPress(System::Object^ sender, System::EventArgs^ e)
	{
		// TODO: add cmd
	}
	
	private: System::Void onTriggerPress(System::Object^ sender, System::EventArgs^ e)
	{
		static bool isPressed = false;
		isPressed = !isPressed;
		if (isPressed) {
			this->Trigger->BackColor = System::Drawing::Color::ForestGreen;
			this->Trigger->Text = L"Trigger ON";
		}
		else {
			this->Trigger->BackColor = System::Drawing::SystemColors::Control;
			this->Trigger->Text = L"Trigger OFF";
		}

		//Command cmd = {
		//	.id = DEVICE_CMD_TRIGGER_ENABLE,
		//}
		//sendCommand(); // TODO: add cmd
	}

	private: System::Void serialPort1_DataReceived(System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e)
	{
		this->textBox1->CheckForIllegalCrossThreadCalls = false; // Disable exeption
		String^ msg = this->serialPort1->ReadLine();
		//msg->Insert(msg->Length, "\r\n");
		this->textBox1->AppendText(msg);
		//this->textBox1->Paste(msg);
		// TODO: uncomment when MCU side will be ready
		//uint32_t id = msg[0] - '0';
		//if (id == DEVICE_CMD_LOG_MESSAGE) {
		//	msg += '\r';
		//	this->textBox1->AppendText(msg);
		//}
	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void fileSystemWatcher1_Changed(System::Object^ sender, System::IO::FileSystemEventArgs^ e) {
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
