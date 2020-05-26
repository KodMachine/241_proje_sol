// 241_proje.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include "rlutil.h"
#include "Level_1.h"
#include "Run.h"

int main()
{ 
    Run r1;
    r1.play();
    rlutil::locate(1, 41);
}
