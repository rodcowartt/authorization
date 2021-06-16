//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
	: TForm(Owner)
{
ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{
String S,S1,S2,S3,S4,S5=Form1->Edit1->Text;
int a=0,b,c=0,d=0,ar;
TStringList *file= new TStringList;//массив элементов где каждый элемент - строка
file->LoadFromFile("ppl.txt"); // Загружаем файл
for(int i=0;i<file->Count;i++)//берем строку
{
S=file->Strings[i];
S2=S;
S5="]"+S5+";";
b=S.Pos(S5)+S5.Length()-1;
ar=S.Pos(S5)+1;
S1=S.SubString(a,ar-5)+"[01]"+Form1->Edit1->Text;//Всё что до пароля юзера
S2=S.SubString(b+1,S.Length());
S3=S2.SubString(0,S2.Pos(";")-1);// пароль юзера
c=b+S2.Pos(";");
S2=S.SubString(c,S.Length()); //Всё что после пароля юзера
if(CompareStr(Edit1->Text,S3)==0)
{
  if(CompareStr(Edit2->Text,Edit1->Text)==0)
  {
	   ShowMessage("Новый пароль должен отличаться от старого!");
  }
  else
  {
	   if(CompareStr(Edit2->Text,Edit3->Text)==0 and CompareStr(Edit2->Text,"")!=0)
   {
	   S=S1+";"+Edit2->Text+S2;
	   file->Strings[i]=S;
	   file->SaveToFile("ppl.txt");
	   ShowMessage("Пароль успешно изменён!");
	   Form1->Memo1->Lines->Clear();
	   Form1->Memo1->Lines->Add("[01]");
	   ModalResult = mrCancel;
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
ShowMessage("Старый пароль введён непрвильно");
}
}

void __fastcall TForm5::FormClose(TObject *Sender, TCloseAction &Action)
{
String S,S1,S2,S3,S4,S5=Form1->Edit1->Text;
int a=0,b,c=0,d=0,ar;
TStringList *file= new TStringList;//массив элементов где каждый элемент - строка
file->LoadFromFile("ppl.txt"); // Загружаем файл
for(int i=0;i<file->Count;i++)//берем строку
{
S=file->Strings[i];
S2=S;
S5="]"+S5+";";
b=S.Pos(S5)+S5.Length()-1;
ar=S.Pos(S5)+1;
 if (CompareStr(S.SubString(ar-4,4),"[00]")==0)
 {
   ShowMessage("Вы сами не поменяли пароль, пеняйте на себя");
   S1=S.SubString(a,ar-5)+"[02]"+Form1->Edit1->Text;//Всё что до пароля юзера
   S2=S.SubString(b+1,S.Length());
   S3=S2.SubString(0,S2.Pos(";")-1);// пароль юзера
   c=b+S2.Pos(";");
   S2=S.SubString(c,S.Length()); //Всё что после пароля юзера
   S=S1+";"+S3+S2;
   file->Strings[i]=S;
   file->SaveToFile("ppl.txt");
   Form1->Memo1->Lines->Clear();
   Form1->Memo1->Lines->Add("[02]");
   break;
 }
}

}
//---------------------------------------------------------------------------

