/**My Bank WITH NORMAL TRANSACTION**/
#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<dos.h>
#include<iomanip.h>
//THE MENU CLASS DISPLAYS THE MENU
class menus
{
public:
void showmenu(void);
private:
void closemenu(void);
};
// The Class displays all the Customer Account related functions
class disprecords
{
public:
void adddetails(int,char name[30],char address[60],float);
void displaycustomers(void);
void deleteaccount(int);
void updatebalance(int,float);
void updatecustomer(void);
int lastaccount(void);
int accountexists(int);
char *getname(int);
char *getaddress(int);
float getbalance(int);
int getrecord(int);
void display(int);
void displaylist(void);
int accountnumber;
char name[50],address[50];
float intbalance;
};
// THE CLASS HAS ALL THE TRANSACTIONS RELATED METHODS
class accounttransactions
{
public:
void new_account(void);
void closeaccount(void);
void display_account(void);
void transaction(void);
void adddetails(int,int,int,int,char,char
typetransaction[15],float,float,float);
void deleteaccount(int);
int datediffer(int,int,int,int,int,int);
float getinterest(int,float);
void showaccount(int);
int accountnumber;//VARIABLE FOR ACCOUNT NUMBER
char trantype[10];//VARIABLE OF CHEQUE OR CASH INPUT OR OUTPUT
int dday,mmonth,yyear;//TRANSACTION DATE
char transactions;//TYPE OF TRANSACTION:-DEPOSIT OR WITHDRAWL OF AMOUNT
float intinterest,intamount,intbalance;
static float calcinterest;
void showinterest(void);//ADDED
};
//SHOWMENU() METHOD TO DISPLAY THE MAIN MENU IN THE APPLICATION
void menus::showmenu(void)
{
char choice;
while(1)
{
clrscr();
cout<<"\n --Welcome To My Bank Application-- \n";
cout<<"*********************************************************\n";
cout<<" Choose from options \n";
cout<<"---------------------------------------------------------\n";
cout<<" 1: Open An Account\n";
cout<<" 2: View An Account\n";
cout<<" 3: Show All Accounts\n";
cout<<" 4: Make A Transaction\n";
cout<<" 5: Calculate Interest\n";
cout<<" 6: Close An Account\n";
cout<<" 7: Exit\n\n";
cout<<" PLEASE SELECT A CHOICE:";
choice=getche();
if(choice=='1')
{
accounttransactions objat;//OBJECT OF CLASS ACCOUNTTRANSACTION IS CREATED
objat.new_account();
}
else
if(choice=='2')
{
accounttransactions objat;//OBJECT OF CLASS ACCOUNTTRANSACTION IS CREATED
objat.display_account();
}
else
if(choice=='3')
{
disprecords newrec;//OBJECT OF CLASS DispRecds IS CREATED
newrec.displaycustomers();
}
else
if(choice=='4')
{
accounttransactions objat;//OBJECT OF CLASS ACCOUNTTRANSACTION IS CREATED
objat.transaction();
}
else
if(choice=='5')
{
accounttransactions objat;//OBJECT OF CLASS ACCOUNTTRANSACTION IS CREATED
objat.showinterest();
}
else
if(choice=='6')
{
closemenu();
}
else
if(choice=='7')
{
cout<<"\nThanks FOr Using Our Application.\nPlease Press Any Key TO Exit.\n";
getch();
break;
}
}
}
//CLOSEMENU() METHOD DISPLAYS THE CLOSING OF ACCOUNT OF THE CUSTOMER IN THE APPLICATION
void menus::closemenu(void)
{
char choice;
while(1)
{
clrscr();
cout<<" -Close Menu-\n";
cout<<" ************************\n";
cout<<" 1: Close/Delete AN Account\n";
cout<<" 0: Exit From This Menu\n\n";
cout<<" Select A Choice:";
choice=getche();
if(choice=='1')
{
accounttransactions at;
at.closeaccount();
break;
}
else
if(choice=='0')
{
cout<<"\n You Have Entered 0 To Go To The Previous Menu.\n";
getch();
break;
}
}
}
//LASTACCOUNT() METHOD RETURNS LAST ACCOUNT NO. FROM THE NEWRECORDS.DAT FILE
int disprecords::lastaccount(void)
{
fstream filename;
filename.open("newrecords.dat",ios::in);
filename.seekg(0,ios::beg);
int count=0;
while(filename.read((char*)this,sizeof(disprecords)))
count=accountnumber;
filename.close();
return count;
}
//GETRECORD() METHOD RETURNS THE RECORD NUMBER FROM THE NEWRECORDS.DAT FILE WHEN A BANKING STAFF ENTERS ACCOUNT NO.
int disprecords::getrecord(int retrieve_accno)
{
fstream filename;
filename.open("newrecords.dat",ios::in);
filename.seekg(0,ios::beg);
int count=0;
while(filename.read((char*) this,sizeof(disprecords)))
{
count++;
if(retrieve_accno==accountnumber)
break;
//KEEP ON COUNTING THE RECORD STILL THE ACCOUNY NUMBER IS FOUND AND EXIY FROM THE NEWRECORDS.DAT FILE
}
filename.close();
return count;
}
//DISPLAY METHOD DISPLAYS ALL THE DETAILS OF THE ACCOUNT NUMBER FROM THE NEWRECORDS.DAT FILE
void disprecords::display(int retrieve_accno)
{
int record;
record=getrecord(retrieve_accno);
fstream filename;
filename.open("newrecords.dat",ios::in);
filename.seekg(0,ios::end);
int location;
location=(record)*sizeof(disprecords);
filename.seekp(location);
while(filename.read((char*) this,sizeof(disprecords)))
{
if(retrieve_accno==accountnumber)
{
cout<<"\n ACCOUNT NO. :"<<accountnumber;
cout<<"\n NAME :"<<name;
cout<<"\n ADDRESS :"<<address;
cout<<"\n BALANCE :"<<intbalance;
break;
}
}
filename.close();
}
//GETNAME() METHOD RETURNS THE ACCOUNT HOLDER'S NAME FROM THE NEWRECORDS.DAT FILE
char *disprecords::getname(int retrieve_accno)
{
fstream filename;
filename.open("newrecords.dat",ios::in);
filename.seekg(0,ios::beg);
char retrieve_custname[30];
while(filename.read((char *) this,sizeof(disprecords)))
{
if(accountnumber==retrieve_accno)
{
strcpy(retrieve_custname,name);
}
}
filename.close();
return retrieve_custname;
}
//GETADDRESS()METHOD RETURNS THE ADDRESS OF THE ACCOUNT HOLDER FROM THE NEWRECORDS.DAT FILE
char *disprecords::getaddress(int retrieve_accno)
{
fstream filename;
filename.open("newrecords.dat",ios::in);
filename.seekg(0,ios::beg);
char retrieve_address[60];
while(filename.read((char*)this,sizeof(disprecords)))
{
if(accountnumber == retrieve_accno)
{
strcpy(retrieve_address,address);
}
}
filename.close();
return retrieve_address;
}
/*GETBALANCE() METHOD RETURNS THE BALANCE OF THE ACCOUNT HOLDER FROM THE
NEWRECORDS.DAT FILE*/
float disprecords::getbalance(int retrieve_accno)
{
fstream filename;
filename.open("newrecords.dat",ios::in);
filename.seekg(0,ios::beg);
float ibalance;
while(filename.read((char*)this,sizeof(disprecords)))
{
if(accountnumber==retrieve_accno)
{
ibalance=intbalance;
}
}
filename.close();
return ibalance;
}
// accountexists()method checks if the account exists in the newrecords.dat file or not.
int disprecords::accountexists(int retrieve_accno)
{
fstream filename;
filename.open("newrecords.dat",ios::in);
filename.seekg(0,ios::beg);
int count=0;
while(filename.read((char*)this,sizeof(disprecords)))
{
if(accountnumber==retrieve_accno)
{
count=1;
break;
}
}
filename.close();
return count;
}
/*displaylist()mathod displays the output of all the accounts in a proper
format for the choice 3*/
void disprecords::displaylist()
{
cout<<"\t\n";
int day1,month1,year1;
struct date dateval;
getdate(&dateval);
day1 =dateval.da_day;
month1=dateval.da_mon;
year1=dateval.da_year;
cout<<"\n date:"<<day1<<"/"<<month1<<"/"<<year1<<"\n";
cout<<setw(80)<<"___________________________________\n";
cout<<setw(23)<<"ACCOUNT NO.";
cout<<setw(23)<<"NAME OF PERSON";
cout<<setw(23)<<"BALANCE\n";
cout<<setw(80)<<"___________________________________\n";
}
//displaycustomer()mathod displays all the account holders/customers from the newrecords.dat file
void disprecords::displaycustomers(void)
{
clrscr();
int len1;
int row=8,check;
fstream filename;
FILE*pfile;
pfile=fopen("newrecords.dat","r");
if(pfile=='\0') //chance-----------------of---------------------error
{
cout<<"\n NO ACCOUT EXISTS. PLEASE GO BACK TO THE PREVIOUS MENU. \n";
getch();
return;
//fclose(pfile);
}
else
{
displaylist();
filename.open("newrecords.dat",ios::in);
filename.seekg(0,ios::beg);
while(filename.read((char*)this,sizeof(disprecords)))
{
check=0;
cout.fill(' ');
cout<<setw(20);
cout.setf(ios::right,ios::adjustfield);
cout<<accountnumber;
cout.fill(' ');
cout<<setw(25);
cout.setf(ios::internal,ios::adjustfield);
cout<<name;
cout<<setw(23);
cout.setf(ios::right,ios::adjustfield);
cout<<intbalance<<"\n";
row++;
if(row==23)
{
check=1;
row=8;
cout<<"\n\n CONTINUE THE APPLICATION...\n";
getch();
clrscr();
displaylist();
}
}
}
filename.close();
if(!check)
{
cout<<"\n\n CONTINUE THE APPLICATION...\n";
getch();
}
}
//adddetails() method adds new records of account holders/customers in sthe newrecords.datfile
void disprecords::adddetails(int retrieve_accno,char
retrieve_custname[30],char retrieve_address[60],float ibalance)
{
accountnumber=retrieve_accno;
strcpy(name,retrieve_custname);
strcpy(address,retrieve_address);
intbalance=ibalance;
fstream filename;
filename.open("newrecords.dat",ios::out | ios::app);
filename.write((char*)this,sizeof(disprecords));
filename.close();
}
//deleteaccount()metod deletes rhe particular record from the newrecors.dat file on the basis of the account number.
void disprecords::deleteaccount(int retrieve_accno)
{
fstream filename;
filename.open("newrecords.dat",ios::in);
fstream temp;
temp.open("calcutions.txt",ios::out);
filename.seekg(0,ios::beg);
while(!filename.eof())
{
filename.read((char*)this,sizeof(disprecords));
if(filename.eof())
break;
if(accountnumber!=retrieve_accno)
temp.write((char*)this,sizeof(disprecords));
}
filename.close();
temp.close();
filename.open("newrecords.dat",ios::out);
temp.open("calcutions.txt",ios::in);
temp.seekg(0,ios::beg);
while(!temp.eof())
{
temp.read((char*)this,sizeof(disprecords));
if(temp.eof())
break;
filename.write((char*)this,sizeof(disprecords));
}
filename.close();
temp.close();
}
//updatebalance() method updates the balance of the account number after a transaction is done in the newrecords.dat file
void disprecords::updatebalance(int retrieve_accno,float ibalance)
{
int record;
record=getrecord(retrieve_accno);
fstream filename;
filename.open("newrecords.dat",ios::out|ios::ate);
intbalance=ibalance;
int location;
location=(record-1)*sizeof(disprecords);
filename.seekp(location);
filename.write((char*)this,sizeof(disprecords));
filename.close();
}
//adddetails()methods adds the details of a transaction in the transactions.dat file
void accounttransactions::adddetails(int retrieve_accno,int day1,int
month1,int year1,char t_tran,char typetransaction[10],float
interest_accrued,float t_amount,float ibalance)
{
fstream filename;
filename.open("transactions.dat",ios::app);
accountnumber = retrieve_accno;
dday=day1;
mmonth=month1;
yyear=year1;
transactions=t_tran;
strcpy(trantype,typetransaction);
intinterest=interest_accrued;
intamount=t_amount;
intbalance=ibalance;
filename.write((char*)this,sizeof(accounttransactions));
filename.close();
}
//deleteaccount() method deletes the record of a transactions.datfile
void accounttransactions::deleteaccount(int retrieve_accno)
{
fstream filename;
filename.open("transactions.dat",ios::in);
fstream temp;
temp.open("calculations.txt",ios::out);
filename.seekg(0,ios::beg);
while(!filename.eof())
{
filename.read((char*)this,sizeof(accounttransactions));
if(filename.eof())
break;
if(accountnumber!=retrieve_accno)
temp.write((char*)this,sizeof(accounttransactions));
}
filename.close();
temp.close();
filename.open("transactions.dat",ios::out);
temp.open("calculations.txt",ios::in);
temp.seekg(0,ios::beg);
while(!temp.eof())
{
temp.read((char*)this,sizeof(accounttransactions));
if(temp.eof())
break;
filename.write((char*)this,sizeof(accounttransactions));
}
filename.close();
temp.close();
}
//new_account()method adds a newrecords file and transaction.datfiles(choice 1)
void accounttransactions::new_account(void)
{
char choice;
int i,check;
clrscr();
disprecords newrec;
cout<<"\tPLEASE PRESS 0 TO GO BACK TO THE PREVIOUS MENU.\n";
cout<<" \n";
cout<<"\t-OPEN A NEW BANK ACCOUNT- \n";
cout<<"************************************************************ \n";
int day1,month1,year1;
struct date dateval;
getdate(&dateval);
day1=dateval.da_day;
month1=dateval.da_mon;
year1=dateval.da_year;
int retrieve_accno;
retrieve_accno=newrec.lastaccount();
retrieve_accno++;
if(retrieve_accno==1)
{
newrec.adddetails(retrieve_accno,"ravi","delhi",1.1);
newrec.deleteaccount(retrieve_accno);
adddetails(retrieve_accno,1,1,1997,'d',"default value",1.1,1.1,1.1);
deleteaccount(retrieve_accno);
}
char retrieve_custname[30],tran_acc[10],retrieve_address[60];
float t_bal,ibalance;
cout<<"\tDATE:"<<day1<<"/"<<month1<<"/"<<year1<<"\n";
cout<<"\taccount no.#"<<retrieve_accno;
do{
cout<<"\n\n\tPLEASE ENTER THE NAME OF ACCOUNT OF ACOUNT HOLDER :";
check =1;
gets(retrieve_custname);
if(retrieve_custname[0]=='0')
{
cout<<"\n\tINVALID CUSTOMER NAME.";
getch();
return;
}
strupr(retrieve_custname);
if(strlen(retrieve_custname)==0||strlen(retrieve_custname)>30)
{
check=0;
cout<<"\tCUSTOMER'S NAME IS EITHER BLANK or \n\tITS LENGTH IS GREATER THAN 30 CHARACTERS.\n";
getch();
}
}
while(!check);
do
{
cout<<"\n\tPLEASE ENTER THE ACCOUNT HOLDER'S ADDRESS:";
check=1;
gets(retrieve_address);
if(retrieve_address[0]=='0')
{
cout<<"\n\t\tINVALID CUSTOMER'S ADDRESS.";
getch();
return;
}
strupr(retrieve_address);
if(strlen(retrieve_address)==0||strlen(retrieve_address)>60)
{
check=0;
cout<<"\n\tCUSTOMER'S ADDRESS IS EITHER BLANK or\n\tITS LENGTH IS GREATER THAN 60 CHARACTERS.\n\n";
getch();
}
}
while(!check);
do
{
char chr_verifyingperson[30];
cout<<"\n\tPLEASE ENTER THE NAME OF \n\tTHE VERIFYING PERSON OF THE ACCOUNT HOLDER:";
check=1;
gets(chr_verifyingperson);
if(chr_verifyingperson[0]=='0')
{
cout<<"\n\tINVALID VARIFYING PERSON NAME.";
getch();
return;
}
strupr(chr_verifyingperson);
if(strlen(chr_verifyingperson)<1||strlen(chr_verifyingperson)>30)
{
check=0;
cout<<"\n\tTHE VERIFYING PERSON'S NAME IS EITHER BLANK or\n\tITS LENGTH IS GREATER THAN 30 CHARACTERS. PLEASE TRY AGAIN.\n";
getch();
}
}
while(!check);
do
{
cout<<"\n\tPLEASE ENTER THE DEPOSIT AMOUNT WHILE OPENNING A NEW ACCOUNT:";
check=1;
gets(tran_acc);
t_bal=atof(tran_acc);
ibalance=t_bal;
if(strlen(tran_acc)<1)
{
cout<<"\n\tINVALID TRANSACTION VALUE. EXITING FROM THE CURRENT MENU.\n";
getch();
return;
}
if(ibalance < 1000)
{
check=0;
cout<<"\n\tTHE MINIMUM DEPOSIT AMOUNT SHOULD BE RS.1000.PLEASE TRY AGAIN.\n";
getch();
}
}
while(!check);
do
{
cout<<"\n\tDO YOU WANT TO SAVE THE ACCOUNT?(y/n):";
choice=getche();
choice=toupper(choice);
}
while(choice!='N' && choice!='Y');
if(choice=='N'||choice=='n')
{
cout<<"\n\tTHE CUSTOMER'S ACCOUNT IS CREATED\n.\tPLEASE CONTINUE WITH THE APPLICATION.";
getch();
return;
}
float t_amount, interest_accrued;
t_amount=ibalance;
interest_accrued=0.0;
char t_tran,typetransaction[10];
t_tran='d';
strcpy(typetransaction,"");
newrec.adddetails(retrieve_accno,retrieve_custname,retrieve_address,ibalance);
adddetails(retrieve_accno,day1,month1,year1,t_tran,typetransaction,interest_accrued,t_amount,ibalance);
cout<<"\n\n\tTHE AMOUNT IS SUCESSFULLY CREATED .\n\tPLEASE CONTINUE WITHTHE APPLICATION \n";
getch();
}
//showaccount()method formats the display of the records from the transaction.dat
//file for a particular account(choice 2).
void accounttransactions::showaccount(int retrieve_accno)
{
cout<<"\t\n";
int day1,month1,year1;
struct date dateval;
getdate(&dateval);
day1=dateval.da_day;
month1=dateval.da_mon;
year1=dateval.da_year;
cout<<"\tDATE:"<<day1<<"/"<<month1<<"/"<<year1<<"\n";
cout<<"\tACCOUNT NUMBER:"<<retrieve_accno;
disprecords newrec;
char retrieve_custname[30];
strcpy(retrieve_custname,newrec.getname(retrieve_accno));
char retrieve_address[60];
strcpy(retrieve_address,newrec.getaddress(retrieve_accno));
cout<<setw(25)<<"\n ACCOUNT HOLDER'S NAME:"<<retrieve_custname;
cout<<"\nADDRESS : "<<retrieve_address<<"\n";
cout<<setw(80)<<"\n_______________________________\n";
cout<<setw(10)<<"DATED";
cout<<setw(12)<<"DETAILS";
cout<<setw(12)<<"DEPOSITED";
cout<<setw(15)<<"WITHDRAWN";
cout<<setw(12)<<" ";
cout<<setw(10)<<"BALANCE";
cout<<setw(80)<<"\n____________________\n";
}
// diplay_account() records from transactions.dat file
void accounttransactions::display_account(void)
{
clrscr();
char t_acc[10];
int tran_acc,retrieve_accno;
disprecords obj2;
cout<<" press 0 to go back in tne previos menu \n";
cout<<" please enter the account no.you want to view:";
gets(t_acc);
tran_acc=atoi(t_acc); /* converting account number to integer value */
retrieve_accno=tran_acc;
if(retrieve_accno==0)
{
cout<<"\n youhave press 0 to exit.\n";
getch();
return;
}
clrscr();
disprecords newrec;
accounttransactions aa;
int row=8,check;
fstream filename;
FILE * pFile; //-----------chance----------------------of----------------------error----------
pFile=fopen("newrecords.dat","r");
if(pFile==NULL)
{
cout<<"\n NO SUCH ACCOUNT EXISTS.PLEASE CREATE A NEW ACCOUNT.\n";
getch();
return;
 }
 else if(!newrec.accountexists(retrieve_accno))
 {
 cout<<"\t\n ACCOUNT DOESN'T EXISTS.\n";
 getch();
 return;
 }
 else{
 showaccount(retrieve_accno);
 filename.open("transaction.dat",ios::in);
 /* reading the transaction.dat file and displaying the details of
 a particular account*/
 while(filename.read((char*)this,sizeof(accounttransactions)))
 {
 if(accountnumber==retrieve_accno)
 {
 check=0;
 cout<<setw(3)<<dday<<"/"<<mmonth<<"/"<<yyear;
 cout<<setw(10)<<trantype;
 if(transactions=='d')
 {
 cout.setf(ios::right,ios::adjustfield);
 cout<<setw(15);
 cout<<intamount;
 cout<<setw(20);
 cout<<" ";
 }
 else
 {
 cout.setf(ios::right,ios::adjustfield);
 cout<<setw(25);
 cout<<intamount;
 cout<<setw(10);
 cout<<" ";
 }
cout<<setw(15);
cout.setf(ios::right,ios::adjustfield);
cout<<intbalance<<"\n";
row++;
if(row==23)
{
check=1;
row=8;
cout<<"\n\n PLEASE CONTINUE WITH THE APPLICATION\n";
getch();
clrscr();
showaccount(retrieve_accno);
}
}
}
}
filename.close();
if(!check)
{
cout<<"\n\n PRESS ANY KEY TO CONTINUE WITH THE APPLICATION.\n";
getch();
}
}
//datdiffer() method display the difference between two dates.
int accounttransactions::datediffer(int day1,int month1,int
year1,int day2,int month2,int year2)
{
static int montharr[]={31,28,31,30,31,30,31,31,30,31,30,31};
// array of the months storing the number of day in each array.
int days=0;
while(day1 !=day2||month1 !=month2||year1 !=year2)
{
/* checking if the two dates months and year and
incrementing the number
of days.*/
days++;
day1++;
if(day1>montharr[month1-1])
{
day1=1;
month1++;
}
if(month1>12)
{
month1=1;
year1++;
}
}
return days;
}
//getinterest() function calculates interest on the balance from the transaction.dat file
float accounttransactions::getinterest(int
retrieve_accno,float ibalance)
{
fstream filename;
filename.open("transaction.dat",ios::in);
disprecords newrec;
filename.seekg(0,ios::beg);
int day1,month1,year1,month_day;
while(filename.read((char*)this,sizeof(accounttransactions)))
{
if(accountnumber==retrieve_accno)
{
day1=dday;
month1=mmonth;
year1=yyear;
ibalance=newrec.getbalance(retrieve_accno);
break;
}
 }
 int day2,month2,year2;
 struct date dateval;
getdate(&dateval);
day2=dateval.da_day;
month2=dateval.da_mon;
year2=dateval.da_year;
float interest_accrued=0.0;
int yeardiff=year2-year1;
if((year2<year1)||(year2==year1 && month2<month1)||(year2==year1 &&
month2==month1 && day2<day1))
{
return interest_accrued;
}
month_day=datediffer(day1,month1,year1,day2,month2,year2);
int months;
if(month_day>=30)
{
months=month_day/30;
}
else
{
months=month_day/30;
}
if(interest_accrued==0 && yeardiff==1)
{
interest_accrued=((ibalance*0.5)/100)*(months);
}
else if(yeardiff>1 && yeardiff< 25 && interest_accrued==0)
{
interest_accrued=((ibalance*0.5)/100)*(months);
}
else
{
interest_accrued=0;
}
filename.close();
return interest_accrued;
}
/*method for generating interest and updation of the balance and
adddetails methods.(choice 5)*/
void accounttransactions :: showinterest(void)
{
clrscr();
char t_acc[10];
int tran_acc,retrieve_accno,check;
cout<<strupr("\n IMPORTANT INFORMATION:INTEREST SHOULD BE GENERATED ONLY\n ONCE IN A YEAR.\n\n\t IF YOU HAVE ALREADY GENERATED INTEREST FOR AN ACCOUNT,\n\t PLEASE IGNORE THAT ACCOUNT.\n\t THANK YOU.\n");
cout<<"\n PRESS 0 TO GO BACK TO THE PREVIOUS MENU.\n";
cout<<"\n TO VIEW THE TRANSACTION OF THE ACCOUNT,PLEASE ENTER IT:";
gets(t_acc);
tran_acc=atoi(t_acc);
retrieve_accno=tran_acc;
if(retrieve_accno==0)
return;
clrscr();
disprecords newrec;
if(!newrec.accountexists(retrieve_accno))
{
cout<<"\t\n ACCOUNT DOESN'T EXIST.\n";
getch();
return;
}
cout<<" PRESS 0 TO GO BACK TO PREVIOUS MENU.\n";
cout<<" \n";
cout<<"\n -PLEASE ENTER THE ACCOUNT NO. TO GENERATE INTEREST- \n";
cout<<"\n************************************\n";
int day1, month1, year1;
struct date dateval;
getdate(&dateval);
day1=dateval.da_day;
month1=dateval.da_mon;
year1=dateval.da_year;
cout<<" DATE :"<<day1<<"/"<<month1<<"/"<<year1<<"\n";
cout<<" ACCOUNT NO:"<<retrieve_accno<<"\n";
char retrieve_custname[30];
char retrieve_address[60];
float ibalance;
strcpy(retrieve_custname,newrec.getname(retrieve_accno));
strcpy(retrieve_address,newrec.getaddress(retrieve_accno));
ibalance=newrec.getbalance(retrieve_accno);
cout<<" CUSTOMER NAME : "<<retrieve_custname;
cout<<"\nCUSTOMER ADDRESS: "<<retrieve_address;
cout<<"\nBANK BALANCE : "<<ibalance;
float interest_accrued;
interest_accrued=getinterest(retrieve_accno,ibalance);
 /*calculation of interest of the deposit amount*/
cout<<"\n\TINTEREST GENERATED: "<<interest_accrued;
getch();
ibalance=ibalance+interest_accrued;
disprecords obj2;
/*updating the balance once interest is generated in a year*/
obj2.updatebalance(retrieve_accno,ibalance);
/*adding interest as a deposit when it is generated in a year*/
adddetails(retrieve_accno,day1,month1,year1,'d',"interest",interest_accrued,interest_accrued,ibalance);
}
/*This method does all the deposit/withdrawal transactions in the
transaction.datfile(choice 4)*/
void accounttransactions::transaction(void)
{
clrscr();
char t_acc[10];
int tran_acc,retrieve_accno,check;
cout<<" PRESS 0 TO GO BACK TO PREVIOUS MENU.\n";
cout<<" TO VIEW THE TRANSACTION OF THE ACCOUT,PLEASE ENTER IT:";
gets(t_acc);
tran_acc=atoi(t_acc);
retrieve_accno=tran_acc;
if(retrieve_accno==0)
 return;
clrscr();
disprecords newrec;
if(!newrec.accountexists(retrieve_accno))
{
cout<<"\t\n ACCOUNT DOESN'T EXIST.\n";
getch();
return;
}
cout<<" PRESS 0 TO GO BACK TO PREVIOUS MENU.\n";
cout<<" \n";
cout<<"\n -MAKE CORRECT ENTERY FOR THE TRANSACTION BELOW- \n";
cout<<"*************************************************\n";
int day1,month1,year1;
struct date dateval;
getdate(&dateval);
day1=dateval.da_day;
month1=dateval.da_mon;
year1=dateval.da_year;
month1=dateval.da_mon;
year1=dateval.da_year;
cout<<" DATE :"<<day1<<"/"<<month1<<"/"<<year1<<"\n";
cout<<" ACCOUNT NO. "<<retrieve_accno<<"\n";
char retrieve_custname[30];
char retrieve_address[60];
float ibalance;
float interest_accrued=0.0;
strcpy(retrieve_custname,newrec.getname(retrieve_accno));
strcpy(retrieve_address,newrec.getaddress(retrieve_accno));
ibalance=newrec.getbalance(retrieve_accno);
cout<<" CUSTOMER NAME :"<<retrieve_custname;
cout<<"\n CUSTOMER ADDRESS:"<<retrieve_address;
cout<<"\n BANK BALANCE :"<<ibalance;
char trandetails,typetransaction[10],tm[10];
float t_amount,t_amt;
do
{
cout<<"\n PLEASE ENTER d FOR DEPOSIT or w FOR WITHDRAWL OF AMOUNT:";
trandetails=getche();
if(trandetails=='0')
{
cout<<"\n\n YOU HAVE PRESSED 0 TO EXIT.";
getch();
return;
}
trandetails=toupper(trandetails);
}
while(trandetails!='W'&&trandetails!='D');
do
{
cout<<"\n THE TRANSACTION TYPE IS EITHER CASH OR CHEQUE.\n";
check=1;
cout<<" (cash/cheque):";
gets(typetransaction);
strupr(typetransaction);
if(typetransaction[0]=='0')
{
cout<<"\n\n YOU HAVE PRESSED 0 TO EXIT.";
 getch();
 return;
}
if(strlen(typetransaction)<1||(strcmp(typetransaction,"CASH")&&strcmp(typetransaction,"CHEQUE")) )
{
check=0;
cout<<"\n THE TRANSACTION IS INVALID.\NPLEASE ENTER EITHER CASH OR CHEQUE. \n";
getch();
}
}
while(!check);
if(trandetails=='D')
{
do
{
cout<<"\n please enter the transaction amount: \n";
check=1;
cout<<" amount : Rs.";
gets(tm);
t_amt=atof(tm);
t_amount=t_amt;
if(t_amount<1||(trandetails=='W'&&t_amount>ibalance))
{
check=0;
cout<<"\n either amount is not a numeric value or\n it is blank or\n you are trying to withdraw amount more than in the account.... \n";
getch();
}
}
while(!check);
}
if(trandetails=='W')
{
do
{
cout<<"\n please enter the transaction amount: \n";
check=1;
cout<<" amount : Rs.";
gets(tm);
t_amt=atof(tm);
t_amount=t_amt;
if(t_amount<1||(trandetails=='D'&&t_amount>ibalance))
{
check=0;
cout<<"\n either amount is not a numeric value or\n it is blank or\n you are trying to withdraw amount more than in the account.... \n";
getch();
}
}
while(!check);
}
char choice;
do
{
 cout<<"\n save the changes made in the transaction details?(y/n):";
 choice=getche();
 choice=toupper(choice);
}
while(choice!='N'&&choice!='Y');
if(choice=='N'||choice=='n')
{
 cout<<"\n the transaction is not saved. \n";
 getch();
 return;
}
if(trandetails=='D')
{
 cout<<"\n the amount is deposited in the bank.\n";
 getch();
 ibalance=ibalance+t_amount;
}
else
{
 cout<<"\n the amount is withdrawn from the bank.\n";
 getch();
 ibalance=ibalance-t_amount;
}
newrec.updatebalance(retrieve_accno,ibalance);
/*adding record details for the transaction done (deposit or withdrawal)
and saving it in the file*/
adddetails(retrieve_accno,day1,month1,year1,trandetails,typetransaction,interest_accrued,t_amount,ibalance);
}
/*this method deletes the account from both the dat files(choice 6)*/
void accounttransactions :: closeaccount(void)
{
 clrscr();
 char t_acc[10];
 int tran_acc,retrieve_accno;
 cout<<"\tpress 0 to go back to previous menu.\n";
 cout<<"\tplease enter the account you want to close : " ;
 gets(t_acc);
tran_acc=atoi(t_acc);
/*changing account no. to integer type.*/
retrieve_accno=tran_acc;
clrscr();
disprecords newrec;
if(!newrec.accountexists(retrieve_accno))
{
cout<<"\n\tyou have entered an invalid account or it does not exist.\n";
cout<<"\n\tplease try again.\n";
getch();
return;
}
cout<<"\n\tpress 0 to go back to previous menu\n";
cout<<"\n\tclosing this account.\n";
cout<<"*******************************\n\n";
int day1,month1,year1;
struct date dateval;
getdate(&dateval);
day1=dateval.da_day;
month1=dateval.da_mon;
year1=dateval.da_year;
cout<<"date:"<<day1<<"/"<<month1<<"/"<<year1<<"\n";
char choice;
newrec.display(retrieve_accno);
/*Displaying the account details on the basis of the retrievedaccount
number*/
do
{
cout<<"\n\tAre you sure you want to close this account? (y/n): ";
choice=getche();
choice=toupper(choice);
}
while(choice!='N'&&choice!='Y');
if(choice=='N'||choice=='n')
{
cout<<"\n\tThe account is not closed.\n";
getch();
return;
}
newrec.deleteaccount(retrieve_accno);
deleteaccount(retrieve_accno);
cout<<"\n\n\tRecord Deleted Successfully.\n";
cout<<"\tPlease Continue With the application....\n";
getch();
}
/*The login method checks for the username and the password for accessing
the banking application*/
int login(void)
{
char username[9],ch;
char username1[]="shruti";
int i=0;
char a,b[9],pass[]="gupta";
cout<<"\n\n";
cout<<"\n\t\tLOGIN TO THE MY BANK APPLICATION.\n";
cout<<"\t***********************************************\n";
cout<<"\n\n\t PLEASE ENTER USERNAME: ";
cin>>username;
cout<<"\n\n\tPLEASE ENTER THE PASSWORD TO AUTHENTICATE YOURSELF: ";
fflush(stdin);
do
{
ch=getche();
if(isalnum(ch))
{
b[i]=ch;
cout<<"\b*";
i++;
}
else if(ch=='\b')
{
i--;
}
}
while(ch!='\r');
b[i]='\0';
fflush(stdin);
if((strcmp(b,pass)==0 &&(strcmp(username1,username)==0)))
{
cout<<"\n\n\tYOU HAVE ENTERED SUCESSFULLY\n\n\t";
return(1);
}
else
{
cout<<"\n\n\tINCORRECT USERNAME OR PASSWORD.";
cout<<"\n";
return(0);
}
}
//THIS IS THE MAIN FUNCTION WHICH DISPLAYS THE MENU
void main(void)
{
clrscr();
int val,ch;
a: //LABEL
val=login();
 if(val==0)
 {
 cout<<"\n\t WANT TO TRY AGAIN?";
cout<<"\n\t 1.TRYAGAIN";
cout<<"\n\t 2.EXIT";
cout<<"\n\n\t ENTER YOUR CHOICE AND PRESS ENTER:";
cin>>ch;
if(ch==1)
{
clrscr();
goto a;
}
else
{
exit(0);
}
 }
 menus obj1;
 obj1.showmenu();
}