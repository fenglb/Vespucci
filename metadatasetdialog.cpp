/*******************************************************************************
    Copyright (C) 2014 Wright State University - All Rights Reserved
    Daniel P. Foose - Author

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
*******************************************************************************/
#include "metadatasetdialog.h"
#include "ui_metadatasetdialog.h"
#include "metadataset.h"
MetaDatasetDialog::MetaDatasetDialog(QWidget *parent, VespucciWorkspace *ws) :
    QDialog(parent),
    ui(new Ui::MetaDatasetDialog)
{
    ui->setupUi(this);
    cout << "MetaDatasetDialog Constructor" << endl;
    dataset_list_view_ = this->findChild<QListView*>("datasetListView");
    cout << "height of list view: " << dataset_list_view_->height();
    workspace = ws;
    cout << "get model" << endl;
    dataset_list_model_ = ws->dataset_list_model();
    cout << "set model" << endl;
    dataset_list_view_->setModel(dataset_list_model_);
    cout << "set selection model" << endl;
    dataset_list_view_->setSelectionMode(QAbstractItemView::MultiSelection);
    cout << "find boxen" << endl;
    method_selection_box_ = findChild<QComboBox *>("methodComboBox");
    name_line_edit_ = findChild<QLineEdit *>("nameLineEdit");
}

MetaDatasetDialog::~MetaDatasetDialog()
{
    delete ui;
}

void MetaDatasetDialog::on_buttonBox_rejected()
{
    this->close();
}

void MetaDatasetDialog::on_buttonBox_accepted()
{
    QList<QSharedPointer<VespucciDataset> > parent_datasets;
    QModelIndexList selected_indices = dataset_list_view_->selectionModel()->selectedRows();
    for (int i = 0; i < selected_indices.size(); ++i){
        parent_datasets.append(dataset_list_model_->DatasetAt(selected_indices[i].row()));
    }

    QString method_description = method_selection_box_->currentText();
    VespucciMetaMethod method;
    switch(method_selection_box_->currentIndex()){
    case 0:
        cout << method_description.toStdString() << endl;
        cout << "0" << endl;
        method = ConcatenateDatasets;
        break;
    case 1: default:
        cout << method_description.toStdString() << endl;
        cout << "1 or default" << endl;
        method = AverageSpectra;
        break;
    }

    QString name = name_line_edit_->text();
    QFile *log_file = workspace->CreateLogFile(name);

    QSharedPointer<MetaDataset> new_dataset(new MetaDataset(name, workspace->main_window(), log_file, workspace->directory_ptr(), method_description, method, parent_datasets));
    workspace->AddDataset(new_dataset);
}
