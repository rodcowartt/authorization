//---------------------------------------------------------------------------

#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <AppEvnts.hpp>
#include "Unit1.h"
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TButton *Button1;
	TStaticText *StaticText1;
	TStaticText *StaticText2;
	TStaticText *StaticText3;
	TButton *Button2;
	TMemo *Memo1;
	TImage *Image1;
	TTimer *Timer1;
	TButton *Button3;
	TTimer *Timer2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:	 bool first_access=false;
bool first_time=true;
		int hern=0;	// User declarations
	__fastcall TForm4(TComponent* Owner);
	 void __fastcall FWM_DEVICECHANGE(TMessage &Message);
      BEGIN_MESSAGE_MAP
        MESSAGE_HANDLER(WM_DEVICECHANGE, TMessage, FWM_DEVICECHANGE)
		END_MESSAGE_MAP(TControl)
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
