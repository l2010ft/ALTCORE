#include <thread>
#include <queue>
#include <condition_variable>
#include "scheduler.h"
#include "core/config.h"

scheduler::scheduler() {
    chargue scriptch;
    chargue physicsch;

    std::thread scriptload1(&scheduler::Scripts, &scriptch);
    std::thread phisicsload1(&scheduler::Scripts, &physicsch);

    scriptload1.join();
    phisicsload1.join();
}

void scheduler::Phisycs(chargue& physiccom) {

}

void scheduler::Scripts(chargue& scriptcom) {

}