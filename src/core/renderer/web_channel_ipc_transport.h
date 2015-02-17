/****************************************************************************
**
** Copyright (C) 2015 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the QtWebEngine module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef NAVIGATOR_QT_EXTENSION_H
#define NAVIGATOR_QT_EXTENSION_H

#include "base/values.h"
#include "content/public/renderer/render_view_observer.h"
#include <QtCore/qcompilerdetection.h>

namespace v8 {
class Extension;
}

class WebChannelIPCTransport : public content::RenderViewObserver {
public:
    static v8::Extension* getV8Extension();

    WebChannelIPCTransport(content::RenderView *);

private:
    void dispatchWebChannelMessage(const std::vector<char> &binaryJSON);
    virtual bool OnMessageReceived(const IPC::Message &message) Q_DECL_OVERRIDE;
};

#endif // NAVIGATOR_QT_EXTENSION_H