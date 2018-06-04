//
//  Testfile.hpp
//  game_engine
//
//  Created by 霍志权 on 2018/6/4.
//  Copyright © 2018年 霍志权. All rights reserved.
//

#ifndef Testfile_hpp
#define Testfile_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned char* readDatafromFile(char *fn);
char *textFileRead(const char *fn);
int textFileWrite(char *fn, char *s);

#endif /* Testfile_hpp */
