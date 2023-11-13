/**********************************
Подготовка к N5, made by Medved, 2018
***********************************/
//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "MainForm.h"
#include "AddFunc.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TGETsumN5 *GETsumN5;
using namespace KANJI;
//---------------------------------------------------------------------------
__fastcall TGETsumN5::TGETsumN5(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TGETsumN5::FormCreate(TObject *Sender) {
	char stroka[100];
	GETsumN5->Height=303;
	GETsumN5->Width=290;
	Button1->Height=40;
	Button1->Width=140;
	Button2->Height=40;
	Button2->Width=140;
	Button3->Height=40;
	Button3->Width=140;
	Button4->Height=40;
	Button4->Width=140;
	Kanji->Width=281;
	Kanji->Height=169;
	ShufflePics();
	for (int i=0;i<total;i++)
	 StringGrid1->Cells[i][0]=Rotation[i];
	ChtenieF();
	//sprintf(stroka,"You have 5 more HP (%d/%d)",n,total);
	Label1->Caption="(0/103)";//kanji[Rotation[n]];
	StringGrid1->Visible=false;
	//Label2->Visible=false;
	Label2->Caption="HP";
	Label3->Visible=false;
	StrCopy(KANJI::answer,kanji[Rotation[n]]);
	char s[50];
	//sprintf(s,"pics\\%s.bmp",kanji[Rotation[n]]);
	//Kanji->Picture->LoadFromFile(s);
	sprintf(s,"kanji%d",Rotation[n]);// пишем в строку путь файла
	GETsumN5->Kanji->Picture->Bitmap->LoadFromResourceName((int)HInstance,s);
	ShuffleButtons();
	ProgressBar2->Position=5;
}
//---------------------------------------------------------------------------
void __fastcall TGETsumN5::Button1Click(TObject *Sender)
{
	GetAnswer(1);
	NextPic();
}
//---------------------------------------------------------------------------
void __fastcall TGETsumN5::Button2Click(TObject *Sender)
{
	GetAnswer(2);
	NextPic();
}
//---------------------------------------------------------------------------
void __fastcall TGETsumN5::Button3Click(TObject *Sender)
{
	GetAnswer(3);
	NextPic();
}
//---------------------------------------------------------------------------
void __fastcall TGETsumN5::Button4Click(TObject *Sender)
{
	GetAnswer(4);
	NextPic();
}
//---------------------------------------------------------------------------


