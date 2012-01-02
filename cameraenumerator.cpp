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

void CameraEnumerator::finished()
{
}

void CameraEnumerator::run()
{
    num_cameras=cam_con.EnumerateCameras();
    emit finished();
}
