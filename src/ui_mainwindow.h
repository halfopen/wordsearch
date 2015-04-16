/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QProgressBar *progressBar;
    QTabWidget *TopList;
    QWidget *CountTopTab;
    QTextBrowser *CountTop;
    QWidget *SearchTopTab;
    QTextBrowser *SearchTop;
    QLabel *label_2;
    QGroupBox *groupBox;
    QTextBrowser *textBrowser;
    QPushButton *pushButton;
    QGroupBox *groupBox_2;
    QLineEdit *searhInput;
    QPushButton *pushButton_2;
    QTextBrowser *searchResult;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_3;
    QListWidget *filelist;
    QPushButton *add;
    QPushButton *remove;
    QPushButton *ok;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(869, 502);
        MainWindow->setMinimumSize(QSize(869, 502));
        MainWindow->setMaximumSize(QSize(869, 502));
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QStringLiteral("wordSearch.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setIconSize(QSize(32, 32));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral("border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(10, 80, 351, 21));
        QFont font;
        font.setPointSize(7);
        progressBar->setFont(font);
        progressBar->setMaximum(0);
        progressBar->setValue(0);
        TopList = new QTabWidget(centralWidget);
        TopList->setObjectName(QStringLiteral("TopList"));
        TopList->setGeometry(QRect(630, 10, 231, 141));
        CountTopTab = new QWidget();
        CountTopTab->setObjectName(QStringLiteral("CountTopTab"));
        CountTop = new QTextBrowser(CountTopTab);
        CountTop->setObjectName(QStringLiteral("CountTop"));
        CountTop->setGeometry(QRect(0, 0, 221, 111));
        TopList->addTab(CountTopTab, QString());
        SearchTopTab = new QWidget();
        SearchTopTab->setObjectName(QStringLiteral("SearchTopTab"));
        SearchTop = new QTextBrowser(SearchTopTab);
        SearchTop->setObjectName(QStringLiteral("SearchTop"));
        SearchTop->setGeometry(QRect(0, 0, 221, 111));
        TopList->addTab(SearchTopTab, QString());
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(370, 70, 271, 81));
        QFont font1;
        font1.setFamily(QStringLiteral("Ume Gothic S4"));
        font1.setPointSize(17);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 110, 201, 371));
        groupBox->setInputMethodHints(Qt::ImhNone);
        groupBox->setFlat(false);
        textBrowser = new QTextBrowser(groupBox);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 20, 201, 301));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 330, 85, 27));
        pushButton->setStyleSheet(QStringLiteral("border-color: rgb(29, 7, 7);"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(220, 110, 641, 381));
        groupBox_2->setFlat(false);
        searhInput = new QLineEdit(groupBox_2);
        searhInput->setObjectName(QStringLiteral("searhInput"));
        searhInput->setGeometry(QRect(0, 20, 101, 21));
        searhInput->setStyleSheet(QStringLiteral("boder-color:rgb(14, 235, 62)"));
        searhInput->setInputMethodHints(Qt::ImhNone);
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(110, 20, 21, 21));
        pushButton_2->setCursor(QCursor(Qt::OpenHandCursor));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/spotlight.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(50, 20));
        pushButton_2->setDefault(false);
        pushButton_2->setFlat(true);
        searchResult = new QTextBrowser(groupBox_2);
        searchResult->setObjectName(QStringLiteral("searchResult"));
        searchResult->setGeometry(QRect(0, 50, 641, 271));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(0, 330, 85, 27));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 0, 621, 71));
        groupBox_3->setMinimumSize(QSize(621, 71));
        filelist = new QListWidget(groupBox_3);
        filelist->setObjectName(QStringLiteral("filelist"));
        filelist->setGeometry(QRect(0, 20, 501, 51));
        filelist->setStyleSheet(QStringLiteral(""));
        add = new QPushButton(groupBox_3);
        add->setObjectName(QStringLiteral("add"));
        add->setGeometry(QRect(500, 20, 16, 21));
        remove = new QPushButton(groupBox_3);
        remove->setObjectName(QStringLiteral("remove"));
        remove->setGeometry(QRect(500, 50, 16, 21));
        ok = new QPushButton(groupBox_3);
        ok->setObjectName(QStringLiteral("ok"));
        ok->setEnabled(false);
        ok->setGeometry(QRect(530, 20, 61, 51));
        ok->setCursor(QCursor(Qt::OpenHandCursor));
        ok->setAutoFillBackground(false);
        ok->setIcon(icon1);
        ok->setIconSize(QSize(50, 50));
        ok->setAutoDefault(false);
        ok->setDefault(false);
        ok->setFlat(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 869, 21));
        MainWindow->setMenuBar(menuBar);
        QWidget::setTabOrder(filelist, add);
        QWidget::setTabOrder(add, remove);
        QWidget::setTabOrder(remove, ok);
        QWidget::setTabOrder(ok, textBrowser);
        QWidget::setTabOrder(textBrowser, pushButton);
        QWidget::setTabOrder(pushButton, searhInput);
        QWidget::setTabOrder(searhInput, pushButton_2);
        QWidget::setTabOrder(pushButton_2, searchResult);
        QWidget::setTabOrder(searchResult, CountTop);
        QWidget::setTabOrder(CountTop, TopList);
        QWidget::setTabOrder(TopList, SearchTop);

        retranslateUi(MainWindow);
        QObject::connect(add, SIGNAL(clicked()), MainWindow, SLOT(addFile()));
        QObject::connect(remove, SIGNAL(clicked()), MainWindow, SLOT(removeFile(QListWidgetItem *item)));
        QObject::connect(remove, SIGNAL(clicked()), filelist, SLOT(clear()));
        QObject::connect(remove, SIGNAL(clicked()), MainWindow, SLOT(removeFile()));
        QObject::connect(ok, SIGNAL(clicked()), MainWindow, SLOT(openFile()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), MainWindow, SLOT(search()));
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindow, SLOT(saveFile()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), MainWindow, SLOT(saveSearchResult()));

        TopList->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "wordSearch", 0));
        TopList->setTabText(TopList->indexOf(CountTopTab), QApplication::translate("MainWindow", "\345\207\272\347\216\260\346\254\241\346\225\260\346\234\200\345\244\232", 0));
        TopList->setTabText(TopList->indexOf(SearchTopTab), QApplication::translate("MainWindow", "\346\220\234\347\264\242\346\254\241\346\225\260\346\234\200\345\244\232", 0));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"justify\"><span style=\" font-size:28pt; font-style:italic; color:#949494;\">\350\257\215\351\242\221\347\273\237\350\256\241\345\222\214\346\243\200\347\264\242\345\267\245\345\205\267</span></p></body></html>", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\350\257\215\351\242\221\347\273\237\350\256\241", 0));
        pushButton->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\347\273\223\346\236\234", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\345\215\225\350\257\215\346\243\200\347\264\242", 0));
        pushButton_2->setText(QString());
        pushButton_3->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\347\273\223\346\236\234", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\346\267\273\345\212\240\346\226\207\344\273\266", 0));
        add->setText(QApplication::translate("MainWindow", "+", 0));
        remove->setText(QApplication::translate("MainWindow", "-", 0));
        ok->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
