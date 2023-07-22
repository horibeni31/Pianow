#ifndef MAINWINDOW_H
#define MAINWINDOW_H

namespace Ui {
  class MainWindow;

}
#include <QMainWindow>

class MainWindow : public QMainWindow {

  Q_OBJECT

public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();
private slots:
  void on_btnSettings_clicked();
  void on_btnExit_clicked();
  void on_btnStart_clicked();
private:
Ui::MainWindow* _ui;
  
};

#endif