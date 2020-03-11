#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QLabel>
#include "p_data.h"
#include "p_image.h"
#include "p_copy.h"

class QPushButton;
namespace Ui {
class Widget;
}


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void create_ui();

private slots:

    void on_data_burner_clicked();

    void on_image_burner_clicked();

    void on_copy_image_clicked();

private:
    Ui::Widget *ui;

    QStackedWidget *tabWidget;
    //QLabel *m_pIconLabel;
    //QLabel *m_pTitleLabel;
    QPushButton *data_burner;
    QPushButton *image_burner;
    QPushButton *copy_image;
    p_data *data_page;
    p_image *image_page;
    p_copy *copy_page;
};

#endif // WIDGET_H
