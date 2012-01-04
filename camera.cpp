#include "camera.h"

Camera::Camera()
{
    cam=NULL;
}

Camera::~Camera()
{
    Disconnect();
}

bool Camera::Connect(char id[MAX_CAMERA_ID_LEN])
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
