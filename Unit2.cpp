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
// ������ ������
// ���� ��� �������� ������ ���������� �������.
ModalResult = mrOk;
}

void __fastcall TForm2::Button2Click(TObject *Sender)   //����������� ������ ������������ �� ���� ������
{
	   Form3->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender) //����� ������ ������
{
String S,S1,S2,S3,S4;
int a=0,b,c=0,d=0;
TStringList *file= new TStringList;//������ ��������� ��� ������ ������� - ������
file->LoadFromFile("ppl.txt"); // ��������� ����
for(int i=0;i<file->Count;i++)//����� ������
{
S=file->Strings[i];

S2=S;
b=S.Pos("admin")+5;            // � ������� �������� �������� ������ ��� ������
S1=S.SubString(a,b);//�� ��� �� ������ ������
S2=S.SubString(b+1,S.Length());
S3=S2.SubString(0,S2.Pos(";")-1);// ������ ������
c=b+S2.Pos(";");
S2=S.SubString(c,S.Length()); //�� ��� ����� ������ ������
if(CompareStr(Edit1->Text,S3)==0)
{
   if(CompareStr(Edit2->Text,Edit3->Text)==0 and CompareStr(Edit2->Text,"")!=0)
   {
	   S=S1+Edit2->Text+S2;
	   file->Strings[i]=S;
	   file->SaveToFile("ppl.txt");     // ���� ��� ���������, ������ �������� � ������������ � ��������� ��������
	   ShowMessage("������ ������� �������");
   }
   else if (CompareStr(Edit2->Text,"")==0)        //�������� �� ������ ������
   {
	ShowMessage("������ �� ����� ���� ������");
   }
   else                                                      //�������� �� ������������ ���������� ����� ������
   {
	   ShowMessage("��������� ������������ �������� ������ ������!");
   }
}
else                                        //�������� �� ������������ ����� ������� ������
ShowMessage("������ ������ ����� ����������");
}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
Image1->Picture->LoadFromFile("pics\\admin.jpg");
String S,S1,S2,S0,D,D1;
int a=4,b,c=0,d=0,p=3,l=0,m=0,j=0,log_count=0;
bool login=true;
TStringList *file= new TStringList;//������ ��������� ��� ������ ������� - ������
file->LoadFromFile("ppl.txt"); // ��������� ����
Memo1->Lines->Clear();
Memo1->Lines->Add("������ ������������������ �������������:");
for(int i=0;i<file->Count;i++)//����� ������
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
   Memo1->Lines->Add(S1);  // ������
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
 ShowMessage("������������ ������ �1 ��������� ������� ������ \n" "��������:\n" "5.������������ ������������ ����� �������� ������\n" "10.������������� �������� ��� ����� ������������� ������\n" "12.�������������� ����� ������ ��� ������ ����������� ������������ � �������\n" "����� ��������� ������ �.�. ��-31");
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button6Click(TObject *Sender)
{
String S,S1,S2,S3,S4,S5=Edit4->Text,S6,SS,LOGIN;
int a=0,b,c=0,d=0,j=0,pos=0;
TStringList *file= new TStringList;//������ ��������� ��� ������ ������� - ������
file->LoadFromFile("ppl.txt"); // ��������� ����
for(int i=0;i<file->Count;i++)//����� ������
{
S=file->Strings[i];
LOGIN="]"+Edit4->Text+";";
pos=S.Pos(LOGIN);
if (CompareStr("",Memo1->Lines->Strings[0])==0)     // �������� �� ������� �������������
{
  ShowMessage("������� ������� ������ �������� �������������");
}
else if (CompareStr(S5,"")==0)   //�������� ������� ����� ������������
{
  ShowMessage("������� ��� ������������");
}
else if (pos==0)             	//�������� �� ������� ������ ������������
{
 ShowMessage("������ ������������ ���");
}

else if (CompareStr(S5,"admin")==0)      //�������� �� ������
{
  ShowMessage("������ ������������� ������");
}
else             //���� ��� �������� �������� �������, �� ��� ��� ���������� �����������
{
while(j<Memo1->Lines->Count)
{
if (CompareStr(S5,Memo1->Lines->Strings[j])==0)
{
							 //� ������� �������� ������ ������� ������������
S2=S;
S6=S5;
S5="]"+S5+";";
b=S.Pos(S5)+S5.Length()-1;
S1=S.SubString(a,b);//�� ��� �� ������ �����
SS=S1.SubString(b-S5.Length()-2,4);
S1=S.SubString(a,b-5-S6.Length());
S2=S.SubString(b+1,S.Length());
S3=S2.SubString(0,S2.Pos(";")-1);// ������ �����
c=b+S2.Pos(";");
S2=S.SubString(c,S.Length()); //�� ��� ����� ������ �����
S=S1+"[55]"+S6+";"+S3+S2;      //������� � ����������
file->Strings[i]=S;
file->SaveToFile("ppl.txt");      //��������� ������ � ����
ShowMessage("������������ ������� ������������");   //����������� �� �������� ����������
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
TStringList *file= new TStringList;//������ ��������� ��� ������ ������� - ������
file->LoadFromFile("ppl.txt"); // ��������� ����
for(int i=0;i<file->Count;i++)//����� ������
{
S=file->Strings[i];
LOGIN="]"+Edit4->Text+";";
pos=S.Pos(LOGIN);
if (CompareStr("",Memo1->Lines->Strings[0])==0)
{
  ShowMessage("������� ������� ������ �������� �������������");
}
else if (CompareStr(S5,"")==0)
{
  ShowMessage("������� ��� ������������");
}
else if (pos==0)
{
 ShowMessage("������ ������������ ���");
}
else if (CompareStr(S5,"admin")==0)
{
  ShowMessage("������ �������������� ������");
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
S1=S.SubString(a,b);//�� ��� �� ������ �����
SS=S1.SubString(b-S5.Length()-2,4);
S1=S.SubString(a,b-5-S6.Length());
S2=S.SubString(b+1,S.Length());
S3=S2.SubString(0,S2.Pos(";")-1);// ������ �����
c=b+S2.Pos(";");
S2=S.SubString(c,S.Length()); //�� ��� ����� ������ �����
S=S1+"[00]"+S6+";"+S3+S2;
file->Strings[i]=S;
file->SaveToFile("ppl.txt");
ShowMessage("������������ ������� �������������");
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
TStringList *file= new TStringList;//������ ��������� ��� ������ ������� - ������
file->LoadFromFile("ppl.txt"); // ��������� ����
for(int i=0;i<file->Count;i++)//����� ������
{
S=file->Strings[i];
LOGIN="]"+Edit4->Text+";";
pos=S.Pos(LOGIN);
if (CompareStr("",Memo1->Lines->Strings[0])==0)
{
  ShowMessage("������� ������� ������ �������� �������������");
}
else if (CompareStr(S5,"")==0)
{
  ShowMessage("������� ��� ������������");
}
else if (pos==0)
{
 ShowMessage("������ ������������ ���");
}
else if (CompareStr(S5,"admin")==0)
{
  ShowMessage("������ ������� ������");
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
S1=S.SubString(a,b);//�� ��� �� ������ �����
S2=S.SubString(b+1,S.Length());
c=b+5+S2.Pos(";");
S2=S.SubString(c,S.Length()); //�� ��� ����� ������ �����
S=S1+S2;
file->Strings[i]=S;
file->SaveToFile("ppl.txt");
ShowMessage("������������ ������� �����");
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
	TStringList *file= new TStringList;//������ ��������� ��� ������ ������� - ������

	if (first_code==true)          //�������� �� ������ ������
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
	{                                                         //�������� �� ���������� �������
	  ShowMessage("It is not a magic sqaure!");
      Form2->Memo2->Lines->Clear();
	  return;
	}
	sumg0=0;       //��������� ����������
	sumv0=0;       //��������� ����������
  }

  }

	file->LoadFromFile("ppl.txt"); // ��������� ����
	for(int z=0;z<file->Count;z++)//����� ������
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
	S1=S.SubString(b0,b);  //�� �� ������
	//ShowMessage("DO PAROLYA "+S1);
	S2=S.SubString(b+1,S.Length());
	S3=S2.SubString(0,S2.Pos(";")-1);//������ �����
	//ShowMessage("ETO PAROL: "+S3);
	pass=S3;
	c=b+S2.Pos(";");
	S2=S.SubString(c,S.Length());//�� ��� ����� ������ �����
	//ShowMessage("POSLE PAROLYA "+S2);
	S7= S2.SubString(2,S2.Length());
	S6=S.SubString(S1.Length()+S3.Length()+5,S7.Pos(";")-3); // ��������� ����
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
				StringGrid1->Cells[j][i] = "-";   //���������� �� ������ ������ ������(25 ��������)

			 }
			 else
			 {
				StringGrid1->Cells[j][i] = letter; //������ ������ ���������������� ������ ������������� ������ ����������� ��������
			 }

		  }

		}
	  }
  }
   for (int i = 0; i < 5; i++)
	  {
		for (int j = 0; j < 5; j++)
		{
			 coded_pass=coded_pass+	StringGrid1->Cells[j][i]; //������������� ������
		}
	  }
	   S=S1+coded_pass+S2;  // ������ �������������� ������ � ������ ����� ����� ������������
	   file->Strings[z]=S;
	   file->SaveToFile("ppl.txt");     //���������� � ����

	   Memo2->Lines->SaveToFile("code.txt");    //���������� ����������� ��������(������������������ �����)

	   coded_pass="";
	   ar=ar-1;       //���������  ������������
	   }
	}
	ShowMessage("������ ������� �����������");   //���� �������� ������ �������
  }
  else
	ShowMessage("������� ����������� ������");   //���� ������ ������������
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
  TStringList *file= new TStringList;//������ ��������� ��� ������ ������� - ������
   Form2->Memo2->Lines->LoadFromFile("code.txt");
   if(CompareStr("",Form2->Memo2->Lines->Strings[1])!=0)
   {
	file->LoadFromFile("ppl.txt"); // ��������� ����
	for(int z=0;z<file->Count;z++)//����� ������
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
	S1=S.SubString(b0,b);  //�� �� ������

	S2=S.SubString(b+1,S.Length());
	S3=S2.SubString(0,S2.Pos(";")-1);//������ �����

	pass=S3;
	c=b+S2.Pos(";");
	S2=S.SubString(c,S.Length());//�� ��� ����� ������ �����

	S7= S2.SubString(2,S2.Length());
	S6=S.SubString(S1.Length()+S3.Length()+5,S7.Pos(";")-3); // ��������� ����


	int op=26;
	int counter=1;
	while (op>0) //������ ��� 25 �������� ������
	{
      a=1;
	int cifr=0;
  for (int i=0; i < 5; i++)
  {
	for (int j=0; j < 5; j++)
	{
	  letter=pass.SubString(a,1); //��������� ������ �������������� ������
	  a=a+1;
	  StringGrid3->Cells[j][i]=  Form2->Memo2->Lines->Strings[cifr+1];
	  cifr++;
	  if(counter==StrToInt(StringGrid3->Cells[j][i])) //������������� ������ ������� ������ � ������ � ������ ��� ��������
	  {                                           // ����� ������ ��������������� (������ ������ ������ ����� � ������ � ������� 1)
			if(CompareStr(letter,"-")!=0)
			{
			  uncoded_pass=uncoded_pass+letter;   //�������������� ������
			  counter++;
			}


	  }

	}
  }
  op=op-1; //��������� ������ �������������� ������
  }
	S=S1+uncoded_pass+S2;  //������� ������ � ������ ����� � ������
	file->Strings[z]=S;
	file->SaveToFile("ppl.txt");   //���������� ��������������� ������
	uncoded_pass="";
	ar=ar-1;       //  ��������� ������������
	}
	}
	Form2->Memo2->Lines->Clear(); // ������ ����������� ����� ��� ��������
	Memo2->Lines->SaveToFile("code.txt");//code ������
	ShowMessage("������ ������� ������������");  //���� �������� ������ �������
   }
   else
   ShowMessage("� ��� ������ �� ������������");   //���� ������ �� ���� ������������
}


