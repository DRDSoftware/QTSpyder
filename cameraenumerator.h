#ifndef CAMERAENUMERATOR_H
#define CAMERAENUMERATOR_H

#include <CameraConnection.h>
#include <Spyder3GigEInterface.h>
#include <QThread>

/// Max length of one camera id in characters
#define MAX_CAMERA_ID_LEN 65

/// Provide the support for search and identify the cameras
/// correctly connected to the pc, the search is executed in
/// asyncronous mode
class CameraEnumerator: protected QThread
{
public:
    virtual ~CameraEnumerator() {}

    /// Start the search
    void start();

    /// Stop the search
    void stop();

    /// Return True if the search is in progress
    inline bool isSearching()
    {
        return isRunning();
    }

    /// Return the number of cameras found
    inline int getNumCameras()
    {
        return num_cameras;
    }

    /// Get id of one camera found
    /// \param [in] index Index of the camera
    /// \param [out] id String that will contain the id of the camera
    /// \retval True in case of success
    /// \retval False in case of failure
    bool getCameraID(int index, char id[MAX_CAMERA_ID_LEN]);

signals:
    /// Signal generated when the search of cameras ended
    void finished() {}

protected:
    void run();

    /// DALSA SDK Class for enumerate the cameras
    /// and retrieve their ids
    CCameraConnection cam_con;
    /// Numbers of cameras found
    int num_cameras;
};

#endif // CAMERAENUMERATOR_H
