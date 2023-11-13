//---------------------------------------------------------------------------

#ifndef MainFormH
#define MainFormH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TGETsumN5 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TImage *Kanji;
        TProgressBar *ProgressBar1;
        TStringGrid *StringGrid1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TProgressBar *ProgressBar2;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TGETsumN5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGETsumN5 *GETsumN5;
//---------------------------------------------------------------------------
#endif

