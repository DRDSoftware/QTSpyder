#include "capturedimage.h"
#include <QDebug>

CapturedImage::CapturedImage(): buffer(NULL, 0)
{
    created=false;
}

CapturedImage::~CapturedImage()
{
    destroy();
}

void CapturedImage::create(Camera *cam)
{
    width=cam->getSizeWidth();
    height=cam->getSizeHeight();
    pixel_size=cam->getPixelByteSize();

    long size = width*height*pixel_size;

    buffer.SetBuffer(new unsigned char[size], size);
    created=true;
}

void CapturedImage::destroy()
{
    if(created)
    {
        delete [] buffer.GetBuffer();
        created=false;
    }
}
