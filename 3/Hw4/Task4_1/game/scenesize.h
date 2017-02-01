#pragma once

#include <QtGlobal>

struct SceneSize
{
    SceneSize(qreal w, qreal h):
        width(w),
        height(h)
    {}
    qreal width;
    qreal height;
};
