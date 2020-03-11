#include <QVBoxLayout>
#include <QPixmap>
#include <QIcon>
#include <QTableWidget>
#include <QPushButton>
#include <QLabel>

#include "widget.h"
#include "ui_widget.h"
#include "title_bar.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());

    create_ui();

    ui->setupUi(this);
    setWindowIcon(QIcon("/home/test/qt-workspace/burner-test/pic/logo.ico"));
    this->setWindowTitle("Kylin-burner");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::create_ui()
{
    TitleBar *pTitleBar = new TitleBar(this);
    installEventFilter(pTitleBar);

    QPalette pal(palette());
    pal.setColor(QPalette::Background, QColor(255, 255, 255));
    setAutoFillBackground(true);
    setPalette(pal);

    tabWidget = new QStackedWidget(this);

    QWidget *back = new QWidget(this);
    back->resize(600,125);
    back->setStyleSheet("QWidget{border-image: url(:/new/prefix1/pic/icon-侧边背景.png);border:none;background-repeat: no-repeat;background:transparent;}");


    data_burner = new QPushButton("data burner", this);
    data_burner->setFixedSize(125, 50);
    data_burner->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-数据刻录-默认.png);"
                               "background-color:rgba(87, 137, 217, 0.2);"
                               "background-repeat: no-repeat;"
                               "background-position:left;"
                               "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                           "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-数据刻录-悬停点击.png);"
                               "background-color:rgba(87, 137, 217,0.15);"
                               "background-repeat: no-repeat;"
                               "background-position:left;"
                               "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                           "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-数据刻录-悬停点击.png);"
                               "background-color:rgba(87, 137, 217, 0.2);"
                               "background-repeat: no-repeat;"
                               "background-position:left;"
                               "border:none;color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}");

    image_burner = new QPushButton("image burner");
    image_burner->setFixedSize(125, 50);
    image_burner->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-镜像刻录-默认.png);"
                                "background-color:transparent;"
                                "background-repeat: no-repeat;"
                                "background-position:left;"
                                "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                           "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                "background-color:rgba(87, 137, 217, 0.15);"
                                "background-repeat: no-repeat;"
                                "background-position:left;"
                                "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                           "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                "background-color:rgba(87, 137, 217, 0.2);"
                                "background-repeat: no-repeat;"
                                "background-position:left;"
                                "border:none;"
                                "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}");
    copy_image = new QPushButton("copy image");
    copy_image->setFixedSize(125, 50);
    copy_image->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-光盘复制-默认.png);"
                              "background-color:transparent;"
                              "background-repeat: no-repeat;"
                              "background-position:left;"
                              "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                           "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-光盘复制-悬停点击.png);"
                              "background-color:rgba(87, 137, 217, 0.15);"
                              "background-repeat: no-repeat;"
                              "background-position:left;"
                              "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                           "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-光盘复制-悬停点击.png);"
                              "background-color:rgba(87, 137, 217, 0.2);"
                              "background-repeat: no-repeat;"
                              "background-position:left;"
                              "border:none;"
                              "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}");

    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->addSpacing(50);
    vLayout->addWidget(data_burner);
    vLayout->addSpacing(20);
    vLayout->addWidget(image_burner);
    vLayout->addSpacing(20);
    vLayout->addWidget(copy_image);
    vLayout->addStretch();
    back->setLayout(vLayout);

    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(back);
    hLayout->addWidget(tabWidget);

    QVBoxLayout *pLayout = new QVBoxLayout();
    pLayout->addWidget(pTitleBar);
    pLayout->addLayout(hLayout);
    pLayout->setSpacing(0);
    pLayout->setMargin(0);
    setLayout(pLayout);

    data_page = new p_data(this);
    image_page = new p_image(this);
    copy_page = new p_copy(this);

    connect(data_burner, SIGNAL(clicked(bool)), this, SLOT(on_data_burner_clicked()));
    connect(image_burner, SIGNAL(clicked(bool)), this, SLOT(on_image_burner_clicked()));
    connect(copy_image, SIGNAL(clicked(bool)), this, SLOT(on_copy_image_clicked()));

    tabWidget->addWidget(data_page);
    tabWidget->addWidget(image_page);
    tabWidget->addWidget(copy_page);
    tabWidget->setCurrentWidget(data_page);

    tabWidget->showFullScreen();
}

