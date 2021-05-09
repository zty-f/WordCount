#include <iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void countword(char* filename) {
    int wordCount = 0;
    FILE* f;

    char buffer[1000];

    char c;

    int bufferlen;

    int isLastBlank = 0; // 上个字符是否是空格(1表示是  0表示不是)
    int i;

    if ((f = fopen(filename, "rb")) == NULL) {

        printf("文件不能打开\n");

        exit(0);

    }

    while (fgets(buffer, 1000, f) != NULL) {

        bufferlen = strlen(buffer);

        for (i = 0; i < bufferlen; i++) {

            c = buffer[i];

            if (c == ' ' || c == '\t') {

                if (isLastBlank == 0) {

                    wordCount++;

                }

                isLastBlank = 1;

            }
            else if (c != '\n' && c != '\r') {

                isLastBlank = 0;

            }



        }

        if (isLastBlank == 0)

            wordCount++;

        isLastBlank = 1;


    }

    fclose(f);
    printf("该文本文件中含有单词数：%d 个\n", wordCount);
}
void countchar(char* filename) {

    FILE* f;

    char buffer[1000];

    char c;
    int charCount = 0;
    int bufferlen;

    int isLastBlank = 0; // 上个字符是否是空格(1表示是  0表示不是)
    int i;



    if ((f = fopen(filename, "rb")) == NULL) {

        printf("文件不能打开\n");

        exit(0);

    }

    while (fgets(buffer, 1000, f) != NULL) {

        bufferlen = strlen(buffer);

        for (i = 0; i < bufferlen; i++) {

            c = buffer[i];

           if (c != '\n' && c != '\r') {

                charCount++;

                isLastBlank = 0;

            }

        }

        isLastBlank = 1;

    }

    fclose(f);

    printf("该文本文件中含有字符数：%d  个\n", charCount);

}
void main(int argc, char *argv[])
{
    FILE* f;  //定义文件指针变量
    if ((f = fopen(argv[2], "r")) == NULL)
    {
    printf("文件为空！");
    }
    else if (!strcmp(argv[1], "-w")) //不同控制参数实现不同的功能
    {
        countword(argv[2]);
    }
    else if (!strcmp(argv[1], "-c"))
    {
        countchar(argv[2]);
    }
    else {
        printf("文件路径出错或者命令输入错误！\n");
    }
}