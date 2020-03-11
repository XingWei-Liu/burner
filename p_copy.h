#ifndef P_COPY_H
#define P_COPY_H

#include <QWidget>
#include <QDialog>
#include <QComboBox>
#include <QCheckBox>
#include <QDebug>
#include <QFileDialog>
#include "property.h"

namespace Ui {
class p_copy;
}

class p_copy : public QWidget
{
    Q_OBJECT

public:
    explicit p_copy(QWidget *parent = nullptr);
    ~p_copy();
    void create_ui();
private slots:

    void on_file_clicked();

    void on_create_clicked();

    void on_burn_setting_clicked();
    void setting_exit();
    void setting_ok();

private:
    Ui::p_copy *ui;
    class property pro;
    QDialog *burn_setting;
    QComboBox *speed;
    QCheckBox *append;
    QCheckBox *burn_proof;
    QCheckBox *simulation;

};

#endif // P_COPY_H
