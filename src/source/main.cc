#include <QApplication>

#include "adapter.h"
#include "mainwindow.h"
#include "./model/cave/cellularautomaton.h"
#include "./model/cave/cave.h"


int main(int argc, char *argv[]) {
  QApplication a(argc, argv);

  s21::Cave cave;
  s21::CellularAutomaton cellular_automaton(cave);
  s21::Adapter adapter(cellular_automaton);
  
  s21::MainWindow w(adapter);

  w.show();
  return a.exec();
}
