//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include "Unit2.h"
#include "Unit3.h"
#include "Unit4.h"
#include <Vcl.ExtCtrls.hpp>
/*
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
*/

//---------------------------------------------------------------------------
class TForm1 : public TForm
{

__published:	// IDE-managed Components
	TButton *Button1;
	TEdit *Edit1;
	TEdit *Edit2;
	TTimer *Timer1;
	TLabel *Label1;
	TMemo *Memo1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	//void __fastcall Button1Click(TObject *Sender);
   //	void __fastcall Timer1Timer(TObject *Sender);

private:	// User declarations
public: int attempts=3, hours=0,minuts=0,sec=0;   // User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
