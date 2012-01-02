#include "cameraenumerator.h"

void CameraEnumerator::start()
{
    num_cameras=0;
    QThread::start();
}

void CameraEnumerator::stop()
{
    terminate();
    num_cameras=0;
}

bool CameraEnumerator::getCameraID(int index, char id[MAX_CAMERA_ID_LEN])
{
    if(num_cameras==0 || index<0 || index>=num_cameras)
    {
        return false;
    }

    return cam_con.GetCameraID(index, id, MAX_CAMERA_ID_LEN);
}

CSpyder3GigEInterface *CameraEnumerator::getCamera(int index)
{
    char id[MAX_CAMERA_ID_LEN];

    if(getCameraID(index, id)==true)
    {
        return getCamera(id);
    }

    return NULL;
}

CSpyder3GigEInterface *CameraEnumerator::getCamera(char id[MAX_CAMERA_ID_LEN])
{
    if(cam_con.Open(id)==false)
    {
        return NULL;
    }

    return cam_con.GetCamera();
}

void CameraEnumerator::run()
{
    num_cameras=cam_con.EnumerateCameras();
    emit finished();
}
