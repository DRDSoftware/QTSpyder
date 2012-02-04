#include "camera.h"
#include "capturedimage.h"

Camera::Camera()
{
    cam=NULL;
    image=NULL;
}

Camera::~Camera()
{
    Disconnect();
}

bool Camera::Connect(const char id[MAX_CAMERA_ID_LEN])
{
    if(conn.Open(id)==true)
    {
        cam=conn.GetCamera();
        return true;
    }

    return false;
}

void Camera::Disconnect()
{
    if(isConnected())
    {
        conn.Disconnect();
        cam=NULL;
    }
}

float Camera::getTemperature()
{
    float retval;
    cam->GetCameraTemperature(retval);
    return retval;
}

float Camera::getVoltage()
{
    float retval;
    cam->GetCameraVoltage(retval);
    return retval;
}

unsigned long Camera::getSizeWidth()
{
    unsigned long v;
    if(cam->GetSizeX(v)!=CY_RESULT_OK){
        v=-1;
        printError();
        conn.Disconnect();
        cam=NULL;
    }
    return v;
}

unsigned long Camera::getSizeHeight()
{
    unsigned int v;
    if(cam->GetSizeY(v)!=CY_RESULT_OK){
        v=-1;
        printError();
        conn.Disconnect();
        cam=NULL;
    }
    return v;
}

unsigned long Camera::getPixelByteSize()
{
    unsigned long v;
    if(cam->GetPixelByteSize(v)!=CY_RESULT_OK){
        v=-1;
        printError();
        conn.Disconnect();
        cam=NULL;
    }
    return v;
}

void Camera::printError()
{
    CyErrorInfo errInfo;
    cam->GetErrorInfo(&errInfo);
    qDebug()<<"Errore esecuzione comando telcamera\n"<<"CyResult: "<<errInfo.mResult<<
              "\n"<<errInfo.mSourceFile<<":"<<errInfo.mSourceLine<<"\n"<<
              "Message: "<<errInfo.mMessage;
}

void Camera::acquireImage(CapturedImage *image)
{
    if(!isConnected())
        return;

    this->image=image;
    QThread::start();
}

void Camera::run()
{
    CyGrabber &grabber=cam->GetGrabber();
    if(grabber.Grab(CyChannel(0), image->getCyBuffer(), 0)==CY_RESULT_OK)
    {
        qDebug()<<"Acquisizione riuscita";
        emit finishedAcquiring(true);
    }
    else
    {
        qDebug()<<"Acquisizione fallita!!!";
        emit finishedAcquiring(false);
    }
}
