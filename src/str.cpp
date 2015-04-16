/*
 * MainWindow的处埋函数实现
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "str.h"
#include <stdio.h>
#include <QMessageBox>
#include <QTextStream>
#include <qfile.h>

#define _DICT_PATH_ "/etc/wordSearch/v_dict"

//是否为标点符号,用来分词
///
/// \brief isPunctuation
/// \param s
/// \return
///
bool isPunctuation(QString s)
{   QString pattern("[a-zA-Z]+");
    QRegExp rx(pattern);
    bool match = rx.exactMatch(s);
    return !match;
}
//转成字符串
QString toString(int n)
{
    char str[10];
    sprintf(str,"%d",n);
    return str;
}

/// \brief isEndofStc 判断是不是句子的结尾
/// \param c
/// \return
///
bool isEndofStc(char c){
    if(c == '!' || c== '.' || c=='!' || c=='?')return true;
    return false;
}

void MainWindow::clearMap()
{
    wordMap.clear();
}


/// \brief MainWindow::addWord 插入一个新的单词
/// \param word
///
void MainWindow::addWord(QString word)
{   if(word == "")return ;
     QMap<QString, WordInfo>::iterator wi;
    wi=wordMap.find(word);
    if(wi == wordMap.end())
        {
        WordInfo w;
        wordInfoInit(w);
        w.count=1;
        wordMap.insert(word,w);
        //result +=word +"\n";
    }
    //如果不是虚词
    if(wi.value().count != 0)
        wi.value().count = wi.value().count +1;
}


///处理一行数据
/// \brief MainWindow::lineInsert
/// \param line 要处理的行
///
 void MainWindow::lineInsert(QString line)
  {  line = line.trimmed();
     int length=line.length();  //字符长度
    QString temp;                   //暂时保存单词
    for(int i = 0;i<length;i++){
        temp ="";                       //暂存清空
        while( i<length && !isPunctuation(""+line[i])){
               line[i] = line[i].toLower();
               temp +=line[i];      //
               i++;
        }
        addWord(temp);
    }
}

 //初始化虚词表
 /// \brief MainWindow::mapInit
 ///
 void MainWindow::mapInit()
 {      QString word;
        QFile file(_DICT_PATH_);
        if (!file.open(QIODevice::ReadOnly)) {
             QMessageBox::critical(this, tr("Error"), tr("加载虚词表失败") );
         return;
        }
         QTextStream in(&file);
        while(! in.atEnd())
         {      word = in.readLine();
                WordInfo w;
                w.count = 0;
                wordMap.insert(word, w);
         }
           file.close();
 }

 //////////////
 /// \brief MainWindow::saveMap
 ///
 void MainWindow::saveMap()
 {
     QMap<QString, WordInfo>::const_iterator i;
      int flag = 0;
       for( i=wordMap.constBegin(); i!=wordMap.constEnd(); ++i){        //遍历
           flag = i.value().count;

           //如果不是虚词
           if(flag != 0){
               result += i.key()+"\t\t"+toString(flag)+"\n";
               addToCountTop(i.key(), flag);
           }
       }
       //显示单词词频排行榜
       showCountTop();
 }
 ///
 /// \brief MainWindow::addToSearchResult
 /// \param currentSentence
 /// \param word
 ///
 void MainWindow::addToSearchResult(QString currentSentence, QString word)
 {  QString tempWord="";
     int l= currentSentence .length();  //字符长度
    for(int i = 0;i<l;i++){
        tempWord ="";                       //暂存清空
        while( i<l&& !isPunctuation(""+ currentSentence[i])){
                currentSentence[i] =  currentSentence [i].toLower();
               tempWord += currentSentence[i];      //
               i++;
        }
        if(tempWord == word){
                 searchResult +="       line "+toString(lineNum)+"->"+currentSentence+"\n";
                 ui->searchResult->append("       line "+toString(lineNum)+"->"+currentSentence );
        }
    }
 }
////测试,这个地方有可能会让程序崩溃= =
 /// \brief MainWindow::lineSearch
 /// \param line
 /// \param word
 ///
 void MainWindow::lineSearch(QString line, QString word)
 {  QString tempWord="";
     int length=0;
     length = line.size();                  //当前字符串长度
    line = line.trimmed();
     currentSentence = "";
     for(int i=0;i<length;i++){
         tempWord ="";                       //暂存清空
         if(isEndofStc(line[i].toLatin1()) ){
           addToSearchResult(currentSentence, word);
             currentSentence = "";
            continue;
         }
         currentSentence+= line[i];
     }
    addToSearchResult(currentSentence, word);
 }

 /// \brief MainWindow::searchWord搜索一个单词
 /// \param word要搜索的单词
 ///
void MainWindow::searchWord(QString word)
 {
     QMap<QString, WordInfo>::iterator wi;
     wi=wordMap.find(word);
    if(wi == wordMap.end()){        //没有找到
        ui->searchResult->setText("Not found!");
    }
    else{                                           //找到了一个记录

        if(wi.value().count == 0){      // 如果是一个虚词
            ui->searchResult->setText("Not found!");
            return ;
        }

        wi.value().searchCount+=1;//把当前单词的搜索次数+1
         addToSearchTop(wi.key(), wi.value().searchCount);
        searchResult += wi.key()+"  "+toString(wi.value().count)+" "+toString(wi.value().searchCount)+"\n";
        ui->searchResult->append(wi.key()+"  "+toString(wi.value().count)+" "+toString(wi.value().searchCount) );

        QString line;
        for(int i=0;i<fileNum;i++){
         if (!fileList[i].isEmpty()) {           //如果文件列表不为空
                QFile file(fileList[i]);
                if (!file.open(QIODevice::ReadOnly)) {  //如果成功打开文件
                         QMessageBox::critical(this, tr("Error"), tr("打开文件:") +fileList[i]+" 失败");
                            return;
                    }
                QTextStream in(&file);
                searchResult +="fileName:"+fileList[i]+" \n";
                ui->searchResult->append(QString::fromLocal8Bit("<div style=\" color:red\">文件:</div>"));
                ui->searchResult->append(fileList[i]);
                ui->searchResult->append(QString::fromLocal8Bit("<hr >"));
                lineNum = 0;
                while(! in.atEnd())
                {
                    line = in.readLine();   //读取一行数据
                    lineSearch(line, word);           //处理一行数据
                    lineNum++;                //行号+1
                }
                file.close();
            }
        }
        //ui->searchResult->setText(searchResult);
    }
 }


///添加到单词次数榜
/// \brief MainWindow::addToCountTop
/// \param word 要添加的单词
/// \param count该单词出现的次数
///
 void MainWindow::addToCountTop(QString word, int count)
 { /*  for(int i=0;i<10;i++)
     {
         if(count <= wordCountTop[i].times)continue;                        //移到比该单词次数小的位置
         else{
            for(int j=8;j>i;j--){                                                                   //插入该单词,其它的后移
                wordCountTop[j+1].times = wordCountTop[j].times;
                wordCountTop[j+1].wordName = wordCountTop[j].wordName;
            }
            wordCountTop[i].times =count;                                       //插入该单词
            wordCountTop[i].wordName = word;
            break;
        }
     }*/
     for(int i=9;i>=0;i--)
     {  //判断是否已经在排行榜中
         if(word == wordCountTop[i].wordName){
             wordCountTop[i].times+=1;    //只要把搜索次数+1
             sortCountTop();                       //重新排序
             return;
        }
     }
     //如果次数比最后大,直接插入到最后一个中
     if(count >wordCountTop[9].times ){
         wordCountTop[9].times = count;
         wordCountTop[9].wordName = word;
         sortCountTop();                      //重新排序
     }
 }

 //暂时用冒泡代替一下
 ///
 /// \brief MainWindow::sortCountTop
 ///
  void MainWindow::sortCountTop()
  {  int tempTimes;
     QString tempWord;
     for(int j=0;j<10;j++)
      for(int i=0;i<9;i++)
      {
          if(wordCountTop[i].times <wordCountTop[i+1].times){
             tempTimes = wordCountTop[i].times;
             tempWord = wordCountTop[i].wordName;

              wordCountTop[i].times = wordCountTop[i+1].times;
              wordCountTop[i].wordName = wordCountTop[i+1].wordName;

              wordCountTop[i+1].times = tempTimes;
              wordCountTop[i+1].wordName = tempWord;
          }
      }
  }

  //显示单词次数排行榜
  ///
  /// \brief MainWindow::showCountTop
  ///
 void MainWindow::showCountTop()
 {
     QString countTop="No : 单词\t-\t次数\n";
     for(int i=0;i<10;i++){
         countTop+=toString(i+1)+" : "+wordCountTop[i].wordName +"\t-\t"+toString(wordCountTop[i].times)+"\n";
     }
     ui->TopList->setCurrentIndex(0);
     ui->CountTop->setText(countTop);
 }

