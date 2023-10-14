#include "src/settingsdialog.h"

#include <qdialog.h>
#include <qobjectdefs.h>

#include <QComboBox>
#include <iostream>
#include <vector>

#include "settings.h"
#include "src/midicontroller.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) : QDialog(parent), _ui(new Ui::SettingsDialog())
{
    _ui->setupUi(this);

    std::vector<std::string> devices = MidiController::GetInstance()->getDevices();
    for (int i = 0; i < devices.size(); i++)
    {
        _ui->comboBox->addItem(devices[i].c_str());
        if (devices[i] == Settings::getInstance()->midiDevice())
            _ui->comboBox->setCurrentIndex(i);
    }
}
SettingsDialog::~SettingsDialog()
{
    delete _ui;
}

void SettingsDialog::accept()
{
    Settings::getInstance()->setMidiDevice(_ui->comboBox->itemText(_ui->comboBox->currentIndex()).toStdString());
    MidiController::GetInstance()->Connect(_ui->comboBox->currentIndex());
    QDialog::accept();
}