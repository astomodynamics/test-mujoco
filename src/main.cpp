#include "mujoco/mujoco.h"
#include <cstring> 
#include "stdio.h"

int main() {
    mjModel* m = 0;  // Initialize m to NULL
    mjData* d = 0;

    // Load model from file 
    char error[1000] = "Could not load binary model";
    m = mj_loadModel("model.xml", NULL); // Pass NULL for vfs directly

    if (m == NULL) {
        mju_error_s("Load model error: %s", error);
        return 1; 
    }

    // Make data 
    d = mj_makeData(m);

    // Run simulation for 1000 steps
    while( d->time < 1.0 )
        mj_step(m, d);

    // Free model and data 
    mj_deleteData(d);
    mj_deleteModel(m);

    return 0; 
}