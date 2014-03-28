#include "CWebSiteItemDelegate.h"
#include <QStyleOptionViewItem>
#include <QCheckBox>
#include <QPainter>
#include <QApplication>
#include <QMessageBox>
#include "CWebSiteListModel.h"

#define UNDEFINEDWEB "--Undefined--"

CWebSiteItemDelegate::CWebSiteItemDelegate(QObject *parent) :
    QStyledItemDelegate(parent)
{
}

QWidget *CWebSiteItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &/*option*/, const QModelIndex &index) const
{
    QCheckBox* checkBox = new QCheckBox(parent);
    QString strWebsite = index.data(WebSiteRole).toString();
    if (strWebsite.isEmpty()) {
        checkBox->setText(UNDEFINEDWEB);
    } else {
        checkBox->setText(strWebsite);
    }

    bool bChecked = index.data(WebUseableRole).toBool();
    checkBox->setChecked(bChecked);

    return checkBox;
}

void CWebSiteItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QCheckBox* checkBox = static_cast<QCheckBox*>(editor);
    checkBox->setEnabled(true);
    checkBox->setCheckable(true);
    QString strWebsite = index.data(WebSiteRole).toString();
    if (strWebsite.isEmpty()) {
        checkBox->setText(UNDEFINEDWEB);
    } else {
        checkBox->setText(strWebsite);
    }

    bool bChecked = index.data(WebUseableRole).toBool();
    checkBox->setChecked(bChecked);
}

void CWebSiteItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QCheckBox* checkBox = static_cast<QCheckBox*>(editor);
    connect(checkBox, SIGNAL(toggled(bool)), SLOT(on_checkBox_Toggle(bool)));

    QString strWebsite = checkBox->text();
    bool bChecked = checkBox->checkState() == Qt::Checked;

    model->setData(index, strWebsite, WebSiteRole);
    model->setData(index, bChecked, WebUseableRole);
}

void CWebSiteItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &/*index*/) const
{
    editor->setGeometry(option.rect);
}

void CWebSiteItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    int value = index.data(WebUseableRole).toInt();

    QStyleOptionButton check_box_style_option;
    check_box_style_option.state |= QStyle::State_Enabled;
    if (value == 1) {
        check_box_style_option.state |= QStyle::State_On;
    } else {
        check_box_style_option.state |= QStyle::State_Off;
    }
    check_box_style_option.rect = option.rect;
    check_box_style_option.text = index.data(WebSiteRole).toString();

    QApplication::style()->drawControl(QStyle::CE_CheckBox, &check_box_style_option, painter);
}

QSize CWebSiteItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &/*index*/) const
{
    return option.rect.size();
}

bool CWebSiteItemDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if (event->type() == QEvent::MouseButtonPress) {
        bool checkState = option.checkState == Qt::Checked ? false : false;
        model->setData(index, WebUseableRole, checkState);
    }

    return QStyledItemDelegate::editorEvent(event, model, option, index);
}

void CWebSiteItemDelegate::on_checkBox_Toggle(bool b)
{
    QMessageBox::information(0, "Info", "CheckBox toggled");
}

