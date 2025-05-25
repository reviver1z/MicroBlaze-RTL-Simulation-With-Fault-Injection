# MicroBlaze-RTL-Simulation-With-Fault-Injection
Based on my previous GitHub repository: https://github.com/reviver1z/MicroBlaze-RTL-Simulation

Bit-flips were injected into the BRAM signal of the MicroBlaze RTL Simulation system to demonstrate how a single fault can modify the result of summing 9 float values (1.0+2.0+3.0+4.0+5.0+6.0+7.0+8.0+9.0=45.0).

SDK Folder Contains helloworld.c *(VITIS : application program).

VIVADO Folder Contains testbench.vhd *(VIVADO : testbench).

array_sum.pdf Contains instructions *(FOLLOW : along).

**Note 1:**  
To inject bit-flips, I used the `add_force` command to override the binary pattern on the `bram_wrdata_a_0` signal.  
Before doing that, make sure to set the signal's radix to **binary**.  
Then, run the full simulation and observe the altered result in the `charbuffer[1:20]` signal and in the **TCL Console**, which should now differ from the original sum.

**Note 2:**  
Examples of bit-flip injection can be found in the waveform screenshots provided in `arraysum.pdf` (Pages 34–38).
