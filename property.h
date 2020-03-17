#ifndef PROPERTY_H
#define PROPERTY_H

#include <QString>
#include <QComboBox>
#include <QCheckBox>
#include <QLineEdit>

class property
{
public:
    void set_clean_disk(QString ret);
    void set_check_disk(QString ret);
    void set_md5_check(bool ret);
    void set_md5_file(QString ret);

    void set_filter_hide(bool ret);
    void set_filter_link(bool ret);
    void set_filter_deform_link(bool ret);

    void set_burn_speed(QString ret);
    void set_burn_append(bool ret);
    void set_burn_proof(bool ret);
    void set_simulation(bool ret);

    void set_burn_iso(QString ret);
    void set_burn_disk(QString ret);
    void set_copy_disk(QString ret);
    void set_copy_iso(QString ret);
    void set_copy_to_disk(QString ret);

    QString get_clean_disk();
    QString get_check_disk();
    bool get_md5_check();
    QString get_md5_file();

    bool get_filter_hide();
    bool get_filter_link();
    bool get_filter_deform_link();

    QString get_burn_speed();
    bool get_burn_append();
    bool get_burn_proof();
    bool get_simulation();

    QString get_burn_iso();
    QString get_burn_disk();
    QString get_copy_disk();
    QString get_copy_iso();
    QString get_copy_to_disk();


private:
    QString clean_disk;
    QString check_disk;
    bool md5_check;
    QString md5_file;

    bool filter_hide;
    bool filter_link;
    bool filter_deform_link;

    QString burn_speed;
    bool burn_append;
    bool burn_proof;
    bool simulation;

    QString burn_iso;
    QString burn_disk;

    QString copy_disk;
    QString copy_iso;
    QString copy_to_disk;
};



#endif // PROPERTY_H
