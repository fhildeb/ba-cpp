__kernel void hello_world(__global int* number_array)
{
  int workUnit = (int)get_global_id(0);

  number_array[workUnit] = workUnit;
}
