#ifndef __MAZE_SOURCE_VIEW_QGRAPHICSCELLITEM_H__
#define __MAZE_SOURCE_VIEW_QGRAPHICSCELLITEM_H__

#include <QBrush>
#include <QGraphicsItem>
#include <QPainter>

namespace s21 {
class QGraphicsCellItem : public QGraphicsItem {
 public:
  QGraphicsCellItem(QGraphicsItem* parent = nullptr);
  QGraphicsCellItem(qreal x1, qreal y1, qreal x2, qreal y2,
                    QGraphicsItem* parent = nullptr);

  QRectF boundingRect() const override;

  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
             QWidget* widget = nullptr) override;

  void setBorderUp(bool show);
  void setBorderDown(bool show);
  void setBorderLeft(bool show);
  void setBorderRight(bool show);
  void setFilled(bool filled);
  void setBorderSize(int size);

 private:
  qreal x1_{};
  qreal y1_{};
  qreal x2_{};
  qreal y2_{};
  bool filled_{};
  int border_size_{};
  bool up_border_{};
  bool down_border_{};
  bool left_border_{};
  bool right_border_{};
};

}  // namespace s21

#endif  // __MAZE_SOURCE_VIEW_QGRAPHICSCELLITEM_H__