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

#ifndef FILTERTAG_H
#define FILTERTAG_H

#include <QWidget>
class QCompleter;
class FlowLayout;
class QVBoxLayout;

namespace Ui {
class FilterTag;
}

class FilterTag : public QWidget
{
    Q_OBJECT

public:
    explicit FilterTag(QWidget *parent = 0);
    ~FilterTag();

    // Initialize the different tags that can be selected
    void setPossibleTags(QStringList tags);

    void select(QStringList tags);
    QStringList getSelection();

signals:
    void selectionChanged();

private slots:
    void onCompletionSelected(QString completion);
    void on_lineEdit_returnPressed();
    void onCellDelete();

private:
    Ui::FilterTag *ui;
    QStringList _possibleTags;
    QStringList _tags;
    QCompleter * _completer;
    QVBoxLayout * _layout;
};

#endif // FILTERTAG_H
