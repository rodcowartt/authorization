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
// �����������
ModalResult = mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
String S,S1;
int pos1=0,pos2=0,pos3=0,pos0=0,pos4=0,pos5=0,pos6=0;
TStringList *file= new TStringList;//������ ��������� ��� ������ ������� - ������
file->LoadFromFile("ppl.txt"); // ��������� ����
 for(int i=0;i<file->Count;i++)//����� ������
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
if (CompareStr(Edit1->Text,"")==0)              //�������� �� ������ �����
{
ShowMessage("����� �� ����� ���� ������");
}
else if (CompareStr(Edit1->Text,"admin")==0)      //�������� �� �������� 2 ��������������
{
	ShowMessage("����� �� ����� ���� admin");
}
else if (pos4!=0 or pos5!=0 or pos6!=0)          //�������� �� ����������� � ������
{
   ShowMessage("� ����� ������ ������������ ������������ ������� ����� ��� ';', '[', ']'.");
}
else
{
  if (CompareStr(Edit2->Text,"")==0)         //�������� �� ������ ������
 {
 ShowMessage("������ �� ����� ���� ������");

}
else
{
  if(pos1==0 and pos2==0 and pos3==0)
{
if(CompareStr(Edit2->Text,Edit3->Text)==0)    // ���� �� �����, �� ������ ������ ������������ � ��������� ��������
{
 S=S+"[00]"+Edit1->Text+";"+Edit2->Text+";";
 file->Strings[i]=S;
 file->SaveToFile("ppl.txt");
 ModalResult = mrCancel;
}
else                                                //�������� �� ���������� �������
	ShowMessage("������ ������ ����������");
}
else                                                //�������� �� ����������� � ������
{
	ShowMessage("� ����� ������ ������������ ������������ ������� ����� ��� ';', '[', ']'.");
}
}
}
}
else                      // �������� �� ���������� ������������
{
	ShowMessage("������������ � ����� ������ ��� ����������");
}
}
}
