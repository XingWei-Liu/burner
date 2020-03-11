#include <QLabel>
#include <QMenu>
#include <QPushButton>
#include <QHBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include <QApplication>
#include <QDialog>
#include <QComboBox>
#include <QCheckBox>
#include <QTextEdit>

#include "title_bar.h"


TitleBar::TitleBar(QWidget *parent)
    : QWidget(parent)
{
    setFixedHeight(50);

    m_pIconLabel = new QLabel(this);
    m_pTitleLabel = new QLabel(this);
    m_pMenubutton = new QToolButton(this);
    m_pMinimizeButton = new QPushButton(this);
    m_pMaximizeButton = new QPushButton(this);
    m_pCloseButton = new QPushButton(this);

    m_pIconLabel->setFixedSize(20, 20);
    m_pIconLabel->setScaledContents(true);

    m_pTitleLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    m_pMenubutton->setFixedSize(30, 30);
    m_pMinimizeButton->setFixedSize(30, 30);
    m_pMaximizeButton->setFixedSize(30, 30);
    m_pCloseButton->setFixedSize(30, 30);

    m_pTitleLabel->setObjectName("whiteLabel");
    m_pMenubutton->setObjectName("menuButton");
    m_pMinimizeButton->setObjectName("minimizeButton");
    m_pMaximizeButton->setObjectName("maximizeButton");
    m_pCloseButton->setObjectName("closeButton");

    m_pMenubutton->setToolTip("Menu");
    m_pMinimizeButton->setToolTip("Minimize");
    m_pMaximizeButton->setToolTip("Maximize");
    m_pCloseButton->setToolTip("Close");

    m_pTitleLabel->setContentsMargins(8,0,0,0);
    m_pTitleLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);


    m_pMenubutton->setStyleSheet("QToolButton{border-image: url(:/new/prefix1/pic/icon-设置-默认.png);border:none;background-color:rgb(255, 255, 255);border-radius: 4px;}"
                                "QToolButton:hover{border-image: url(:/new/prefix1/pic/icon-设置-悬停点击.png);border:none;background-color:rgb(61, 107, 229);border-radius: 4px;}"
                                "QToolButton:checked{border-image: url(:/new/prefix1/pic/icon-设置-悬停点击.png;border:none;background-color:rgb(50, 87, 202);border-radius: 4px;}");

    m_pMinimizeButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/pic/icon-最小化-默认.png);border:none;background-color:rgb(255, 255, 255);border-radius: 4px;}"
                                "QPushButton:hover{border-image: url(:/new/prefix1/pic/icon-最小化-悬停点击.png);border:none;background-color:rgb(61, 107, 229);border-radius: 4px;}"
                                "QPushButton:checked{border-image: url(:/new/prefix1/pic/icon-最小化-悬停点击.png;border:none;background-color:rgb(50, 87, 202);border-radius: 4px;}");

    m_pMaximizeButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/pic/icon-最大化-默认.png);border:none;background-color:rgb(255, 255, 255);border-radius: 4px;}"
                                "QPushButton:hover{border-image: url(:/new/prefix1/pic/icon-最大化-悬停点击.png);border:none;background-color:rgb(61, 107, 229);border-radius: 4px;}"
                                "QPushButton:checked{border-image: url(:/new/prefix1/pic/icon-最大化-悬停点击.png;border:none;background-color:rgb(50, 87, 202);border-radius: 4px;}");

    m_pCloseButton->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/pic/icon-关闭-默认.png);border:none;background-color:rgb(255, 255, 255);border-radius: 4px;}"
                                "QPushButton:hover{border-image: url(:/new/prefix1/pic/icon-关闭-悬停点击.png);border:none;background-color:rgb(248, 100, 87);border-radius: 4px;}"
                                "QPushButton:checked{border-image: url(:/new/prefix1/pic/icon-关闭-悬停点击.png;border:none;background-color:rgb(228, 236, 80);border-radius: 4px;}");

    QMenu *menu = new QMenu(this);  //新建菜单

    menu->addAction(QIcon(""),"popup",this,SLOT(popup()));
    menu->addAction(QIcon(""),"clean",this,SLOT(clean()));
    menu->addAction(QIcon(""),"MD5",this,SLOT(md5()));
    menu->addAction(QIcon(""),"help",this,SLOT(help()));
    menu->addAction(QIcon(""),"about",this,SLOT(about()));

    menu->setStyleSheet("QMenu:hover{background-color:rgb(248, 100, 87);}");

    m_pMenubutton->setPopupMode(QToolButton::InstantPopup); //点击模式
    m_pMenubutton->setMenu(menu);  //下拉菜单


    QHBoxLayout *mainWidgetLayout = new QHBoxLayout(this);
    QWidget *mainWidget = new QWidget;
    QHBoxLayout *pLayout = new QHBoxLayout;

    mainWidgetLayout->addWidget(mainWidget);
    mainWidget->setLayout(pLayout);
    mainWidgetLayout->setMargin(0);
    pLayout->setContentsMargins(7,0,0,0);
    pLayout->setSpacing(0);
    mainWidget->setStyleSheet("QWidget{background-color:rgb(255,255,255);}");
    pLayout->addWidget(m_pIconLabel);
    pLayout->addWidget(m_pTitleLabel);
    pLayout->addStretch();
    pLayout->addWidget(m_pMenubutton);
    pLayout->addWidget(m_pMinimizeButton);
    pLayout->addWidget(m_pMaximizeButton);
    pLayout->addWidget(m_pCloseButton);

    connect(m_pMenubutton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
    connect(m_pMinimizeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
    connect(m_pMaximizeButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
    connect(m_pCloseButton, SIGNAL(clicked(bool)), this, SLOT(onClicked()));
}

TitleBar::~TitleBar()
{

}


void TitleBar::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

    emit m_pMaximizeButton->clicked();
}

void TitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if( event->buttons().testFlag(Qt::LeftButton) && mMoving)
    {
        QWidget *pWindow = this->window();
        pWindow->move(pWindow->pos() + (event->globalPos() - mLastMousePosition));
        mLastMousePosition = event->globalPos();
    }
}

