#include <QDialog>
#include <QList>
#include <QFileDialog>
#include <QLineEdit>
#include <QDebug>
#include <QStringList>
#include <QStandardItem>
#include <QInputDialog>
#include <QMessageBox>
#include <QCheckBox>
#include <QDebug>

#include "p_data.h"
#include "ui_p_data.h"

p_data::p_data(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::p_data)
{
    ui->setupUi(this);
    create_ui();
}

p_data::~p_data()
{
    delete ui;
}

void p_data::create_ui()
{
    ui->textBrowser->setMaximumSize(30,30);

    ui->add->setFixedSize(80,30);
    ui->del->setFixedSize(80,30);
    ui->clean->setFixedSize(80,30);
    ui->mkdir->setFixedSize(80,30);
    ui->add->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-添加-默认.png);background-color:rgb(233, 233, 233);background-repeat: no-repeat;background-position:left;color:rgb(0, 0, 0);font: 14px;border-radius: 4px;}"
                           "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-添加-悬停点击.png);background-color:rgb(107, 142, 235);background-repeat: no-repeat;background-position:left;color:rgb(0, 0, 0);font: 14px;border-radius: 4px;}"
                           "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-添加-悬停点击.png);background-color:rgb(65, 95, 196);background-repeat: no-repeat;background-position:left;border:none;color:rgb(0, 0, 0);font: 14px;border-radius: 4px;}");

    ui->del->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-删除-默认.png);background-color:rgb(233, 233, 233);background-repeat: no-repeat;background-position:left;color:rgb(0, 0, 0);font: 14px;border-radius: 4px;}"
                           "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-删除-悬停点击.png);background-color:rgb(107, 142, 235);background-repeat: no-repeat;background-position:left;color:rgb(0, 0, 0);font: 14px;border-radius: 4px;}"
                           "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-删除-悬停点击.png);background-color:rgb(65, 95, 196);background-repeat: no-repeat;background-position:left;border:none;color:rgb(0, 0, 0);font: 14px;border-radius: 4px;}");
    ui->clean->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-清空-默认.png);background-color:rgb(233, 233, 233);background-repeat: no-repeat;background-position:left;color:rgb(0, 0, 0);font: 14px;border-radius: 4px;}"
                           "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-清空-悬停点击.png);background-color:rgb(107, 142, 235);background-repeat: no-repeat;background-position:left;color:rgb(0, 0, 0);font: 14px;border-radius: 4px;}"
                           "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-清空-悬停点击.png);background-color:rgb(65, 95, 196);background-repeat: no-repeat;background-position:left;border:none;color:rgb(0, 0, 0);font: 14px;border-radius: 4px;}");
    ui->mkdir->setStyleSheet("QPushButton{background-image: url(:/new/prefix1/pic/icon-新建文件-默认.png);background-color:rgb(233, 233, 233);background-repeat: no-repeat;background-position:left;color:rgb(0, 0, 0);font: 14px;border-radius: 4px;}"
                           "QPushButton:hover{background-image: url(:/new/prefix1/pic/icon-新建文件-悬停点击.png);background-color:rgb(107, 142, 235);background-repeat: no-repeat;background-position:left;color:rgb(0, 0, 0);font: 14px;border-radius: 4px;}"
                           "QPushButton:pressed{background-image: url(:/new/prefix1/pic/icon-新建文件-悬停点击.png);background-color:rgb(65, 95, 196);background-repeat: no-repeat;background-position:left;border:none;color:rgb(0, 0, 0);font: 14px;border-radius: 4px;}");
    ui->filefilter->setStyleSheet("QPushButton{background-color:rgb(255, 255, 255);background-repeat: no-repeat;border:none;color:rgb(65, 95, 196);font: 14px;}");

    ui->label_2->setFixedSize(75,30);
    ui->label_3->setFixedSize(75,30);
    ui->comboBox->setFixedSize(310,30);
    ui->comboBox_2->setFixedSize(310,30);
    ui->burner_setting->setFixedSize(80,30);
    ui->burner_setting->setStyleSheet("QPushButton{background-color:rgb(233, 233, 233);font: 14px;border-radius: 4px;}"
                           "QPushButton:hover{background-color:rgb(107, 142, 235);font: 14px;border-radius: 4px;}"
                           "QPushButton:pressed{border:none;background-color:rgb(65, 95, 196);font: 14px;border-radius: 4px;}");

    ui->start_burner->setFixedSize(140,45);
    ui->start_burner->setStyleSheet("QPushButton{background-color:rgb(61, 107, 229);font: 14px;border-radius: 4px;color: rgb(255,255,255);}"
                           "QPushButton:hover{background-color:rgb(107, 142, 235);font: 14px;border-radius: 4px;color: rgb(255,255,255);}"
                           "QPushButton:pressed{border:none;background-color:rgb(65, 95, 196);font: 14px;border-radius: 4px;color: rgb(255,255,255);}");

    data_model = new QFileSystemModel;
    data_model->setRootPath(QDir::currentPath());
    data_model->setRootPath("/home/test");


