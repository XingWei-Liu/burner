#ifndef P_IMAGE_H
#define P_IMAGE_H

#include <QWidget>
#include <QDialog>
#include <QComboBox>
#include <QCheckBox>
#include <QDebug>
#include <QFileDialog>
#include "property.h"

namespace Ui {
class p_image;
}

class p_image : public QWidget
{
    Q_OBJECT

public:
    explicit p_image(QWidget *parent = nullptr);
    ~p_image();
    void create_ui();
private slots:
    void on_file_clicked();

    void on_burner_setting_clicked();

    void on_start_burner_clicked();

    void setting_exit();
    void setting_ok();

private:
    Ui::p_image *ui;
    class property pro;
    QDialog *burn_setting;
    QComboBox *speed;
    QCheckBox *append;
    QCheckBox *burn_proof;
    QCheckBox *simulation;
};

#endif // P_IMAGE_H
