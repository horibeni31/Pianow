#ifndef SETTINGS_H
#define SETTINGS_H
#include <QDialog>

namespace Ui {

class SettingsDialog;
}

class SettingsDialog : public QDialog {
  Q_OBJECT
private:
  Ui::SettingsDialog *_ui;

public:
  SettingsDialog(QWidget *parent = nullptr);
  ~SettingsDialog();

private slots:
  void device_selection_changed(int index);
};

#endif