void Widget::on_data_burner_clicked()
{
    tabWidget->setCurrentWidget(data_page);
    data_burner->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-数据刻录-悬停点击.png);"
                               "background-color:rgba(87, 137, 217, 0.2);"
                               "background-repeat: no-repeat;"
                               "background-position:left;"
                               "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                               "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                    "background-color:rgba(87, 137, 217, 0.15);"
                                    "background-repeat: no-repeat;"
                                    "background-position:left;"
                                    "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                               "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                    "background-color:rgba(87, 137, 217, 0.2);"
                                    "background-repeat: no-repeat;"
                                    "background-position:left;"
                                    "border:none;"
                                    "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}");
    image_burner->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-镜像刻录-默认.png);"
                                "background-color:transparent;"
                                "background-repeat: no-repeat;"
                                "background-position:left;"
                                "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                                "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                     "background-color:rgba(87, 137, 217, 0.15);"
                                     "background-repeat: no-repeat;"
                                     "background-position:left;"
                                     "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                                "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                     "background-color:rgba(87, 137, 217, 0.2);"
                                     "background-repeat: no-repeat;"
                                     "background-position:left;"
                                     "border:none;"
                                     "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}");
    copy_image->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-光盘复制-默认.png);"
                              "background-color:transparent;"
                              "background-repeat: no-repeat;"
                              "background-position:left;"
                              "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                              "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-光盘复制-悬停点击.png);"
                                 "background-color:rgba(87, 137, 217, 0.15);"
                                 "background-repeat: no-repeat;"
                                 "background-position:left;"
                                 "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                              "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-光盘复制-悬停点击.png);"
                                 "background-color:rgba(87, 137, 217, 0.2);"
                                 "background-repeat: no-repeat;"
                                 "background-position:left;"
                                 "border:none;"
                                 "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}");
}

void Widget::on_image_burner_clicked()
{
    tabWidget->setCurrentWidget(image_page);
    data_burner->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-数据刻录-默认.png);"
                               "background-color:transparent;"
                               "background-repeat: no-repeat;"
                               "background-position:left;"
                               "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                               "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                    "background-color:rgba(87, 137, 217, 0.15);"
                                    "background-repeat: no-repeat;"
                                    "background-position:left;"
                                    "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                               "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                    "background-color:rgba(87, 137, 217, 0.2);"
                                    "background-repeat: no-repeat;"
                                    "background-position:left;"
                                    "border:none;"
                                    "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}");
    image_burner->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                "background-color:rgba(87, 137, 217, 0.2);"
                                "background-repeat: no-repeat;"
                                "background-position:left;"
                                "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                                "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                     "background-color:rgba(87, 137, 217, 0.15);"
                                     "background-repeat: no-repeat;"
                                     "background-position:left;"
                                     "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                                "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                     "background-color:rgba(87, 137, 217, 0.2);"
                                     "background-repeat: no-repeat;"
                                     "background-position:left;"
                                     "border:none;"
                                     "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}");
    copy_image->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-光盘复制-默认.png);"
                              "background-color:transparent;"
                              "background-repeat: no-repeat;"
                              "background-position:left;"
                              "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                              "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-光盘复制-悬停点击.png);"
                                 "background-color:rgba(87, 137, 217, 0.15);"
                                 "background-repeat: no-repeat;"
                                 "background-position:left;"
                                 "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                              "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-光盘复制-悬停点击.png);"
                                 "background-color:rgba(87, 137, 217, 0.2);"
                                 "background-repeat: no-repeat;"
                                 "background-position:left;"
                                 "border:none;"
                                 "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}");
}

void Widget::on_copy_image_clicked()
{
    tabWidget->setCurrentWidget(copy_page);
    data_burner->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-数据刻录-默认.png);"
                               "background-color:transparent;"
                               "background-repeat: no-repeat;"
                               "background-position:left;"
                               "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                               "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                    "background-color:rgba(87, 137, 217, 0.15);"
                                    "background-repeat: no-repeat;"
                                    "background-position:left;"
                                    "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                               "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                    "background-color:rgba(87, 137, 217, 0.2);"
                                    "background-repeat: no-repeat;"
                                    "background-position:left;"
                                    "border:none;"
                                    "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}");
    image_burner->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-镜像刻录-默认.png);"
                                "background-color:transparent;"
                                "background-repeat: no-repeat;"
                                "background-position:left;"
                                "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                                "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                     "background-color:rgba(87, 137, 217, 0.15);"
                                     "background-repeat: no-repeat;"
                                     "background-position:left;"
                                     "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                                "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-镜像刻录-悬停点击.png);"
                                     "background-color:rgba(87, 137, 217, 0.2);"
                                     "background-repeat: no-repeat;"
                                     "background-position:left;"
                                     "border:none;"
                                     "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}");
    copy_image->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-光盘复制-悬停点击.png);"
                              "background-color:rgba(87, 137, 217, 0.2);"
                              "background-repeat: no-repeat;"
                              "background-position:left;"
                              "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                              "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-光盘复制-悬停点击.png);"
                                 "background-color:rgba(87, 137, 217, 0.15);"
                                 "background-repeat: no-repeat;"
                                 "background-position:left;"
                                 "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}"
                              "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-光盘复制-悬停点击.png);"
                                 "background-color:rgba(87, 137, 217, 0.2);"
                                 "background-repeat: no-repeat;"
                                 "background-position:left;"
                                 "border:none;"
                                 "color:rgb(65, 127, 249);font: 14px;border-radius: 6px;}");
}
