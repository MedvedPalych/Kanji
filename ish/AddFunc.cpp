/**********************************
���������� � N5, made by Medved, 2018
***********************************/
#include "AddFunc.h"
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MainForm.h"


namespace KANJI {
  FILE *fkanji;
  int Rotation[total], n, yes, no;
  int wr_button[3], cor_button;
  char stroka[50], answer[50], niceCapt[50];
  char kanji[total][50];

//****************************/ ����� �� ���� ���������� � �������
  bool Repeat(int a, int b[total]) {
    for (int j=0; j<total; j++)
      if (b[j]==a)
        return true;
      return false;
}

void KRASIVO(char* nekrasivo) {        // �������� ������ ����������
  char s[50];                          // strtok �������� ������� ������
  StrCopy(s,nekrasivo);                // ������� �������� "����������", �����
  char *buf=strtok(s,"_");             // �� ��������� ��
  char *buf2=strtok(NULL,"_");         // �� ������ �������� �������� ������
  sprintf(niceCapt,"%s / %s",buf,buf2); // � ����� "�� / ���"
}

//****************************/ ������������� �������
void ShufflePics() {         // ��� ��������
  randomize();
  int Prev[total];
// ������������� �������
  for (int i=0; i<total; i++) {
    Rotation[i]=random(total);
    for (int k=0;;k++)
      if (!Repeat(Rotation[i], Prev))
        break;
      else Rotation[i]=random(total);
    Prev[i]=Rotation[i];
  }
}

//***************************/ ������ "�����"=���������� �������� �������
void NextPic() {
  char s[50],prog[20];
  n++;                                         // ��������� ���� �������
  StrCopy(KANJI::answer,kanji[Rotation[n]]);   // ������ �����
  ShuffleButtons();                            // ������������ ������
  sprintf(prog,"(%d/%d)",n,total);
  GETsumN5->Label1->Caption=prog;              // ������� �������� �� �����
  GETsumN5->ProgressBar1->StepBy(1);
  GETsumN5->ProgressBar2->Position=5-no;
  if (n >= total || no >= 5)                   // ����� �� ��������� ��
    quit();                                    // ������� ��� �� �����
//  GETsumN5->Label1->Caption=kanji[Rotation[n]]; // ��� ��� �������
//  sprintf(s,"pics\\\\%s.bmp",kanji[Rotation[n]]);// ����� � ������ ���� �����
//  GETsumN5->Kanji->Picture->LoadFromFile(s);   // ��������� � ����� ���� ����
  sprintf(s,"kanji%d",Rotation[n]);// ����� � ������ ���� �����
  GETsumN5->Kanji->Picture->Bitmap->LoadFromResourceName((int)HInstance,s);
}


//***************************/ ���������� ����� ������ (����) � �������
void GetAnswer(int button){
//  (StrComp(answer,KANJI::answer)==0)?(yes++):(no++);
  (button-1==cor_button)?(yes++):(no++);
}

//***************************/ ��������� ���� � ��������� ������
void ChtenieF() {
  int n=0;

  if ((fkanji=fopen("KANJIS.scr","r"))==NULL) {
    MessageBox(0,"���� \"KANJIS.scr\" �� ������!","������",MB_OK|MB_ICONERROR);
    exit(0);
  }

  while (!feof(fkanji)) {
    fgets(stroka,51,fkanji);
    sscanf(stroka,"%s\n", &kanji[n]);// kanji[n][��� �������� � �������]
    n++;
  } // ������ while
  fclose(fkanji);
}

//****************************/ �������������� ������
void ShuffleButtons() {
  randomize();
  int Prev[3];
     cor_button=random(4); // ������, ����� ������ � �������
// �������� ������ ������������ ������, ����� ����� ��� �� ���� �������� � ������
// ������ ����� �� �������������� � ������������ � ��������� �������, ����� ��
// ������� ��������, �� ��� ����
  for (int i=0; i<3; i++) {
   wr_button[i]=random(total);
    for (int k=0;;k++)
      if (!Repeat(wr_button[i], Prev) && StrComp(kanji[wr_button[i]],KANJI::answer))
        break;
      else wr_button[i]=random(total);
    Prev[i]=wr_button[i];
  } // ��������� � �������� ���������� � ������������ ������
// ��������� "����������" ������, � ���� �����. ������ ���������� �����
  switch (cor_button) {
    case 0: KRASIVO(KANJI::answer);      GETsumN5->Button1->Caption=niceCapt;
            KRASIVO(kanji[wr_button[0]]);GETsumN5->Button2->Caption=niceCapt;
            KRASIVO(kanji[wr_button[1]]);GETsumN5->Button3->Caption=niceCapt;
            KRASIVO(kanji[wr_button[2]]);GETsumN5->Button4->Caption=niceCapt;
    break;
    case 1: KRASIVO(kanji[wr_button[0]]);GETsumN5->Button1->Caption=niceCapt;
            KRASIVO(KANJI::answer);      GETsumN5->Button2->Caption=niceCapt;
            KRASIVO(kanji[wr_button[1]]);GETsumN5->Button3->Caption=niceCapt;
            KRASIVO(kanji[wr_button[2]]);GETsumN5->Button4->Caption=niceCapt;
    break;
    case 2: KRASIVO(kanji[wr_button[0]]);GETsumN5->Button1->Caption=niceCapt;
            KRASIVO(kanji[wr_button[1]]);GETsumN5->Button2->Caption=niceCapt;
            KRASIVO(KANJI::answer);      GETsumN5->Button3->Caption=niceCapt;
            KRASIVO(kanji[wr_button[2]]);GETsumN5->Button4->Caption=niceCapt;
    break;
    case 3: KRASIVO(kanji[wr_button[0]]);GETsumN5->Button1->Caption=niceCapt;
            KRASIVO(kanji[wr_button[1]]);GETsumN5->Button2->Caption=niceCapt;
            KRASIVO(kanji[wr_button[2]]);GETsumN5->Button3->Caption=niceCapt;
            KRASIVO(KANJI::answer);      GETsumN5->Button4->Caption=niceCapt;
    break;
    default: break;
  } // switch
} // ShuffleButtons

//****************************/ ������� �� ����������
void quit() {
  char s[100];
  if (no < 5) {
    GETsumN5->Enabled=false;
    sprintf(s,"�� ��������� ��� �������� � ����� �� �����!\n������: %d", no);
    MessageBox(0,s,"����������!",MB_OK);
    exit(0);
  } else {
    GETsumN5->Enabled=false;
    sprintf(s,"�� �������� ���� ��� � �� ���������� � ��������. �����.");
    MessageBox(0,s,"Try harder, scrub",MB_OK);
    exit(0);
  }
} // quit
} // namespace


