#ifndef __MAZE_MODEL_MAZEGENERATOR_H__
#define __MAZE_MODEL_MAZEGENERATOR_H__

#include "maze.h"

namespace s21 {

class MazeGenerator {
 public:
  Maze generatePerfectMaze(size_t M, size_t N) {
    std::vector<std::vector<Cell>> grid(M, std::vector<Cell>(N, {0, 0, 0}));

    for (size_t row = 0; row < M; row++) {
      gen_preprocessing(grid, row);
      gen_right_walls(grid[row]);
      gen_down_walls(grid[row]);
    }
    gen_postprocessing(grid[M - 1]);

    return Maze(grid);
  }

 private:
  void gen_preprocessing(std::vector<std::vector<Cell>>& grid, size_t num_row) {
    size_t N = grid[0].size();

    if (num_row == 0) {
      for (size_t i = 0; i < N; i++) {
        grid[num_row][i].set_id = i;
      }
    } else {
      grid[num_row] = grid[num_row - 1];

      for (size_t col = 0; col < N; col++) {
        int new_set = num_row * N + col;

        if (grid[num_row][col].down_wall == 1) {
          grid[num_row][col].set_id = new_set;
        }

        grid[num_row][col].right_wall = 0;
        grid[num_row][col].down_wall = 0;
      }
    }
  }

  void gen_right_walls(std::vector<Cell>& curr_row) {
    size_t N = curr_row.size();

    for (size_t element = 0; element < N - 1; element++) {
      if (dist(gen)) {
        curr_row[element].right_wall = 1;
      } else {
        if (curr_row[element].set_id == curr_row[element + 1].set_id) {
          curr_row[element].right_wall = 1;
        } else {
          for (int i = 0; i < N; i++) {
            if (curr_row[i].set_id == curr_row[element + 1].set_id) {
              curr_row[i].set_id = curr_row[element].set_id;
            }
          }
        }
      }
    }
  }

  void gen_down_walls(std::vector<Cell>& curr_row) {
    size_t N = curr_row.size();

    for (size_t element = N - 1; static_cast<int>(element) >= 0; element--) {
      if (!dist(gen)) {
        curr_row[element].down_wall = 0;
      } else {
        int count_down_walls = 0;
        for (int i = 0; i < N; i++) {
          if (curr_row[element].set_id == curr_row[i].set_id &&
              !curr_row[i].down_wall) {
            count_down_walls++;
          }
        }

        if (count_down_walls > 1) {
          curr_row[element].down_wall = 1;
        }
      }
    }
  }

  void gen_postprocessing(std::vector<Cell>& curr_row) {
    size_t N = curr_row.size();

    for (size_t element = 0; element < N - 1; element++) {
      curr_row[element].down_wall = 1;

      if (curr_row[element].set_id != curr_row[element + 1].set_id) {
        curr_row[element].right_wall = 0;
      }

      for (int i = 0; i < N; i++) {
        if (curr_row[i].set_id == curr_row[element + 1].set_id) {
          curr_row[i].set_id = curr_row[element].set_id;
        }
      }
    }
  }

 private:
  std::random_device rd{};
  std::mt19937 gen{rd()};
  std::uniform_int_distribution<> dist{0, 1};
};

}  // namespace s21

#endif  // __MAZE_MODEL_MAZEGENERATOR_H__