//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit4.h"
#include "dstring.h"
#include "string.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
 // ���������
   Timer1->Enabled = false;
   Timer1->Interval = 1000;

}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
String S,S1,S2,S0,D,D1,SS,uncoded_pass,letter;
int a=4,b,c=0,d=0,p=3,l=0,m=0,j=0,log_count=0,oops=0;
bool login=true;
TStringList *file= new TStringList;//������ ��������� ��� ������ ������� - ������
file->LoadFromFile("ppl.txt"); // ��������� ����
if(Timer1->Enabled==true and Form2->CheckBox3->Checked==1)
{
ShowMessage("��� ������!");
}
else
{
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
  oops=j;

  S1=S2.SubString(5,b-4);                           // login
  SS=S2.SubString(0,4);                             // ��������� ������������ (������������ ��� ���)
  Memo1->Lines->Clear();
  Memo1->Lines->Add(SS);
  //ShowMessage(SS);
  if (CompareStr(SS,"[55]")==0 and CompareStr(S1,Edit1->Text)==0)
  {

	  ShowMessage("�� ������������� :(");
	  break;
  }
  else
  {
	   if ((CompareStr(Edit1->Text,"")==0) or (CompareStr(Edit1->Text,"�����")==0))
  {
   ShowMessage("������� �����!");
   j=m+5;
  }
  if (login==true)
  {
   //ShowMessage("LOGIN: "+ S1);  // ������

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

  if ((CompareStr(S1,Edit1->Text)==0))
  {
	if ((CompareStr(S1,"admin")==0))   // �������� �� ������ ���� ����� ����� �� d = 1.
	{
	 d=1;
	}
	else
	{
	  d=0;
	}
	//ShowMessage("��� �����: "+S1);
	String S3=S1;//�������� ������ � ������ �����

	a=b;
	if(c==0)
	{
		S2=S2.SubString(a+2,S.Length());
	}
  else
	 {
		S2=S2.SubString(a+2,S.Length());
	 }
  if (c==0)
  {
  b=S2.Pos(";")-1;
  c=1;
  }
  else
  {
	b=S2.Pos(";")-1;
  }
  if (c==0)
	{
	S1=S2.SubString(0,b);
	}
  else
  {
   S1=S2.SubString(0,b);
  }
  //ShowMessage("PASSWORD: " + Edit2->Text);
  if (CompareStr("������$�4",Edit2->Text)==0 or CompareStr("",Edit2->Text)==0 )
  {
	ShowMessage("������� ������!");
  }
  else
  {

  Form2->Memo2->Lines->Clear();
  Form2->Memo2->Lines->LoadFromFile("code.txt");
  if (CompareStr("",Form2->Memo2->Lines->Strings[0])!=0)
  {
  int ar=26;
  int counter=1;
   //ShowMessage(S1);
   while (ar>0) //���� ���� ������� ��� 25 �������� ������
{
	int abc=1;

	int cifr=0;

  for (int i=0; i < 5; i++)
  {
	for (int j=0; j < 5; j++)
	{
	  letter=S1.SubString(abc,1); //��������� ������ ������
	  abc=abc+1;
	  Form2->StringGrid3->Cells[j][i]= Form2->Memo2->Lines->Strings[cifr+1];
	  cifr++; //��������� ����� ������ ��� ��������
	  if(counter==StrToInt(Form2->StringGrid3->Cells[j][i])) //������������� ������ ������� ������ � ������ � ������ ��� ��������
	  {                                           // ����� ������ ��������������� (������ ������ ������ ����� � ������ � ������� 1)
			if(CompareStr(letter,"-")!=0)
			{
			  uncoded_pass=uncoded_pass+letter;   //�������������� ������
			  counter++;     //��������� ������ ������
			}

	  }

	}
  }
  ar=ar-1;   //��������� ������ ������
}

  }
  else
  uncoded_pass=S1;  // ������
  //ShowMessage(uncoded_pass);


  if ((CompareStr(uncoded_pass,Edit2->Text)==0))
  {
	 //ShowMessage("���!! ��� ������: "+S1);
	 attempts=3;   // ���������� ������� ����� �� ������� ����� �������� ������ (�� ���������)
	 if(d==1) // �������� �� ������, ���� ����� ����� �� d ����� ����� 1.
	 {

	 d=0;
	  Form2->ShowModal();             // ������� �� ���� ��������������
	 }
	 else
	 {
	   Form4->ShowModal();            // ������� �� ���� ������������
	 }
	  d=0;          // ��� �������� �� ������


	   break;
  }
  else
  {
   attempts=attempts-1; //���������� �������, ��� ������������ ����� ������
   oops=0;
   ShowMessage("�� ��������� ����� ������.� ��� �������� "+IntToStr(attempts)+" �������");   // ����������� ���������� �������
   Timer1->Enabled=true;    // ������ �������
  int hours= StrToInt(Time().FormatString("hh"));    // ����� �������
  int  minuts= StrToInt(Time().FormatString("mm"));
  int sec=StrToInt( Time().FormatString("ss"));
  if (Form2->CheckBox3->Checked==1)
  {
   Label1 -> Caption ="�������� �����: "+Form2->Edit5->Text+ " ������";   //����������� �������
  }

   if (attempts==0)
   {
	ShowMessage("�� ������������ ��� �������, ��������� �����������");
	Form1->Close();                                                       //�������� ��������� ��� ���������� �������
   }
  }
  }
  }
  else
  {
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
if (oops==m)
{
	ShowMessage("������ ������ ���!");
}
}
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{

	if ( sec >= 1 ) {
				sec--;
		} else if ( sec <= 0 ) {
				sec = 59;
				sec--;
				if ( minuts >= 1 ) {
						minuts--;
				} else if ( minuts <= 0 ) {
						minuts = 59;
						if ( hours >= 1 ) {
								hours--;
						} else if ( hours <= 0 ) {
								hours = 0;
								minuts = 0;
								sec = StrToInt(Form2->Edit5->Text)-1;
						}
				}
		}
		if (Form2->CheckBox3->Checked==1)
		{
		  Label1 -> Caption ="�������� �����: "+ IntToStr( sec  ) + " ������";
		}

		if (sec==0)
		{
		 Label1 -> Caption ="";
		 Timer1->Enabled=false;
		}

}
//---------------------------------------------------------------------------

