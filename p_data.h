#ifndef P_DATA_H
#define P_DATA_H

#include <QWidget>
#include <QFileSystemModel>
#include <QComboBox>
#include <QCheckBox>

#include "property.h"

namespace Ui {
class p_data;
}

class p_data : public QWidget
{
    Q_OBJECT

public:
    explicit p_data(QWidget *parent = nullptr);
    ~p_data();

    void create_ui();
private slots:
    void on_add_clicked();

    void on_mkdir_clicked();

    void on_del_clicked();

    void on_clean_clicked();

    void on_filefilter_clicked();

    void on_burner_setting_clicked();

    void on_start_burner_clicked();

    void setting_exit();
    void setting_ok();

private:
    Ui::p_data *ui;
    class property pro;
    QFileSystemModel *data_model;
    QDialog *burn_setting;
    QComboBox *speed;
    QCheckBox *append;
    QCheckBox *burn_proof;
    QCheckBox *simulation;
};

#endif // P_DATA_H
