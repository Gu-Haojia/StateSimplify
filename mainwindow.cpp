#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/qmath.h>
#include <QSpinBox>
#include <QTableWidget>
#include <QHeaderView>
#include <QDebug>
#include <QFont>
#include <QString>
#include <QMainWindow>
#include <QLabel>
#include <QTableWidgetItem>
#include <QDebug>
#include <QString>
#include <QDialog>
#include <QMessageBox>
#include <QEvent>
#include <func.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setFixedSize(900,600);
    ui->tableWidget1_1->setColumnCount(1);
    ui->tableWidget1_1->setRowCount(2);
    ui->tableWidget2_1->setColumnCount(1);
    ui->tableWidget2_1->setRowCount(2);

    ui->textBrowser->setText("Σ(っ°Д°;)っ\n还没有输入呢~");
    ui->textBrowser_2->setText("Σ(っ°Д°;)っ\n还没有输入呢~");

    int St = ui->inSt->value();
    int In = ui->inIn->value();

    connect(ui->inSt,static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), [=]()mutable{
        St = ui->inSt->value();
        In = ui->inIn->value();
        ui->tableWidget1_1->setRowCount(St);
        ui->tableWidget2_1->setRowCount(St);
//        for(int i=0 ;i<St;i++)
//       {
//           for(int k=0;k<In;k++)
//           {

//               ui-> tableWidget1_1->item(i,k)->setTextAlignment(Qt::AlignCenter);
//               ui-> tableWidget2_1->item(i,k)->setTextAlignment(Qt::AlignCenter);

//           }
//       }

    });

    connect(ui->inIn,static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged), [=]()mutable{
        In = ui->inIn->value();
        St = ui->inSt->value();
        ui->tableWidget1_1->setColumnCount(In);
        ui->tableWidget2_1->setColumnCount(In);
//        for(int i=0 ;i<St;i++)
//       {
//           for(int k=0;k<In;k++)
//           {

//               ui-> tableWidget1_1->item(i,k)->setTextAlignment(Qt::AlignCenter);
//               ui-> tableWidget2_1->item(i,k)->setTextAlignment(Qt::AlignCenter);

//           }
//       }
    });




    QFont font = ui->tableWidget1_1->horizontalHeader()->font();
    font.setBold(true);
    ui->tableWidget1_1->horizontalHeader()->setFont(font);
    ui->tableWidget1_1->horizontalHeader()->setStretchLastSection(true);
    QFont font1 = ui->tableWidget1_1->verticalHeader()->font();
    font1.setBold(true);
    ui->tableWidget1_1->verticalHeader()->setFont(font);
    ui->tableWidget1_1->verticalHeader()->setStretchLastSection(true);

    ui->tableWidget1_1->resizeColumnsToContents();
    ui->tableWidget1_1->resizeRowsToContents();
    ui->tableWidget1_1->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget1_1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget1_1->horizontalHeader()->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget1_1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget1_1->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(210,210,210);color: black;}");
    ui->tableWidget1_1->verticalHeader()->setStyleSheet("QHeaderView::section{background:rgb(210,210,210);color: black;}");

    font.setBold(true);
    ui->tableWidget2_1->horizontalHeader()->setFont(font);
    ui->tableWidget2_1->horizontalHeader()->setStretchLastSection(true);
    font.setBold(true);
    ui->tableWidget2_1->verticalHeader()->setFont(font);
    ui->tableWidget2_1->verticalHeader()->setStretchLastSection(true);
    ui->tableWidget2_1->resizeColumnsToContents();
    ui->tableWidget2_1->resizeRowsToContents();
    ui->tableWidget2_1->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget2_1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget2_1->horizontalHeader()->setFocusPolicy(Qt::NoFocus);
    ui->tableWidget2_1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget2_1->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(210,210,210);color: black;}");
    ui->tableWidget2_1->verticalHeader()->setStyleSheet("QHeaderView::section{background:rgb(210,210,210);color: black;}");


    ui->tableWidget2_1->setStyleSheet(QString("QTableWidget QHeaderView::section{background:rgb(	220 ,220, 220,230);font-weight:bold; border:none; height:35px; color:black;} QTableWidget::item:selected { background-color: rgb(107,170,162,230) }"));
    ui->tableWidget1_1->setStyleSheet(QString("QTableWidget QHeaderView::section{background:rgb(	220 ,220, 220,230);font-weight:bold; border:none; height:35px; color:black;} QTableWidget::item:selected { background-color: rgb(107,170,162,230) }"));
    int as[SIZE][SIZE];
    int ai[SIZE][SIZE];

    connect(ui->fresh,&QPushButton::clicked,[=]()mutable{
        St=ui->inSt->value();
        In=ui->inIn->value();
        int ta,tb;

        for(int i=0 ;i<St;i++)
       {

           for(int k=0;k<In;k++)
           {


               if(ui->tableWidget1_1->item(i,k) != NULL)
              {
                 ta=ui->tableWidget1_1->item(i,k)->text().toInt();
                ui-> tableWidget1_1->item(i,k)->setTextAlignment(Qt::AlignCenter);
                 if(ta>0&&ta<=St)
                 {
                     as[i][k] = ui->tableWidget1_1->item(i,k)->text().toInt();
                 }else{

                     QMessageBox ::critical(this,"Error","输入有误，请重新输入");
                     return;
                 }

              }else{
                  QMessageBox ::critical(this,"Error","输入有误，请重新输入");
                  return;
              }

              if(ui->tableWidget2_1->item(i,k) != NULL)
              {
                  tb=ui->tableWidget2_1->item(i,k)->text().toInt();
                  ui-> tableWidget2_1->item(i,k)->setTextAlignment(Qt::AlignCenter);
                  if(tb==0||tb==1)
                  {
                      ai[i][k] = ui->tableWidget2_1->item(i,k)->text().toInt();
                   }else{
                      QMessageBox ::critical(this,"Error","输入有误，请重新输入");
                      return;
                  }
              }else{
                      QMessageBox ::critical(this,"Error","输入有误，请重新输入");
                      return;
                  }



           }
       }




        int iiii=In;
        Solution bot;
        bot.in1(St,iiii,as);
        bot.in2(ai);
        bot.calc();

        int outraw[SIZE][SIZE];

        bot.out(outraw);

        int visit[SIZE];
        int list[SIZE];
        int outS=0;


       QString y2="(～￣▽￣)～ \n以下状态合并：\n";

        for(int i=0;i<St;i++){
            list[i]=-1;
        }

        for(int i=0;i<St;i++){
            visit[i]=-1;
        }

        for(int i=0;i<St;i++){
            if(visit[i]==-1){
                y2.append("{ S");
                y2.append('1'+i);
                y2.append(" ");
                visit[i]=i;
                list[outS]=i;
                for(int j=i+1;j<St;j++){
                    if(outraw[i][j]){
                        visit[j]=i;
                        y2.append("S");
                        y2.append('1'+j);
                        y2.append(" ");
                    }
                }
                outS++;
                y2.append("}\n");
            }
        }


//        for(int i=0 ; i < outS; i++){
//            int p=0;
//            while(!list[i][p]){
//                qDebug()<<list[i][p];
//            }


//        }

        ui->textBrowser_2->setText(y2);


          QString no="Σ(☉▽☉\n已经是最简了欸~";
          QString yes="(oﾟ▽ﾟ)o  \n化简后剩余状态数： ";
         if(outS==St){
             ui->textBrowser->setText(no);
         }else{

             yes.append(outS+'0');
             ui->textBrowser->setText(yes);
         }

        ui->tableWidget2->setRowCount(outS);
        ui->tableWidget2->setColumnCount(In);

        QFont font3 = ui->tableWidget2->horizontalHeader()->font();

        ui->tableWidget2->horizontalHeader()->setFont(font3);
        ui->tableWidget2->horizontalHeader()->setStretchLastSection(true);
        QFont font4 = ui->tableWidget2->verticalHeader()->font();

        ui->tableWidget2->verticalHeader()->setFont(font);
        ui->tableWidget2->verticalHeader()->setStretchLastSection(true);

        ui->tableWidget2->resizeColumnsToContents();
        ui->tableWidget2->resizeRowsToContents();
        ui->tableWidget2->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableWidget2->horizontalHeader()->setFocusPolicy(Qt::NoFocus);
        ui->tableWidget2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->tableWidget2->horizontalHeader()->setStyleSheet("QHeaderView::section{background:rgb(210,210,210);color: black;}");
        ui->tableWidget2->verticalHeader()->setStyleSheet("QHeaderView::section{background:rgb(210,210,210);color: black;}");
        ui->tableWidget2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableWidget2->setStyleSheet(QString("QTableWidget QHeaderView::section{background:rgb(	220 ,220, 220,230);font-weight:bold; border:none; height:35px; color:black;} QTableWidget::item:selected { background-color: rgb(107,170,162,230) }"));
       QStringList head;
       for(int i=0;i<outS;i++){
            head<<"S"+QString::number(list[i]+1);
            ui-> tableWidget2->setVerticalHeaderLabels(head);
       }

       ui-> tableWidget2->setVerticalHeaderLabels(head);


        for(int i=0 ; i < outS; i++)
        {
            for(int k =0 ;k< In; k++)
            {

               QString str=QString::asprintf("S%d/%d  ",visit[as[list[i]][k]-1]+1,ai[list[i]][k]);

               ui-> tableWidget2->setItem(i,k,new QTableWidgetItem(str));
               ui-> tableWidget2->item(i,k)->setTextAlignment(Qt::AlignCenter);
            }
        }



    });








}

MainWindow::~MainWindow()
{
    delete ui;
}

