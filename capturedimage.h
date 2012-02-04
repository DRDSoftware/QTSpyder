#ifndef CAPTUREDIMAGE_H
#define CAPTUREDIMAGE_H

#include "CyUserBuffer.h"
#include "camera.h"
#include <QImage>

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

    bool save(const char *name);

    /// Return the the QImage object containing the image
    inline const QImage *getImage() const
    {
        return qimage;
    }

    inline CyUserBuffer &getCyBuffer() const
    {
        return const_cast<CyUserBuffer &>(buffer);
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
    QImage *qimage;
    bool created;

    /// Width of the image captured
    unsigned long width;
    /// Height of the image captured
    unsigned long height;
    /// Size in byte of one pixel
    unsigned long pixel_size;
};

#endif // CAPTUREDIMAGE_H