void TitleBar::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = true;
        mLastMousePosition = event->globalPos();
    }
}

void TitleBar::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        mMoving = false;
    }
}

bool TitleBar::eventFilter(QObject *obj, QEvent *event)
{
    switch (event->type())
    {
    case QEvent::WindowTitleChange:
    {
        QWidget *pWidget = qobject_cast<QWidget *>(obj);
        if (pWidget)
        {
            m_pTitleLabel->setText(pWidget->windowTitle());
            return true;
        }
    }
    case QEvent::WindowIconChange:
    {
        QWidget *pWidget = qobject_cast<QWidget *>(obj);
        if (pWidget)
        {
            QIcon icon = pWidget->windowIcon();
            m_pIconLabel->setPixmap(icon.pixmap(m_pIconLabel->size()));
            return true;
        }
    }
    case QEvent::WindowStateChange:
    case QEvent::Resize:
         updateMaximize();
         return true;
     default:
         return QWidget::eventFilter(obj, event);

     }
     return QWidget::eventFilter(obj, event);
}

void TitleBar::onClicked()
{
    QPushButton *pButton = qobject_cast<QPushButton *>(sender());
    QWidget *pWindow = this->window();
    if (pWindow->isTopLevel())
    {
        if (pButton == m_pMinimizeButton)
        {
            pWindow->showMinimized();
        }
        else if (pButton == m_pMaximizeButton)
        {
            pWindow->isMaximized() ? pWindow->showNormal() : pWindow->showMaximized();
        }
        else if (pButton == m_pCloseButton)
        {
            pWindow->close();
        }
    }
}

void TitleBar::updateMaximize()
{
    QWidget *pWindow = this->window();
    if (pWindow->isTopLevel())
    {
        bool bMaximize = pWindow->isMaximized();
        if (bMaximize)
        {
            m_pMaximizeButton->setToolTip(tr("Restore"));
            m_pMaximizeButton->setProperty("maximizeProperty", "restore");
        }
        else
        {
            m_pMaximizeButton->setProperty("maximizeProperty", "maximize");
            m_pMaximizeButton->setToolTip(tr("Maximize"));
        }

        m_pMaximizeButton->setStyle(QApplication::style());
    }
}