//    QDir myFile("../burn-test/pic/");
//    QStandardItemModel *itemmodel = new QStandardItemModel();
//    ui->treeView->setModel(itemmodel);
//    QStandardItem *item = new QStandardItem();
//    items.push_back(item);//添加QStandardItemModel信息

//    itemmodel->appendRow(items);//插入父节点信息
//    QList<QStandardItem *> childItems;//List容器
//    int index;
//    QString filename;
//    for(int i=2 ; i<myFile.count(); i++)
//    {
//        filename=myFile[i];//myFile[i]为第i个文件名，前两个分别是"."和".."目录标志，在这里不使用
//        index=filename.lastIndexOf(".");//设置"."的标记，一般扩展名在最后一个"."之后
//        filename.truncate(index);//去除扩展名
//        QStandardItem *item = new QStandardItem(filename);
//        childItems.push_back(item);//插入数据
//    }
//        items.at(0)->appendRows(childItems);//插入子节点
    //ui->treeView->setRootIndex(data_model->index(QDir::currentPath()));

    ui->treeView->setModel(data_model);
    ui->treeView->setRootIndex(data_model->index("/home/test/"));
    ui->treeView->setColumnWidth(0,400);
/*
    QStringList list;
    list.append("name");
    list.append("size");
    list.append("t
ype");
    list.append("path");

    QStandardItemModel *itemmodel = new QStandardItemModel();
    itemmodel->setHorizontalHeaderLabels(list);
*/
//    QStandardItemModel *itemmodel = new QStandardItemModel();
//    ui->treeView->setModel(itemmodel);
//    QStandardItem *item = new QStandardItem();
//    items.push_back(item);

}

/*
 * if(ui->combox == "")
 * button text = "choice path"
*/

void p_data::on_add_clicked()
{
    QString s = QFileDialog::getExistingDirectory(this, "open file dialog", "/home/test");
    qDebug() << "filenames: " << s;

    //ui->treeView->setRootIndex(data_model->index(s));
}

void p_data::on_mkdir_clicked()
{
    QModelIndex index = ui->treeView->currentIndex();
    if (!index.isValid()) {
        return;
    }
    QString dirName = QInputDialog::getText(this,
                                            tr("Create Directory"),
                                            tr("Directory name"));
    if (!dirName.isEmpty()) {
        if (!data_model->mkdir(index, dirName).isValid()) {
            QMessageBox::information(this,
                                     tr("Create Directory"),
                                     tr("Failed to create the directory"));
        }
    }
}

void p_data::on_del_clicked()
{
    QModelIndex index = ui->treeView->currentIndex();
        if (!index.isValid()) {
            return;
        }
        bool ok;
        if (data_model->fileInfo(index).isDir()) {
            ok = data_model->rmdir(index);
        } else {
            ok = data_model->remove(index);
        }
        if (!ok) {
            QMessageBox::information(this,
                             tr("Remove"),
                             tr("Failed to remove %1").arg(data_model->fileName(index)));

        }
}

void p_data::on_clean_clicked()
{

}

void p_data::on_filefilter_clicked()
{

}

void p_data::on_burner_setting_clicked()
{
    if (ui->burner_setting->text() == "burner setting"){
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
    append->setChecked(true);
    burn_proof = new QCheckBox("use Burn-Proof(recommended)");
    burn_proof->setChecked(true);
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
    }else {
        QString s = QFileDialog::getOpenFileName(this, "open file dialog", "/home/test", "iso file(*.iso*.udf)");
        qDebug() << "filenames: " << s;
        ui->treeView->setRootIndex(data_model->index(s));
    }
}

void p_data::on_start_burner_clicked()
{

    qDebug("%s %d %d %d", pro.get_burn_speed().toLatin1().data(), pro.get_burn_append(), pro.get_burn_proof(), pro.get_simulation());
    if (ui->burner_setting->text() == "burner setting")
    {
        pro.set_burn_disk(ui->comboBox_2->currentText());

    }else {
        pro.set_copy_iso(ui->comboBox_2->currentText());

    }
}

void p_data::setting_exit()
{
    burn_setting->close();
}
void p_data::setting_ok()
{
    pro.set_burn_speed(speed->currentText());
    pro.set_burn_append(append->isChecked());
    pro.set_burn_proof(burn_proof->isChecked());
    pro.set_simulation(simulation->isChecked());
    burn_setting->close();
}
