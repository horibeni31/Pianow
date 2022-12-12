#ifndef SETTINGS_H
#define SETTINGS_H
#include <QComboBox>
#include <qboxlayout.h>
#include <qcombobox.h>
#include <qdialog.h>
#include <qmainwindow.h>
#include <qobjectdefs.h>
class Settings : public QDialog {
  Q_OBJECT
private:
  QVBoxLayout *layout;
  QComboBox *cmb_midi_devices;

public:
  Settings();
private slots:
  void device_selection_changed(int index);
};

#endif