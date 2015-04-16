#ifndef STR_H
#define STR_H

#include <QString>
struct WordInfo
{
    QString word;
    int count;                                           //单词出现次数
    int lineNum;                                       //行
    QString fileName[1024];                   //出现的文件名
    int fileNum;                                        //出现的文件数
    QString sentenceList[1024];             //出现的句子内容
    QString sentenceNum[1024];          //出现的句子所在位置的句数
    int sentenceNo;                                 //共有多少个句子
    int searchCount;                                //被搜索的次数
};

//整数转字符串
void wordInfoInit(WordInfo w);
QString  toString(int);

bool isEndofStc(char c);
#endif // STR_H

