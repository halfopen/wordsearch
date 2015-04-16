#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QListWidgetItem>
#include <QListWidget>
#include <QMainWindow>
#include "str.h"
namespace Ui {
    class MainWindow;
}

//排行榜结构
struct TopList{
    QString wordName;           //单词名
    int times;                              //次数
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;                                     //
    int fileNum;                                                    //打开的文件数目
    int sentenceNum;                                          //当时打开文件扫到的句子数
    QString fileList[1024];                                     //文件名列表
    QString result;                                                 //词频统计结果
    QString searchResult;                                   //当前搜索结果
    QString currentSentence;                                //保存当前的句子
    int lineNum;

    QMap <QString, WordInfo> wordMap;        //保存结果的字典
    TopList  wordCountTop[10];                          //词频排行榜
    TopList  wordSearchTop[10];                         //搜索排行榜

//信号槽
private slots:
    void openFile();                 //打开文件
    void addFile();                  //添加文件
    void removeFile();           //清空文件列表
    void saveFile();                //保存结果到本地
    void saveSearchResult();
    void showResult();          //显示结果
    void search();                  //搜索单词

//
public:
    void lineInsert(QString line);                  //处理一行
    void lineSearch(QString line, QString word);
    void mapInit();                                         //初始化
    void TopListInit();                                     //排行榜初始化
    void saveMap();                                      //把map 保存到result
    void addWord(QString );                       //添加一个单词记录
    void addWord(QString , int lineNum, QString fileName);                 //添加一个单词记录

    void addToSearchResult(QString currentSentence, QString word);

    void addToCountTop(QString, int);        //把一个单词添加到词频排行榜中
    void addToSearchTop(QString, int);       //把一个单词添加到搜索排行榜中
    void sortSearchTop();                               //把搜索排行榜排序
    void sortCountTop();

    void showCountTop();                             //显示词频排行榜
    void showSearchTop();                            //显示搜索排行榜

    void clearMap();                                     //清空
    void searchWord(QString word);          //搜索一个单词
};

#endif // MAINWINDOW_H
