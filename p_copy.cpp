#include "p_copy.h"
#include "ui_p_copy.h"

p_copy::p_copy(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::p_copy)
{
    ui->setupUi(this);
    create_ui();
}

p_copy::~p_copy()
{
    delete ui;
}

void p_copy::create_ui()
{
    ui->comboBox_2->setFixedSize(360,30);
    ui->comboBox->setFixedSize(360,30);
    ui->lineEdit_2->setFixedSize(360,30);

    ui->burn_setting->setFixedSize(80,30);
    ui->burn_setting->setStyleSheet("QPushButton{background-color:rgb(233, 233, 233);font: 14px;border-radius: 4px;}"
                           "QPushButton:hover{background-color:rgb(107, 142, 235);font: 14px;border-radius: 4px;}"
                           "QPushButton:pressed{border:none;background-color:rgb(65, 95, 196);font: 14px;border-radius: 4px;}");

    ui->file->setFixedSize(80,30);
    ui->file->setStyleSheet("QPushButton{background-color:rgb(233, 233, 233);font: 14px;border-radius: 4px;}"
                           "QPushButton:hover{background-color:rgb(107, 142, 235);font: 14px;border-radius: 4px;}"
                           "QPushButton:pressed{border:none;background-color:rgb(65, 95, 196);font: 14px;border-radius: 4px;}");

    ui->create->setFixedSize(140,45);
    ui->create->setStyleSheet("QPushButton{background-color:rgb(61, 107, 229);font: 14px;border-radius: 4px;color: rgb(255,255,255);}"
                           "QPushButton:hover{background-color:rgb(107, 142, 235);font: 14px;border-radius: 4px;color: rgb(255,255,255);}"
                           "QPushButton:pressed{border:none;background-color:rgb(65, 95, 196);font: 14px;border-radius: 4px;color: rgb(255,255,255);}");
}


void p_copy::on_file_clicked()
{
    QString s = QFileDialog::getOpenFileName(this, "open file dialog", "/home/test"," iso file(*.iso *.udf) ");
    ui->lineEdit_2->setText(s);
}

void p_copy::on_create_clicked()
{
    pro.set_copy_disk(ui->comboBox_2->currentText());
    pro.set_copy_iso(ui->lineEdit_2->text());
    pro.set_copy_to_disk(ui->comboBox->currentText());
}

void p_copy::on_burn_setting_clicked()
{
    burn_setting = new QDialog();
    burn_setting->setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    burn_setting->setFixedSize(400, 400);

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

    connect(close, SIGNAL(clicked(bool)), this, SLOT(setting_exit()));
    QHBoxLayout *titlebar = new QHBoxLayout();
    titlebar->addWidget(icon);
    titlebar->addSpacing(10);
    titlebar->addWidget(title);
    titlebar->addStretch();
    titlebar->addWidget(close);

    QLabel *setting_label = new QLabel("burn setting");
    setting_label->setFixedSize(200,30);
    setting_label->setStyleSheet("QLabel{font: 24px ;color: #444444;}");

    QLabel *burn_speed = new QLabel("burn speed");
    speed = new QComboBox();
    QStringList list = {"max","1x", "2x","3x","4x"};
    speed->addItems(list);

    append = new QCheckBox("The next time you do not close the disc, you can add additional files (recommended)");
    append->setChecked(false);
    burn_proof = new QCheckBox("use Burn-Proof(recommended)");
    burn_proof->setChecked(false);
    simulation = new QCheckBox("Simulation before burning");
    simulation->setChecked(false);

    QLabel *tmpfile = new QLabel("burn speed");
    QLineEdit *tmp = new QLineEdit();

    QHBoxLayout *hLayout = new QHBoxLayout();
    QPushButton *cancel = new QPushButton("cancel");
    QPushButton *ok = new QPushButton("ok");
    hLayout->addStretch();
    hLayout->addWidget(cancel);
    hLayout->addWidget(ok);

    QVBoxLayout *mainLayout = new QVBoxLayout(burn_setting);
    mainLayout->addLayout(titlebar);
    mainLayout->addSpacing(20);
    mainLayout->addWidget(setting_label);
    mainLayout->addSpacing(20);
    mainLayout->addWidget(burn_speed);
    mainLayout->addWidget(speed);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(append);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(burn_proof);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(simulation);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(tmpfile);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(tmp);
    mainLayout->addSpacing(20);
    mainLayout->addLayout(hLayout);
    mainLayout->addSpacing(20);

    connect(cancel, SIGNAL(clicked(bool)), this, SLOT(setting_exit()));
    connect(ok, SIGNAL(clicked(bool)), this, SLOT(setting_ok()));
    burn_setting->setModal(true);
    burn_setting->show();
}
void p_copy::setting_exit()
{
    burn_setting->close();
}
void p_copy::setting_ok()
{
    pro.set_burn_speed(speed->currentText());
    pro.set_burn_append(append->isChecked());
    pro.set_burn_proof(burn_proof->isChecked());
    pro.set_simulation(simulation->isChecked());
    burn_setting->close();
}
