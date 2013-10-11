/***************************************************************************
**                                                                        **
**  Polyphone, a soundfont editor                                         **
**  Copyright (C) 2013 Davy Triponney                                     **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program.  If not, see http://www.gnu.org/licenses/.   **
**                                                                        **
****************************************************************************
**           Author: Davy Triponney                                       **
**  Website/Contact: http://www.polyphone.fr/                             **
**             Date: 01.01.2013                                           **
***************************************************************************/

#ifndef PIANOKEYBDCUSTOM_H
#define PIANOKEYBDCUSTOM_H

#include "pianokeybd.h"
#include "RtMidi.h"
#include <QKeyEvent>
#include <keymapper.h>

// Evenements
class NoteEvent : public QEvent
{
public:
    NoteEvent(unsigned char note, unsigned char val) : QEvent(QEvent::User),
          m_note(note),
          m_velocity(val) {}
    unsigned char getNote() const {return m_note;}
    unsigned char getVelocity() const {return m_velocity;}

protected:
    unsigned char m_note;
    unsigned char m_velocity;
};


class PianoKeybdCustom : public PianoKeybd
{
    Q_OBJECT
public:
    enum KeyboardType
    {
        KEYBOARD_5_OCTAVES,
        KEYBOARD_6_OCTAVES,
        KEYBOARD_128_NOTES
    };
    PianoKeybdCustom(QWidget * parent);
    ~PianoKeybdCustom();
    // Méthodes publiques
    QStringList getPortNames();
    void openMidiPort(int val);
    void changeKey(int key, int vel);
    void setKeyboardType(KeyboardType type);
    void setMapper(KeyMapper * mapper)
    {
        _mapper = mapper;
    }

signals:
    void keyChanged(int note, int vel);

protected:
    void keyPressEvent(QKeyEvent *event)
    {
        if (event->isAutoRepeat())
            event->ignore();
        else
        {
            if (_mapper)
            {
                QString modifier = QString::null;
                if (event->modifiers() & Qt::ShiftModifier)
                    modifier += "Shift+";
                QString key = (QString)QKeySequence(event->key());
                int note = _mapper->getKey(QKeySequence(modifier + key));
                if (note != -1)
                    this->changeKey(note, 127);
            }
            event->accept();
        }
    }

    void keyReleaseEvent(QKeyEvent *event)
    {
        if (event->isAutoRepeat())
            event->ignore();
        else
        {
            if (_mapper)
            {
                QString modifier = QString::null;
                if (event->modifiers() & Qt::ShiftModifier)
                    modifier += "Shift+";
                QString key = (QString)QKeySequence(event->key());
                int note = _mapper->getKey(QKeySequence(modifier + key));
                if (note != -1)
                    this->changeKey(note, 0);
            }
            event->accept();
        }
    }

    void customEvent(QEvent * event)
    {
        NoteEvent *noteEvent = dynamic_cast<NoteEvent *>(event);
        this->changeKey(noteEvent->getNote(), noteEvent->getVelocity());
        event->accept();
    }

private:
    RtMidiIn * midiin;
    KeyMapper * _mapper;
};


#endif // PIANOKEYBDCUSTOM_H
