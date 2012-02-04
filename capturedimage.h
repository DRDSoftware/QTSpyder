#ifndef CAPTUREDIMAGE_H
#define CAPTUREDIMAGE_H

#include "CyUserBuffer.h"
#include "camera.h"

class CapturedImage
{
public:
    CapturedImage();
    virtual ~CapturedImage();

    /// Create the object
    /// \param cam Pointer to the camera from which
    ///            you will acquire the image
    void create(Camera *cam);

    void destroy();

    /// Return the pointer to first pixel in the image
    inline const unsigned char *getRowData() const
    {
        return buffer.GetBuffer();
    }

    /// Return the width of the image captured
    inline const unsigned long getWidth() const
    {
        return width;
    }

    /// Retrun the height of the image captured
    inline const unsigned long getHeight() const
    {
        return height;
    }

    /// Return the size in byte of one pixel
    inline const unsigned long getPixelSize() const
    {
        return pixel_size;
    }

protected:
    CyUserBuffer buffer;
    bool created;

    /// Width of the image captured
    unsigned long width;
    /// Height of the image captured
    unsigned long height;
    /// Size in byte of one pixel
    unsigned long pixel_size;
};

#endif // CAPTUREDIMAGE_H