//暂时用冒泡代替一下
 ///
 /// \brief MainWindow::sortSearchTop
 ///
 void MainWindow::sortSearchTop()
 {  int tempTimes;
    QString tempWord;
    for(int j=0;j<10;j++)
     for(int i=0;i<9;i++)
     {
         if(wordSearchTop[i].times <wordSearchTop[i+1].times){
            tempTimes = wordSearchTop[i].times;
            tempWord = wordSearchTop[i].wordName;

             wordSearchTop[i].times = wordSearchTop[i+1].times;
             wordSearchTop[i].wordName = wordSearchTop[i+1].wordName;

             wordSearchTop[i+1].times = tempTimes;
             wordSearchTop[i+1].wordName = tempWord;
         }
     }
 }


 ///把一个单词加入到搜索排行榜中
 /// \brief MainWindow::addToSearchTop
 /// \param word要加入的单词,
 /// \param count单词被搜索的次数
 ///
 void MainWindow::addToSearchTop(QString word, int count)
 {
          for(int i=9;i>=0;i--)
          {  //判断是否已经在排行榜中
              if(word == wordSearchTop[i].wordName){
                  wordSearchTop[i].times+=1;    //只要把搜索次数+1
                  sortSearchTop();                       //重新排序
                  return;
             }
          }
          //如果次数比最后大,直接插入到最后一个中
          if(count >wordSearchTop[9].times ){
              wordSearchTop[9].times = count;
              wordSearchTop[9].wordName = word;
              sortSearchTop();                      //重新排序
          }
 }

 //显示排行榜
 ///
 /// \brief MainWindow::showSearchTop
 ///
 void MainWindow::showSearchTop()
 {  QString searchTop="No : 单词\t-\t次数\n";
     for(int i=0;i<10;i++){
         searchTop+=toString(i+1)+" : "+wordSearchTop[i].wordName +"\t-\t"+toString(wordSearchTop[i].times)+"\n";
     }
     ui->TopList->setCurrentIndex(1);
     ui->SearchTop->setText(searchTop);
 }

 ///
 /// \brief wordInfoInit
 /// \param w
 ///
 void wordInfoInit(WordInfo w)
 {
     w.count = 0;
     w.fileNum = 0;
     w.lineNum = 0;
     w.sentenceNo = 0;
     w.searchCount = 0;
 }
