#ifndef STAFF_H
#define STAFF_H
#include <qnamespace.h>

#include "src/midimessage.h"
namespace Ui
{
class StaffWidget;
}
#include <qimage.h>
#include <qobjectdefs.h>
#include <qpainter.h>

#include <QWidget>
#include <vector>
class StaffWidget : public QWidget
{
    Q_OBJECT
  public:
    StaffWidget(QWidget* parent = nullptr);
    ~StaffWidget();
    void increaseCursorPosition();
    void resetCursor();
    void AddNote(Note n, bool fixed = false);
    void RemoveNote(Note n, bool fixed = false);

  protected:
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
    void drawNote(Note n, QPainter& painter, Qt::GlobalColor color = Qt::black, int position = 0);
  private slots:
    void onMidiEvent(const MidiMessage& message);

  private:
    int _gap;
    int _staffHeight;
    int _cursorPosition = 0;
    QImage treble;
    QImage bass;
    std::vector<Note> pressedNotes;
    std::vector<Note> fixNotes;

    QImage image;
    Ui::StaffWidget* _ui;
};
#endif