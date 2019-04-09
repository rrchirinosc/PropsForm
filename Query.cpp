// PropsForm: 
//			A Windows Forms application that connects to an SQL Server via ODBC and allows to execute and visualize query results.
//
// Usage:	
//					
//			Once started click the Connect button to launch the ODBC Select Data Source which can be either local or system installed.
//			If the connecton succeedes, the UI shows the server we are connected to and queries can be executed.
//			To start, select an existing database in the connected server by doing 'use DBname' and upon success 'select' statements 
//			can be executed against it.
//
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
