#include "capturedimage.h"
#include <QDebug>
#include <QRgb>
#include <QVector>

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
    QVector<QRgb> colormap;

    for(int i=0; i<256; i++)
    {
        colormap.push_back(0xFF000000 & ((unsigned char)(i)<<16) & ((unsigned char)(i)<<8) & (unsigned char)(i));
    }

    width=cam->getSizeWidth();
    height=cam->getSizeHeight();
    pixel_size=cam->getPixelByteSize();

    long size = width*height*pixel_size;

    unsigned char *data=new unsigned char[size];
    buffer.SetBuffer(data, size);
    qimage=new QImage((const unsigned char *)data, width, height, QImage::Format_Indexed8);
    qimage->setColorTable(colormap);
    created=true;
}

void CapturedImage::destroy()
{
    if(created)
    {
        delete qimage;
        delete [] buffer.GetBuffer();
        qimage=NULL;
        created=false;
    }
}
