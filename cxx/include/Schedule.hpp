#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "Minisymposia.hpp"
#include "Rooms.hpp"
#include <QAbstractTableModel>

class Schedule : public QAbstractTableModel
{
public:
  Schedule(int nrows, int ncols, Rooms* rooms, Minisymposia* mini, QObject *parent = nullptr);
  ~Schedule();
  int rowCount(const QModelIndex &parent = QModelIndex()) const override;
  int columnCount(const QModelIndex &parent = QModelIndex()) const override;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
  QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
  bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
  Qt::ItemFlags flags(const QModelIndex &index) const override;
  Qt::DropActions supportedDropActions() const override;
  QMimeData* mimeData(const QModelIndexList &indices) const override;
  bool dropMimeData(const QMimeData *data, Qt::DropAction action, 
                    int row, int column, const QModelIndex &parent) override;
private:
  Rooms* rooms_;
  Minisymposia* mini_;
  Kokkos::View<int**, Kokkos::HostSpace> mini_indices_;
};

#endif // SCHEDULE_H