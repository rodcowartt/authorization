#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include <jpeg.hpp>
#include <windows.h>
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
// ПАНЕЛЬ АДМИНА
// срок мин действия пароля изменяется админом.
ModalResult = mrOk;
}

void __fastcall TForm2::Button2Click(TObject *Sender)   //Регистрация нового пользователя из меню админа
{
	   Form3->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender) //Смена пароля админа
{
String S,S1,S2,S3,S4;
int a=0,b,c=0,d=0;
TStringList *file= new TStringList;//массив элементов где каждый элемент - строка
file->LoadFromFile("ppl.txt"); // Загружаем файл
for(int i=0;i<file->Count;i++)//берем строку
{
S=file->Strings[i];

S2=S;
b=S.Pos("admin")+5;            // с помощью подстрок получаем нужные нам данные
S1=S.SubString(a,b);//Всё что до пароля админа
S2=S.SubString(b+1,S.Length());
S3=S2.SubString(0,S2.Pos(";")-1);// пароль админа
c=b+S2.Pos(";");
S2=S.SubString(c,S.Length()); //Всё что после пароля админа
if(CompareStr(Edit1->Text,S3)==0)
{
   if(CompareStr(Edit2->Text,Edit3->Text)==0 and CompareStr(Edit2->Text,"")!=0)
   {
	   S=S1+Edit2->Text+S2;
	   file->Strings[i]=S;
	   file->SaveToFile("ppl.txt");     // если все правильно, пароль меняется и записывается в текстовый документ
	   ShowMessage("Пароль успешно изменен");
   }
   else if (CompareStr(Edit2->Text,"")==0)        //проверка на пустой пароль
   {
	ShowMessage("Пароль не может быть пустым");
   }
   else                                                      //проверка на правильность повторного ввода пароля
   {
	   ShowMessage("Проверьте правильность введения нового пароля!");
   }
}
else                                        //проверка на правильность ввода старого пароля
ShowMessage("Старый пароль введён непрвильно");
}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
Image1->Picture->LoadFromFile("pics\\admin.jpg");
String S,S1,S2,S0,D,D1;
int a=4,b,c=0,d=0,p=3,l=0,m=0,j=0,log_count=0;
bool login=true;
TStringList *file= new TStringList;//массив элементов где каждый элемент - строка
file->LoadFromFile("ppl.txt"); // Загружаем файл
Memo1->Lines->Clear();
Memo1->Lines->Add("Список зарегистрированных пользователей:");
for(int i=0;i<file->Count;i++)//берем строку
{
S=file->Strings[i];
S2=S;
b=S.Pos(";")-1;
S1=S.SubString(a,b);
D=S;
D1=D;
while (CompareStr(D1,"")!=0)
	{
	  l=D1.Pos(";");
	  D1=D1.SubString(l+1,D1.Length());
	  if (l!=0)
	  {
		m++;
	  }

	}
for(j=0;j<m;j++)
  {
  if (c==0)
  {
	S1=S2.SubString(5,b-4);
  }
  else
  {
	S1=S2.SubString(5,b-4);
  }
  if (login==true)
  {
   if (S1!="admin")
   {
   Memo1->Lines->Add(S1);  // логины
   }
   login=false;
  }
  else
  {
   login=true;
  }
  if (log_count==0)
  {
	  log_count++;
	  login=true;
  }
	a=b;
	if(c==0)
	  {
		S2=S2.SubString(a+2,S.Length());
		c=1;
	  }
	  else
	{
	  S2=S2.SubString(a+1,S.Length());
	}
	b=S2.Pos(";")+1;
	S2=S2.SubString(b,S.Length());
	b=S2.Pos(";")-1;
}
}
}

