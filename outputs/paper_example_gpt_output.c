```c
#include <stdio.h>
#include <assert.h>

float DAT_001020e0[6] = { /* Initialize with appropriate values */ };
float DAT_001020e4[6] = { /* Initialize with appropriate values */ };
float DAT_00102100[6] = { /* Initialize with appropriate values */ };
float DAT_00102104[6] = { /* Initialize with appropriate values */ };
float DAT_00102110[6] = { /* Initialize with appropriate values */ };
float DAT_00102114[6] = { /* Initialize with appropriate values */ };

int func0(float param1, float *array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (abs(array[i] - array[j]) < param1) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    assert(func0(DAT_001020f8, DAT_001020e0, 6) == 1);
    assert(func0(DAT_001020fc, DAT_001020e0, 6) == 0);
    assert(func0(DAT_00102100, DAT_001020e0, 5) == 1);
    assert(func0(DAT_00102104, DAT_001020e0, 5) == 0);
    assert(func0(DAT_001020e4, DAT_001020e0, 5) == 1);
    assert(func0(DAT_00102110, DAT_001020f0, 5) == 1);
    assert(func0(DAT_00102114, DAT_001020f0, 5) == 0);

    return 0;
}
```