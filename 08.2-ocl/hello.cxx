#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>

#include <CL/cl.h>

using namespace std;

int main(int argv, char** argc)
{
  cl_uint ret_num_devices;
  cl_uint ret_num_platforms;

  cl_int  ret;

  // unser PlattformID-Array ist noch NULL, wir wollen nur die Anzahl
  // von Plattformen wissen, um den Array zu reservieren

  ret = clGetPlatformIDs(0, NULL, &ret_num_platforms);

  if(ret != CL_SUCCESS) {
    cerr << "clGetPlatformIDs() kam mit Fehler zurück" << endl;
    exit(-1);
  } // if

  cout << "Anzahl Plattformen: " << ret_num_platforms << endl;
  
  // jetzt den Speicher reservieren ...

  cl_platform_id platformIDs[ret_num_platforms]; // wenn wir so reservieren, ist kein
                                                 // delete[] nötig, bei new schon!
  
  // ... und den platformID Array füllen

  ret = clGetPlatformIDs(ret_num_platforms, platformIDs, &ret_num_platforms);

  for(int i = 0; i < ret_num_platforms; i++) {
    cout << "Plattform Nr.: " << i << " (intern " << platformIDs[i] << ")" << endl;
    cout << "====================================" << endl;    

    const int SIZE_INFO_STRING = 1024; // sollte für den Info-Text reichen
    char info_string[SIZE_INFO_STRING];

    ret = clGetPlatformInfo(platformIDs[i], CL_PLATFORM_NAME, SIZE_INFO_STRING, (void*) info_string, NULL);
    if(ret != CL_SUCCESS) {exit(-1);};
    cout << "Name:           " << info_string << endl;

    ret = clGetPlatformInfo(platformIDs[i], CL_PLATFORM_VERSION, SIZE_INFO_STRING, (void*) info_string, NULL);
    if(ret != CL_SUCCESS) {exit(-1);};
    cout << "Version:        " << info_string << endl;

    ret = clGetPlatformInfo(platformIDs[i], CL_PLATFORM_VENDOR, SIZE_INFO_STRING, (void*) info_string, NULL);
    if(ret != CL_SUCCESS) {exit(-1);}
    cout << "Vendor:         " << info_string << endl;

    // jetzt die Devices auflisten. Wieviele gibt es eigentlich?

    cl_uint ret_num_devices;
    ret = clGetDeviceIDs(platformIDs[i], CL_DEVICE_TYPE_ALL, 0, NULL, &ret_num_devices);

    cout << "Anzahl Devices: " << ret_num_devices << endl << endl;

    cl_device_id deviceIDs[ret_num_devices];
    ret = clGetDeviceIDs(platformIDs[i], CL_DEVICE_TYPE_ALL, ret_num_devices, deviceIDs, &ret_num_devices);

    for(int j = 0; j < ret_num_devices; j++) {
      cout << "    Gerät Nr.: " << j << " (intern " << deviceIDs[j] << ")" << endl;
      cout << "    ---------------------------------" << endl;
    
      ret = clGetDeviceInfo(deviceIDs[j], CL_DEVICE_NAME, SIZE_INFO_STRING, (void*)info_string, NULL);
      
      if(ret != CL_SUCCESS) {exit(-1);}
      cout << "    Name:                " << info_string << endl;
      ret = clGetDeviceInfo(deviceIDs[j], CL_DEVICE_TYPE, SIZE_INFO_STRING, (void*)info_string, NULL);
      if(ret != CL_SUCCESS) {exit(-1);};
      switch (*((int*)info_string)) {
      case CL_DEVICE_TYPE_CPU:
	printf("    Type:                CL_DEVICE_TYPE_CPU\n");
	break;

      case CL_DEVICE_TYPE_GPU:
	printf("    Type:                CL_DEVICE_TYPE_GPU\n");
	break;

      case CL_DEVICE_TYPE_ACCELERATOR:
	printf("    Type:                CL_DEVICE_TYPE_ACCELERATOR\n");
	break;

      case CL_DEVICE_TYPE_DEFAULT:
	printf("    Type:                CL_DEVICE_TYPE_DEFAULT\n");
	break;

      } // switch
      
      ret = clGetDeviceInfo(deviceIDs[j], CL_DEVICE_MAX_COMPUTE_UNITS, SIZE_INFO_STRING, (void*)info_string, NULL);
      if(ret != CL_SUCCESS) {exit(-1);}      
      cout << "    Compute units:       " << *((cl_uint*)info_string) << endl;
      
      ret = clGetDeviceInfo(deviceIDs[j], CL_DEVICE_GLOBAL_MEM_SIZE, SIZE_INFO_STRING, (void*)info_string, NULL);
      if(ret != CL_SUCCESS) {exit(-1);}
      cout << "    Global dev. memory:  " << *((cl_ulong*)info_string) << endl;
      
      ret = clGetDeviceInfo(deviceIDs[j], CL_DEVICE_LOCAL_MEM_SIZE, SIZE_INFO_STRING, (void*)info_string, NULL);
      if(ret != CL_SUCCESS) {exit(-1);}
      cout << "    Local dev. memory:   " << *((cl_ulong*)info_string) << endl;

      ret = clGetDeviceInfo(deviceIDs[j], CL_DEVICE_MAX_WORK_GROUP_SIZE, SIZE_INFO_STRING, (void*)info_string, NULL);
      if(ret != CL_SUCCESS) {exit(-1);}
      cout << "    Max. workgroup size: " << *((cl_ulong*)info_string) << endl << endl;
      
    } // for

    cout << endl;
  } // for

  int plattform_index, device_index;

  cout << "Plattform: "; cin >> plattform_index;

  // Jetzt nochmal den device_array abholen

  const int MAX_NO_DEVICES = 32;

  cl_device_id deviceIDs[MAX_NO_DEVICES];
  ret = clGetDeviceIDs(platformIDs[plattform_index], CL_DEVICE_TYPE_ALL, MAX_NO_DEVICES, deviceIDs, &ret_num_devices);

  cout << "Device: "; cin >> device_index;

  // MODIFIZIERTER CODE AB HIER:
  // -----------------
  //
  // der Benutzer hat die Plattfrom platformIDs[plattform_index] ausgewählt
  // und das Gerät deviceIDs[device_index]

  // Context für das gewählte Device erzeugen
  // Hinweis: Ein Context kann man für alle Geräte einer Plattform erstellen.
  //          Hier übergeben Sie einfach das Array deviceIDs für alle Geräte.
  
  	cl_context context = clCreateContext(NULL, ret_num_devices,deviceIDs, NULL, 
  								NULL, &ret);
  								
   if(ret != CL_SUCCESS) {exit(-1);}

  // Warteschlange für den Context erzeugen
  // Hinweis: Eine Warteschlange muss immer für genau ein Gerät angegeben werden.
  //          Erzeugen Sie hier eine WS für das Gerät deviceIDs[device_index].

  // cl_command_queue command_queue = clCreateCommandQueue(...);  

  cl_command_queue command_queue = clCreateCommandQueue(context, deviceIDs[device_index],
  												0, &ret);
	if(ret != CL_SUCCESS) {exit(-1);}

  // Speicher für Nummern-Array im Gerät erzeugen
  // Hinweis: Überlegen Sie Sich, ob der Speicher für das Gerät lesbar, schreibbar
  //          oder beides sein muss. Mit beidem sind Sie auf der sicheren Seite.
  //          Sie können statt der 20 auch die Konstante TOTAL_NUMBERS benutzen.

  const cl_int TOTAL_NUMBERS = 20;

  cl_mem dev_mem_numbers = NULL; 
  
  dev_mem_numbers = clCreateBuffer(context, CL_MEM_READ_WRITE, TOTAL_NUMBERS*sizeof(cl_int), NULL,
  							&ret);

  // Programm aus Quelltext erzeugen

  // Hinweis: Hier wird aus der Datei hello.cl eine OpenCL-C
  //          Kernel-Funktion geladen und im String source_str
  //          gespeichert. Als Parameter bekommt die Kernel-Funktion
  //          einen Zeiger auf einen Array (der Größe 20). Welche
  //          Teilaufgabe die Kernel-Funktion bearbeiten soll erfährt
  //          sie aus get_global_id(0), z.B. soll Teilaufgabe 5
  //          bearbeitet werden. Die Aufgabe ist lediglich in das
  //          Array-Element 5 die Zahl 5 zu schreiben. Wir erkennen
  //          dadurch später im Hauptprogramm, dass der Kernel
  //          ausgeführt wurde.
  
  // OpenCL-Code kompilieren: Eigentlich brauchen Sie den OpenCl-Code
  //                          nicht kompilieren, da dies während der
  //                          Laufzeit gemacht wird.  Wenn Sie Ihren
  //                          OpenCL-Code vorher doch prüfen möchten,
  //                          so tun Sie dies mit 'make cl_compile'
  //                          auf der Konsole.

  char* source_str = NULL;

  ifstream source_code_file("hello.cl", ifstream::in);
  
  if (source_code_file.good()) {
  
    source_code_file.seekg (0, source_code_file.end);
    int length_file = source_code_file.tellg();
    source_code_file.seekg (0, source_code_file.beg);

    source_str = new char [length_file+1];

    source_code_file.read(source_str, length_file);;
    source_str[length_file] = 0; // 0 indicates end of string                                                                
    cout << "Eingelesenes OpenCL-Programm: " << endl << source_str << endl;
  } // if
    
  source_code_file.close();

  cl_program program;

  // Musterlösung:
  program = clCreateProgramWithSource(context, 1, (const char **)&source_str, NULL, &ret);
  if(ret != CL_SUCCESS) {cerr << "OpenCL-C programm konnte nicht erzeugt werden" << endl; exit(-1);}

  // erzeuge Programm

  ret = clBuildProgram(program, 0, NULL, NULL, NULL, NULL);
  if(ret != CL_SUCCESS) {cerr << "OpenCL-C programm konnte nicht übersetzt werden" << endl; exit(-1);}

  // erzeuge einen Kernel

  cl_kernel kernel;
  kernel = clCreateKernel(program, "hello_world", &ret);
	if(ret == CL_SUCCESS) cout << "Kernel wurde erzeugt" << endl;
	
  // Kernel-Argument setzen
  // Hinweis: Hier müssen Sie den Kernel-Parameter "anmelden. Dabei wird als letztes Element ein Zeiger auf
  //          das zuvor reservierte cl_mem Objekt erwartet, als vorletztes Element die Größe dieses Zeigers.

  ret = clSetKernelArg(kernel, 0, sizeof(dev_mem_numbers), (void *)&dev_mem_numbers);

  // Größe der Aufgabe definieren
  // Hinweis: Sie wollten bei Aufgabe 0 anfangen und haben maximal 20 zu vergeben. Denken Sie daran, dass
  //          die Funktion Zeiger auf die Variablen will und nicht die Variablen selbst!

  const size_t glob_work_offs = 0;
  const size_t glob_work_size = TOTAL_NUMBERS;
  
  ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, &glob_work_offs, &glob_work_size, 
  											NULL, NULL, NULL, NULL);

  // Eigenen Array reservieren, und zwar vom Typ cl_int mit Platz für 20 Einträge

   cl_int* ret_array = new cl_int[TOTAL_NUMBERS];

  // Lieber erst die Berechnung des Ergebnisses abwarten bevor wir es lesen.
  
  ret = clFlush(command_queue);
  ret = clFinish(command_queue);

  // Ergebnis wieder zurücklesen

  ret = clEnqueueReadBuffer(command_queue, dev_mem_numbers, CL_TRUE, 0,
  									TOTAL_NUMBERS*sizeof(cl_int), ret_array, 0, NULL, NULL);

  // ... und geben ihn aus um zu sehen, ob der Kernel wirklich ausgeführt wurde.
	for(int i=0; i < TOTAL_NUMBERS; i++){		
		cout << ret_array[i] << endl;
	}
  ret = clFinish(command_queue);

  // Aufräumarbeiten

  if(source_str) delete source_str; source_str = NULL;

  ret = clReleaseMemObject(dev_mem_numbers);
  ret = clReleaseKernel(kernel);
  ret = clReleaseProgram(program);
  ret = clReleaseCommandQueue(command_queue);
  ret = clReleaseContext(context);

  return 0;
}
