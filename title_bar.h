#ifndef TITLE_BAR_H
#define TITLE_BAR_H
#include <QWidget>
#include <QToolButton>
#include <QLabel>
#include <QPushButton>
#include <QComboBox>
#include <QCheckBox>
#include <QLineEdit>

#include "property.h"


class TitleBar : public QWidget
{
    Q_OBJECT

public:
    explicit TitleBar(QWidget *parent = 0);
    ~TitleBar();

protected:

    // 双击标题栏进行界面的最大化/还原
    virtual void mouseDoubleClickEvent(QMouseEvent *event);

    // 进行鼠界面的拖动
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    // 设置界面标题与图标
    virtual bool eventFilter(QObject *obj, QEvent *event);

private slots:

    // 进行最小化、最大化/还原、关闭操作
    void onClicked();
    void popup();
    void clean();
    void md5();
    void filter();
    void help();
    void about();
    void clean_exit();
    void check_exit();
    void filter_exit();
    void clean_ok();
    void check_ok();

private:
    QPoint mLastMousePosition;
    bool mMoving;
    // 最大化/还原
    void updateMaximize();

private:
    class property pro;
    QComboBox *clean_combo;
    QComboBox *check_combo;
    QCheckBox *md5_check;
    QLineEdit *md5_file;

    QCheckBox *hide_check;
    QCheckBox *link_check;
    QCheckBox *deform_link;

    QDialog *clean_dialog;
    QDialog *check_dialog;
    QDialog *filter_dialog;
    QLabel *m_pIconLabel;
    QLabel *m_pTitleLabel;
    QToolButton *m_pMenubutton;
    QPushButton *m_pMinimizeButton;
    QPushButton *m_pMaximizeButton;
    QPushButton *m_pCloseButton;
};
#endif // TITLE_BAR_H
