#ifndef CAMERA_H
#define CAMERA_H

#include "cameraenumerator.h"
#include <QDebug>
#include <QThread>

class CapturedImage;

class Camera: public QThread
{
private:
    Q_OBJECT

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

    void acquireImage(CapturedImage *image);

    /// Return True if the camera is acquiring an image
    inline bool isAcquiring()
    {
        return isRunning();
    }

signals:
    void finishedAcquiring(bool);

protected:
    void run();

    CCameraConnection conn;
    CSpyder3GigEInterface *cam;

    void printError();

private:
    /// Used to pass param to run method
    CapturedImage *image;
};

#endif // CAMERA_H
