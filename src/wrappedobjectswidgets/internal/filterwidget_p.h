/****************************************************************************
**
** Copyright (C) 2012 Sandro S. Andrade <sandroandrade@kde.org>
** Contact: http://www.qt-project.org/
**
** This file is part of the QtWrappedObjectsWidgets module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia  LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/
#ifndef FILTERWIDGET_P_H
#define FILTERWIDGET_P_H

#include "../qtwrappedobjectswidgetsglobal.h"

#include <QtWidgets/QLineEdit>
#include <QtWidgets/QToolButton>

#define ICONBUTTON_SIZE 16

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(QtWrappedObjectsWidgets)

class Q_WRAPPEDOBJECTSWIDGETS_EXPORT HintLineEdit : public QLineEdit
{
    Q_OBJECT

public:
    explicit HintLineEdit(QWidget *parent = 0);

    bool refuseFocus() const;
    void setRefuseFocus(bool v);

protected:
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void focusInEvent(QFocusEvent *e);

private:
    const Qt::FocusPolicy m_defaultFocusPolicy;
    bool m_refuseFocus;
};

// IconButton: This is a simple helper class that represents clickable icons

class Q_WRAPPEDOBJECTSWIDGETS_EXPORT IconButton: public QToolButton
{
    Q_OBJECT
    Q_PROPERTY(float fader READ fader WRITE setFader)

public:
    IconButton(QWidget *parent);
    void paintEvent(QPaintEvent *event);
    float fader() { return m_fader; }
    void setFader(float value) { m_fader = value; update(); }
    void animateShow(bool visible);

private:
    float m_fader;
};

// FilterWidget: For filtering item views, with reset button Uses HintLineEdit.

class Q_WRAPPEDOBJECTSWIDGETS_EXPORT FilterWidget : public QWidget
{
    Q_OBJECT

public:
    enum LayoutMode {
        // For use in toolbars: Expand to the right
        LayoutAlignRight,
        // No special alignment
        LayoutAlignNone
    };

    explicit FilterWidget(QWidget *parent = 0, LayoutMode lm = LayoutAlignNone);

    QString text() const;
    void resizeEvent(QResizeEvent *);
    bool refuseFocus() const; // see HintLineEdit
    void setRefuseFocus(bool v);

Q_SIGNALS:
    void filterChanged(const QString &);

public Q_SLOTS:
    void reset();

private Q_SLOTS:
    void checkButton(const QString &text);

private:
    QIcon createIconSet(const QString &name);

    HintLineEdit *m_editor;
    IconButton *m_button;
    int m_buttonwidth;
    QString m_oldText;
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // FILTERWIDGET_P_H