//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)
{
 ShowMessage("Лабараторная работа №1 ПАРОЛЬНЫЕ СИСТЕМЫ ЗАЩИТЫ \n" "Варианты:\n" "5.Установление минимального срока действия пароля\n" "10.Использование задержки при вводе неправильного пароля\n" "12.Принудительная смена пароля при первой регистрации пользователя в системе\n" "Автор программы Белков А.И. БИ-31");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button6Click(TObject *Sender)
{
String S,S1,S2,S3,S4,S5=Edit4->Text,S6,SS,LOGIN;
int a=0,b,c=0,d=0,j=0,pos=0;
TStringList *file= new TStringList;//массив элементов где каждый элемент - строка
file->LoadFromFile("ppl.txt"); // Загружаем файл
for(int i=0;i<file->Count;i++)//берем строку
{
S=file->Strings[i];
LOGIN="]"+Edit4->Text+";";
pos=S.Pos(LOGIN);
if (CompareStr("",Memo1->Lines->Strings[0])==0)     // проверка на наличие пользователей
{
  ShowMessage("Сначала нажмите кнопку показать пользователей");
}
else if (CompareStr(S5,"")==0)   //проверка пустого имени пользователя
{
  ShowMessage("Введите имя пользователя");
}
else if (pos==0)             	//проверка на наличие такого пользователя
{
 ShowMessage("Такого пользователя нет");
}

else if (CompareStr(S5,"admin")==0)      //проверка на админа
{
  ShowMessage("Нельзя заблокировать админа");
}
else             //если все проверка пройдены успешно, то идёт код блокировки ползователя
{
while(j<Memo1->Lines->Count)
{
if (CompareStr(S5,Memo1->Lines->Strings[j])==0)
{
							 //с помощью подстрок находи нужного пользователя
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
S=S1+"[55]"+S6+";"+S3+S2;      //отметка о блокировке
file->Strings[i]=S;
file->SaveToFile("ppl.txt");      //сохраняем данные в файл
ShowMessage("Пользователь успешно заблокирован");   //уведомление об успешной блокировке
j=1+Memo1->Lines->Count;

}
else
{
 j++;
}
}
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button5Click(TObject *Sender)
{
String S,S1,S2,S3,S4,S5=Edit4->Text,S6,SS,LOGIN;
int a=0,b,c=0,d=0,j=0,pos=0;
TStringList *file= new TStringList;//массив элементов где каждый элемент - строка
file->LoadFromFile("ppl.txt"); // Загружаем файл
for(int i=0;i<file->Count;i++)//берем строку
{
S=file->Strings[i];
LOGIN="]"+Edit4->Text+";";
pos=S.Pos(LOGIN);
if (CompareStr("",Memo1->Lines->Strings[0])==0)
{
  ShowMessage("Сначала нажмите кнопку показать пользователей");
}
else if (CompareStr(S5,"")==0)
{
  ShowMessage("Введите имя пользователя");
}
else if (pos==0)
{
 ShowMessage("Такого пользователя нет");
}
else if (CompareStr(S5,"admin")==0)
{
  ShowMessage("Нельзя разблокировать админа");
}
else
{
while(j<Memo1->Lines->Count)
{
if (CompareStr(S5,Memo1->Lines->Strings[j])==0)
{

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
S=S1+"[00]"+S6+";"+S3+S2;
file->Strings[i]=S;
file->SaveToFile("ppl.txt");
ShowMessage("Пользователь успешно разблокирован");
j=1+Memo1->Lines->Count;

}
else
{
 j++;
}
}
}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button7Click(TObject *Sender)
{
 String S,S1,S2,S3,S4,S5=Edit4->Text,S6,SS,LOGIN;
int a=0,b,c=0,d=0,j=0,pos=0;
TStringList *file= new TStringList;//массив элементов где каждый элемент - строка
file->LoadFromFile("ppl.txt"); // Загружаем файл
for(int i=0;i<file->Count;i++)//берем строку
{
S=file->Strings[i];
LOGIN="]"+Edit4->Text+";";
pos=S.Pos(LOGIN);
if (CompareStr("",Memo1->Lines->Strings[0])==0)
{
  ShowMessage("Сначала нажмите кнопку показать пользователей");
}
else if (CompareStr(S5,"")==0)
{
  ShowMessage("Введите имя пользователя");
}
else if (pos==0)
{
 ShowMessage("Такого пользователя нет");
}
else if (CompareStr(S5,"admin")==0)
{
  ShowMessage("Нельзя удалить админа");
}
else
{
while(j<Memo1->Lines->Count)
{
if (CompareStr(S5,Memo1->Lines->Strings[j])==0)
{
S2=S;
S6=S5;
S5="]"+S5+";";
b=S.Pos(S5)-4;
S1=S.SubString(a,b);//Всё что до логина юзера
S2=S.SubString(b+1,S.Length());
c=b+5+S2.Pos(";");
S2=S.SubString(c,S.Length()); //Всё что после пароля юзера
S=S1+S2;
file->Strings[i]=S;
file->SaveToFile("ppl.txt");
ShowMessage("Пользователь успешно удалён");
j=1+Memo1->Lines->Count;

}
else
{
 j++;
}
}
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button9Click(TObject *Sender)
{
  int a,sumg0=0, sumg1=0, sumv0=0,sumv1=0;
  bool first=true,user1=true, first_code=true;
  String pass="password",letter,coded_pass;
  String S,S1,S2,S3,S4,S5,S6,S7,SS,code;
  if(CompareStr("",Form2->Memo2->Lines->Strings[25])==0)
  {
  Form2->Memo2->Lines->Clear();

	int b0=0 ,b,c=0,d=0,ar=Memo1->Lines->Count-1;
	Form2->Memo2->Lines->Add(ar);
	TStringList *file= new TStringList;//массив элементов где каждый элемент - строка

	if (first_code==true)          //проверка на первые строки
  {
	 first_code=false;

	for (int i=0; i < 5; i++)
  {
	for (int j=0; j < 5; j++)
	{
	  sumg0=sumg0 + StrToInt(StringGrid2->Cells[j][i]);
	  sumv0=sumv0 + StrToInt(StringGrid2->Cells[i][j]);
	  Memo2->Lines->Add(StringGrid2->Cells[j][i]);

	}
	if (first==true)
	{
	  sumg1=sumg0;
	  sumv1=sumv0;
	  first=false;
	}
	if (sumg1!=sumg0 or sumv1!=sumv0 or StrToInt(StringGrid2->Cells[0][0])==StrToInt(StringGrid2->Cells[1][1]))
	{                                                         //проверка на магический квадрат
	  ShowMessage("It is not a magic sqaure!");
      Form2->Memo2->Lines->Clear();
	  return;
	}
	sumg0=0;       //обнуление переменных
	sumv0=0;       //обнуление переменных
  }

  }

	file->LoadFromFile("ppl.txt"); // Загружаем файл
	for(int z=0;z<file->Count;z++)//берем строку
	{
	S=file->Strings[z];
		while (ar>0)
	{
	S2=S;
	if (user1==true)
	{
	 S5="]"+S.SubString(5,S.Pos(";")-5)+";";
	 user1=false;
	}
	else
	{
	  S5=S6;
	}


	b=S.Pos(S5)+S5.Length()-1;
	S1=S.SubString(b0,b);  //всё до пароля
	//ShowMessage("DO PAROLYA "+S1);
	S2=S.SubString(b+1,S.Length());
	S3=S2.SubString(0,S2.Pos(";")-1);//пароль юзера
	//ShowMessage("ETO PAROL: "+S3);
	pass=S3;
	c=b+S2.Pos(";");
	S2=S.SubString(c,S.Length());//Всё что после пароля юзера
	//ShowMessage("POSLE PAROLYA "+S2);
	S7= S2.SubString(2,S2.Length());
	S6=S.SubString(S1.Length()+S3.Length()+5,S7.Pos(";")-3); // следующий юзер
	//ShowMessage("SLED UZER"+S6);
	a=1;
  for (int i=0; i < 5; i++)
  {
	for (int j=0; j < 5; j++)
	{

	letter=pass.SubString(a,1);
	  a=a+1;
	  if (CompareStr(letter,"")==0)
	  {
		StringGrid1->Cells[j][i] = "-";
	  }
	  else
	  {
		 StringGrid1->Cells[j][i] = letter;
	  }

	}

  }

	   code="";



  a=1;

  while(a<25)
  {
	  for (int i = 0; i < 5; i++)
	  {
		for (int j = 0; j < 5; j++)
		{
		  if (StrToInt(StringGrid2->Cells[j][i])==a)
		  {
			letter=pass.SubString(a,1);
			a=a+1;
			if (CompareStr(letter,"")==0)
			 {
				StringGrid1->Cells[j][i] = "-";   //заполнение до нужной длинны пароля(25 символов)

			 }
			 else
			 {
				StringGrid1->Cells[j][i] = letter; //каждый символ незашифрованного пароля соответствует ячейке магического квадрата
			 }

		  }

		}
	  }
  }
   for (int i = 0; i < 5; i++)
	  {
		for (int j = 0; j < 5; j++)
		{
			 coded_pass=coded_pass+	StringGrid1->Cells[j][i]; //зашифрованный пароль
		}
	  }
	   S=S1+coded_pass+S2;  // вствка зашифрованного пароля в строку после имени пользователя
	   file->Strings[z]=S;
	   file->SaveToFile("ppl.txt");     //сохранение в файл

	   Memo2->Lines->SaveToFile("code.txt");    //сохранение магического квадрата(последовательность чисел)

	   coded_pass="";
	   ar=ar-1;       //следующий  пользователь
	   }
	}
	ShowMessage("Пароли успешно зашифрованы");   //если операция прошла успешно
  }
  else
	ShowMessage("Сначала расшифруйте пароли");   //если пароли зашифрованны
}

//--------------------------------------------------------------
void __fastcall TForm2::Button10Click(TObject *Sender)
{
  int a,sumg0=0, sumg1=0, sumv0=0,sumv1=0;
  bool first=true,user1=true, first_code=true;
  String pass="password",letter,uncoded_pass;
  String S,S1,S2,S3,S4,S5,S6,S7,SS,code;
  Form2->Memo2->Lines->Clear();
  int b0=0 ,b,c=0,d=0,ar=Memo1->Lines->Count-1;
  TStringList *file= new TStringList;//массив элементов где каждый элемент - строка
   Form2->Memo2->Lines->LoadFromFile("code.txt");
   if(CompareStr("",Form2->Memo2->Lines->Strings[1])!=0)
   {
	file->LoadFromFile("ppl.txt"); // Загружаем файл
	for(int z=0;z<file->Count;z++)//берем строку
	{
	S=file->Strings[z];
		while (ar>0)
	{
	S2=S;
	if (user1==true)
	{
	 S5="]"+S.SubString(5,S.Pos(";")-5)+";";
	 user1=false;
	}
	else
	{
	  S5=S6;
	}

	b=S.Pos(S5)+S5.Length()-1;
	S1=S.SubString(b0,b);  //всё до пароля

	S2=S.SubString(b+1,S.Length());
	S3=S2.SubString(0,S2.Pos(";")-1);//пароль юзера

	pass=S3;
	c=b+S2.Pos(";");
	S2=S.SubString(c,S.Length());//Всё что после пароля юзера

	S7= S2.SubString(2,S2.Length());
	S6=S.SubString(S1.Length()+S3.Length()+5,S7.Pos(";")-3); // следующий юзер


	int op=26;
	int counter=1;
	while (op>0) //пройдёт все 25 символов пароля
	{
      a=1;
	int cifr=0;
  for (int i=0; i < 5; i++)
  {
	for (int j=0; j < 5; j++)
	{
	  letter=pass.SubString(a,1); //следующий символ зашифрованного пароля
	  a=a+1;
	  StringGrid3->Cells[j][i]=  Form2->Memo2->Lines->Strings[cifr+1];
	  cifr++;
	  if(counter==StrToInt(StringGrid3->Cells[j][i])) //сопоставление номера символа пароля и номера в ячейке маг квадрата
	  {                                           // номер должен соответствовать (первый символ пароля лежит в ячейке с номером 1)
			if(CompareStr(letter,"-")!=0)
			{
			  uncoded_pass=uncoded_pass+letter;   //расшифрованный пароль
			  counter++;
			}


	  }

	}
  }
  op=op-1; //следующий символ зашифрованного пароля
  }
	S=S1+uncoded_pass+S2;  //вставка пароля в нужное место в строке
	file->Strings[z]=S;
	file->SaveToFile("ppl.txt");   //сохранение расшифрованного пароля
	uncoded_pass="";
	ar=ar-1;       //  следующий пользователь
	}
	}
	Form2->Memo2->Lines->Clear(); // убираю запомненные числа маг квадрата
	Memo2->Lines->SaveToFile("code.txt");//code пустой
	ShowMessage("Пароли успешно расшифрованы");  //если операция прошла успешно
   }
   else
   ShowMessage("У вас ничего не зашифрованно");   //если пароли не были зашифрованны
}


