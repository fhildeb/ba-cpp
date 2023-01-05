# OpenCL Kernel Integration

## Functionality

The program starts a kernel function, which is specified in the `hello.cl` file and already read in by the template of `hello.cxx`. The task consists of 20 work items. Each item is a call of the kernel.

The kernel function is writing its work item number into an array of 20 `cl_int`. Due to hardware speed, the array is filled practically at the same time. In the main program we check, if the kernel has been executed by printing the contents of the array.

The kernel is compiled at runtime.
