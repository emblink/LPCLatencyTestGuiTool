#pragma once
#include "protocol.h"
#include <cstring>
#include <stdio.h>

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
	private: System::Windows::Forms::Label^ COM_PORT;

	private: System::Windows::Forms::Button^ ResetDevice;
	private: System::Windows::Forms::Button^ Trigger;
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
	private: System::Windows::Forms::Label^ PeriodMax;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ Start;



	private: System::Windows::Forms::Button^ Disconnect;
	private: System::Windows::Forms::Timer^ PingTimer;
	private: System::Windows::Forms::RichTextBox^ Log;
	private: System::Windows::Forms::CheckBox^ RandomCheckbox;
	private: System::Windows::Forms::CheckBox^ DebugCheckBox;


	private: System::Windows::Forms::Button^ ClearLog;
	private: System::Windows::Forms::Button^ Stop;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown3;
	private: System::Windows::Forms::Label^ PeriodMin;
	private: System::Windows::Forms::Splitter^ splitter1;










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
			this->COM_PORT = (gcnew System::Windows::Forms::Label());
			this->ResetDevice = (gcnew System::Windows::Forms::Button());
			this->Trigger = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->PeriodMax = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->Start = (gcnew System::Windows::Forms::Button());
			this->Disconnect = (gcnew System::Windows::Forms::Button());
			this->PingTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->Log = (gcnew System::Windows::Forms::RichTextBox());
			this->RandomCheckbox = (gcnew System::Windows::Forms::CheckBox());
			this->DebugCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->ClearLog = (gcnew System::Windows::Forms::Button());
			this->Stop = (gcnew System::Windows::Forms::Button());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->PeriodMin = (gcnew System::Windows::Forms::Label());
			this->splitter1 = (gcnew System::Windows::Forms::Splitter());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
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
			this->comboBox1->Location = System::Drawing::Point(457, 12);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(151, 21);
			this->comboBox1->TabIndex = 0;
			// 
			// Connect
			// 
			this->Connect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Connect->ForeColor = System::Drawing::Color::ForestGreen;
			this->Connect->Location = System::Drawing::Point(387, 199);
			this->Connect->Name = L"Connect";
			this->Connect->Size = System::Drawing::Size(97, 48);
			this->Connect->TabIndex = 1;
			this->Connect->Text = L"Connect";
			this->Connect->UseVisualStyleBackColor = true;
			this->Connect->Click += gcnew System::EventHandler(this, &Form1::onConnectClick);
			// 
			// COM_PORT
			// 
			this->COM_PORT->AutoSize = true;
			this->COM_PORT->Location = System::Drawing::Point(384, 15);
			this->COM_PORT->Name = L"COM_PORT";
			this->COM_PORT->Size = System::Drawing::Size(67, 13);
			this->COM_PORT->TabIndex = 2;
			this->COM_PORT->Text = L"COM_PORT";
			this->COM_PORT->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// ResetDevice
			// 
			this->ResetDevice->Enabled = false;
			this->ResetDevice->ForeColor = System::Drawing::Color::Red;
			this->ResetDevice->Location = System::Drawing::Point(524, 253);
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
			this->Trigger->Location = System::Drawing::Point(387, 253);
			this->Trigger->Name = L"Trigger";
			this->Trigger->Size = System::Drawing::Size(97, 47);
			this->Trigger->TabIndex = 4;
			this->Trigger->Text = L"Trigger OFF";
			this->Trigger->UseVisualStyleBackColor = false;
			this->Trigger->Click += gcnew System::EventHandler(this, &Form1::onTriggerPress);
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(370, 374);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(272, 23);
			this->progressBar1->TabIndex = 5;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numericUpDown1->Location = System::Drawing::Point(461, 118);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown1->MaximumSize = System::Drawing::Size(150, 0);
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(86, 29);
			this->numericUpDown1->TabIndex = 6;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65, 0, 0, 0 });
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(483, 157);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 500000, 0, 0, 0 });
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(80, 20);
			this->numericUpDown2->TabIndex = 7;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			// 
			// PeriodMax
			// 
			this->PeriodMax->AutoSize = true;
			this->PeriodMax->Location = System::Drawing::Point(377, 125);
			this->PeriodMax->Name = L"PeriodMax";
			this->PeriodMax->Size = System::Drawing::Size(78, 13);
			this->PeriodMax->TabIndex = 8;
			this->PeriodMax->Text = L"Period max, ms";
			this->PeriodMax->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(370, 159);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Measurements Count";
			// 
			// Start
			// 
			this->Start->Enabled = false;
			this->Start->Location = System::Drawing::Point(387, 306);
			this->Start->Name = L"Start";
			this->Start->Size = System::Drawing::Size(97, 47);
			this->Start->TabIndex = 10;
			this->Start->Text = L"Start";
			this->Start->UseVisualStyleBackColor = true;
			this->Start->Click += gcnew System::EventHandler(this, &Form1::onStartPress);
			// 
			// Disconnect
			// 
			this->Disconnect->Enabled = false;
			this->Disconnect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Disconnect->ForeColor = System::Drawing::Color::Red;
			this->Disconnect->Location = System::Drawing::Point(524, 199);
			this->Disconnect->Name = L"Disconnect";
			this->Disconnect->Size = System::Drawing::Size(97, 48);
			this->Disconnect->TabIndex = 12;
			this->Disconnect->Text = L"Disconnect";
			this->Disconnect->UseVisualStyleBackColor = true;
			this->Disconnect->Click += gcnew System::EventHandler(this, &Form1::onDisconnectClick);
			// 
			// PingTimer
			// 
			this->PingTimer->Tick += gcnew System::EventHandler(this, &Form1::pingTimerEvent);
			// 
			// Log
			// 
			this->Log->Dock = System::Windows::Forms::DockStyle::Left;
			this->Log->Location = System::Drawing::Point(0, 0);
			this->Log->Name = L"Log";
			this->Log->ReadOnly = true;
			this->Log->Size = System::Drawing::Size(364, 427);
			this->Log->TabIndex = 13;
			this->Log->Text = L"";
			// 
			// RandomCheckbox
			// 
			this->RandomCheckbox->AutoSize = true;
			this->RandomCheckbox->Location = System::Drawing::Point(553, 91);
			this->RandomCheckbox->Name = L"RandomCheckbox";
			this->RandomCheckbox->Size = System::Drawing::Size(99, 17);
			this->RandomCheckbox->TabIndex = 14;
			this->RandomCheckbox->Text = L"Random Period";
			this->RandomCheckbox->UseVisualStyleBackColor = true;
			// 
			// DebugCheckBox
			// 
			this->DebugCheckBox->AutoSize = true;
			this->DebugCheckBox->Location = System::Drawing::Point(457, 53);
			this->DebugCheckBox->Name = L"DebugCheckBox";
			this->DebugCheckBox->Size = System::Drawing::Size(75, 17);
			this->DebugCheckBox->TabIndex = 15;
			this->DebugCheckBox->Text = L"Debug log";
			this->DebugCheckBox->UseVisualStyleBackColor = true;
			this->DebugCheckBox->CheckedChanged += gcnew System::EventHandler(this, &Form1::checkBox2_CheckedChanged);
			// 
			// ClearLog
			// 
			this->ClearLog->Location = System::Drawing::Point(370, 44);
			this->ClearLog->Name = L"ClearLog";
			this->ClearLog->Size = System::Drawing::Size(66, 33);
			this->ClearLog->TabIndex = 16;
			this->ClearLog->Text = L"Clear Log";
			this->ClearLog->UseVisualStyleBackColor = true;
			this->ClearLog->Click += gcnew System::EventHandler(this, &Form1::ClearLog_Click);
			// 
			// Stop
			// 
			this->Stop->Location = System::Drawing::Point(524, 306);
			this->Stop->Name = L"Stop";
			this->Stop->Size = System::Drawing::Size(97, 47);
			this->Stop->TabIndex = 17;
			this->Stop->Text = L"Stop";
			this->Stop->UseVisualStyleBackColor = true;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numericUpDown3->Location = System::Drawing::Point(461, 85);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->numericUpDown3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(86, 29);
			this->numericUpDown3->TabIndex = 18;
			this->numericUpDown3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 65, 0, 0, 0 });
			// 
			// PeriodMin
			// 
			this->PeriodMin->AutoSize = true;
			this->PeriodMin->Location = System::Drawing::Point(380, 95);
			this->PeriodMin->Name = L"PeriodMin";
			this->PeriodMin->Size = System::Drawing::Size(75, 13);
			this->PeriodMin->TabIndex = 19;
			this->PeriodMin->Text = L"Period min, ms";
			this->PeriodMin->Click += gcnew System::EventHandler(this, &Form1::PeriodMin_Click);
			// 
			// splitter1
			// 
			this->splitter1->Location = System::Drawing::Point(364, 0);
			this->splitter1->Name = L"splitter1";
			this->splitter1->Size = System::Drawing::Size(10, 427);
			this->splitter1->TabIndex = 20;
			this->splitter1->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(654, 427);
			this->Controls->Add(this->splitter1);
			this->Controls->Add(this->PeriodMin);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->Stop);
			this->Controls->Add(this->ClearLog);
			this->Controls->Add(this->DebugCheckBox);
			this->Controls->Add(this->RandomCheckbox);
			this->Controls->Add(this->Log);
			this->Controls->Add(this->Disconnect);
			this->Controls->Add(this->Start);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->PeriodMax);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->Trigger);
			this->Controls->Add(this->ResetDevice);
			this->Controls->Add(this->COM_PORT);
			this->Controls->Add(this->Connect);
			this->Controls->Add(this->comboBox1);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LPCLatencyTestTool";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
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
						this->Log->AppendText("Connected\r\n");
						this->Connect->Enabled = false;
						this->Disconnect->Enabled = true;
						this->ResetDevice->Enabled = true;
						this->Start->Enabled = true; // start
						this->Disconnect->Enabled = true;
						this->Trigger->Enabled = true;
						this->PingTimer->Enabled = true;
					}
					else {
						this->Log->AppendText("Connection failed\r\n");
					}
				}
				else {
					this->Log->AppendText("Already connected\r\n");
				}
			}
			catch(UnauthorizedAccessException^) {
				this->Log->AppendText("UnauthorizedAccess\r\n");
			}
		} else {
			this->Log->AppendText("Choose COM PORT\r\n");
		}
	}

	private: System::Void onDisconnectClick(System::Object^ sender, System::EventArgs^ e) {
		if (this->serialPort1->IsOpen) {
			this->serialPort1->Close();
			this->Log->AppendText("Disconnected\r\n");
			this->Connect->Enabled = true;
			this->Disconnect->Enabled = false;
			this->ResetDevice->Enabled = false;
			this->Start->Enabled = false; // start
			this->Disconnect->Enabled = false;
			this->Trigger->Enabled = false;
			this->PingTimer->Enabled = false;
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
		this->Log->CheckForIllegalCrossThreadCalls = false; // Disable exeption
		try {
			String^ msg = this->serialPort1->ReadLine();
			this->Log->AppendText(msg);
		}
		catch (TimeoutException^) {

		}
		// TODO: uncomment when MCU side will be ready
		//uint32_t id = msg[0] - '0';
		//if (id == DEVICE_CMD_LOG_MESSAGE) {
		//	this->Log->AppendText(msg);
		//}
	}

	private: System::Void pingTimerEvent(System::Object^ sender, System::EventArgs^ e) {
		//Packet packet;
		//memset(&packet, 0, sizeof(packet));
		//static uint8_t num = 0;
		//packet.general.id = PACKET_ID_PING;
		//packet.general.len = num;
		//packet.general.terminator = '\n';
		//String^ msg = gcnew String((char *) packet.data);
		//this->serialPort1->Write(msg);
		//char log[50];
		//sprintf(log, "Ping %u...\r\n", num);
		//String^ msgLog = gcnew String(log);
		//this->Log->AppendText(msgLog);
		//num++;
	}

	private: System::Void Log_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void fileSystemWatcher1_Changed(System::Object^ sender, System::IO::FileSystemEventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
	private: System::Void ClearLog_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Log->Clear();
	}

private: System::Void PeriodMin_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
