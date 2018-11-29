/***************************************************************************
**                                                                        **
**  Polyphone, a soundfont editor                                         **
**  Copyright (C) 2013-2018 Davy Triponney                                **
**                                                                        **
**  This program is free software: you can redistribute it and/or modify  **
**  it under the terms of the GNU General Public License as published by  **
**  the Free Software Foundation, either version 3 of the License, or     **
**  (at your option) any later version.                                   **
**                                                                        **
**  This program is distributed in the hope that it will be useful,       **
**  but WITHOUT ANY WARRANTY; without even the implied warranty of        **
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the          **
**  GNU General Public License for more details.                          **
**                                                                        **
**  You should have received a copy of the GNU General Public License     **
**  along with this program. If not, see http://www.gnu.org/licenses/.    **
**                                                                        **
****************************************************************************
**           Author: Davy Triponney                                       **
**  Website/Contact: https://www.polyphone-soundfonts.com                 **
**             Date: 01.01.2013                                           **
***************************************************************************/

#ifndef SF2PDTAPART_SHDR_H
#define SF2PDTAPART_SHDR_H

#include "sf2basetypes.h"
#include <QString>
class QDataStream;

class Sf2PdtaPart_shdr
{
public:
    Sf2PdtaPart_shdr();

    bool _isValid;

    QString _name;
    quint32Reversed _start;
    quint32Reversed _end;
    quint32Reversed _startLoop;
    quint32Reversed _endLoop;
    quint32Reversed _sampleRate;
    quint8 _originalPitch;
    qint8 _correction;
    quint16Reversed _wSampleLink;
    quint16Reversed _sfSampleType;
};

// Extension methods for QDataStream to serialize / deserialize
QDataStream & operator >> (QDataStream &in, Sf2PdtaPart_shdr &shdr);
//QDataStream & operator << (QDataStream &out, const Sf2PdtaPart_shdr &shdr);

#endif // SF2PDTAPART_SHDR_H
