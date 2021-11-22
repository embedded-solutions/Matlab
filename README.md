Simulink (Embedded Coder) Target for MicroDAQ Real-Time Measurement System
=============

Description
============

MicroDAQ (http://www.embedded-solutions.pl) is a Real-Time Measurement
and Rapid Control Prototyping System.

Simulink (http://www.mathworks.com/products/simulink) is a leading environment
for multidomain simulation and Model-Based Design.

Embedded Coder (http://www.mathworks.com/products/embedded-coder) allows you to
generate C code and deploy your algorithms to target hardware.

**Supported Matlab version:**

This package will work with R2013a - R2017a. 

Installation
============

1) Install latest MicroDAQ firmware from firmware directory.
- Open web browser and enter MicroDAQ IP address to open MicroDAQ Web Panel
- Go to 'File manager' and navigate to 'upgrade' direcotry 
- Click upload icon (plus sign - top-right side of File manager)
- Press first button and navigate to firmware directory (downloaded with Simulink Target for MicroDAQ). Confirm with 'Open'
- The 'opk' file shall be uploaded on target and visible in 'upgrade' directory.
- Go to Upgrade (left-side menu) and confirm with Upgrade button. 
- After device reboot check info and installed firmware version

2) Install DSP compiler for MicroDAQ 
This compiler will be used by Matlab/Simulink to compile generated code. You will be asked for install path when configuring Simulink Target for MicroDAQ with 'microdaq_setup' Matlab script.
- Download C6000 DSP compiler from: https://www.ti.com/tool/download/C6000-CGT-8-3/8.3.2
- Install compiler (do not use spaces in paths)
3) Make sure you have a working/supported host compiler (http://www.mathworks.com/support/compilers/index.html) by running
        
        mex -setup
in MATLAB.
Avoid using the lcc compiler which ships with MATLAB for Windows. It is known to cause problems.

4) Configure Simulink Target for MicroDAQ
- In Matlab navigate to directory 'microdaq_ert' which should contain 'microdaq_setup.m' script. 
- Run scropt from Matlab console 
- You will be asked to point directory in which C6000 DSP compiler is installed (see point 2). Example path can be: c:\ti\ti-cgt-c6000_8.3.2\
- In the next step provide IP address of MicroDAQ device. By default 10.10.1.1 is for Ethernet, 10.10.2.1 is for Wi-Fi and 10.10.3.1 is for Ethernet over USB. Connection with MicroDAQ should be verified with standard system 'ping' command executed from windows command line. 
- After script completion verify connection with 'mdaqPing' Matlab command.
- If 'mdaqPing' return 'SUCCESS" you can start using Matlab/Simulink with MicroDAQ. 



TODO
============

- CAN Receive need CAN Pack block in model. Unable to call mdlInitialize_CAN_datatype(S) in S-function due to 'mex' linkage problem with scanutil.lib. https://www.mathworks.com/help/vnt/ug/create-custom-can-blocks.html
- PIL mode from time to time has problem with connecting to MicroDAQ
- TCP/UDP blocks are not supported 
- MEM blocks are not supported
- More documentation
- More demos
