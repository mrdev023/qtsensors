// Copyright (C) 2016 Alexander Volkov <a.volkov@rusbitech.ru>
// Copyright (C) 2016 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR LGPL-3.0-only OR GPL-2.0-only OR GPL-3.0-only

#ifndef IIOSENSORPROXY_PROXIMITYSENSOR_H
#define IIOSENSORPROXY_PROXIMITYSENSOR_H

#include "iiosensorproxysensorbase.h"

#include <qproximitysensor.h>

class NetHadessSensorProxyInterface;

class IIOSensorProxyProximitySensor : public IIOSensorProxySensorBase
{
    Q_OBJECT
public:
    static char const * const id;

    IIOSensorProxyProximitySensor(QSensor *sensor);
    ~IIOSensorProxyProximitySensor();

    void start() override;
    void stop() override;

protected:
    void updateProperties(const QVariantMap &changedProperties) override;

private:
    void updateProximityNear(bool proximityNear);

    QProximityReading m_reading;
    NetHadessSensorProxyInterface *m_sensorProxyInterface;
};

#endif // IIOSENSORPROXY_PROXIMITYSENSOR_H
