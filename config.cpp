#include "config.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

Config *Config::my = NULL;

Config::Config()
{
    assert(my==NULL);
    my=this;
    LoadDefoultValues();
}

void Config::LoadDefoultValues()
{
    show_about = true;
    distance_left_side = 0;
    distance_right_side = 1024;
    height = 1;
    line_fetching_fr = 300;
    capture_time = 0;
    save_output = false;
    file_path = "";
    file_name = "capture?.png";
}

QString Config::LoadFromFile(const QString &name)
{
    QFile f(name);

    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return f.errorString();
    }

    QTextStream ts(&f);
    QString token;

    while(!ts.atEnd())
    {
        ts>>token;
        if(token=="show_about")
        {
            ts>>token;
            if(token=="=")
            {
                ts>>token;
                show_about=token.toInt();
            }
        }
        if(token=="distance_left_side")
        {
            ts>>token;
            if(token=="=")
            {
                ts>>token;
                distance_left_side=token.toInt();
            }
        }
        if(token=="distance_right_side")
        {
            ts>>token;
            if(token=="=")
            {
                ts>>token;
                distance_right_side=token.toInt();
            }
        }
        if(token=="height")
        {
            ts>>token;
            if(token=="=")
            {
                ts>>token;
                height=token.toInt();
            }
        }
        if(token=="line_fetching_fr")
        {
            ts>>token;
            if(token=="=")
            {
                ts>>token;
                line_fetching_fr=token.toInt();
            }
        }
        if(token=="capture_time")
        {
            ts>>token;
            if(token=="=")
            {
                ts>>token;
                capture_time=token.toInt();
            }
        }
        if(token=="save_output")
        {
            ts>>token;
            if(token=="=")
            {
                ts>>token;
                save_output=token.toInt();
            }
        }
        if(token=="file_path")
        {
            ts>>token;
            if(token=="=")
            {
                ts>>token;
                file_path=token;
            }
        }
        if(token=="file_name")
        {
            ts>>token;
            if(token=="=")
            {
                ts>>token;
                file_name=token;
            }
        }
    }

    f.close();
    return QString();
}

QString Config::SaveToFile(const QString &name)
{
    QFile f(name);

    if(!f.open(QIODevice::WriteOnly | QIODevice::Text | QFile::Truncate))
    {
        return f.errorString();
    }

    QTextStream ts(&f);

    ts<<"show_about = "<<show_about<<"\n";
    ts<<"distance_left_side = "<<distance_left_side<<"\n";
    ts<<"distance_right_side = "<<distance_right_side<<"\n";
    ts<<"height = "<<height<<"\n";
    ts<<"line_fetching_fr = "<<line_fetching_fr<<"\n";
    ts<<"capture_time = "<<capture_time<<"\n";
    ts<<"save_output = "<<save_output<<"\n";
    ts<<"file_path = "<<file_path<<"\n";
    ts<<"file_name = "<<file_name<<"\n";

    f.close();
    return QString();
}
