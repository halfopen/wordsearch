/*
 * MainWindow的信号函数实现
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QListWidgetItem>
#include <QListWidget>

#include "str.h"


MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->remove->setDisabled(true);
     fileNum = 0;
     ui->progressBar->setHidden(true);
     currentSentence ="句子:";

}

//排行榜初始化
///
/// \brief MainWindow::TopListInit
///
void MainWindow::TopListInit()
{
    for(int i=0;i<10;i++){
        wordCountTop[i].wordName="";
        wordCountTop[i].times=0;
        wordSearchTop[i].wordName="";
        wordSearchTop[i].times=0;
    }
}

//移除文件
///
/// \brief MainWindow::removeFile
///
void MainWindow::removeFile()
{
    ui->remove->setDisabled(false);

    ui->progressBar->setMaximum(0);
    ui->progressBar->setHidden(true);
    fileNum = 0;
    wordMap.clear();    //清空
    ui->textBrowser->setText("");
    ui->searchResult->setText("");
    //重新
    mapInit();
    result = "";
}

//点击打开按钮
//添加到文件列表
///
/// \brief MainWindow::addFile
///
void MainWindow::addFile()
{
    //  打开一个打开文件窗口
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(), tr("Text Files (*.txt);;C++ Files (*.cpp *.cc *.C *.h)"));
        ui->remove->setDisabled(false);     //设置重置按纽为不可用
        bool isInFileList = false;                  //标记文件列表中是否已经存在
        for(int i=0;i<fileNum;i++){               //
        	if(fileList[i] == fileName)isInFileList = true;
    	}
        if(isInFileList)                                //如果文件已经在文件列表中了
        {
            QMessageBox::information(this,tr("提示"),tr("文件已经添加!"));
            return ;
        }
        if (!fileName.isEmpty() && isInFileList==false ) {
                QFile file(fileName);
                if (!file.open(QIODevice::ReadOnly)) {
                    QMessageBox::critical(this, tr("文件打开错误"), tr("不能打开文件"));
                    return;
                }
		//保存文件名到文件列表
                fileList[fileNum] = fileName;
		//文件数目+1
                fileNum ++;
		//添加一个列表项
                QListWidgetItem* lst1 = new QListWidgetItem(fileName, ui->filelist);
                ui->filelist->addItem(lst1);
		//关闭文件
                file.close();
	}
        ui->progressBar->setHidden(false);
        ui->progressBar->setMaximum(fileNum);
        ui->ok->setDisabled(false);
}

//打开文件
///
/// \brief MainWindow::openFile
///
void MainWindow::openFile()
{     TopListInit();
    wordMap.clear();
        mapInit();
         result = "";
        QString line;
        for(int i=0;i<fileNum;i++){
        if (!fileList[i].isEmpty()) {           //如果文件列表不为空
                QFile file(fileList[i]);
                if (!file.open(QIODevice::ReadOnly)) {  //如果成功打开文件
                    QMessageBox::critical(this, tr("Error"), tr("打开文件:") +fileList[i]+" 失败");
                    return;
                }
                QTextStream in(&file);
                int lineNum = 0;
                while(! in.atEnd())
               {    line = in.readLine();   //读取一行数据
                    lineInsert(line);           //处理一行数据
                    lineNum++;                //行号+1
                }
                ui->progressBar->setValue(fileNum);
                file.close();
        }
        }
        saveMap();                          //显示单词词频结果到界面
       ui->textBrowser->setText(result);
         ui->ok->setDisabled(true);
}


void MainWindow::showResult()
{

}

//保存文件
///
/// \brief MainWindow::saveFile
///
void MainWindow::saveFile()
{   //打开一个保存文件窗口
    QString fName = QFileDialog::getSaveFileName(this,
            tr("Save Result"),                //窗口标题
            "Result",                             //默认文件名
            tr("Result File(*)"));          //文件类型

        if (!fName.isNull())           //如果点的是确定
        {
            //fileName是文件名
            QFile file(fName);
            file.open(QFile::WriteOnly);

            QTextStream out(&file);
             out<<result<<endl;     //写入到文件中
             file.close();
        }
        else
        {
            //点的是取消
        }
}

void MainWindow::saveSearchResult()
{   //打开一个保存文件窗口
    QString fName = QFileDialog::getSaveFileName(this,
            tr("Save SearchResult"),                //窗口标题
            "SearchResult",                             //默认文件名
            tr("Result File(*)"));          //文件类型

        if (!fName.isNull())           //如果点的是确定
        {
            //fileName是文件名
            QFile file(fName);
            file.open(QFile::WriteOnly);

            QTextStream out(&file);
             out<<searchResult<<endl;     //写入到文件中
             file.close();
        }
        else
        {
            //点的是取消
        }
}


//点击搜索按纽
///
/// \brief MainWindow::search
///
void MainWindow::search()
{
    QString wordName;
    wordName = ui->searhInput->text();      //获取输入框中的数据
    if(wordName.isEmpty() == false)             //如果输入不为空
    {   searchResult = "";
        ui->searchResult->setText("");
        searchWord(wordName);                   //搜索这个单词
         showSearchTop();                               //显示搜索结果
    }
    else{
         QMessageBox::critical(this, tr("提示"), tr("输入不能为空"));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
