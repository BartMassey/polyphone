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

#ifndef TOOLBALANCEADJUSTMENT_H
#define TOOLBALANCEADJUSTMENT_H

#include "abstracttooliterating.h"
#include <QObject>
#include <QMutex>

class ToolBalanceAdjustment: public AbstractToolIterating
{
    Q_OBJECT

public:
    ToolBalanceAdjustment() : AbstractToolIterating(elementSmpl) {}

    /// Icon, label and category displayed to the user to describe the tool
    QString getIconName() const override
    {
        return ":/tool/balance.svg";
    }

    QString getCategory() const override
    {
        return trUtf8("Stereo samples");
    }

    /// Internal identifier
    QString getIdentifier() const override
    {
        return "smpl:balance";
    }

    /// Method executed before the iterating process
    void beforeProcess(IdList ids) override;

    /// Process an element
    void process(SoundfontManager * sm, EltID id, AbstractToolParameters * parameters) override;

protected:
    QString getLabelInternal() const override
    {
        return trUtf8("Balance adjustement");
    }

    /// Get the warning to display after the tool is run
    QString getWarning() override;

private:
    QMutex _mutex;
    IdList _processedSamples;
    QStringList _monoSamplesInError;
};

#endif // TOOLBALANCEADJUSTMENT_H
