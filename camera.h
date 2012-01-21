#ifndef CAMERA_H
#define CAMERA_H

#include "cameraenumerator.h"
#include <QDebug>

class Camera
{
public:
    Camera();
    virtual ~Camera();

    bool Connect(const char id[]);
    bool Connect(const QString *string)
    {
        return Connect(string->toStdString().data());
    }

    void Disconnect();

    inline bool isConnected()
    {
        return (cam!=NULL)?true:false;
    }

    float getTemperature();

    float getVoltage();
    unsigned long getSizeWidth();

    unsigned long getSizeHeight();

    unsigned long getPixelByteSize();

protected:
    CCameraConnection conn;
    CSpyder3GigEInterface *cam;

    void printError();
};

#endif // CAMERA_H
