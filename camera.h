#ifndef CAMERA_H
#define CAMERA_H

#include "cameraenumerator.h"

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

protected:
    CCameraConnection conn;
    CSpyder3GigEInterface *cam;
};

#endif // CAMERA_H
