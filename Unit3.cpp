//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "dstring.h"
#include "string.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
// РЕГИСТРАЦИЯ
ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
String S,S1;
int pos1=0,pos2=0,pos3=0,pos0=0,pos4=0,pos5=0,pos6=0;
TStringList *file= new TStringList;//массив элементов где каждый элемент - строка
file->LoadFromFile("ppl.txt"); // Загружаем файл
 for(int i=0;i<file->Count;i++)//берем строку
{
S=file->Strings[i];
S1="]"+Edit1->Text+";";
pos0=S.Pos(S1);
if (pos0==0)
{
  pos1=Edit2->Text.Pos(";");

pos2=Edit2->Text.Pos("[");

pos3=Edit2->Text.Pos("]");
pos4=Edit1->Text.Pos(";");
pos5=Edit1->Text.Pos("]");
pos6=Edit1->Text.Pos("[");
if (CompareStr(Edit1->Text,"")==0)              //проверка на пустой логин
{
ShowMessage("Логин не может быть пустым");
}
else if (CompareStr(Edit1->Text,"admin")==0)      //проверка на создание 2 адимнимтратора
{
	ShowMessage("Логин не может быть admin");
}
else if (pos4!=0 or pos5!=0 or pos6!=0)          //проверка на спецсимволы в логине
{
   ShowMessage("В вашем логине присутствуют недопустимые символы такие как ';', '[', ']'.");
}
else
{
  if (CompareStr(Edit2->Text,"")==0)         //проверка на пустой пароль
 {
 ShowMessage("Пароль не может быть пустым");

}
else
{
  if(pos1==0 and pos2==0 and pos3==0)
{
if(CompareStr(Edit2->Text,Edit3->Text)==0)    // если всё верно, то запись нового пользователя в текстовый документ
{
 S=S+"[00]"+Edit1->Text+";"+Edit2->Text+";";
 file->Strings[i]=S;
 file->SaveToFile("ppl.txt");
 ModalResult = mrCancel;
}
else                                                //проверка на совпадение паролей
	ShowMessage("Пароли должны совападать");
}
else                                                //проверка на спецсимволы в пароле
{
	ShowMessage("В вашем пароле присутствуют недопустимые символы такие как ';', '[', ']'.");
}
}
}
}
else                      // проверка на повторного пользователя
{
	ShowMessage("Пользователь с таким именем уже существует");
}
}
}
