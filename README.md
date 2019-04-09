# PropsForm
A Windows Forms application that connects to an SQL Server via ODBC and allows to execute 
and visualize query results.

Once started click the Connect button to launch the ODBC Select Data Source which can be either 
local or system installed.

If the connecton succeedes, the UI shows the server we are connected to and queries can be executed.

To start, select an existing database in the connected server by doing 'use DBname' and upon success 
'select' statements can be executed against it.

Compilation details:

Project was created using Visual Studio 2017 -- not tested with other versions.

To build dowload source and execute PropsConsole.vcxproj.

This will launch Visual Studio with the project loaded.

Build the desired configuration and save the solution file (sln) for future use.
