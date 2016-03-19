#include <stdio.h>
#include <time.h>
#include <math.h>
#include <qtXLS.h>

const qt_K_INTEGER  DIMArr = 50, NoColumns = 5, TEXTLen = 256;
static struct qT_TIMESTAMP_STRUCT TSArr[DIMArr];      // defines a date & time structure

void set_qT_SQLColumn( qT_SQLColumn *tColumn, 
                       char* sName,
                       void *ArrayAddr,
                       qt_K_INT4 iArrayDim, 
                       qt_K_INT4 iArrayType, 
                       qt_K_INT4 iLENArrElem )
{
   // tColumn->Name = sName;	// column name
   strcpy(tColumn->Name, sName);	// column name
   tColumn->ArrayAddr	= (qt_K_LP)ArrayAddr;   // address of array
   tColumn->ArrayDim		= iArrayDim;      // array dimension
   tColumn->ArrayType	= iArrayType;     // type of array
   tColumn->LENArrElem	= iLENArrElem;    // size of an array element (in bytes)
   tColumn->IndArrAddr	= 0;              // reserved, unused (should be 0)

   return;
}

void Set_TSArr( int j )
// fill date & time structure with some date and time values
{
   int hour;

   if ( j == 0 )
   {
      time_t now = time(NULL);
      tm *z = localtime(&now);
      TSArr[j].year		= z->tm_year + 1900;
      TSArr[j].month		= z->tm_mon + 1;
      TSArr[j].day		= z->tm_mday;
      TSArr[j].hour		= z->tm_hour;
      TSArr[j].minute	= z->tm_min;
      TSArr[j].second	= z->tm_sec;
      TSArr[j].fraction	= 0;
   }
   else
   // increment date and time
   {
      TSArr[j] = TSArr[j-1];

      TSArr[j].day = TSArr[j-1].day + 1;
      if ( TSArr[j].day > 28 )
      {
         TSArr[j].day = 1;
         TSArr[j].month = TSArr[j-1].month + 1;
         if ( TSArr[j].month > 12 )
         {
            TSArr[j].month = 1;
            TSArr[j].year = TSArr[j-1].year + 1;
         }
      }

      TSArr[j].second = TSArr[j-1].second + 1;
      if ( TSArr[j].second > 59 ) 
      {
         TSArr[j].second = 1;
         TSArr[j].minute = TSArr[j-1].minute + 1;
         if ( TSArr[j].minute > 59 ) 
         {
            TSArr[j].minute = 1;
            hour = TSArr[j-1].hour;
            TSArr[j].hour = hour % 24 + 1;
         }
      }
   }
   return;
}

