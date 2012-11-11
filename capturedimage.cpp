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
    QVector<QRgb> colormap(256);

    for(int i=0; i<256; i++)
    {
        colormap[i]=(0xFF000000 | (((unsigned char)(i))<<16) | (((unsigned char)(i))<<8) | ((unsigned char)(i)));
    }

    width=cam->getSizeWidth();
    height=cam->getSizeHeight();
    pixel_size=cam->getPixelByteSize();

    qDebug()<<"Creata CapturedImage: "<<width<<"x"<<height<<"x"<<pixel_size*8;

    long size = width*height*pixel_size;

    unsigned char *data=new unsigned char[size];
    qimage=new QImage((const unsigned char *)data, width, height, QImage::Format_Indexed8);
    qimage->setColorTable(colormap);
    delete [] data;

    buffer.SetBuffer(qimage->bits(), size);

    created=true;
}

void CapturedImage::destroy()
{
    if(created)
    {
        delete qimage;
        qimage=NULL;
        created=false;
    }
}

bool CapturedImage::save(const char *name)
{
    return qimage->save(name, "PNG", 100);
}