void TitleBar::popup()
{

}
void TitleBar::clean()
{
    clean_dialog = new QDialog;
    clean_dialog->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    clean_dialog->setFixedSize(400, 400);

    QLabel *icon = new QLabel();
    icon->setFixedSize(30,30);
    icon->setStyleSheet("QLabel{background-image: url(:/new/prefix1/pic/logo.png);background-color:rgb(233, 233, 233);background-repeat: no-repeat;}");
    QLabel *title = new QLabel("kylin-burner");
    title->setFixedSize(80,30);
    title->setStyleSheet("QLabel{background-color:rgb(233, 233, 233);background-repeat: no-repeat;color:rgb(0, 0, 0);font: 14px;}");
    QPushButton *close = new QPushButton();
    close->setFixedSize(30,30);
    close->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/pic/icon-关闭-默认.png);border:none;background-color:rgb(233, 233, 233);border-radius: 4px;}"
                                "QPushButton:hover{border-image: url(:/new/prefix1/pic/icon-关闭-悬停点击.png);border:none;background-color:rgb(248, 100, 87);border-radius: 4px;}");

    connect(close, SIGNAL(clicked(bool)), this, SLOT(clean_exit()));
    QHBoxLayout *titlebar = new QHBoxLayout();
    titlebar->addWidget(icon);
    titlebar->addSpacing(10);
    titlebar->addWidget(title);
    titlebar->addStretch();
    titlebar->addWidget(close);

    QVBoxLayout *mainWidgetLayout = new QVBoxLayout(clean_dialog);
    QLabel *clean_label = new QLabel("clean");
    clean_label->setStyleSheet("QLabel{font: 24px ;color: #444444;}");
    QLabel *clean_label1 = new QLabel("add clean CD");
    clean_combo = new QComboBox();
    QLabel *prompt = new QLabel("");

    QHBoxLayout *hLayout = new QHBoxLayout();
    QPushButton *cancel = new QPushButton("cancel");
    QPushButton *ok = new QPushButton("ok");
    hLayout->addWidget(cancel);
    hLayout->addWidget(ok);

    mainWidgetLayout->addLayout(titlebar);
    mainWidgetLayout->addSpacing(10);
    mainWidgetLayout->addWidget(clean_label);
    mainWidgetLayout->addSpacing(20);
    mainWidgetLayout->addWidget(clean_label1);
    mainWidgetLayout->addWidget(clean_combo);
    mainWidgetLayout->addWidget(prompt);
    mainWidgetLayout->addStretch();
    mainWidgetLayout->addLayout(hLayout);

    connect(ok, SIGNAL(clicked(bool)), this, SLOT(clean_ok()));
    connect(cancel, SIGNAL(clicked(bool)), this, SLOT(clean_exit()));
    clean_dialog->setModal(true);
    clean_dialog->show();
}
void TitleBar::md5()
{
    check_dialog = new QDialog;
    check_dialog->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    check_dialog->setFixedSize(400, 400);

    QLabel *icon = new QLabel();
    icon->setFixedSize(30,30);
    icon->setStyleSheet("QLabel{background-image: url(:/new/prefix1/pic/logo.png);background-color:rgb(233, 233, 233);background-repeat: no-repeat;}");
    QLabel *title = new QLabel("kylin-burner");
    title->setFixedSize(80,30);
    title->setStyleSheet("QLabel{background-color:rgb(233, 233, 233);background-repeat: no-repeat;color:rgb(0, 0, 0);font: 14px;}");
    QPushButton *close = new QPushButton();
    close->setFixedSize(30,30);
    close->setStyleSheet("QPushButton{border-image: url(:/new/prefix1/pic/icon-关闭-默认.png);border:none;background-color:rgb(233, 233, 233);border-radius: 4px;}"
                                "QPushButton:hover{border-image: url(:/new/prefix1/pic/icon-关闭-悬停点击.png);border:none;background-color:rgb(248, 100, 87);border-radius: 4px;}");

    connect(close, SIGNAL(clicked(bool)), this, SLOT(check_exit()));
    QHBoxLayout *titlebar = new QHBoxLayout();
    titlebar->addWidget(icon);
    titlebar->addSpacing(10);
    titlebar->addWidget(title);
    titlebar->addStretch();
    titlebar->addWidget(close);
    QVBoxLayout *mainWidgetLayout = new QVBoxLayout(check_dialog);
    QLabel *check_label = new QLabel("check MD5");
    QLabel *check_label1 = new QLabel("choice check CD");
    check_combo = new QComboBox();
    md5_check = new QCheckBox();
    md5_check->setText("Checking discs with MD5 files");
    md5_file = new QLineEdit("");
    md5_file->setMaximumSize(300,30);
    QPushButton *choice = new QPushButton();
    QHBoxLayout *hLayout1 = new QHBoxLayout(check_dialog);
    hLayout1->addWidget(md5_file);
    hLayout1->addWidget(choice);

    QHBoxLayout *hLayout = new QHBoxLayout(check_dialog);
    QPushButton *cancel = new QPushButton("cancel");
    QPushButton *ok = new QPushButton("ok");
    hLayout->addWidget(cancel);
    hLayout->addWidget(ok);

    mainWidgetLayout->addLayout(titlebar);
    mainWidgetLayout->addWidget(check_label);
    mainWidgetLayout->addSpacing(20);
    mainWidgetLayout->addWidget(check_label1);
    mainWidgetLayout->addWidget(check_combo);
    mainWidgetLayout->addSpacing(20);
    mainWidgetLayout->addWidget(md5_check);
    mainWidgetLayout->addLayout(hLayout1);
    mainWidgetLayout->addStretch();
    mainWidgetLayout->addLayout(hLayout);

    connect(ok, SIGNAL(clicked(bool)), this, SLOT(check_ok()));
    connect(cancel, SIGNAL(clicked(bool)), this, SLOT(check_exit()));
    check_dialog->setModal(true);
    check_dialog->show();
}
void TitleBar::help()
{

}
void TitleBar::about()
{

}

void TitleBar::clean_ok()
{
    pro.set_clean_disk(clean_combo->currentText());
    clean_dialog->close();
}
void TitleBar::check_ok()
{
    pro.set_check_disk(check_combo->currentText());
    pro.set_md5_check(md5_check->isChecked());
    pro.set_md5_file(md5_file->text());
    check_dialog->close();
}

void TitleBar::clean_exit()
{
    clean_dialog->close();
}
void TitleBar::check_exit()
{
    check_dialog->close();
}

