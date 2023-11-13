#ifndef _AddFunc
#define _AddFunc
#endif

#define total 103

namespace KANJI {
extern int  Rotation[total], n, yes, no;
extern char kanji[total][50], answer[50];
extern int  wr_button[3], cor_button;
void ShufflePics();
void ShuffleButtons();
void NextPic();
void GetAnswer(int button);
void ChtenieF();
void quit();
}
