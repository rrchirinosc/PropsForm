// PropsForm: 
//			A Windows Forms application that connects to an SQL Server via ODBC and allows to execute and visualize query results.
//
// Usage:	
//			Since this is a test program, in its first version, it has some usability restrictions.
//			The program requires an ODBC system Data Server Name (DSN) properly installed in the machine hosting the SQL database.
//			There is support for both 32 and 64bit DSNs depending on what platform the program has been compiled for. As by default 
//			it is compiled for Win32, it can connect only via 32bit DSNs.
//			Upon starting, the program queries for a DSN and indicates whether or not the connection succeeded.
//			Once connected, queries can be executed at the prompt.
//			Program also accept the DSN from the command-line.
//
// Modules:	
//			Query, main application single form in charge to connect, execute queries and show result sets
//			PropsSQLHandler, class in charge to handle all SQL communication
//
// Author:	
//			Raul R. Chirinos, 2019
//			version 1.0.0.1
//
// Notes:	
//			This program has taken some ideas, not code, from sample programs and documentation provided by Microsoft.

#include <windows.h>
#include "Query.h"


using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void Main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PropsForm::Query form;
	Application::Run(%form);
}
