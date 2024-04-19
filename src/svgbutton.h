/** @file svgbutton.h
 * @brief Custom PushButton for svg rendering with hover effects
 * 
 * @author Jakub Miko 
*/
#pragma once

#include <QObject>
#include <QPushButton>
#include <qsvgrenderer.h>
#include <qvariantanimation.h>

/**
 * @brief Custom PushButton for svg rendering with hover effects
 *
 * While Qt does support SvgWidgets, it doesnt allow for manipulating color.
 */
class SvgButton : public QPushButton
{
    Q_OBJECT
    Q_PROPERTY(QString path READ path WRITE setPath NOTIFY pathChanged FINAL); // path for the rendered svg
    Q_PROPERTY(QColor color_default READ color_default WRITE setColor_default NOTIFY color_default_Changed FINAL); // the idle color of the widget
    Q_PROPERTY(QColor color_hover READ color_hover WRITE setColor_hover NOTIFY color_hover_Changed FINAL); // the hovered color of the widget

public:
    SvgButton(QWidget *parent = nullptr);


protected:
    virtual void paintEvent(QPaintEvent *event) override;



private: // for internal use only
    void EnterHover(); // start hover animation
    void LeaveHover(); // end hover animation
    void SetColor(const QVariant& color); // change the widget color (called by the animation)

public:
    void SetPath(QString path); // set the path for the svg
    bool event(QEvent *event) override;
    QString path() const;
    void setPath(const QString &newPath);
    QColor color_default() const;
    void setColor_default(const QColor &newColor_default);

    QColor color_hover() const;
    void setColor_hover(const QColor &newColor_hover);

protected:
    virtual void resizeEvent(QResizeEvent *event) override; // handle resizing

signals:
    void pathChanged(); // update svg when path changes
    void color_default_Changed(); // required by QProperties
    void color_hover_Changed(); // required by QProperties

private:
    QString m_path; ///< path to the rendered SVG
    QColor m_color_default; ///< the idle color of the widget
    QColor m_color_hover; ///< the hovered color of the widget
    QSvgRenderer* svg_renderer; ///< SvgRenderer instance for painting svg image to @ref image
    QColor target_color; ///< the current color (set by the animation)
    QImage image; ///< the canvas containing the rendered content to display
    QVariantAnimation animation; ///< used for handling animations
};
