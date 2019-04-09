#pragma once
#include "PropsSQLHandler.h"
#include <vcclr.h>



namespace PropsForm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	#define MAX_COLUMNS 20				// max output table columns
	#define MAX_COLUMN_DATA 50			// max characters per table cell
	#define	MAX_SERVER_NAME	256			// buffer size to get server name 

	/// <summary>
	/// Summary for Query
	/// </summary>
	public ref class Query : public System::Windows::Forms::Form
	{
	public:
		Query(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			bConnected = false;
		}
	private: System::Windows::Forms::Button^  run_query;
	private: System::Windows::Forms::Button^  clear_query;
	private: System::Windows::Forms::TextBox^  query_status;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private:
		PropsSQLHandler *pHandler;		// SQL commands handler
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
			 bool bConnected;


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Query()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  dsn_connect;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  connected_dsn;
	private: System::Windows::Forms::ListView^  query_results;
	private: System::Windows::Forms::TextBox^  query_box;
	private: System::Windows::Forms::Label^  label3;

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
			this->dsn_connect = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->connected_dsn = (gcnew System::Windows::Forms::TextBox());
			this->query_results = (gcnew System::Windows::Forms::ListView());
			this->query_box = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->run_query = (gcnew System::Windows::Forms::Button());
			this->clear_query = (gcnew System::Windows::Forms::Button());
			this->query_status = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1->SuspendLayout();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dsn_connect
			// 
			this->dsn_connect->Location = System::Drawing::Point(446, 28);
			this->dsn_connect->Name = L"dsn_connect";
			this->dsn_connect->Size = System::Drawing::Size(145, 45);
			this->dsn_connect->TabIndex = 0;
			this->dsn_connect->Text = L"Connect";
			this->dsn_connect->UseVisualStyleBackColor = true;
			this->dsn_connect->Click += gcnew System::EventHandler(this, &Query::dsn_connect_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(23, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Connected to:";
			// 
			// connected_dsn
			// 
			this->connected_dsn->Location = System::Drawing::Point(26, 53);
			this->connected_dsn->Name = L"connected_dsn";
			this->connected_dsn->ReadOnly = true;
			this->connected_dsn->Size = System::Drawing::Size(390, 20);
			this->connected_dsn->TabIndex = 2;
			// 
			// query_results
			// 
			this->query_results->GridLines = true;
			this->query_results->Location = System::Drawing::Point(26, 298);
			this->query_results->Name = L"query_results";
			this->query_results->Size = System::Drawing::Size(565, 357);
			this->query_results->TabIndex = 6;
			this->query_results->UseCompatibleStateImageBehavior = false;
			this->query_results->View = System::Windows::Forms::View::Details;
			// 
			// query_box
			// 
			this->query_box->Location = System::Drawing::Point(18, 19);
			this->query_box->Multiline = true;
			this->query_box->Name = L"query_box";
			this->query_box->ReadOnly = true;
			this->query_box->Size = System::Drawing::Size(372, 130);
			this->query_box->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(23, 273);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(66, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Result table:";
			// 
			// run_query
			// 
			this->run_query->Location = System::Drawing::Point(414, 103);
			this->run_query->Name = L"run_query";
			this->run_query->Size = System::Drawing::Size(145, 46);
			this->run_query->TabIndex = 11;
			this->run_query->Text = L"Execute";
			this->run_query->UseVisualStyleBackColor = true;
			this->run_query->Click += gcnew System::EventHandler(this, &Query::run_query_Click);
			// 
			// clear_query
			// 
			this->clear_query->Location = System::Drawing::Point(466, 19);
			this->clear_query->Name = L"clear_query";
			this->clear_query->Size = System::Drawing::Size(93, 29);
			this->clear_query->TabIndex = 12;
			this->clear_query->Text = L"Clear";
			this->clear_query->UseVisualStyleBackColor = true;
			this->clear_query->Click += gcnew System::EventHandler(this, &Query::clear_query_Click);
			// 
			// query_status
			// 
			this->query_status->Enabled = false;
			this->query_status->ForeColor = System::Drawing::SystemColors::WindowText;
			this->query_status->Location = System::Drawing::Point(26, 663);
			this->query_status->Name = L"query_status";
			this->query_status->ReadOnly = true;
			this->query_status->Size = System::Drawing::Size(565, 20);
			this->query_status->TabIndex = 13;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->query_box);
			this->groupBox1->Controls->Add(this->clear_query);
			this->groupBox1->Controls->Add(this->run_query);
			this->groupBox1->Location = System::Drawing::Point(26, 95);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(565, 163);
			this->groupBox1->TabIndex = 14;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Query";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(614, 24);
			this->menuStrip1->TabIndex = 15;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(52, 20);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Query::aboutToolStripMenuItem_Click);
			// 
			// Query
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Cornsilk;
			this->ClientSize = System::Drawing::Size(614, 691);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->query_status);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->query_results);
			this->Controls->Add(this->connected_dsn);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dsn_connect);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->MaximumSize = System::Drawing::Size(630, 730);
			this->MinimumSize = System::Drawing::Size(630, 730);
			this->Name = L"Query";
			this->Text = L"PropsForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Query::Query_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Query::Query_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
		//
		// Form is loading. Initialize SQL handler, quit upon failure
		//
		private: System::Void Query_Load(System::Object^  sender, System::EventArgs^  e) {

			SQLRETURN sqlRet;

			pHandler = new PropsSQLHandler();
			if (!pHandler) {
				MessageBox::Show("Unable to load SQL handler, exiting", this->Text, System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error);
				this->Close();
			}

			// Allocate an environment
			sqlRet = pHandler->Init();
			if (SQLFAILED(sqlRet))
				MessageBox::Show("Unable to load SQL handler, exiting", this->Text, System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error);
		}
		

		//
		// Connect button event which brings up the the system Select DSN dialog 
		//
		private: System::Void dsn_connect_Click(System::Object^  sender, System::EventArgs^  e) {

			SQLRETURN sqlRet;
			HWND  hwnd = static_cast<HWND>(this->Handle.ToPointer());

			// No new connection handled so we track if are already connected
			if (bConnected) {
				MessageBox::Show("Already connected", this->Text, System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Information);
				return;
			}

			// Attempt to Connect and react accordingly
			sqlRet = pHandler->Connect(hwnd, NULL);

			if (SQLFAILED(sqlRet)) {
				MessageBox::Show("No valid DSN given or unable to connect", this->Text, System::Windows::Forms::MessageBoxButtons::OK,
					System::Windows::Forms::MessageBoxIcon::Error);
			}
			else {
				sqlRet = pHandler->AllocStatementHandle();
				if (SQLFAILED(sqlRet)) {
					MessageBox::Show("Unable to allocate query handle", this->Text, System::Windows::Forms::MessageBoxButtons::OK,
						System::Windows::Forms::MessageBoxIcon::Error);
				}
				else {
					WCHAR server[MAX_SERVER_NAME];
					sqlRet = pHandler->GetServerName(server, MAX_SERVER_NAME);

					String ^dsn_str = gcnew String(server);
					this->connected_dsn->Text = SQLSUCCEEDED(sqlRet) ? dsn_str : L"N/A";
					this->bConnected = true;

					this->query_box->ReadOnly = false;
					this->run_query->Enabled = true;
				}
			}
		}

		//
		// Run query event. ExecuteQuery() handles query outcome
		//
		private: System::Void run_query_Click(System::Object^  sender, System::EventArgs^  e) {
			
			String^ query = gcnew String("");

			// clean listview of possible old results
			this->query_results->Clear();

			// get query
			query = this->query_box->Text;

			if (String::IsNullOrEmpty(query) || String::IsNullOrWhiteSpace(query)) {
				this->query_status->ForeColor = System::Drawing::Color::Black;
				this->query_status->Text = "Nothing to execute";
				return;
			}

			this->ExecuteQuery(query);
		}

		//
		// This function just clears both the query and the results from the UI
		//
		private: System::Void clear_query_Click(System::Object^  sender, System::EventArgs^  e) {

			this->query_box->Clear();
			this->query_results->Clear();
			this->query_status->Clear();
			this->query_status->BackColor = System::Drawing::Color::White;
		}

		//
		//	Form is being closed, cleanup
		//
		private: System::Void Query_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {

			// remove SQL handler if instantiated
			if (this->pHandler)
				delete pHandler;
		}

		//
		// Query execution, handle query return values and upon success forward the result set for display
		//
		private: SQLRETURN ExecuteQuery(String^ query) {

			SQLRETURN sqlRet;
			SQLSMALLINT nColumns;
			bool status = true;
			pin_ptr<const wchar_t> str = PtrToStringChars(query);

			// Execute the query
			sqlRet = pHandler->Query((SQLWCHAR*)str, &nColumns);

			switch (sqlRet) {

			case SQL_SUCCESS:
			case SQL_SUCCESS_WITH_INFO:
				if (nColumns) {
					this->Cursor = System::Windows::Forms::Cursors::WaitCursor;
					status = DisplayQueryResults(nColumns);
					this->Cursor = System::Windows::Forms::Cursors::Default;
				}
				if (status) {
					this->query_status->BackColor = System::Drawing::Color::LightGreen;
					this->query_status->Text = L"Query executed successfully";
					break;
				}

			case SQL_ERROR:
				this->query_status->BackColor = System::Drawing::Color::LightSalmon;
				this->query_status->Text = L"Query error";
				break;

			case SQL_NO_DATA:
				this->query_status->BackColor = System::Drawing::Color::LightGray;
				this->query_status->Text = L"No rows affected";
				break;

			case SQL_INVALID_HANDLE:
				this->query_status->BackColor = System::Drawing::Color::LightGreen;
				this->query_status->Text = L"Invalid handle";
				break;

				// Anything else not handled for the sake of this test program
			default:
				break;
			}

			return pHandler->ResetQuery();
		}

		//
		// Display query results in a listview
		// Column data is fetch and display a row at the time
		// TODO: See to optimize
		//
		private: bool DisplayQueryResults(SQLSMALLINT nColumns) {

			WCHAR colNameBuffer[MAX_COLUMN_DATA];	// buffer to contain column names
			SQLRETURN sqlRet;						// SQL return 
			SQLLEN colBindLength;
			bool bNoData;							// no more data in the statement flag
			WCHAR *pBuffers[MAX_COLUMNS];			// holds pointers to column data

			// Clean up columns buffer array
			ZeroMemory(&pBuffers, sizeof(WCHAR*)*MAX_COLUMNS);

			// Add column headers, first to show row number
			this->query_results->Columns->Add("", 100, System::Windows::Forms::HorizontalAlignment::Right);

			// Loop to output result table header, allocate cell buffers and 
			// bind column buffers with driver
			for (SQLSMALLINT column = 0; column < nColumns; column++) {

				// Display column names
				sqlRet = this->pHandler->GetColumnName(column + 1, colNameBuffer, MAX_COLUMN_DATA);
				if (SQLSUCCEEDED(sqlRet)) {
					String^ columnName = gcnew String(colNameBuffer);
					this->query_results->Columns->Add(columnName, 100, System::Windows::Forms::HorizontalAlignment::Left);
				}

				//Allocate column (table cell) data
				pBuffers[column] = (WCHAR*)malloc(MAX_COLUMN_DATA);
				if (pBuffers[column] == NULL) {
					return false;
				}

				// Bind column data
				this->pHandler->BindColumn(column + 1, pBuffers[column], MAX_COLUMN_DATA, &colBindLength);
			}

			// Display column data
		
			int rowCount = 0;
			bNoData = false;

			do {
				// Get whole statement data
				sqlRet = pHandler->FetchColumnData();

				if (sqlRet == SQL_NO_DATA_FOUND)
				{
					bNoData = true;
				}
				else
				{
					// There's data, display complete row preceeded by row number
					System::Windows::Forms::ListViewItem^ row = (gcnew System::Windows::Forms::ListViewItem());
					++rowCount;
					String^ rowNumber = gcnew String(rowCount.ToString());
					row->Text = rowNumber;
					for (SQLSMALLINT column = 0; column < nColumns; column++) {
						String^ columnValue = gcnew String(pBuffers[column]);
						row->SubItems->Add(columnValue);
					}
					this->query_results->Items->Add(row);
				}
			} while (!bNoData);

			// adjust listview
			this->query_results->AutoResizeColumns(System::Windows::Forms::ColumnHeaderAutoResizeStyle::ColumnContent);
			this->query_results->AutoResizeColumns(System::Windows::Forms::ColumnHeaderAutoResizeStyle::HeaderSize);


			// Clean up, unbind buffers and free them
			for (SQLSMALLINT column = 0; column < nColumns; column++) {
				// Unbind column
				pHandler->BindColumn(column + 1, NULL, 0, NULL);

				// Release memory used by binding
				if (pBuffers[column] != NULL) {
					free(pBuffers[column]);
					pBuffers[column] = NULL;
				}
			}
			return true;
		}

		//
		// About box
		//
		private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
			MessageBox::Show("Written by Raul Chirinos Coya, 2019", this->Text, System::Windows::Forms::MessageBoxButtons::OK,
				System::Windows::Forms::MessageBoxIcon::Error);
		}
};
}

