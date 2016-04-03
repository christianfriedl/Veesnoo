#include "Label.h"
#include "Logger.h"

using namespace nv;

int main() {
    Label l("abcde", 1, 1);
    Logger::get().log("label l:");
    Logger::get().log(l.toString());
    l.refresh();
    getch();
}
