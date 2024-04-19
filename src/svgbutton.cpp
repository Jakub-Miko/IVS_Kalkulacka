/** @file svgbutton.h
 * @brief Custom PushButton for svg rendering with hover effects
 *
 * @author Jakub Miko
*/
#include "svgbutton.h"
#include <QtSvgWidgets/QtSvgWidgets>
#include <QMediaPlayer>
#include <QAudioOutput>

SvgButton::SvgButton(QWidget *parent) : QPushButton(parent), target_color(QColor(72,72,72)), animation(),
    m_color_default(QColor(72,72,72)), m_color_hover(QColor(30,30,30)) {
    QSvgRenderer* widget = new QSvgRenderer(this);
    svg_renderer = widget;
    svg_renderer->setAspectRatioMode(Qt::AspectRatioMode::KeepAspectRatio);

    animation.setStartValue(target_color);
    animation.setDuration(300);
    animation.setEndValue(m_color_hover);

    connect(&animation, &QVariantAnimation::valueChanged, this, &SvgButton::SetColor);
}

void SvgButton::SetColor(const QVariant& color)
{
    this->target_color = color.value<QColor>();
    update();
}

void SvgButton::SetPath(QString path)
{
    svg_renderer->load(QString(":/resources/") + this->path()); // Loads the svg from the Resource file
    int margin = std::abs(width() - height()) / 2; ///< margin used for maintaining the aspect ration
    QRect res;
    if(width() >height()) {
        res = QRect(margin ,0, height(), height());

    } else {
        res = QRect(0 ,margin, width(), width());

    }
    QImage image(res.size(),QImage::Format_A2BGR30_Premultiplied);
    image.fill(Qt::GlobalColor::transparent); // Clear the canvas
    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing , true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform,true);

    painter.setCompositionMode(QPainter::CompositionMode_SourceOver); // make sure both alpha and color channels are written
    svg_renderer->setAspectRatioMode(Qt::AspectRatioMode::KeepAspectRatio);
    svg_renderer->render(&painter,QRectF(0 ,0, res.width(), res.height())); // render the svg
    this->image = image;
    painter.end();
}


void SvgButton::paintEvent(QPaintEvent *event)
{
    // Calculate the image size, maintaining the aspect ratio
    int margin = std::abs(width() - height()) /2;
    QRect res;
    if(width() >height()) {
        res = QRect(margin ,0, height(), height());

    } else {
        res = QRect(0 ,margin, width(), width());

    }

    QPainter painter(&image);
    painter.setCompositionMode(QPainter::CompositionMode_SourceIn); // Make only the color channel is used and the existing alpha(svg image) is used as a mask
    painter.fillRect(QRect(0,0,width(), height()), target_color); // the rectangle with the desired color is masked in the shaped of the svg contained in the alpha channel
    painter.end();

    // Draw the canvas into the widget surface
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing , true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform,true);
    if(width() >height()) {
        painter.drawImage(QRectF(margin ,0, height(), height()), image);

    } else {
        painter.drawImage(QRectF(0 ,margin, width(), width()), image);

    }
    painter.end();

}

void SvgButton::resizeEvent(QResizeEvent *event)
{
    // Resize the image, and rerender the svg for the new resolution
    int margin = std::abs(width() - height()) /2;
    QRect res;
    if(width() >height()) {
        res = QRect(margin ,0, height(), height());

    } else {
        res = QRect(0 ,margin, width(), width());

    }
    QImage image(res.size(),QImage::Format_A2BGR30_Premultiplied);
    image.fill(Qt::GlobalColor::transparent);
    QPainter painter(&image);
    painter.setRenderHint(QPainter::Antialiasing , true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform,true);

    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    svg_renderer->render(&painter,QRectF(0 ,0, res.width(), res.height()));
    this->image = image;
    painter.end();
    QWidget::resizeEvent(event);
}

void SvgButton::EnterHover()
{
    animation.stop();
    QColor value = animation.currentValue().value<QColor>();
    animation.setStartValue(value);
    animation.setEndValue(m_color_hover);
    animation.start();
}

void SvgButton::LeaveHover()
{
    animation.stop();
    QColor value = animation.currentValue().value<QColor>();
    animation.setStartValue(value);
    animation.setEndValue(m_color_default);
    animation.start();
}


bool SvgButton::event(QEvent *event)
{
    // Capture hover events to launch animations
    if(event->type() == QEvent::Type::Enter) {
        EnterHover();
        //qDebug() << "Enter";
    }

    if(event->type() == QEvent::Type::Leave) {
        LeaveHover();
        //qDebug() << "Enter";
    }


    return QPushButton::event(event);
}

QString SvgButton::path() const
{
    return m_path;
}

void SvgButton::setPath(const QString &newPath)
{
    if (m_path == newPath)
        return;
    m_path = newPath;
    SetPath(newPath);
    emit pathChanged();
}

QColor SvgButton::color_default() const
{
    return m_color_default;
}

void SvgButton::setColor_default(const QColor &newColor_default)
{
    if (m_color_default == newColor_default)
        return;
    m_color_default = newColor_default;
    target_color = newColor_default;
    animation.setStartValue(target_color);
    emit color_default_Changed();
}

QColor SvgButton::color_hover() const
{
    return m_color_hover;
}

void SvgButton::setColor_hover(const QColor &newColor_hover)
{
    if (m_color_hover == newColor_hover)
        return;
    m_color_hover = newColor_hover;
    emit color_hover_Changed();
}
