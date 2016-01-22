#include "Scrollable.h"

Scrollable::Scrollable(vector<Column*> _columns)
{
  columns = _columns;
}

Column* Scrollable::next()
{
  Column* result = columns[idx_state];
  idx_state++;

  return result;
}
