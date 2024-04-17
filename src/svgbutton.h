#ifndef SVGBUTTON_H
#define SVGBUTTON_H

#include <QObject>
#include <QPushButton>
#include <qsvgrenderer.h>
#include <qvariantanimation.h>

class SvgButton : public QPushButton
{
    Q_OBJECT

    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged FINAL);
    Q_PROPERTY(QColor color_default READ color_default WRITE setColor_default NOTIFY color_default_Changed FINAL)
    Q_PROPERTY(QColor color_hover READ color_hover WRITE setColor_hover NOTIFY color_hover_Changed FINAL)

public:
    SvgButton(QWidget *parent = nullptr);

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event) override;


    // QWidget interface
public:
    void EnterHover();
    void LeaveHover();
    void SetColor(const QVariant& color);

    void SetPath(QString path);
    // QWidget interface
protected:
    virtual void resizeEvent(QResizeEvent *event) override;
    QSvgRenderer* svg_renderer;
    QColor target_color;
    QImage image;
    QVariantAnimation animation;
    // QObject interface
public:
    bool event(QEvent *event) override;
    QString path() const;
    void setPath(const QString &newPath);
    QColor color_default() const;
    void setColor_default(const QColor &newColor_default);

    QColor color_hover() const;
    void setColor_hover(const QColor &newColor_hover);

signals:
    void pathChanged();
    void color_default_Changed();

    void color_hover_Changed();

private:
    QString m_path;
    QColor m_color_default;
    QColor m_color_hover;
};

#endif // SVGBUTTON_H
