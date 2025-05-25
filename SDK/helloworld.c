#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xil_io.h"
#include "xparameters.h"

int main()
{
    init_platform();

    static float arr[9] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0};
    union {
        unsigned int a;
        float b;
    } itof;
    float sum = 0.0;
    int i;

    // Writing array values to BRAM:
    for(i = 0; i < 9; i++){
         itof.b = arr[i];
         Xil_Out32(XPAR_AXI_BRAM_0_BASEADDRESS + (4 * i), itof.a);// Writing to BRAM.
         sum += arr[i];
    }
    
    itof.b = sum;//Saving : Result : In : UNION
    Xil_Out32(XPAR_AXI_BRAM_0_BASEADDRESS + (4 * 9), itof.a); //Write The sum to BRAM.

    cleanup_platform();
    return 0;
}