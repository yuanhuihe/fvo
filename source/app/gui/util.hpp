#pragma once
#include <opencv\cv.h>
#include <qimage.h>
namespace yuanhui
{
    class util
    {
    private:
        util() {};
        ~util() {};
    public:
        static bool  IplImage2QImage(IplImage *src, QImage* des)
        {
            if (des == nullptr) return false;

            int h = src->height;
            int w = src->width;
            int channels = src->nChannels;
            char *data = src->imageData;

            if (des->height() != h || des->width() != w || des->format() != QImage::Format_ARGB32)
            {
                delete des;
                des = new QImage(w, h, QImage::Format_ARGB32);
            }

            for (int y = 0; y < h; y++, data += src->widthStep) {
                for (int x = 0; x < w; x++) {
                    char r, g, b, a = 0;

                    if (channels == 1) {
                        r = data[x * channels];
                        g = data[x * channels];
                        b = data[x * channels];
                    }
                    else if (channels == 3 || channels == 4) {
                        r = data[x * channels + 2];
                        g = data[x * channels + 1];
                        b = data[x * channels];
                    }

                    if (channels == 4) {
                        a = data[x * channels + 3];
                        des->setPixel(x, y, qRgba(r, g, b, a));
                    }
                    else {
                        des->setPixel(x, y, qRgb(r, g, b));
                    }
                }
            }
            
            true;
        }
    };

} // namespace yuanhui
