
#include "property.h"

void property::set_clean_disk(QString ret)
{
    clean_disk = "";
    clean_disk += ret;
}
void property::set_check_disk(QString ret)
{
    check_disk = "";
    check_disk += ret;
}
void property::set_md5_check(bool ret)
{
    md5_check = ret;
}
void property::set_md5_file(QString ret)
{
    md5_file = "";
    md5_file = ret;
}
void property::set_burn_speed(QString ret)
{
    burn_speed = "";
    burn_speed += ret;
}
void property::set_burn_append(bool ret)
{
    burn_append = ret;
}
void property::set_burn_proof(bool ret)
{
    burn_proof = ret;
}
void property::set_simulation(bool ret)
{
    simulation = ret;
}
void property::set_burn_iso(QString ret)
{
    burn_iso = "";
    burn_iso += ret;
}
void property::set_burn_disk(QString ret)
{
    burn_disk = "";
    burn_disk += ret;
}
void property::set_copy_disk(QString ret)
{
    copy_disk = "";
    copy_disk += ret;
}
void property::set_copy_iso(QString ret)
{
    copy_iso = "";
    copy_iso += ret;
}
void property::set_copy_to_disk(QString ret)
{
    copy_to_disk = "";
    copy_to_disk += ret;
}
void property::set_filter_hide(bool ret)
{
    filter_hide = ret;
}
void property::set_filter_link(bool ret)
{
    filter_link = ret;
}
void property::set_filter_deform_link(bool ret)
{
    filter_deform_link = ret;
}


QString property::get_clean_disk()
{
    return clean_disk;
}
QString property::get_check_disk()
{
    return check_disk;
}
bool property::get_md5_check()
{
    return md5_check;
}
QString property::get_md5_file()
{
    return md5_file;
}
QString property::get_burn_speed()
{
    return burn_speed;
}
bool property::get_burn_append()
{
    return burn_append;
}
bool property::get_burn_proof()
{
    return burn_proof;
}
bool property::get_simulation()
{
    return simulation;
}
QString property::get_burn_iso()
{
    return burn_iso;
}
QString property::get_burn_disk()
{
    return burn_disk;
}
QString property::get_copy_disk()
{
    return copy_disk;
}
QString property::get_copy_iso()
{
    return copy_iso;
}
QString property::get_copy_to_disk()
{
    return copy_to_disk;
}
bool property::get_filter_hide()
{
    return filter_hide;
}
bool property::get_filter_link()
{
    return filter_link;
}
bool property::get_filter_deform_link()
{
    return filter_deform_link;
}