int main(void)
{
// Program demonstrates usage of qtXLS routines to export some
// data to  an EXCEL file.
//
// We are going to create an EXCEL file named "qtXLSDemo3.xls"
// which contains a table named "qtXLSDemoTable" with
// columns:  lfdNr   x   y   Description   Date_Time   


// Arrays with data to be exported.
   char *szTextArr;           // [DIMArr][TEXTLen];
   qt_K_INTEGER *lfdNrArr;    // INTEGER*4 [DIMArr] arrays
   qt_K_R8 *xArr, *yArr;      // REAL*8 [DIMArr] arrays

   qt_K_R8 angle;
   const qt_K_R8 PI = 3.1415932654;

// variables to be used by qtXLS routines
   qt_K_HANDLE hDS;
   qt_K_INT4 iRet, iRow, TNLen, NoRows, ind;
   char *szFileName;
   struct qT_SQLColumn *tColumns[NoColumns];
   char *szTableName;
   char *szTableDefinition;

   // qtSetXLSLicencePath( szPathName )   // change the path to a location where the licence file resides

   NoRows = DIMArr;
   // allocate arrays for result set
   //szTextArr[NoRows] = new char [NoRows][TEXTLen];
   szTextArr =(char *) calloc(NoRows, TEXTLen);
   lfdNrArr = new qt_K_INTEGER [NoRows];
   xArr = new qt_K_R8 [NoRows];
   yArr = new qt_K_R8 [NoRows];

   if (    szTextArr == NULL 
        || lfdNrArr == NULL 
        || xArr == NULL 
        || yArr == NULL )
   {
      printf("Could not allocate arrays.n");
      return -1;		// to the "Exit"
   }
   // Fill arrays with values (the data we"re going to export into an EXCEL file)
   for (ind = 0; ind < DIMArr; ind++)
   {
      iRow = ind + 1;
      lfdNrArr[ind] = iRow;
      xArr[ind] = iRow * 0.01;
      angle = xArr[ind] * PI;
      yArr[ind] = cos(angle);
      sprintf(szTextArr + ind * TEXTLen, "(Angle = , %.2f,  (degree)", angle * 180. / PI);
      Set_TSArr( ind );    // routine (see CONTAINS section) sets TSArr
   }

// create "empty" EXCEL file
   szFileName = "qtXLSDemo3.xls";
   hDS = qtXLSCreateEXCELFile( szFileName );   // returns a "data source handle" to be used with other qtXLS routines
   if ( hDS == 0 )
   {
      printf("Error returned from qtXLSCreateEXCELFile = %d\n", hDS);
      return -1;
   }
   else
      printf("qtXLSCreateEXCELFile created the file %s\n", szFileName);

   qtXLSSetErrorLevel( 1 );                  // continue, if an error occurs (if possible)
   //T qtXLSSetErrorMessagesDisplay( 1 );    // turn on "error display"

// Create (empty) table
// --------------------
   szTableName = "qtXLSDemoTable";                 // table name (zero terminated)
   TNLen = qtXLSGetszStringLength( szTableName );  // returns length of string (without terminating zero)

// check if table already exists
   if ( qtXLSDoesTableNameExist( hDS, szTableName ) == 1 )
      printf("Table %s already exists.\n", szTableName);
   else
   {
   // create table by setting up a command line containing the table name followed 
   // by a list of pairs of column names and column types (like NUMBER, DATETIME, TEXT, CURRENCY or LOGICAL).
      szTableDefinition = new char [1000];
      strcpy(szTableDefinition, szTableName);
      strcpy(&szTableDefinition[TNLen],
             " (lfdNr NUMBER, x NUMBER, y NUMBER, Description TEXT, Date_Time DATETIME)");
      iRet = qtXLSCreateTable( hDS, szTableDefinition  );
      if ( iRet != 0) return -1;    // stop on error
   }

// Set up columns "lfdNr   x   y   Description   Date_Time" for export
// -------------------------------------------------------------------
   // create array of structure tColumns
   tColumns[0] = (qT_SQLColumn *) calloc(NoColumns, sizeof(qT_SQLColumn));
   for (ind = 1; ind < NoColumns; ind++)
   tColumns[ind] = tColumns[ind-1] + 1; // + sizeof(qT_SQLColumn);

   // 1st column
   set_qT_SQLColumn( tColumns[0], 
                     "lfdNr", 
                     lfdNrArr, 
                     NoRows,
                     qt_SQL_C_SLONG, 
                     4 );
// and remaining columns
   set_qT_SQLColumn(tColumns[1], "x", xArr, NoRows, qt_SQL_C_DOUBLE, 8);
   set_qT_SQLColumn(tColumns[2], "y", yArr, NoRows, qt_SQL_C_DOUBLE, 8);
   set_qT_SQLColumn(tColumns[3], "Description", szTextArr, NoRows, qt_SQL_C_CHAR, TEXTLen);
   set_qT_SQLColumn(tColumns[4], "Date_Time", TSArr, NoRows, qt_SQL_C_TIMESTAMP, 16);

// Fill table with rows
// --------------------
   iRet = qtXLSWriteRows( hDS, szTableName, NoColumns, NoRows, tColumns[0] );

   if ( iRet >= 0 ) 
      printf("qtXLSWriteRows successful. Number of rows written: %d\n", iRet);
   else
      printf("Error returned from qtXLSWriteRows; iError = %d\n", iRet);

   iRet = qtXLSCloseEXCELFile( hDS );
   if ( iRet == 0 )
   {
      printf("Data successfully exported to EXCEL file %s\n", szFileName);
      printf("qtXLS closed.\n");
   }
   else
      printf("Error returned from qtXLSCloseEXCELFile = %d\n", iRet);

   printf("\n");
   printf("(C) QT software GmbH, Germany. All rights reserved. 2006.\n");
   printf("    http:\\www.qtsoftware.de    eMail: info@qtsoftware.de\n");
   return 0;
}