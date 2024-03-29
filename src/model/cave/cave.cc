#include "cave.h"

namespace s21 {

Cave::Cave() {}

Cave::Cave(size_t rows, size_t cols) : rows_(rows), cols_(cols) {
  grid_.resize(rows, std::vector<bool>(cols, false));
}

Cave::Cave(const Grid &matrix)
    : rows_(matrix.size()),
      cols_(matrix.size() == 0 ? 0 : matrix[0].size()),
      grid_(matrix) {}

size_t Cave::getRows() const { return rows_; }

size_t Cave::getCols() const { return cols_; }

bool Cave::isAlive(size_t row, size_t col) const {
  if (row >= rows_ || col >= cols_) {
    throw std::out_of_range("Index out of range");
  }
  return grid_[row][col];
}

void Cave::setAlive(size_t row, size_t col, bool alive) {
  if (row >= rows_ || col >= cols_) {
    throw std::out_of_range("Index out of range");
  }
  grid_[row][col] = alive;
}

const Cave::Grid &Cave::getGrid() const { return grid_; }

void Cave::setGrid(Grid &grid) {
  grid_ = grid;
  rows_ = grid.size();
  cols_ = grid.size() == 0 ? 0 : grid[0].size();
}

void Cave::setGrid(Grid &&grid) {
  rows_ = grid.size();
  cols_ = grid.size() == 0 ? 0 : grid[0].size();
  grid_ = std::move(grid);
}

size_t Cave::get_number_living_neighbors(size_t row, size_t col) {
  if (row >= rows_ || col >= cols_) {
    throw std::out_of_range("Index out of range");
  }
  size_t number = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) {
        continue;
      }

      if ((row == 0 && i == -1) || (col == 0 && j == -1) ||
          (row == rows_ - 1 && i == 1) || (col == cols_ - 1 && j == 1)) {
        ++number;
        continue;
      }
      if (grid_[row + i][col + j]) {
        ++number;
      }
    }
  }
  return number;
}

}  // namespace s21
