// Copyright (c) 2017-2018 The PIVX developers
// Copyright (c) 2019 The XChainZ developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZXCZCONTROLDIALOG_H
#define ZXCZCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zxcz/zerocoin.h"
#include "privacydialog.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZXczControlDialog;
}

class CZXczControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZXczControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZXczControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZXczControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZXczControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZXczControlDialog(QWidget *parent);
    ~ZXczControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZXczControlDialog *ui;
    WalletModel* model;
    PrivacyDialog* privacyDialog;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZXczControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZXCZCONTROLDIALOG_H
