/************************************************************************************
    Copyright (C) 2014 Daniel P. Foose - All Rights Reserved

    This file is part of Vespucci.

    Vespucci is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Vespucci is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Vespucci.  If not, see <http://www.gnu.org/licenses/>.
***************************************************************************************/
#ifndef UNIVARIATEDIALOG_H
#define UNIVARIATEDIALOG_H

#include <QDialog>
#include "vespucciworkspace.h"

namespace Ui {
class UnivariateDialog;
}

///
/// \brief The UnivariateDialog class
/// Class allowing user to create univariate images
class UnivariateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UnivariateDialog(QWidget *parent, VespucciWorkspace *ws, int row);
    ~UnivariateDialog();

private slots:
    void on_buttonBox_accepted();

    void on_peakComboBox_currentTextChanged(const QString &arg1);

    void on_buttonBox_rejected();

private:
    Ui::UnivariateDialog *ui;

    ///
    /// \brief workspace
    /// The current workspace
    VespucciWorkspace *workspace;

    ///
    /// \brief spectrum_plot_
    /// The plot displaying a spectrum
    QCustomPlot *spectrum_plot_;

    ///
    /// \brief min_box_
    /// The user enters her desired minimum value here.
    QLineEdit *min_box_;

    ///
    /// \brief max_box_
    /// The user enters her desired maximum value here.
    QLineEdit *max_box_;

    ///
    /// \brief name_box_
    /// The user enters the name of the dataset her
    QLineEdit *name_box_;

    ///
    /// \brief color_selector_
    /// User selects desired color scheme here
    QComboBox *color_selector_;

    ///
    /// \brief value_method_selector_
    /// User selects value determination method here
    QComboBox *value_method_selector_;

    ///
    /// \brief negative_box_
    /// User selects whether or not the dataset has "negative peaks". This may
    /// be deprecated soon
    QCheckBox *negative_box_;

    ///
    /// \brief integration_method_selector_
    /// User selects integration method here
    QComboBox *integration_method_selector_;

    ///
    /// \brief integration_method_label_
    /// Displays the integration method
    QLabel *integration_method_label_;

    ///
    /// \brief data_index_
    /// Index of current dataset in relevant lists
    int data_index_;

    ///
    /// \brief data_
    /// The current dataset
    QSharedPointer<VespucciDataset> data_;
};

#endif // UNIVARIATEDIALOG_H
