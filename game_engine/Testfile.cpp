//
//  Testfile.cpp
//  game_engine
//
//  Created by 霍志权 on 2018/6/4.
//  Copyright © 2018年 霍志权. All rights reserved.
//

#include "Testfile.hpp"

// 从file读data
unsigned char* readDatafromFile(char *fn)
{
    FILE *fp;
    unsigned char *content = NULL;
    long count = 0;
    if (fn != NULL)
    {
        fp = fopen(fn, "rb");
        if (fp != NULL)
        {
            fseek(fp, 0, SEEK_END);
            count = ftell(fp);
            rewind(fp); // 将文件内部的位置指针重新指向一个流（数据流/文件）的开头
            if (count > 0)
            {
                content = (unsigned char *)malloc(sizeof(unsigned char) * (count+1));
                count = fread(content, sizeof(unsigned char), count, fp);
                content[count] = '\0';
            }
            fclose(fp);
        }
    }
    return content;
}

// 读入字符流
char *textFileRead(const char *fn)
{
    FILE *fp;
    char *content = NULL;
    long count = 0;
    fp = fopen(fn, "rt");
    if (fn != NULL)
    {
        fseek(fp, 0, SEEK_END);
        count = ftell(fp);
        rewind(fp);
        if (count > 0)
        {
            content = (char *)malloc(sizeof(char)*(count+1));  // malloc 向系统申请分配指定size个字节的内存空间
            count = fread(content, sizeof(char), count, fp);
            content[count] = '\0';
        }
        fclose(fp);
    }
    return content;
}

// 写入
int textFileWrite(char *fn, char *s)
{
    FILE *fp;
    int status = 0;
    if (fn != NULL)
    {
        fp = fopen(fn, "W");
        if (fp != NULL)
        {
            if (fwrite(s, sizeof(char), strlen(s), fp) == strlen(s))
            {
                status = 1;
            }
            fclose(fp);
        }
    }
    return status;
}
