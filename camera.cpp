#include "camera.h"

Camera::Camera()
{
    cam=NULL;
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
