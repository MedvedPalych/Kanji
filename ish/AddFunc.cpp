/**********************************
Подготовка к N5, made by Medved, 2018
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

//****************************/ Чтобы не было повторений в рандоме
  bool Repeat(int a, int b[total]) {
    for (int j=0; j<total; j++)
      if (b[j]==a)
        return true;
      return false;
}

void KRASIVO(char* nekrasivo) {        // названия файлов некрасивые
  char s[50];                          // strtok изменяет входную строку
  StrCopy(s,nekrasivo);                // поэтому копируем "некрасивую", чтобы
  char *buf=strtok(s,"_");             // не каверкать ее
  char *buf2=strtok(NULL,"_");         // на выходе получаем красивую строку
  sprintf(niceCapt,"%s / %s",buf,buf2); // в форме "он / кун"
}

//****************************/ Рандомизируем ротацию
void ShufflePics() {         // без повторов
  randomize();
  int Prev[total];
// предотвращаем повторы
  for (int i=0; i<total; i++) {
    Rotation[i]=random(total);
    for (int k=0;;k++)
      if (!Repeat(Rotation[i], Prev))
        break;
      else Rotation[i]=random(total);
    Prev[i]=Rotation[i];
  }
}

//***************************/ Делаем "ответ"=следующему элементу ротации
void NextPic() {
  char s[50],prog[20];
  n++;                                         // следующий член ротации
  StrCopy(KANJI::answer,kanji[Rotation[n]]);   // делаем ответ
  ShuffleButtons();                            // перемешиваем кнопки
  sprintf(prog,"(%d/%d)",n,total);
  GETsumN5->Label1->Caption=prog;              // выводим прогресс на лейбл
  GETsumN5->ProgressBar1->StepBy(1);
  GETsumN5->ProgressBar2->Position=5-no;
  if (n >= total || no >= 5)                   // выход из программы по
    quit();                                    // ошибкам или по концу
//  GETsumN5->Label1->Caption=kanji[Rotation[n]]; // это для отладки
//  sprintf(s,"pics\\\\%s.bmp",kanji[Rotation[n]]);// пишем в строку путь файла
//  GETsumN5->Kanji->Picture->LoadFromFile(s);   // открываем в ТИмаж этот файл
  sprintf(s,"kanji%d",Rotation[n]);// пишем в строку путь файла
  GETsumN5->Kanji->Picture->Bitmap->LoadFromResourceName((int)HInstance,s);
}


//***************************/ Сравниваем кепшн кнопки (вход) с ответом
void GetAnswer(int button){
//  (StrComp(answer,KANJI::answer)==0)?(yes++):(no++);
  (button-1==cor_button)?(yes++):(no++);
}

//***************************/ открываем файл и заполняем кандзи
void ChtenieF() {
  int n=0;

  if ((fkanji=fopen("KANJIS.scr","r"))==NULL) {
    MessageBox(0,"Файл \"KANJIS.scr\" не найден!","Ошибка",MB_OK|MB_ICONERROR);
    exit(0);
  }

  while (!feof(fkanji)) {
    fgets(stroka,51,fkanji);
    sscanf(stroka,"%s\n", &kanji[n]);// kanji[n][сам иероглиф в ромадзи]
    n++;
  } // скобка while
  fclose(fkanji);
}

//****************************/ Перетасовываем кнопки
void ShuffleButtons() {
  randomize();
  int Prev[3];
     cor_button=random(4); // рандом, какая кнопка с ответом
// рандомим массив неправильных кнопок, чтобы среди них не было повторов и ответа
// вообще можно всё рандомирование и неповторение в отдельную функцию, чтобы не
// плодить копипаст, но мне лень
  for (int i=0; i<3; i++) {
   wr_button[i]=random(total);
    for (int k=0;;k++)
      if (!Repeat(wr_button[i], Prev) && StrComp(kanji[wr_button[i]],KANJI::answer))
        break;
      else wr_button[i]=random(total);
    Prev[i]=wr_button[i];
  } // закончили с рандомом правильной и неправильных кнопок
// проверяем "правильную" кнопку, и даем соотв. кнопке правильный ответ
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

//****************************/ Выходим из приложения
void quit() {
  char s[100];
  if (no < 5) {
    GETsumN5->Enabled=false;
    sprintf(s,"Вы перебрали все варианты и дошли до конца!\nОшибок: %d", no);
    MessageBox(0,s,"Поздравляю!",MB_OK);
    exit(0);
  } else {
    GETsumN5->Enabled=false;
    sprintf(s,"Вы ошиблись пять раз и не справились с заданием. Позор.");
    MessageBox(0,s,"Try harder, scrub",MB_OK);
    exit(0);
  }
} // quit
} // namespace


